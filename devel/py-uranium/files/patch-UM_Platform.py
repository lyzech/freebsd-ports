--- UM/Platform.py.orig	2019-11-20 14:52:40 UTC
+++ UM/Platform.py
@@ -35,7 +35,7 @@ class Platform:
     __platform_type = PlatformType.Other
     if sys.platform == "win32":
         __platform_type = PlatformType.Windows
-    elif sys.platform == "linux":
+    elif sys.platform == "linux" or sys.platform[:7] == "freebsd":
         __platform_type = PlatformType.Linux
     elif sys.platform == "darwin":
         __platform_type = PlatformType.OSX
