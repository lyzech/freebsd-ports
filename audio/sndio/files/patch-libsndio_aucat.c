--- libsndio/aucat.c.orig	2018-01-11 20:57:37 UTC
+++ libsndio/aucat.c
@@ -247,7 +247,7 @@ aucat_mkcookie(unsigned char *cookie)
 #define COOKIE_SUFFIX	"/.aucat_cookie"
 #define TEMPL_SUFFIX	".XXXXXXXX"
 	struct stat sb;
-	char *home, *path = NULL, *tmp = NULL;
+	char *home = NULL, *path = NULL, *tmp = NULL;
 	size_t home_len, path_len;
 	int fd, len;
 
@@ -257,6 +257,11 @@ aucat_mkcookie(unsigned char *cookie)
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
@@ -267,6 +272,7 @@ aucat_mkcookie(unsigned char *cookie)
 	memcpy(path, home, home_len);
 	memcpy(path + home_len, COOKIE_SUFFIX, sizeof(COOKIE_SUFFIX));
 	path_len = home_len + sizeof(COOKIE_SUFFIX) - 1;
+open_cookie:
 	fd = open(path, O_RDONLY);
 	if (fd < 0) {
 		if (errno != ENOENT)
