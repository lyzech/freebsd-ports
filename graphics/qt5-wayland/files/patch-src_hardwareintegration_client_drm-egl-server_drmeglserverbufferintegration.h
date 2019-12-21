--- src/hardwareintegration/client/drm-egl-server/drmeglserverbufferintegration.h.orig	2019-10-15 04:21:15 UTC
+++ src/hardwareintegration/client/drm-egl-server/drmeglserverbufferintegration.h
@@ -50,6 +50,7 @@
 
 #include <EGL/egl.h>
 #include <EGL/eglext.h>
+#include <EGL/eglmesaext.h>
 #ifndef EGL_KHR_image
 typedef void *EGLImageKHR;
 typedef EGLImageKHR (EGLAPIENTRYP PFNEGLCREATEIMAGEKHRPROC) (EGLDisplay dpy, EGLContext ctx, EGLenum target, EGLClientBuffer buffer, const EGLint *attrib_list);
