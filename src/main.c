#include <stdio.h>
#include "function.h"
#include "integral.c"
#include <string.h>
#include <stdlib.h>
#include "tests.c"

int main(int argc, char* argv[]) {
   if (argc >1 && (!strcmp(argv[1],"--root") || !strcmp(argv[1],"-r")))
   {
      double *a = root(f1, f3, -0.5, 0, 0.00001, f1_deriative, f3_deriative);
      double *b = root(f2, f3, 0, 0.5, 0.00001, f2_deriative, f3_deriative);
      double *c = root(f1, f2, 1.5, 2, 0.00001, f1_deriative, f2_deriative);
      printf("roots: %f %f %f \n", a[0], b[0], c[0]);
      free(a);
      free(b);
      free(c);
      return 0;
   }
   if (argc >1 && (!strcmp(argv[1],"--iterations") || !strcmp(argv[1],"-i")))
   {
      double *a = root(f1, f3, -0.5, 0, 0.00001, f1_deriative, f3_deriative);
      double *b = root(f2, f3, 0, 0.5, 0.00001, f2_deriative, f3_deriative);
      double *c = root(f1, f2, 1.5, 2, 0.00001, f1_deriative, f2_deriative);
      printf("number of iterations: %f %f %f \n", a[1], b[1], c[1]);
      free(a);
      free(b);
      free(c);
      return 0;
   }
   if (argc >1 && (!strcmp(argv[1],"--help") || !strcmp(argv[1],"-h")))
   {
      printf("-h   --help\n    To display all available parameters\n");
      printf("-r   --roots\n    Print roots\n-i   --iterations\n    Print the number of iterations required to solve the equation\n");
      printf("-R   --test-root\n    For testing function root, accept arguments in format F1:F2:A:B:E:R\n");
      printf("-I   --test-integrals\n    For testing function integral, accept arguments in format F:A:B:E:R\n");
      return 0;
   }
   if (argc >1 && (!strcmp(argv[1],"--test-root") || !strcmp(argv[1],"-R")))
   {
      char *istr = strtok(argv[2], ":");
      int i = 0;
      double array[6];
      while (istr!=NULL)
      {
         array[i] = atof(istr);
         i++;
         istr = strtok (NULL, ":");
      }
      test_root(array[0], array[1], array[2], array[3], array[4], array[5]);
      return 0;
   }
   if (argc >1 && (!strcmp(argv[1],"--test-integral") || !strcmp(argv[1],"-I")))
   {
      char *istr = strtok(argv[2], ":");
      int i = 0;
      double array[5];
      while (istr!=NULL)
      {
         array[i] = atof(istr);
         i++;
         istr = strtok (NULL, ":");
      }
      test_integral(array[0], array[1], array[2], array[3], array[4]);
      return 0;
   }
   double *a = root(f1, f3, -0.5, 0, 0.00001, f1_deriative, f3_deriative);
   double *b = root(f2, f3, 0, 0.5, 0.00001, f2_deriative, f3_deriative);
   double d = integral(f1, a[0], b[0], 0.00001) - integral(f3, a[0], b[0], 0.00001);
   free(a);
   a = root(f1, f2, 1.5, 2, 0.00001, f1_deriative, f2_deriative);
   d += integral(f1, b[0], a[0], 0.00001) - integral(f2, b[0], a[0], 0.00001);
   free(a);
   free(b);
   printf("%.*f\n", 3, d);
   return 0;
}
