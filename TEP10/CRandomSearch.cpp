//
// Created by legusie on 1/6/20.
//

#include <iostream>
#include "CRandomSearch.h"

CRandomSearch::CRandomSearch() {
  pc_problem = NULL;
}

bool CRandomSearch::bSetProblem(CMscnProblem &cProblem) {
  if (&cProblem == NULL) return false;
  pc_problem = &cProblem;
  return true;
}

CSolution CRandomSearch::c_get_random_solution() {
  CRandom c_random;
  CSolution c_solution(pc_problem->iGetD(), pc_problem->iGetF(), pc_problem->iGetM(), pc_problem->iGetS());
  c_solution.c_xd.vFillRandom(c_random, I_D_MIN, I_D_MAX);
  c_solution.c_xf.vFillRandom(c_random, I_F_MIN, I_F_MAX);
  c_solution.c_xm.vFillRandom(c_random, I_M_MIN, I_M_MAX);
  c_solution.vCalcVector();

  return c_solution;
}
CSolution CRandomSearch::c_get_random_good_solution() {
  CRandom c_random;
  CSolution c_solution(pc_problem->iGetD(), pc_problem->iGetF(), pc_problem->iGetM(), pc_problem->iGetS());
  v_fill_good(c_solution.c_xd, pc_problem->cGetXDminmax());
  v_fill_good(c_solution.c_xf, pc_problem->cGetXFminmax());
  v_fill_good(c_solution.c_xm, pc_problem->cGetXMminmax());
  c_solution.vCalcVector();
  return c_solution;

}

void CRandomSearch::v_fill_good(CMatrix &cMatrix, CMatrix &cMinmax) {
  CRandom c_random;
  for (int i = 0; i < cMatrix.iGetRows(); i++) {
    for (int j = 0; j < cMatrix.iGetCols(); j++) {
      cMatrix(i,j) = c_random.dGetDouble(cMinmax(i, 2*j), cMinmax(i, 2*j+1));
    }
  }
}

CSolution CRandomSearch::solve() {
  if (pc_problem == NULL) return CSolution();
  int i_counter = 0;
  CSolution c_best = c_get_random_good_solution();
  bool b_succ;
  while(!pc_problem->bConstraintsSatisfied(c_best, b_succ)){
    c_best = c_get_random_good_solution();
  }

  std::cout << "1 poprawny" << std::endl;

  for (int i = 0; i < 100000; i++) {
    CSolution c_temp = c_get_random_good_solution();
    bool b_succ;
    if (pc_problem->bConstraintsSatisfied(c_temp, b_succ) && pc_problem->dGetQuality(c_temp, b_succ) > pc_problem->dGetQuality(c_best, b_succ)) {
      c_best = c_temp;
      i_counter++;
    }
  }
  std::cout << " " << i_counter << " " ;

  return c_best;
}


