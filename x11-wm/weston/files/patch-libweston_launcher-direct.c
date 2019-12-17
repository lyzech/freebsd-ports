--- libweston/launcher-direct.c.orig	2017-08-08 18:57:03 UTC
+++ libweston/launcher-direct.c
@@ -33,19 +33,27 @@
 #include <unistd.h>
 #include <signal.h>
 #include <sys/stat.h>
-#include <sys/sysmacros.h>
+/* #include <sys/sysmacros.h> */
 #include <sys/ioctl.h>
-#include <linux/vt.h>
-#include <linux/kd.h>
-#include <linux/major.h>
+/* #include <linux/vt.h> */
+/* #include <linux/kd.h> */
+/* #include <linux/major.h> */
+/* #define TTY_BASENAME    "/dev/tty" */
+/* #define TTY_0           "/dev/tty0" */
 
+#include <termios.h>
+#include <sys/consio.h>
+#include <sys/kbio.h>
+#define TTY_BASENAME    "/dev/ttyv"
+#define TTY_0           "/dev/ttyv0"
+
 #include "launcher-impl.h"
 
-#define DRM_MAJOR 226
+/* #define DRM_MAJOR 226 */
 
-#ifndef KDSKBMUTE
-#define KDSKBMUTE	0x4B51
-#endif
+/* #ifndef KDSKBMUTE */
+/* #define KDSKBMUTE	0x4B51 */
+/* #endif */
 
 #ifdef BUILD_DRM_COMPOSITOR
 
@@ -117,7 +125,7 @@ setup_tty(struct launcher_direct *launcher, int tty)
 	struct vt_mode mode = { 0 };
 	struct stat buf;
 	char tty_device[32] ="<stdin>";
-	int ret, kd_mode;
+	int ret, kd_mode, vt;
 
 	if (tty == 0) {
 		launcher->tty = dup(tty);
@@ -126,7 +134,7 @@ setup_tty(struct launcher_direct *launcher, int tty)
 			return -1;
 		}
 	} else {
-		snprintf(tty_device, sizeof tty_device, "/dev/tty%d", tty);
+		snprintf(tty_device, sizeof tty_device, "%s%d", TTY_BASENAME, tty);
 		launcher->tty = open(tty_device, O_RDWR | O_CLOEXEC);
 		if (launcher->tty == -1) {
 			weston_log("couldn't open tty %s: %m\n", tty_device);
@@ -134,14 +142,20 @@ setup_tty(struct launcher_direct *launcher, int tty)
 		}
 	}
 
-	if (fstat(launcher->tty, &buf) == -1 ||
-	    major(buf.st_rdev) != TTY_MAJOR || minor(buf.st_rdev) == 0) {
-		weston_log("%s not a vt\n", tty_device);
-		weston_log("if running weston from ssh, "
-			   "use --tty to specify a tty\n");
-		goto err_close;
+	ret = ioctl(launcher->tty, VT_GETINDEX, &vt);
+	if (ret) {
+		weston_log("failed to get VT index: %m\n");
+		return -1;
 	}
 
+	/* if (fstat(launcher->tty, &buf) == -1 || */
+	/*     major(buf.st_rdev) != TTY_MAJOR || minor(buf.st_rdev) == 0) { */
+	/* 	weston_log("%s not a vt\n", tty_device); */
+	/* 	weston_log("if running weston from ssh, " */
+	/* 		   "use --tty to specify a tty\n"); */
+	/* 	goto err_close; */
+	/* } */
+
 	ret = ioctl(launcher->tty, KDGETMODE, &kd_mode);
 	if (ret) {
 		weston_log("failed to get VT mode: %m\n");
@@ -153,20 +167,31 @@ setup_tty(struct launcher_direct *launcher, int tty)
 		goto err_close;
 	}
 
-	ioctl(launcher->tty, VT_ACTIVATE, minor(buf.st_rdev));
-	ioctl(launcher->tty, VT_WAITACTIVE, minor(buf.st_rdev));
+	ioctl(launcher->tty, VT_ACTIVATE, vt);
+	ioctl(launcher->tty, VT_WAITACTIVE, vt);
 
 	if (ioctl(launcher->tty, KDGKBMODE, &launcher->kb_mode)) {
 		weston_log("failed to read keyboard mode: %m\n");
 		goto err_close;
 	}
 
-	if (ioctl(launcher->tty, KDSKBMUTE, 1) &&
-	    ioctl(launcher->tty, KDSKBMODE, K_OFF)) {
-		weston_log("failed to set K_OFF keyboard mode: %m\n");
+	if (ioctl(launcher->tty, KDSKBMODE, K_RAW) == -1) {
+		weston_log("Could not set keyboard mode to K_RAW");
 		goto err_close;
 	}
 
+	/* Put the tty into raw mode */
+	struct termios tios;
+	if (tcgetattr(launcher->tty, &tios)) {
+		weston_log("Failed to get terminal attribute");
+		goto err_close;
+	}
+	cfmakeraw(&tios);
+	if (tcsetattr(launcher->tty, TCSAFLUSH, &tios)) {
+		weston_log("Failed to set terminal attribute");
+		goto err_close;
+	}
+
 	ret = ioctl(launcher->tty, KDSETMODE, KD_GRAPHICS);
 	if (ret) {
 		weston_log("failed to set KD_GRAPHICS mode on tty: %m\n");
@@ -184,10 +209,10 @@ setup_tty(struct launcher_direct *launcher, int tty)
 		ret = -EINVAL;
 		goto err_close;
 	}
-
 	mode.mode = VT_PROCESS;
-	mode.relsig = SIGRTMIN;
+	mode.relsig = SIGRTMAX;
 	mode.acqsig = SIGRTMIN;
+	mode.frsig = SIGIO; /* not used, but has to be set anyway */
 	if (ioctl(launcher->tty, VT_SETMODE, &mode) < 0) {
 		weston_log("failed to take control of vt handling\n");
 		goto err_close;
@@ -222,13 +247,11 @@ launcher_direct_open(struct weston_launcher *launcher_
 		return -1;
 	}
 
-	if (major(s.st_rdev) == DRM_MAJOR) {
-		launcher->drm_fd = fd;
-		if (!is_drm_master(fd)) {
-			weston_log("drm fd not master\n");
-			close(fd);
-			return -1;
-		}
+	launcher->drm_fd = fd;
+	if (!is_drm_master(fd)) {
+		weston_log("drm fd not master\n");
+		close(fd);
+		return -1;
 	}
 
 	return fd;
@@ -246,13 +269,22 @@ launcher_direct_restore(struct weston_launcher *launch
 	struct launcher_direct *launcher = wl_container_of(launcher_base, launcher, base);
 	struct vt_mode mode = { 0 };
 
-	if (ioctl(launcher->tty, KDSKBMUTE, 0) &&
-	    ioctl(launcher->tty, KDSKBMODE, launcher->kb_mode))
+	if (ioctl(launcher->tty, KDSKBMODE, launcher->kb_mode))
 		weston_log("failed to restore kb mode: %m\n");
 
 	if (ioctl(launcher->tty, KDSETMODE, KD_TEXT))
 		weston_log("failed to set KD_TEXT mode on tty: %m\n");
 
+	/* Restore sane mode */
+	struct termios tios;
+	if (tcgetattr(launcher->tty, &tios)) {
+		weston_log("Failed to get terminal attribute");
+	} else {
+		cfmakesane(&tios);
+		if (tcsetattr(launcher->tty, TCSAFLUSH, &tios)) {
+			weston_log("Failed to set terminal attribute");
+		}
+	}
 	/* We have to drop master before we switch the VT back in
 	 * VT_AUTO, so we don't risk switching to a VT with another
 	 * display server, that will then fail to set drm master. */
