--- src/hardwareintegration/client/libhybris-egl-server/libhybriseglserverbufferintegration.h.orig	2019-10-15 04:21:15 UTC
+++ src/hardwareintegration/client/libhybris-egl-server/libhybriseglserverbufferintegration.h
@@ -49,6 +49,7 @@
 
 #include <EGL/egl.h>
 #include <EGL/eglext.h>
+#include <EGL/eglmesaext.h>
 #ifndef EGL_KHR_image
 typedef void *EGLImageKHR;
 typedef EGLImageKHR (EGLAPIENTRYP PFNEGLCREATEIMAGEKHRPROC) (EGLDisplay dpy, EGLContext ctx, EGLenum target, EGLClientBuffer buffer, const EGLint *attrib_list);
