//
// Created by legusie on 1/11/20.
//

#ifndef TEP9_CPROBLEM_H
#define TEP9_CPROBLEM_H

#include <vector>
class CProblem {
public:
    virtual double dGetQuality(std::vector<double> vSolution, bool& bSucc) = 0;
    virtual bool bConstraintsSatisfied(std::vector<double> vSolution, bool& bSucc) = 0;
    virtual double getMin(int iIndex) = 0;
    virtual double getMax(int iIndex) = 0;
    virtual int getSize() = 0;
};

#endif //TEP9_CPROBLEM_H
