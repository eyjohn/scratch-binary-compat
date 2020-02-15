#include <windows.h>

typedef void (CALLBACK* DoStuff)();

int main() {
    HINSTANCE libbInst = LoadLibrary ("libb.dll");
    DoStuff libbDoStuff = (DoStuff) GetProcAddress(libbInst, "libbDoStuff");

    HINSTANCE libcInst = LoadLibrary ("libc.dll");
    DoStuff libcDoStuff = (DoStuff) GetProcAddress(libcInst, "libcDoStuff");

    libbDoStuff();
    libcDoStuff();
    libbDoStuff();
    libcDoStuff();
    return 0;
}