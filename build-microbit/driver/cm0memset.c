#include <stddef.h>
extern void __aeabi_memset(void *r0, size_t r1, int r2);
void memset(void *r0, size_t r1, int r2) {
    __aeabi_memset(r0, r1, r2);
}
