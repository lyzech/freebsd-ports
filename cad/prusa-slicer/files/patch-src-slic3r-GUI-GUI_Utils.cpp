--- src/slic3r/GUI/GUI_Utils.cpp.orig	2019-10-20 13:12:51.325192000 +0200
+++ src/slic3r/GUI/GUI_Utils.cpp	2019-10-20 13:11:48.848520000 +0200
@@ -106,7 +106,7 @@
         if (hdc == NULL) { return DPI_DEFAULT; }
         return GetDeviceCaps(hdc, LOGPIXELSX);
     }
-#elif defined __linux__
+#elif defined __linux__ || defined __FreeBSD__
     // TODO
     return DPI_DEFAULT;
 #elif defined __APPLE__
