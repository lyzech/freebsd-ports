--- tools/zunitc/src/zunitc_impl.c.orig	2017-08-08 18:57:03 UTC
+++ tools/zunitc/src/zunitc_impl.c
@@ -36,6 +36,7 @@
 #include <sys/wait.h>
 #include <time.h>
 #include <unistd.h>
+#include <signal.h>
 
 #include "zunitc/zunitc_impl.h"
 #include "zunitc/zunitc.h"
