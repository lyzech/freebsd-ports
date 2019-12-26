--- src/slic3r/GUI/Preset.hpp.orig	2019-12-24 08:44:58 UTC
+++ src/slic3r/GUI/Preset.hpp
@@ -448,13 +448,13 @@ class PresetCollection (public)
 
     void            clear_bitmap_cache();
 
-#ifdef __linux__
+#ifdef __WXGTK__
 	static const char* separator_head() { return "------- "; }
 	static const char* separator_tail() { return " -------"; }
-#else /* __linux__ */
+#else /* __WXGTK__ */
     static const char* separator_head() { return "————— "; }
     static const char* separator_tail() { return " —————"; }
-#endif /* __linux__ */
+#endif /* __WXGTK__ */
 	static wxString    separator(const std::string &label);
 
 protected:
