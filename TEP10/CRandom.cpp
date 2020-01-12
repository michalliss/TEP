//
// Created by legusie on 1/6/20.
//

#include "CRandom.h"

CRandom::CRandom()
        :c_gen(c_rd())
{

}

CRandom::CRandom(unsigned long iSeed)
        :c_gen(iSeed)
{

}

int CRandom::iGetInt(int iFrom, int iTo)
{
    std::uniform_int_distribution<int> c_dis(iFrom, iTo);
    return c_dis(c_gen);
}

double CRandom::dGetDouble(double dFrom, double dTo)
{
    std::uniform_real_distribution<double> c_dis(dFrom, dTo);
    return c_dis(c_gen);
}

void CRandom::vSetSeed(unsigned long iSeed)
{
    c_gen.seed(iSeed);
}
