//
// Created by legusie on 1/6/20.
//

#ifndef TEP9_CRANDOMSEARCH_H
#define TEP9_CRANDOMSEARCH_H

#include "CMscnProblem.h"
#include <iostream>

#define I_DX_MIN 100
#define I_DX_MAX 500
#define I_FX_MIN 100
#define I_FX_MAX 500
#define I_MX_MIN 100
#define I_MX_MAX 500
#define I_MAX_ITERATIONS 100000

class CRandomSearch {
private:
    CMscnProblem* pc_problem;
    CRandom c_random;

    CSolution c_get_random_solution();
    CSolution c_get_random_good_solution();
    void v_fill_good(CMatrix& cMatrix, CMatrix& cMinmax);

public:
    CRandomSearch();
    CRandomSearch(unsigned long iSeed);
    bool bSetProblem(CMscnProblem& cProblem);
    CSolution cSolve();
    CSolution cSolve2();
};

#endif //TEP9_CRANDOMSEARCH_H
