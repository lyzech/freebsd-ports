--- src/ThreeMFParser.h.orig	2019-09-17 09:34:47 UTC
+++ src/ThreeMFParser.h
@@ -21,7 +21,7 @@
 
 #include "SavitarExport.h"
 #include "SceneNode.h"
-#include "../pugixml/src/pugixml.hpp"
+#include <pugixml.hpp>
 
 #include <string>
 namespace Savitar
@@ -44,4 +44,4 @@ namespace Savitar
         std::string sceneToString(Scene scene);
     };
 }
-#endif
\ No newline at end of file
+#endif
