#include "prime_tester.h"
#include <cmath>

class MillerRabinPrimeTester : public PrimeTester
{
public:
    bool check(unsigned int N, unsigned int k);
    double getProbability(unsigned int k);
};

bool MillerRabinPrimeTester::check(unsigned int N, unsigned int k)
{
    // to check cases of when N is even and not 2
    if (N > 2 and N % 2 == 0)
        return false;

    for (auto i = 1; i < k; i++)
    {
        // 1 <= a < N
        auto a = (rand() % (N - 2)) + 1;
        auto mr_exponent = N - 1;
        while (mr_exponent % 2 == 0)
        {
            auto result = mod_exp(a, mr_exponent, N);

            // if it passes, increment mr_iterator and redefine mr_exponent
            if (result == 1)
            {
                mr_exponent = (mr_exponent / 2);
            }
            else if (N - result == 1)
                break; // if it becomes "-1", then it passed
            else
                return false;
        }
    }

    // if it passes, it's prime
    return true;
}

double MillerRabinPrimeTester::getProbability(unsigned int k)
{
    return 1.0 - std::pow(0.25, k);
}