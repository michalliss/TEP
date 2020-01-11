#include <iostream>
#include "CMscnProblem.h"
#include "CRandomSearch.h"
#include "constants.h"
void runSimulation()
{
    CMscnProblem c_problem;
    c_problem.vGenerateInstance(I_SEED, I_PROBLEM_D, I_PROBLEM_F, I_PROBLEM_M, I_PROBLEM_S);
    //c_problem.bLoad(S_FILE_PROBLEM_LOAD);
    c_problem.bSave(S_FILE_PROBLEM_SAVE);

    CRandomSearch c_random_search(I_SEED);
    c_random_search.bSetProblem(c_problem);

    CSolution c_solution;
    c_solution = c_random_search.cSolve2();
    bool b_succ;
    std::cout << MSG_ROZWIAZANIE << std::endl;
    for (int i = 0; i<c_solution.iLenght(); i++) {
        std::cout << c_problem.getMin(i) << " < " << c_solution.c_vector[i] << " < " << c_problem.getMax(i)
                  << std::endl;
    }
    std::cout << std::endl;
    std::cout << MSG_QUALITY << c_problem.dGetQuality(c_solution, b_succ) << ", " << MSG_SUCCESS << b_succ << std::endl;
    std::cout << MSG_POPRAWNOSC << c_problem.bConstraintsSatisfied(c_solution, b_succ) << ", " << MSG_SUCCESS << b_succ
              << std::endl;
}

int main()
{
    runSimulation();
}