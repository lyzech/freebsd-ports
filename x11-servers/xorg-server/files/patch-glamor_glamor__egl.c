--- glamor/glamor_egl.c.orig	2019-05-30 18:27:34 UTC
+++ glamor/glamor_egl.c
@@ -355,8 +355,8 @@ glamor_make_pixmap_exportable(PixmapPtr pixmap, Bool m
     return TRUE;
 }
 
-struct gbm_bo *
-glamor_gbm_bo_from_pixmap(ScreenPtr screen, PixmapPtr pixmap)
+static struct gbm_bo *
+glamor_gbm_bo_from_pixmap_internal(ScreenPtr screen, PixmapPtr pixmap)
 {
     struct glamor_egl_screen_private *glamor_egl =
         glamor_egl_get_screen_private(xf86ScreenToScrn(screen));
@@ -370,6 +370,15 @@ glamor_gbm_bo_from_pixmap(ScreenPtr screen, PixmapPtr 
                          pixmap_priv->image, 0);
 }
 
+struct gbm_bo *
+glamor_gbm_bo_from_pixmap(ScreenPtr screen, PixmapPtr pixmap)
+{
+    if (!glamor_make_pixmap_exportable(pixmap, TRUE))
+        return NULL;
+
+    return glamor_gbm_bo_from_pixmap_internal(screen, pixmap);
+}
+
 int
 glamor_egl_fds_from_pixmap(ScreenPtr screen, PixmapPtr pixmap, int *fds,
                            uint32_t *strides, uint32_t *offsets,
@@ -385,7 +394,7 @@ glamor_egl_fds_from_pixmap(ScreenPtr screen, PixmapPtr
     if (!glamor_make_pixmap_exportable(pixmap, TRUE))
         return 0;
 
-    bo = glamor_gbm_bo_from_pixmap(screen, pixmap);
+    bo = glamor_gbm_bo_from_pixmap_internal(screen, pixmap);
     if (!bo)
         return 0;
 
@@ -423,7 +432,7 @@ glamor_egl_fd_from_pixmap(ScreenPtr screen, PixmapPtr 
     if (!glamor_make_pixmap_exportable(pixmap, FALSE))
         return -1;
 
-    bo = glamor_gbm_bo_from_pixmap(screen, pixmap);
+    bo = glamor_gbm_bo_from_pixmap_internal(screen, pixmap);
     if (!bo)
         return -1;
 
@@ -452,7 +461,7 @@ glamor_egl_fd_name_from_pixmap(ScreenPtr screen,
     if (!glamor_make_pixmap_exportable(pixmap, FALSE))
         goto failure;
 
-    bo = glamor_gbm_bo_from_pixmap(screen, pixmap);
+    bo = glamor_gbm_bo_from_pixmap_internal(screen, pixmap);
     if (!bo)
         goto failure;
 
