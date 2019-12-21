--- config.tests/dmabuf_server_buffer/main.cpp.orig	2019-10-15 04:21:15 UTC
+++ config.tests/dmabuf_server_buffer/main.cpp
@@ -50,6 +50,7 @@
 
 #include <EGL/egl.h>
 #include <EGL/eglext.h>
+#include <EGL/eglmesaext.h>
 #include <drm_fourcc.h>
 
 int main()
