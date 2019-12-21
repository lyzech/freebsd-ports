--- src/slic3r/GUI/Plater.cpp.orig	2019-11-09 15:16:17 UTC
+++ src/slic3r/GUI/Plater.cpp
@@ -3421,7 +3421,7 @@ void Plater::priv::on_right_click(Vec2dEvent& evt)
     }
 
     if (q != nullptr) {
-#ifdef __linux__
+#if defined __linux__ || defined __FreeBSD__
         // For some reason on Linux the menu isn't displayed if position is specified
         // (even though the position is sane).
         q->PopupMenu(menu);
@@ -4762,7 +4762,7 @@ void Plater::on_config_change(const DynamicPrintConfig
 
 void Plater::on_activate()
 {
-#ifdef __linux__
+#if defined __linux__ || defined __FreeBSD__
     wxWindow *focus_window = wxWindow::FindFocus();
     // Activating the main frame, and no window has keyboard focus.
     // Set the keyboard focus to the visible Canvas3D.
