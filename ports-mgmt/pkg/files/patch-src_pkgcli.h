--- src/pkgcli.h.orig	2020-06-29 07:57:00 UTC
+++ src/pkgcli.h
@@ -37,12 +37,9 @@
 
 extern bool quiet;
 extern int nbactions;
-int nbactions;
 extern int nbdone;
-int nbdone;
 extern bool newpkgversion;
 extern int nbtodl;
-int nbtodl;
 
 /* pkg add */
 int exec_add(int, char **);
