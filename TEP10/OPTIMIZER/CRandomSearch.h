//
// Created by legusie on 1/6/20.
//

#ifndef TEP9_CRANDOMSEARCH_H
#define TEP9_CRANDOMSEARCH_H

#include "../MSCN/CMscnProblem.h"
#include "COptimizer.h"
#include <iostream>

#define I_DX_MIN 100
#define I_DX_MAX 500
#define I_FX_MIN 100
#define I_FX_MAX 500
#define I_MX_MIN 100
#define I_MX_MAX 500
#define I_MAX_ITERATIONS 100000

class CRandomSearch : public COptimizer{
private:
    CRandom c_random;
    std::vector<double> c_get_random_good_solution();
    void v_fill_good(CMatrix& c_matrix, CMatrix& c_minmax);
public:
    CRandomSearch();
    explicit CRandomSearch(unsigned long iSeed);
    std::vector<double> cSolve() override;
};

#endif //TEP9_CRANDOMSEARCH_H
