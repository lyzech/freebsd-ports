This patch adds support for the D-pad found on the XBox 360 Controller.

--- src/joystick/bsd/SDL_sysjoystick.c.orig	2014-03-16 02:31:41 UTC
+++ src/joystick/bsd/SDL_sysjoystick.c
@@ -390,11 +390,23 @@ SDL_SYS_JoystickOpen(SDL_Joystick * joy,
             case HUP_GENERIC_DESKTOP:
                 {
                     unsigned usage = HID_USAGE(hitem.usage);
-                    int joyaxe = usage_to_joyaxe(usage);
-                    if (joyaxe >= 0) {
-                        hw->axis_map[joyaxe] = 1;
-                    } else if (usage == HUG_HAT_SWITCH) {
-                        joy->nhats++;
+                    switch(usage) {
+                    case 0x90: // D-pad_Up
+                    case 0x91: // D-pad_Down
+                    case 0x92: // D-pad_Left
+                    case 0x93: // D-pad_Right
+                        joy->nbuttons++;
+                        break;
+                    default:
+                        {
+                            int joyaxe = usage_to_joyaxe(usage);
+                            if (usage == HUG_POINTER) {
+                            } else if (joyaxe >= 0) {
+                                hw->axis_map[joyaxe] = 1;
+                            } else if (usage == HUG_HAT_SWITCH) {
+                                joy->nhats++;
+                            }
+                        }
                     }
                     break;
                 }
@@ -512,24 +524,39 @@ SDL_SYS_JoystickUpdate(SDL_Joystick * jo
                 case HUP_GENERIC_DESKTOP:
                     {
                         unsigned usage = HID_USAGE(hitem.usage);
-                        int joyaxe = usage_to_joyaxe(usage);
-                        if (joyaxe >= 0) {
-                            naxe = joy->hwdata->axis_map[joyaxe];
-                            /* scaleaxe */
+                        switch(usage) {
+                        case 0x90: // D-pad_Up
+                        case 0x91: // D-pad_Down
+                        case 0x92: // D-pad_Left
+                        case 0x93: // D-pad_Right
                             v = (Sint32) hid_get_data(REP_BUF_DATA(rep), &hitem);
-                            v -= (hitem.logical_maximum +
-                                  hitem.logical_minimum + 1) / 2;
-                            v *= 32768 /
-                                ((hitem.logical_maximum -
-                                  hitem.logical_minimum + 1) / 2);
-                            if (v != joy->axes[naxe]) {
-                                SDL_PrivateJoystickAxis(joy, naxe, v);
+                            if (joy->buttons[nbutton] != v) {
+                                SDL_PrivateJoystickButton(joy, nbutton, v);
+                            }
+                            nbutton++;
+                            break;
+                        default:
+                            {
+                                int joyaxe = usage_to_joyaxe(usage);
+                                if (joyaxe >= 0) {
+                                    naxe = joy->hwdata->axis_map[joyaxe];
+                                    /* scaleaxe */
+                                    v = (Sint32) hid_get_data(REP_BUF_DATA(rep), &hitem);
+                                    v -= (hitem.logical_maximum +
+                                          hitem.logical_minimum + 1) / 2;
+                                    v *= 32768 /
+                                        ((hitem.logical_maximum -
+                                          hitem.logical_minimum + 1) / 2);
+                                    if (v != joy->axes[naxe]) {
+                                        SDL_PrivateJoystickAxis(joy, naxe, v);
+                                    }
+                                } else if (usage == HUG_HAT_SWITCH) {
+                                    v = (Sint32) hid_get_data(REP_BUF_DATA(rep), &hitem);
+                                    SDL_PrivateJoystickHat(joy, 0,
+                                                           hatval_to_sdl(v) -
+                                                           hitem.logical_minimum);
+                                }
                             }
-                        } else if (usage == HUG_HAT_SWITCH) {
-                            v = (Sint32) hid_get_data(REP_BUF_DATA(rep), &hitem);
-                            SDL_PrivateJoystickHat(joy, 0,
-                                                   hatval_to_sdl(v) -
-                                                   hitem.logical_minimum);
                         }
                         break;
                     }
