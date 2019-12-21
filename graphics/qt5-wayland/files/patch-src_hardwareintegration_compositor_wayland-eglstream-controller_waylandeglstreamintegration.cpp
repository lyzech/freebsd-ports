--- src/hardwareintegration/compositor/wayland-eglstream-controller/waylandeglstreamintegration.cpp.orig	2019-10-15 04:21:15 UTC
+++ src/hardwareintegration/compositor/wayland-eglstream-controller/waylandeglstreamintegration.cpp
@@ -54,6 +54,7 @@
 
 #include <EGL/egl.h>
 #include <EGL/eglext.h>
+#include <EGL/eglmesaext.h>
 #include <unistd.h>
 
 #ifndef GL_TEXTURE_EXTERNAL_OES
