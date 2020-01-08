//
// Created by legusie on 1/6/20.
//


#include "CRandomSearch.h"

CRandomSearch::CRandomSearch()
        :pc_problem(NULL)
{

}

CRandomSearch::CRandomSearch(unsigned long iSeed)
        :pc_problem(NULL), c_random(iSeed)
{

}

bool CRandomSearch::bSetProblem(CMscnProblem& cProblem)
{
    if (&cProblem==NULL) return false;
    pc_problem = &cProblem;
    return true;
}

CSolution CRandomSearch::c_get_random_solution()
{
    if (pc_problem==NULL) return CSolution();
    CSolution c_solution(pc_problem->iGetD(), pc_problem->iGetF(), pc_problem->iGetM(), pc_problem->iGetS());
    c_solution.c_xd.vFillRandom(c_random, I_DX_MIN, I_DX_MAX);
    c_solution.c_xf.vFillRandom(c_random, I_FX_MIN, I_FX_MAX);
    c_solution.c_xm.vFillRandom(c_random, I_MX_MIN, I_MX_MAX);
    c_solution.vCalcVector();
    return c_solution;
}

CSolution CRandomSearch::c_get_random_good_solution()
{
    if (pc_problem==NULL) return CSolution();
    CSolution c_solution(pc_problem->iGetD(), pc_problem->iGetF(), pc_problem->iGetM(), pc_problem->iGetS());
    v_fill_good(c_solution.c_xd, pc_problem->cGetXDminmax());
    v_fill_good(c_solution.c_xf, pc_problem->cGetXFminmax());
    v_fill_good(c_solution.c_xm, pc_problem->cGetXMminmax());
    c_solution.vCalcVector();
    return c_solution;

}

void CRandomSearch::v_fill_good(CMatrix& cMatrix, CMatrix& cMinmax)
{
    for (int i = 0; i<cMatrix.iGetRows(); i++) {
        for (int j = 0; j<cMatrix.iGetCols(); j++) {
            cMatrix(i, j) = c_random.dGetDouble(cMinmax(i, 2*j), cMinmax(i, 2*j+1));
        }
    }
}

CSolution CRandomSearch::cSolve()
{
    if (pc_problem==NULL) return CSolution();

    CSolution c_best = c_get_random_good_solution();
    bool b_succ;
    c_best = c_get_random_good_solution();

    for (int i = 0; i<I_MAX_ITERATIONS; i++) {
        CSolution c_temp = c_get_random_good_solution();
        if (pc_problem->dGetQuality(c_temp, b_succ)>pc_problem->dGetQuality(c_best, b_succ)) {
            c_best = c_temp;
        }
    }
    return c_best;
}

CSolution CRandomSearch::cSolve2()
{
    if (pc_problem==NULL) return CSolution();

    CSolution c_best = c_get_random_good_solution();
    bool b_succ;
    while (!pc_problem->bConstraintsSatisfied(c_best, b_succ)) {
        c_best = c_get_random_good_solution();
    }
    for (int i = 0; i<I_MAX_ITERATIONS; i++) {
        CSolution c_temp = c_get_random_good_solution();
        bool b_succ;
        if (pc_problem->bConstraintsSatisfied(c_temp, b_succ) &&
                pc_problem->dGetQuality(c_temp, b_succ)>pc_problem->dGetQuality(c_best, b_succ)) {
            c_best = c_temp;
        }
    }
    return c_best;
}



