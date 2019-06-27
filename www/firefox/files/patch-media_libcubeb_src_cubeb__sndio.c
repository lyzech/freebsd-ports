--- media/libcubeb/src/cubeb_sndio.c.orig	2019-06-27 04:33:39 UTC
+++ media/libcubeb/src/cubeb_sndio.c
@@ -323,7 +323,12 @@ sndio_stream_init(cubeb * context,
     goto err;
   }
   s->context = context;
-  s->hdl = sio_open(NULL, s->mode, 1);
+  const char *dev = NULL;
+  if (s->mode == SIO_PLAY)
+    dev = getenv("PLAY_AUDIODEVICE");
+  else if (s->mode == SIO_REC)
+    dev = getenv("REC_AUDIODEVICE");
+  s->hdl = sio_open(dev, s->mode, 1);
   if (s->hdl == NULL) {
     DPR("sndio_stream_init(), sio_open() failed\n");
     goto err;
