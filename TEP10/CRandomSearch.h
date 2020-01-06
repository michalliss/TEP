//
// Created by legusie on 1/6/20.
//

#ifndef TEP9_CRANDOMSEARCH_H
#define TEP9_CRANDOMSEARCH_H


#include "CMscnProblem.h"

#define I_D_MIN 1
#define I_D_MAX 100
#define I_F_MIN 1
#define I_F_MAX 100
#define I_M_MIN 1
#define I_M_MAX 100
#define I_S_MIN 1
#define I_S_MAX 100

class CRandomSearch {
private:
    CMscnProblem *pc_problem;
    CSolution c_get_random_solution();
public:
    CRandomSearch();

    bool bSetProblem(CMscnProblem &cProblem);
    CSolution solve();

};


#endif //TEP9_CRANDOMSEARCH_H
