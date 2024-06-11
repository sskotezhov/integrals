#include <stdio.h>
#include "function.h"
#include "integral.c"

int main(int argc, char* argv[]) {
   double a = root(f1, f3, -0.5, 0, 0.00001, f1_deriative, f3_deriative);
   double b = root(f2, f3, 0, 0.5, 0.00001, f2_deriative, f3_deriative);
   double d = integral(f1, a, b, 0.00001) - integral(f3, a, b, 0.00001);
   a = root(f1, f2, 1.5, 2, 0.00001, f1_deriative, f2_deriative);
   d += integral(f1, b, a, 0.00001) - integral(f2, b, a, 0.00001);
   printf("%.*f\n", 3, d);
   return 0;
}
