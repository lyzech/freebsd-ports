--- src/slic3r/Utils/Serial.cpp.orig	2019-11-09 15:17:44 UTC
+++ src/slic3r/Utils/Serial.cpp
@@ -47,7 +47,7 @@
 	#include <sys/select.h>
 #endif
 
-#if defined(__APPLE__) || defined(__OpenBSD__)
+#if defined(__APPLE__) || defined(__OpenBSD__) || defined(__FreeBSD__)
 	#include <termios.h>
 #elif defined __linux__
 	#include <fcntl.h>
