--- src/joystick/bsd/SDL_sysjoystick.c.orig	2018-10-27 10:57:44 UTC
+++ src/joystick/bsd/SDL_sysjoystick.c
@@ -65,7 +65,6 @@
 #if __FreeBSD_kernel_version > 800063
 #include <dev/usb/usb_ioctl.h>
 #endif
-#include <sys/joystick.h>
 #endif
 
 #if SDL_JOYSTICK_USBHID_MACHINE_JOYSTICK_H
@@ -482,7 +481,7 @@ SDL_SYS_JoystickUpdate(SDL_Joystick * joy)
     int nbutton, naxe = -1;
     Sint32 v;
 
-#if defined(__FREEBSD__) || SDL_JOYSTICK_USBHID_MACHINE_JOYSTICK_H || defined(__FreeBSD_kernel__)
+#if 0
     struct joystick gameport;
     static int x, y, xmin = 0xffff, ymin = 0xffff, xmax = 0, ymax = 0;
 
