//
// Created by legusie on 1/6/20.
//


#include "CRandomSearch.h"

CRandomSearch::CRandomSearch()
        :CSolver()
{

}

CRandomSearch::CRandomSearch(unsigned long iSeed)
        :CSolver(), c_random(iSeed)
{

}

std::vector<double> CRandomSearch::c_get_random_good_solution()
{
    if (pc_problem==NULL) return std::vector<double>();
    std::vector<double> v_solution(pc_problem->getSize());
    for (int i = 0; i<v_solution.size(); i++) {
        v_solution[i] = c_random.dGetDouble(pc_problem->getMin(i), pc_problem->getMax(i));
    }
    return v_solution;

    /*
    CSolution c_solution(pc_problem->iGetD(), pc_problem->iGetF(), pc_problem->iGetM(), pc_problem->iGetS());
    v_fill_good(c_solution.c_xd, pc_problem->cGetXDminmax());
    v_fill_good(c_solution.c_xf, pc_problem->cGetXFminmax());
    v_fill_good(c_solution.c_xm, pc_problem->cGetXMminmax());
    c_solution.vCalcVector();
    return c_solution;
    */
}

void CRandomSearch::v_fill_good(CMatrix& c_matrix, CMatrix& c_minmax)
{
    for (int i = 0; i<c_matrix.iGetRows(); i++) {
        for (int j = 0; j<c_matrix.iGetCols(); j++) {
            c_matrix(i, j) = c_random.dGetDouble(c_minmax(i, 2*j), c_minmax(i, 2*j+1));
        }
    }
}

std::vector<double> CRandomSearch::cSolve()
{
    if (pc_problem==NULL) return std::vector<double>();

    std::vector<double> v_best = c_get_random_good_solution();
    bool b_succ = true;

    while (!pc_problem->bConstraintsSatisfied(v_best, b_succ)) {
        v_best = c_get_random_good_solution();
    }

    pc_controller->vStart();
    while (pc_controller->bContinue()) {
        pc_controller->vUpdate();
        std::vector<double> v_temp = c_get_random_good_solution();
        if (pc_problem->bConstraintsSatisfied(v_temp, b_succ) &&
                pc_problem->dGetQuality(v_temp, b_succ)>pc_problem->dGetQuality(v_best, b_succ)) {
            v_best = v_temp;
        }
    }

    /*
    for (int i = 0; i<I_MAX_ITERATIONS; i++) {
        std::vector<double> v_temp = c_get_random_good_solution();
        bool b_succ = true;
        if (pc_problem->b_constraints_satisfied(v_temp, b_succ) &&
                pc_problem->dGetQuality(v_temp, b_succ)>pc_problem->d_get_quality(v_best, b_succ)) {
            v_best = v_temp;
        }
    }
     */

    return v_best;

}



