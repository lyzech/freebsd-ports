--- shared/xalloc.c.orig	2017-08-08 18:57:03 UTC
+++ shared/xalloc.c
@@ -32,6 +32,8 @@
 
 #include "xalloc.h"
 
+#define program_invocation_short_name getprogname()
+
 void *
 fail_on_null(void *p, size_t size, char *file, int32_t line)
 {
