--- src/hardwareintegration/compositor/brcm-egl/brcmbuffer.cpp.orig	2019-10-15 04:21:15 UTC
+++ src/hardwareintegration/compositor/brcm-egl/brcmbuffer.cpp
@@ -40,6 +40,7 @@
 #include "brcmbuffer.h"
 
 #include <EGL/eglext.h>
+#include <EGL/eglmesaext.h>
 
 #include <EGL/eglext_brcm.h>
 
