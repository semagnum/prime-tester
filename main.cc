#include <iostream>
#include "fermat_prime_tester.h"
#include "miller_rabin_prime_tester.h"

int main()
{
    unsigned int N;
    unsigned int k;

    std::cout << "What positive number would you like to test for prime? ";
    std::cin >> N;

    std::cout << std::endl;
    std::cout << "How many samples? ";
    std::cin >> k;

    std::cout << std::endl;

    MillerRabinPrimeTester mrTester;

    bool result = mrTester.check(N, k);

    std::cout << "MR: ";
    if (result)
    {
        std::cout << "prime with probability of " << mrTester.getProbability(k) << std::endl;
    }
    else
    {
        std::cout << "not prime" << std::endl;
    }

    FermatPrimeTester fTester;
    result = fTester.check(N, k);

    std::cout << "Fermat: ";
    if (result)
    {
        std::cout << "prime with probability of " << fTester.getProbability(k) << std::endl;
    }
    else
    {
        std::cout << "not prime" << std::endl;
    }
}