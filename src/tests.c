#include "function.h"
#include <stdlib.h>
void test_root(int F1, int F2, double a, double b, double e, double r)
{
    int cnt = 0;
    double eps = e;
    while (eps < 1)
    {
        cnt++;
        eps = eps*10;
    }
    if (eps < 2)
    {
        cnt++;
    }
    F1--;
    F2--;
    double (*functions[6])(double) = {f1, f2, f3, f1_deriative, f2_deriative, f3_deriative};
    double *result = root(functions[F1], functions[F2], a, b, e, functions[3+F1], functions[3+F2]);
    double rel_accur = fabs((result[0]-r)/r);
    if (fabs(r)<e)
    {
        rel_accur = 0;
    }
    printf("Test root\n Calculated value: %.*f\n Absolute accuracy: %.*f\n Relative accuracy: %.*f\n", cnt, result[0], cnt, fabs(result[0]-r), cnt+2, rel_accur);
    free(result);
    return;
}
void test_integral(int F1, double a, double b, double e, double r)
{
    double (*functions[3])(double) = {f1, f2, f3};
    int cnt = 0;
    double eps = e;
    while (eps < 1)
    {
        cnt++;
        eps = eps*10;
    }
    if (eps < 2)
    {
        cnt++;
    }
    F1--;
    double result = integral(functions[F1], a, b, e);
    double rel_accur = fabs((result-r)/r);
    if (fabs(r)<e)
    {
        rel_accur = 0;
    }
    printf("Test integral\n Calculated value: %.*f\n Absolute accuracy: %.*f\n Relative accuracy: %.*f\n", cnt, result, cnt, fabs(result-r), cnt+2, rel_accur);
    return;

}