#include <iostream>
#include "CMscnProblem.h"
#include "CRandomSearch.h"

void runSimulation()
{
    CMscnProblem c_problem;
    //c_problem.vGenerateInstance(1234, 3, 3, 3, 3);
    c_problem.bLoad("test.txt");
    c_problem.bSave("savetest.txt");

    CRandomSearch c_random_search(1234);
    c_random_search.bSetProblem(c_problem);

    CSolution c_solution;
    c_solution = c_random_search.cSolve2();


    bool b_succ;

    std::cout << "Rozwiązanie: " << std::endl;
    for (int i = 0; i<c_solution.iLenght(); i++) {
        std::cout << c_problem.getMin(i) << " < " << c_solution.c_vector[i] << " < " << c_problem.getMax(i) << std::endl;
    }
    std::cout << std::endl;
    std::cout << "Quality: " << c_problem.dGetQuality(c_solution, b_succ) << ", Success: " << b_succ << std::endl;
    std::cout << "Poprawność: " << c_problem.bConstraintsSatisfied(c_solution, b_succ) << ", Success: " << b_succ
              << std::endl;
}

int main()
{
    runSimulation();
}