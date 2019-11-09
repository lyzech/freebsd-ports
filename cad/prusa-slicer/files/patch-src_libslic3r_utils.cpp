--- src/libslic3r/utils.cpp.orig	2019-11-09 15:26:13 UTC
+++ src/libslic3r/utils.cpp
@@ -39,7 +39,7 @@
 
 #include <tbb/task_scheduler_init.h>
 
-#if defined(__linux) || defined(__GNUC__ )
+#if defined(__linux) || defined(__FreeBSD__) || defined(__GNUC__ )
 #include <strings.h>
 #endif /* __linux */
 
