--- libsndio/aucat.c.orig	2020-06-28 05:52:52 UTC
+++ libsndio/aucat.c
@@ -248,7 +248,7 @@ aucat_mkcookie(unsigned char *cookie)
 #define COOKIE_SUFFIX	"/.sndio/cookie"
 #define TEMPL_SUFFIX	".XXXXXXXX"
 	struct stat sb;
-	char *home, *path = NULL, *tmp = NULL;
+	char *home = NULL, *path = NULL, *tmp = NULL;
 	size_t home_len, path_len;
 	int fd, len;
 
@@ -258,6 +258,11 @@ aucat_mkcookie(unsigned char *cookie)
 	/*
 	 * try to load the cookie
 	 */
+	path = getenv("AUCAT_COOKIE_PATH");
+	if (path != NULL) {
+		path = strdup(path);
+		goto open_cookie;
+	}
 	home = issetugid() ? NULL : getenv("HOME");
 	if (home == NULL)
 		goto bad_gen;
@@ -268,6 +273,7 @@ aucat_mkcookie(unsigned char *cookie)
 	memcpy(path, home, home_len);
 	memcpy(path + home_len, COOKIE_SUFFIX, sizeof(COOKIE_SUFFIX));
 	path_len = home_len + sizeof(COOKIE_SUFFIX) - 1;
+open_cookie:
 	fd = open(path, O_RDONLY);
 	if (fd == -1) {
 		if (errno != ENOENT)
