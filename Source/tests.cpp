#include <cstdio>
#include <cstdlib>

#include "fmtlib.hpp"


using namespace std;
using namespace fmt;

int test_fast_sqrt()
{
    float b = 13.f * 13.f;

    float sqrt_b = fast_sqrt(b);

    return true;
}

int test_fast_inv_sqrt()
{
    float b = 4.f;

    float inv_sqrt_b = fast_inv_sqrt(b);

    return true;

}

int test_imin()
{
    int a = 10;
    int b = 20;
    int c = 30;

    int m = imin(a, b, c);

    return (m == a);
}

int test_imax()
{
    int a = 10;
    int b = 20;
    int c = 30;

    int m = imax(a, b, c);

    return (m == c);
}

int test_iswap()
{
    int a = 10;
    int b = 20;

    iswap(a, b);

    return (a == 20 && b == 10);

}

int main(int argc, char** argv)
{
    if (!test_iswap()) return 1;
    if (!test_imax()) return 2;
    if (!test_imin()) return 3;
    if (!test_fast_inv_sqrt()) return 4;
    if (!test_fast_sqrt()) return 5;

    return 0;
}