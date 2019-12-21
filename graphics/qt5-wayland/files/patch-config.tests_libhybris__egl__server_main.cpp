--- config.tests/libhybris_egl_server/main.cpp.orig	2019-10-15 04:21:15 UTC
+++ config.tests/libhybris_egl_server/main.cpp
@@ -50,6 +50,7 @@
 
 #include <EGL/egl.h>
 #include <EGL/eglext.h>
+#include <EGL/eglmesaext.h>
 #include <hybris/eglplatformcommon/hybris_nativebufferext.h>
 
 int main()
