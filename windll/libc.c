#include <stdio.h>
#include "liba.h"
#include "libc.h"

void libcDoStuff() {
   printf("LibC Counter Value: %d\n", incrementAndGetCounter());
}