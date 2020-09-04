--- freebsd/FreeBSDProcessList.c.orig	2018-04-10 13:42:59 UTC
+++ freebsd/FreeBSDProcessList.c
@@ -28,8 +28,9 @@ in the source distribution for its full text.
 #include <sys/resource.h>
 
 #define JAIL_ERRMSGLEN	1024
+*/
 char jail_errmsg[JAIL_ERRMSGLEN];
-
+/*
 typedef struct CPUData_ {
 
    double userPercent;
