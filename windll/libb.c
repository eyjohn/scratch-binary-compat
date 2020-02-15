#include <stdio.h>
#include "liba.h"
#include "libb.h"

void libbDoStuff() {
   printf("LibB Counter Value: %d\n", incrementAndGetCounter());
}