--- src/loudness.c.orig	2013-09-07 23:56:16 UTC
+++ src/loudness.c
@@ -59,7 +59,7 @@ bool init_audio( void )
 	
 	ask.freq = freq;
 	ask.format = (BYTES_PER_SAMPLE == 2) ? AUDIO_S16SYS : AUDIO_S8;
-	ask.channels = 1;
+	ask.channels = 2;
 	ask.samples = 2048;
 	ask.callback = audio_cb;
 	
@@ -74,7 +74,7 @@ bool init_audio( void )
 	
 	printf("\tobtained  %d Hz, %d channels, %d samples\n", got.freq, got.channels, got.samples);
 	
-	SDL_BuildAudioCVT(&audio_cvt, ask.format, ask.channels, ask.freq, got.format, got.channels, got.freq);
+	SDL_BuildAudioCVT(&audio_cvt, ask.format, 1, ask.freq, got.format, got.channels, got.freq);
 	
 	opl_init();
 	
