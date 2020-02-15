#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char* line = NULL;
  size_t len = 0;
  ssize_t nread;

  int (*hello_world)();

  for (;;) {
    puts("library path:");
    if (getline(&line, &len, stdin) == -1) break;
    line[strlen(line) - 1] = '\0';
    void* handle = dlopen(line, RTLD_NOW);
    if (handle) {
      printf("woop\n");
      *(void**)(&hello_world) = dlsym(handle, "hello_world");
      if (hello_world) {
        printf("hello_world %d\n", hello_world());
      } else {
        puts(dlerror());
      }
      dlclose(handle);
    } else {
      puts(dlerror());
    }
  }
}