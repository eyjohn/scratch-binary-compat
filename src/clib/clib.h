
typedef void (*STRING_CALLBACK)(const char *);
typedef void (*INT_CALLBACK)(int);

void set_string_callback(STRING_CALLBACK func);
void set_int_callback(INT_CALLBACK func);

void call_string_callback(const char *val);
void call_int_callback(int val);
