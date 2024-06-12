#include <stdio.h>
#include "function.h"
#include "integral.c"
#include "tests.c"

int main(void)
{
    test_root(1, 3, -1.5, 1.5, 0.000001, 0);
    test_root(1, 2, -1.5, 1.5, 0.00000000001, 0.78539816339);
    test_root(2, 3, 0, 1.5, 0.0001, 0.7391);
    test_integral(1, 0, 3.14159265358979323846264, 0.0001, 2);
    test_integral(2, 0, 3.14159265358979323846264, 0.00000000001, 0);
    test_integral(3, 0, 100, 0.000000000000000000001, 5000);
    return 0;
}

