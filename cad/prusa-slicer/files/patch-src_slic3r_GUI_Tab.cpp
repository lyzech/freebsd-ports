--- src/slic3r/GUI/Tab.cpp.orig	2019-11-09 15:12:49 UTC
+++ src/slic3r/GUI/Tab.cpp
@@ -2853,7 +2853,7 @@ void Tab::load_current_preset()
                     if (tab->supports_printer_technology(printer_technology))
                     {
                         wxGetApp().tab_panel()->InsertPage(wxGetApp().tab_panel()->FindPage(this), tab, tab->title());
-                        #ifdef __linux__ // the tabs apparently need to be explicitly shown on Linux (pull request #1563)
+                        #if defined(__linux__) || defined(__FreeBSD__) // the tabs apparently need to be explicitly shown on Linux (pull request #1563)
                             int page_id = wxGetApp().tab_panel()->FindPage(tab);
                             wxGetApp().tab_panel()->GetPage(page_id)->Show(true);
                         #endif // __linux__
@@ -3158,7 +3158,7 @@ void Tab::OnTreeSelChange(wxTreeEvent& event)
 // There is a bug related to Ubuntu overlay scrollbars, see https://github.com/prusa3d/PrusaSlicer/issues/898 and https://github.com/prusa3d/PrusaSlicer/issues/952.
 // The issue apparently manifests when Show()ing a window with overlay scrollbars while the UI is frozen. For this reason,
 // we will Thaw the UI prematurely on Linux. This means destroing the no_updates object prematurely.
-#ifdef __linux__
+#if defined __linux__ || defined __FreeBSD__
     std::unique_ptr<wxWindowUpdateLocker> no_updates(new wxWindowUpdateLocker(this));
 #else
 //	wxWindowUpdateLocker noUpdates(this);
@@ -3186,7 +3186,7 @@ void Tab::OnTreeSelChange(wxTreeEvent& event)
 //			break;
 //		}
 
-    #ifdef __linux__
+    #if defined __linux__ || defined __FreeBSD__
         no_updates.reset(nullptr);
     #endif
 
