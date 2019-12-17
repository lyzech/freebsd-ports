diff --git a/drivers/gpu/drm/drm_os_freebsd.c b/drivers/gpu/drm/drm_os_freebsd.c
index 1cc34c2da..2714ceabf 100644
--- a/drivers/gpu/drm/drm_os_freebsd.c
+++ b/drivers/gpu/drm/drm_os_freebsd.c
@@ -32,7 +32,7 @@ int drm_always_interruptible;
 SYSCTL_INT(_dev_drm, OID_AUTO, always_interruptible, CTLFLAG_RWTUN, &drm_always_interruptible, 0, "always allow a thread to be interrupted in driver wait");
 
 static atomic_t reset_debug_log_armed = ATOMIC_INIT(0);
-static struct callout_handle reset_debug_log_handle;
+static struct callout reset_debug_log_handle;
 
 static void
 clear_debug_func(void *arg __unused)
@@ -44,7 +44,7 @@ void
 cancel_reset_debug_log(void)
 {
 	if (atomic_read(&reset_debug_log_armed))
-		untimeout(clear_debug_func, NULL, reset_debug_log_handle);
+		callout_stop(&reset_debug_log_handle);
 }
 
 static void
@@ -54,8 +54,7 @@ reset_debug_log(void)
 		return;
 
 	if (atomic_add_unless(&reset_debug_log_armed, 1, 1)) {
-		reset_debug_log_handle = timeout(clear_debug_func, NULL,
-		    10*hz);
+		callout_reset(&reset_debug_log_handle, 10*hz, clear_debug_func, NULL);
 	}
 }
 
@@ -315,6 +314,7 @@ drm_modevent(module_t mod, int type, void *data)
 	switch (type) {
 	case MOD_LOAD:
 		TUNABLE_INT_FETCH("drm.debug", &drm_debug);
+		callout_init(&reset_debug_log_handle, 1);
 		break;
 	}
 	return (0);

