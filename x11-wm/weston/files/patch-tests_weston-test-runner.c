--- tests/weston-test-runner.c.orig	2017-08-08 18:57:03 UTC
+++ tests/weston-test-runner.c
@@ -38,6 +38,8 @@
 
 #define SKIP 77
 
+#define program_invocation_short_name getprogname()
+
 char __attribute__((weak)) *server_parameters="";
 
 extern const struct weston_test __start_test_section, __stop_test_section;
