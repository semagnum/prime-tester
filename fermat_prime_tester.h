#include "prime_tester.h"
#include <cmath>

class FermatPrimeTester : public PrimeTester
{
public:
    bool check(unsigned int N, unsigned int k);
    double getProbability(unsigned int k);
};

bool FermatPrimeTester::check(unsigned int N, unsigned int k)
{
    for (int i = 1; i < k; i++)
    {
        auto a = (rand() % (N - 2)) + 1;

        if (mod_exp(a, N - 1, N) != 1)
            return false;
    }

    return true;
}

double FermatPrimeTester::getProbability(unsigned int k)
{
    return 1.0 - std::pow(0.5, k);
}