#include <stdint.h>
#include <stdio.h>

uint32_t add(uint32_t lhs, uint32_t rhs);

int main()
{
    printf("add(1, 2) = %d\n", add(1, 2));  // expect 3
    return 0;
}
