--- libpkg/pkg_repo_meta.c.orig	2020-07-24 06:17:44 UTC
+++ libpkg/pkg_repo_meta.c
@@ -168,7 +168,7 @@ pkg_repo_meta_open_schema_v2()
 			"version = {type = integer};\n"
 			"maintainer = {type = string};\n"
 			"source = {type = string};\n"
-			"packing_format = {enum = [txz, tbz, tgz, tar]};\n"
+			"packing_format = {enum = [tzst, txz, tbz, tgz, tar]};\n"
 			"manifests = {type = string};\n"
 			"conflicts = {type = string};\n"
 			"fulldb = {type = string};\n"
