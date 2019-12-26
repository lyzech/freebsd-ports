--- src/slic3r/GUI/GLCanvas3D.cpp.orig	2019-12-24 08:44:58 UTC
+++ src/slic3r/GUI/GLCanvas3D.cpp
@@ -3066,7 +3066,7 @@ void GLCanvas3D::on_mouse(wxMouseEvent& evt)
 
     if (evt.Entering())
     {
-//#if defined(__WXMSW__) || defined(__linux__)
+//#if defined(__WXMSW__) || defined(__WXGTK__)
 //        // On Windows and Linux needs focus in order to catch key events
         // Set focus in order to remove it from sidebar fields
         if (m_canvas != nullptr) {
