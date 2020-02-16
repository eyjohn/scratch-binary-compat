#include <memory>
#include <string>

extern "C" {
#include <clib.h>
}
namespace cpplib {

class Handler {
 public:
  virtual ~Handler() = default;
  virtual void handle_string(std::string_view) = 0;
  virtual void handle_int(int) = 0;

  static void register_global_handler(std::shared_ptr<Handler> handler);
  static std::shared_ptr<Handler> global_handler();
};

namespace detail {

class GlobalHandler : public Handler {
 public:
  void handle_string(std::string_view) override;
  void handle_int(int) override;
};

namespace {
std::shared_ptr<Handler> global_handler_singleton;
std::shared_ptr<Handler> custom_handler_singleton;
inline void string_callback(const char* val) {
  custom_handler_singleton->handle_string(val);
}
inline void int_callback(int val) { custom_handler_singleton->handle_int(val); }
}  // namespace

}  // namespace detail

inline void Handler::register_global_handler(std::shared_ptr<Handler> handler) {
  detail::global_handler_singleton = std::make_shared<detail::GlobalHandler>();
  detail::custom_handler_singleton = handler;
  set_callbacks(detail::string_callback, detail::int_callback);
}

inline std::shared_ptr<Handler> Handler::global_handler() {
  return detail::global_handler_singleton;
}

inline void detail::GlobalHandler::handle_string(std::string_view value) {
  call_string_callback(value.data());
}
inline void detail::GlobalHandler::handle_int(int value) {
  call_int_callback(value);
}

}  // namespace cpplib