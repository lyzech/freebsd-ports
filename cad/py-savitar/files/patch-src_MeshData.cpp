--- src/MeshData.cpp.orig	2019-09-17 09:34:47 UTC
+++ src/MeshData.cpp
@@ -17,7 +17,7 @@
  */
 
 #include "MeshData.h"
-#include "../pugixml/src/pugixml.hpp"
+#include <pugixml.hpp>
 #include <cstring>
 #include <iostream>
 #include <stdexcept> //For std::runtime_error.
