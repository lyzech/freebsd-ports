--- src/hardwareintegration/compositor/linux-dmabuf-unstable-v1/linuxdmabuf.h.orig	2019-10-15 04:21:15 UTC
+++ src/hardwareintegration/compositor/linux-dmabuf-unstable-v1/linuxdmabuf.h
@@ -53,6 +53,7 @@
 
 #include <EGL/egl.h>
 #include <EGL/eglext.h>
+#include <EGL/eglmesaext.h>
 
 // compatibility with libdrm <= 2.4.74
 #ifndef DRM_FORMAT_RESERVED
