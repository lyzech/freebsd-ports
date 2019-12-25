--- src/slic3r/GUI/GUI_Preview.cpp.orig	2019-11-09 15:20:08 UTC
+++ src/slic3r/GUI/GUI_Preview.cpp
@@ -185,7 +185,7 @@ Preview::Preview(
     , m_loaded(false)
     , m_enabled(false)
     , m_schedule_background_process(schedule_background_process_func)
-#ifdef __linux__
+#if defined __linux__ || defined __FreeBSD__
     , m_volumes_cleanup_required(false)
 #endif // __linux__
 {
@@ -378,7 +378,7 @@ void Preview::load_print(bool keep_z_range)
 
 void Preview::reload_print(bool keep_volumes)
 {
-#ifdef __linux__
+#if defined __linux__ || defined __FreeBSD__
     // We are getting mysterious crashes on Linux in gtk due to OpenGL context activation GH #1874 #1955.
     // So we are applying a workaround here: a delayed release of OpenGL vertex buffers.
     if (!IsShown())
@@ -388,7 +388,7 @@ void Preview::reload_print(bool keep_volumes)
     }
 #endif /* __linux __ */
     if (
-#ifdef __linux__
+#if defined __linux__ || defined __FreeBSD__
         m_volumes_cleanup_required || 
 #endif /* __linux__ */
         !keep_volumes)
@@ -396,7 +396,7 @@ void Preview::reload_print(bool keep_volumes)
         m_canvas->reset_volumes();
         m_canvas->reset_legend_texture();
         m_loaded = false;
-#ifdef __linux__
+#if defined __linux__ || defined __FreeBSD__
         m_volumes_cleanup_required = false;
 #endif /* __linux__ */
     }
