#ifndef __FMT_LIB_H__
#define __FMT_LIB_H__

namespace fmt
{

void iswap(int &x, int &y)
{
    x = x + y - (y = x);
}

int imax(int a, int b, int c)
{
    // initialize max with a
    int max = a;
    
    // set max to b if and only if max is less than b
    (max < b) && (max = b); // these are not conditional statements.
    
    // set max to c if and only if max is less than c
    (max < c) && (max = c); // these are just Boolean expressions.
 
    return max;
}

int imin(int a, int b, int c)
{
    // initialize min with a
    int min = a;
    
    // set min to b if and only if min is more than b
    (min > b) && (min = b);
    
    // set min to c if and only if min is more than c
    (min > c) && (min = c);
    
    return min;
}

bool check_interval(int number, int lower, int upper) {
    // use a < for an inclusive lower bound and exclusive upper bound
    // use <= for an inclusive lower bound and inclusive upper bound
    // alternatively, if the upper bound is inclusive and you can pre-calculate
    //  upper-lower, simply add + 1 to upper-lower and use the < operator.
    return ((unsigned)(number - lower) <= (upper - lower));
}

void vec_max_min(int *in_ptr, int &xmax, int &xmin, int limit)
{
    xmin = 0;
    xmax = 0;
    for (int i = 0; i < limit; i++) {
        xmin += *in_ptr - xmin & *in_ptr - xmin >> 31;
        xmax += *in_ptr - xmax & xmax - *in_ptr >> 31;

        in_ptr++;
    }
}

// Reference: http://h14s.p5r.org/2012/09/0x5f3759df.html?mwh=1
float fast_inv_sqrt(float x) {
    float xhalf = 0.5f * x;
    int i = *(int*)&x;         // evil floating point bit level hacking
    i = 0x5f3759df - (i >> 1);
    x = *(float*)&i;
    x = x * (1.5f - (xhalf * x * x)); // single newthon's method iteration
    return x;
}

float fast_sqrt(float x) {
    float xhalf = 0.5f * x;
    int i = *(int*)&x;         // evil floating point bit level hacking
    i = 0x1fbd1df5 + (i >> 1);
    x = *(float*)&i;
    x = 0.5*x + xhalf/x; // single newthon's method iteration
    return x;
}

double std_dev2(double a[], int n) {
    if (n == 0)
        return 0.0;
    double sum = 0;
    double sq_sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += a[i];
        sq_sum += a[i] * a[i];
    }
    double mean = sum / n;
    double variance = sq_sum / n - mean * mean;
    return fast_sqrt(variance);
}

}

#endif