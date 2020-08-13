--- src/globals.c.orig	2020-06-29 07:57:00 UTC
+++ src/globals.c
@@ -31,6 +31,9 @@ int case_sensitive; /* Case sensitive queries */
 int force; /* Forced operation */
 int quiet; /* Silent output */
 int newpkgversion; /* New package version is available */
+int nbactions;
+int nbdone;
+int nbtodl;
 
 void
 set_globals(void)
@@ -43,5 +46,8 @@ set_globals(void)
 	force = 0;
 	quiet = 0;
 	newpkgversion = 0;
+	nbactions = 0;
+	nbdone = 0;
+	nbtodl = 0;
 }
 
