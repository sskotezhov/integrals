#include <math.h>
#include <stdlib.h>

double* root(double (*f) (double), double (*g) (double), double a, double b, double eps1, double (*f_deriative) (double), double (*g_deriative) (double))
{
    double F_a = f(a)-g(a);
    double F_b = f(b)-g(b);
    double c = (a*F_b-b*F_a)/(F_b-F_a);
    if (fabs(a-b) <= eps1)
    {
        double *array = (double*)malloc(2*sizeof(double));
        array[0] = c;
        array[1] = 1;
        return array;
    }
    double F_der = f_deriative(c) - g_deriative(c);
    double F_der_der = (F_der - f_deriative(c-0.000000001) + g_deriative(c-0.000000001));
    double *array;
    if (F_der*F_der_der > 0)
    {
        double c1 = b - F_b/(f_deriative(b) - g_deriative(b));
        array = root(f, g, c, c1, eps1, f_deriative, g_deriative);
    }
    else
    {
        double c1 = a - F_a/(f_deriative(a) - g_deriative(a));
        array = root(f, g, c1, c, eps1, f_deriative, g_deriative);
    }
    array[1]+=1;
    return array;

}

double integral(double (*f) (double), double a, double b, double eps2)
{
    double F_a_b = f(a) + f(b);
    int n = 10;
    double F_0 = 0, F_1 = 0;
    double h = (b-a)/n, In, I2n;
    for (int i = 1; i<n; i++)
    {
        if (i%2 == 1)
        {
            F_1 += f(a+h*i);
        }
        else
        {
            F_0 += f(a+h*i);
        }
    }
    I2n = h/3*(F_a_b+F_0*2+F_1*4);
    do
    {
        In = I2n;
        F_0 += F_1;
        F_1 = 0;
        n=n*2;
        h = (b-a)/n;
        for (int i = 1; i<n; i+=2)
        {
            F_1 += f(a+h*i);
        }
        I2n = h/3*(F_a_b+F_0*2+F_1*4);
    } while (((1/15)*(fabs(In-I2n)))>=eps2);
    
    return I2n;
}