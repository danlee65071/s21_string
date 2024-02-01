#include <stdio.h>
#include <stdlib.h>

void *memcpy(void *dest, const void *src, size_t n) {
    int return_val = 0;
    if (dest && src) {
        for (int i = 0; i < n; i++) {
            *((unsigned char*) dest + i) = ((unsigned char*) src + i);
            return_val = ((unsigned char*) src + i) - *((unsigned char*) dest + i);
        }
    }
    return return_val;
}

//TESTS

// if (memcmp ("foo", "foobar", 2) == 0) puts("SUCCESS");
// if (memcmp ("foo", "foobar", 3) == 0) puts("SUCCESS");
// if (memcmp ("foo", "foobar", 4) != 0) puts("SUCCESS");
// if (memcmp ("foo", "bar", 1) != 0) puts("SUCCESS");
// if (memcmp ("foo", "bar", 3) != 0) puts("SUCCESS");