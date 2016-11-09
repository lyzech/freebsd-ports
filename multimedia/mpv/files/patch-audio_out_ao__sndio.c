--- audio/out/ao_sndio.c.orig	2016-10-19 21:10:13 UTC
+++ audio/out/ao_sndio.c
@@ -224,17 +224,7 @@ static void reset(struct ao *ao)
 {
     struct priv *p = ao->priv;
 
-    if (p->playing) {
-        MP_WARN(ao, "Blocking until remaining audio is played... (sndio design bug).\n");
-
-        p->playing = false;
-
-        if (!sio_stop(p->hdl))
-            MP_ERR(ao, "reset: couldn't stop\n");
-        p->delay = 0;
-        if (!sio_start(p->hdl))
-            MP_ERR(ao, "reset: couldn't start\n");
-    }
+    p->playing = false;
 }
 
 /*
