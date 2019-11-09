--- src/avrdude/libavrdude.h.orig	2019-09-16 08:49:51 UTC
+++ src/avrdude/libavrdude.h
@@ -950,7 +950,7 @@ int read_config_builtin();
 // Header file for alloca()
 #if defined(WIN32NATIVE)
 #  include <malloc.h>
-#else
+#elif !defined(__FreeBSD__)
 #  include <alloca.h>
 #endif
 
