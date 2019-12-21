--- src/libslic3r/GCode/WipeTower.cpp.orig	2019-11-09 15:25:01 UTC
+++ src/libslic3r/GCode/WipeTower.cpp
@@ -24,7 +24,7 @@ TODO LIST
 #include "Analyzer.hpp"
 #include "BoundingBox.hpp"
 
-#if defined(__linux) || defined(__GNUC__ )
+#if defined(__linux) || defined(__FreeBSD__) || defined(__GNUC__ )
 #include <strings.h>
 #endif /* __linux */
 
