#ifndef PRIME_TESTER_H
#define PRIME_TESTER_H

class PrimeTester
{
public:
    virtual bool check(unsigned int N, unsigned int k) = 0;
    virtual double getProbability(unsigned int k) = 0;

    unsigned int mod_exp(unsigned int x, unsigned int y, unsigned int N);
};

unsigned int PrimeTester::mod_exp(unsigned int x, unsigned int y, unsigned int N)
{
    if (y == 0)
        return 1;

    auto z = mod_exp(x, (y / 2), N);
    // if y is even
    if (y % 2 == 0)
    {
        return (z * z) % N;
    }

    // since it's odd, we need to factor in the x
    return (x * z * z) % N;
}
#endif