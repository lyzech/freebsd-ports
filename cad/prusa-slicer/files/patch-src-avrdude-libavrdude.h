--- src/avrdude/libavrdude.h.orig	2019-10-20 11:27:31.526559000 +0200
+++ src/avrdude/libavrdude.h	2019-10-20 11:30:31.340704000 +0200
@@ -950,7 +950,7 @@
 // Header file for alloca()
 #if defined(WIN32NATIVE)
 #  include <malloc.h>
-#else
+#elif !defined(__FreeBSD__)
 #  include <alloca.h>
 #endif
 
