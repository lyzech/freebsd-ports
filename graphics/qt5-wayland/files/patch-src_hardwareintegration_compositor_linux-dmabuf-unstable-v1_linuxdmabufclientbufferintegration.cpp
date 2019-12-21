--- src/hardwareintegration/compositor/linux-dmabuf-unstable-v1/linuxdmabufclientbufferintegration.cpp.orig	2019-10-15 04:21:15 UTC
+++ src/hardwareintegration/compositor/linux-dmabuf-unstable-v1/linuxdmabufclientbufferintegration.cpp
@@ -49,6 +49,7 @@
 
 #include <EGL/egl.h>
 #include <EGL/eglext.h>
+#include <EGL/eglmesaext.h>
 #include <unistd.h>
 #include <drm_fourcc.h>
 
