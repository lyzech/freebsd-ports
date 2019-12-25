--- src/slic3r/GUI/Mouse3DController.cpp.orig	2019-12-24 08:44:58 UTC
+++ src/slic3r/GUI/Mouse3DController.cpp
@@ -524,7 +524,7 @@ bool Mouse3DController::connect_device()
     {
         if (device.second.size() == 1)
         {
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
             hid_device* test_device = hid_open(device.first.first, device.first.second, nullptr);
             if (test_device != nullptr)
             {
@@ -549,7 +549,7 @@ bool Mouse3DController::connect_device()
 #if ENABLE_3DCONNEXION_DEVICES_DEBUG_OUTPUT
                 std::cout << "Test device: " << std::hex << device.first.first << std::dec << "/" << std::hex << device.first.second << std::dec << " \"" << data.path << "\"";
 #endif // ENABLE_3DCONNEXION_DEVICES_DEBUG_OUTPUT
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
                 hid_device* test_device = hid_open_path(data.path.c_str());
                 if (test_device != nullptr)
                 {
