--- src/slic3r/GUI/GUI_Preview.hpp.orig	2019-11-09 15:19:11 UTC
+++ src/slic3r/GUI/GUI_Preview.hpp
@@ -86,7 +86,7 @@ class Preview : public wxPanel
     BackgroundSlicingProcess* m_process;
     GCodePreviewData* m_gcode_preview_data;
 
-#ifdef __linux__
+#if defined __linux__ || defined __FreeBSD__
     // We are getting mysterious crashes on Linux in gtk due to OpenGL context activation GH #1874 #1955.
     // So we are applying a workaround here.
     bool m_volumes_cleanup_required;
