--- chromecast/browser/metrics/cast_metrics_service_client.h.orig	2019-06-04 18:55:20 UTC
+++ chromecast/browser/metrics/cast_metrics_service_client.h
@@ -111,10 +111,10 @@ class CastMetricsServiceClient : public ::metrics::Met
   std::string force_client_id_;
   bool client_info_loaded_;
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   ExternalMetrics* external_metrics_;
   ExternalMetrics* platform_metrics_;
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
   const scoped_refptr<base::SingleThreadTaskRunner> task_runner_;
   std::unique_ptr<::metrics::MetricsStateManager> metrics_state_manager_;
   std::unique_ptr<::metrics::MetricsService> metrics_service_;
