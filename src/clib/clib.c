#include "clib.h"
#include <stddef.h>

static bool callbacks_set = false;
static STRING_CALLBACK string_callback = NULL;
static INT_CALLBACK int_callback = NULL;

void set_callbacks(STRING_CALLBACK cb1, INT_CALLBACK cb2) {
  string_callback = cb1;
  int_callback = cb2;
  callbacks_set = true;
}

bool are_callbacks_set() { return callbacks_set; }

void call_string_callback(const char *val) { string_callback(val); }
void call_int_callback(int val) { int_callback(val); }
