#pragma once

#include "userspace_types.hpp"

class notification_center final {
public:
  static void post_distributed_notification(CFStringRef name) {
    CFNotificationCenterPostNotification(CFNotificationCenterGetDistributedCenter(),
                                         name,
                                         krbn_distributed_notification_observed_object,
                                         nullptr,
                                         true);
  }

  static void post_distributed_notification_to_all_sessions(CFStringRef name) {
    CFNotificationCenterPostNotificationWithOptions(CFNotificationCenterGetDistributedCenter(),
                                                    name,
                                                    krbn_distributed_notification_observed_object,
                                                    nullptr,
                                                    kCFNotificationDeliverImmediately | kCFNotificationPostToAllSessions);
  }

  static void observe_distributed_notification(const void* observer, CFNotificationCallback callback, CFStringRef name) {
    CFNotificationCenterAddObserver(CFNotificationCenterGetDistributedCenter(),
                                    observer,
                                    callback,
                                    name,
                                    krbn_distributed_notification_observed_object,
                                    CFNotificationSuspensionBehaviorDeliverImmediately);
  }
};
