#include <string.h>

#ifdef __linux__
#include <dlfcn.h>

typedef void* Handle;
Handle open_lib(const char* filename) {
  char basename[100] = "";
  strcat(strcat(strcat(basename, "./lib"), filename), ".so");
  return dlopen(basename, RTLD_NOW);
}

void* open_symbol(Handle handle, const char* symbol) {
  return dlsym(handle, symbol);
}

#define CALLBACK
#elif _WIN32

#include <windows.h>

typedef HINSTANCE Handle;
Handle open_lib(const char* filename) {
  char basename[100] = "";
  strcat(strcat(basename, filename), ".dll");
  return LoadLibrary(basename);
}

void* open_symbol(Handle handle, const char* symbol) {
  return GetProcAddress(handle, symbol);
}

#endif

typedef void(CALLBACK* DoStuff)();

int main() {
  Handle libbInst = open_lib("libb");
//   puts(dlerror());
  DoStuff libbDoStuff = (DoStuff)open_symbol(libbInst, "libbDoStuff");
//   puts(dlerror());

  Handle libcInst = open_lib("libc");
  DoStuff libcDoStuff = (DoStuff)open_symbol(libcInst, "libcDoStuff");

    libbDoStuff();
    libcDoStuff();
    libbDoStuff();
    libcDoStuff();
  return 0;
}