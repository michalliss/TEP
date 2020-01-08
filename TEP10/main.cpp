#include <iostream>
#include "CMscnProblem.h"
#include "CRandomSearch.h"

void runSimulation()
{
    CMscnProblem problem;
    problem.vGenerateInstance(1234, 4, 4, 4, 4);
    problem.bSave("savetest.txt");

    CRandomSearch c_random_search;
    c_random_search.bSetProblem(problem);

    CSolution c_solution;
    c_solution = c_random_search.cSolve2();

    std::cout << "Organiczenia: " << std::endl;

    bool b_succ;
    for (int i = 0; i<c_solution.iLenght(); i++) {
        std::cout << problem.getMin(i) << " < " << c_solution.c_vector[i] << " < " << problem.getMax(i) << std::endl;
    }
    std::cout << std::endl;
    std::cout << "Quality: " << problem.dGetQuality(c_solution, b_succ) << ", Success: " << b_succ << std::endl;
    std::cout << "Poprawność: " << problem.bConstraintsSatisfied(c_solution, b_succ) << ", Success: " << b_succ
              << std::endl;

}

int main()
{
    runSimulation();
}