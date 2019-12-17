--- compositor/main.c.orig	2017-08-08 18:57:02 UTC
+++ compositor/main.c
@@ -41,7 +41,9 @@
 #include <sys/socket.h>
 #include <libinput.h>
 #include <sys/time.h>
-#include <linux/limits.h>
+/* #include <linux/limits.h> */
+#include <limits.h>
+#define PATH_MAX _POSIX_PATH_MAX
 
 #ifdef HAVE_LIBUNWIND
 #define UNW_LOCAL_ONLY
@@ -61,6 +63,7 @@
 #include "compositor-headless.h"
 #include "compositor-rdp.h"
 #include "compositor-fbdev.h"
+#include "compositor-scfb.h"
 #include "compositor-x11.h"
 #include "compositor-wayland.h"
 #include "windowed-output-api.h"
@@ -99,7 +102,7 @@ static int weston_log_timestamp(void)
 
 	if (brokendown_time->tm_mday != cached_tm_mday) {
 		strftime(string, sizeof string, "%Y-%m-%d %Z", brokendown_time);
-		fprintf(weston_logfile, "Date: %s\n", string);
+		fprintf(weston_logfile, "Date: %s\r\n", string);
 
 		cached_tm_mday = brokendown_time->tm_mday;
 	}
@@ -115,6 +118,7 @@ custom_handler(const char *fmt, va_list arg)
 	weston_log_timestamp();
 	fprintf(weston_logfile, "libwayland: ");
 	vfprintf(weston_logfile, fmt, arg);
+	fprintf(weston_logfile, "\r");
 }
 
 static void
@@ -149,6 +153,7 @@ vlog(const char *fmt, va_list ap)
 
 	l = weston_log_timestamp();
 	l += vfprintf(weston_logfile, fmt, ap);
+	l += fprintf(weston_logfile, "\r");
 
 	return l;
 }
@@ -538,6 +543,9 @@ usage(int error_code)
 #if defined(BUILD_FBDEV_COMPOSITOR)
 			"\t\t\t\tfbdev-backend.so\n"
 #endif
+#if defined(BUILD_SCFB_COMPOSITOR)
+			"\t\t\t\tscfb-backend.so\n"
+#endif
 #if defined(BUILD_HEADLESS_COMPOSITOR)
 			"\t\t\t\theadless-backend.so\n"
 #endif
@@ -577,6 +585,14 @@ usage(int error_code)
 		"\n");
 #endif
 
+#if defined(BUILD_SCFB_COMPOSITOR)
+	fprintf(stderr,
+		"Options for scfb-backend.so:\n\n"
+		"  --tty=TTY\t\tThe tty to use\n"
+		"  --device=DEVICE\tThe framebuffer device to use\n"
+		"\n");
+#endif
+
 #if defined(BUILD_HEADLESS_COMPOSITOR)
 	fprintf(stderr,
 		"Options for headless-backend.so:\n\n"
@@ -680,9 +696,9 @@ clock_name(clockid_t clk_id)
 	static const char *names[] = {
 		[CLOCK_REALTIME] =		"CLOCK_REALTIME",
 		[CLOCK_MONOTONIC] =		"CLOCK_MONOTONIC",
-		[CLOCK_MONOTONIC_RAW] =		"CLOCK_MONOTONIC_RAW",
-		[CLOCK_REALTIME_COARSE] =	"CLOCK_REALTIME_COARSE",
-		[CLOCK_MONOTONIC_COARSE] =	"CLOCK_MONOTONIC_COARSE",
+		/* [CLOCK_MONOTONIC_RAW] =		"CLOCK_MONOTONIC_RAW", */
+		/* [CLOCK_REALTIME_COARSE] =	"CLOCK_REALTIME_COARSE", */
+		/* [CLOCK_MONOTONIC_COARSE] =	"CLOCK_MONOTONIC_COARSE", */
 #ifdef CLOCK_BOOTTIME
 		[CLOCK_BOOTTIME] =		"CLOCK_BOOTTIME",
 #endif
@@ -1579,6 +1595,57 @@ load_x11_backend(struct weston_compositor *c,
 }
 
 static void
+scfb_backend_output_configure(struct wl_listener *listener, void *data)
+{
+	struct weston_output *output = data;
+	struct weston_config *wc = wet_get_config(output->compositor);
+	struct weston_config_section *section;
+
+	section = weston_config_get_section(wc, "output", "name", "scfb");
+
+	wet_output_set_transform(output, section, WL_OUTPUT_TRANSFORM_NORMAL, UINT32_MAX);
+	weston_output_set_scale(output, 1);
+
+	weston_output_enable(output);
+}
+
+static int
+load_scfb_backend(struct weston_compositor *c,
+				  int *argc, char **argv, struct weston_config *wc)
+{
+	struct weston_scfb_backend_config config = {{ 0, }};
+	int ret = 0;
+
+	const struct weston_option scfb_options[] = {
+		{ WESTON_OPTION_INTEGER, "tty", 0, &config.tty },
+		{ WESTON_OPTION_STRING, "device", 0, &config.device },
+	};
+
+	parse_options(scfb_options, ARRAY_LENGTH(scfb_options), argc, argv);
+
+	if (!config.device)
+		config.device = strdup("/dev/ttyv1");
+
+	config.base.struct_version = WESTON_SCFB_BACKEND_CONFIG_VERSION;
+	config.base.struct_size = sizeof(struct weston_scfb_backend_config);
+	config.configure_device = configure_input_device;
+
+	/* load the actual wayland backend and configure it */
+	ret = weston_compositor_load_backend(c, WESTON_BACKEND_SCFB,
+					     &config.base);
+
+	if (ret < 0)
+		goto out;
+
+	wet_set_pending_output_handler(c, scfb_backend_output_configure);
+
+out:
+	free(config.device);
+	return ret;
+
+}
+
+static void
 wayland_backend_output_configure_hotplug(struct wl_listener *listener, void *data)
 {
 	struct weston_output *output = data;
@@ -1724,6 +1791,8 @@ load_backend(struct weston_compositor *compositor, con
 		return load_rdp_backend(compositor, argc, argv, config);
 	else if (strstr(backend, "fbdev-backend.so"))
 		return load_fbdev_backend(compositor, argc, argv, config);
+	else if (strstr(backend, "scfb-backend.so"))
+		return load_scfb_backend(compositor, argc, argv, config);
 	else if (strstr(backend, "drm-backend.so"))
 		return load_drm_backend(compositor, argc, argv, config);
 	else if (strstr(backend, "x11-backend.so"))
@@ -1823,9 +1892,9 @@ int main(int argc, char *argv[])
 	weston_log_set_handler(vlog, vlog_continue);
 	weston_log_file_open(log);
 
-	weston_log("%s\n"
-		   STAMP_SPACE "%s\n"
-		   STAMP_SPACE "Bug reports to: %s\n"
+	weston_log("%s\r\n"
+		   STAMP_SPACE "%s\r\n"
+		   STAMP_SPACE "Bug reports to: %s\r\n"
 		   STAMP_SPACE "Build: %s\n",
 		   PACKAGE_STRING, PACKAGE_URL, PACKAGE_BUGREPORT,
 		   BUILD_ID);
