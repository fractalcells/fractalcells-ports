--- ui/gfx/font_fallback_linux.cc.orig	2019-06-04 18:55:50 UTC
+++ ui/gfx/font_fallback_linux.cc
@@ -16,6 +16,10 @@
 #include "base/trace_event/trace_event.h"
 #include "ui/gfx/font.h"
 
+#if defined(OS_BSD)
+#include <unistd.h>
+#endif
+
 namespace gfx {
 
 namespace {
