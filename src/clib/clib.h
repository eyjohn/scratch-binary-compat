#include <stdbool.h>

typedef void (*STRING_CALLBACK)(const char *);
typedef void (*INT_CALLBACK)(int);

void set_callbacks(STRING_CALLBACK cb1, INT_CALLBACK cb2);
bool are_callbacks_set();

void call_string_callback(const char *value);
void call_int_callback(int value);
