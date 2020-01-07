//
// Created by legusie on 1/6/20.
//

#ifndef TEP9_CRANDOMSEARCH_H
#define TEP9_CRANDOMSEARCH_H

#include "CMscnProblem.h"

#define I_D_MIN 100
#define I_D_MAX 500
#define I_F_MIN 100
#define I_F_MAX 500
#define I_M_MIN 100
#define I_M_MAX 500
#define I_S_MIN 100
#define I_S_MAX 500

class CRandomSearch {
 private:
  CMscnProblem *pc_problem;
  CSolution c_get_random_solution();
  CSolution c_get_random_good_solution();
  void v_fill_good(CMatrix &cMatrix, CMatrix &cMinmax);
 public:
  CRandomSearch();

  bool bSetProblem(CMscnProblem &cProblem);
  CSolution solve();

};

#endif //TEP9_CRANDOMSEARCH_H
