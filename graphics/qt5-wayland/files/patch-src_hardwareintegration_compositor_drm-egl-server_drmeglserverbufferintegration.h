--- src/hardwareintegration/compositor/drm-egl-server/drmeglserverbufferintegration.h.orig	2019-10-15 04:21:15 UTC
+++ src/hardwareintegration/compositor/drm-egl-server/drmeglserverbufferintegration.h
@@ -54,6 +54,7 @@
 #include <QtCore/QDebug>
 #include <EGL/egl.h>
 #include <EGL/eglext.h>
+#include <EGL/eglmesaext.h>
 
 #ifndef EGL_KHR_image
 typedef void *EGLImageKHR;
