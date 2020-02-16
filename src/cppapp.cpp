#include <cpplib.h>
#include <iostream>
#include <memory>

namespace {
class AppHandler : public cpplib::Handler {
  void handle_string(std::string_view value) override {
    std::cout << "AppHandler: string - " << value << std::endl;
  }
  void handle_int(int value) override {
    std::cout << "AppHandler: int - " << value << std::endl;
  }
};
}  // namespace

int main() {
  std::shared_ptr<cpplib::Handler> handler = std::make_shared<AppHandler>();
  cpplib::Handler::register_global_handler(handler);
  cpplib::Handler::global_handler()->handle_string("hello");
  cpplib::Handler::global_handler()->handle_int(5);
}