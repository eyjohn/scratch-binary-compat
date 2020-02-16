#include <clib.h>
#include <stdio.h>

void handle_string(const char* value) { printf("Got String: %s\n", value); }
void handle_int(int value) { printf("Got String: %d\n", value); }

int main() {
  set_callbacks(handle_string, handle_int);
  call_string_callback("hello");
  call_int_callback(5);
  return 0;
}