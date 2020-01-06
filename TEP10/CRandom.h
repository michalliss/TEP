//
// Created by legusie on 1/6/20.
//

#ifndef TEP9_CRANDOM_H
#define TEP9_CRANDOM_H
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <random>


class CRandom {
    public:
    int iGetInt(int iFrom, int iTo);
    double dGetDouble(double dFrom, double dTo);
    void vSetSeed(unsigned long iSeed);

    CRandom();
    CRandom(unsigned long iSeed);

private:
    std::random_device c_rd;
    std::mt19937 c_gen;
};


#endif //TEP9_CRANDOM_H
