#include <iostream>
#include "MSCN/CMscnProblem.h"
#include "SOLVE/CRandomSearch.h"
#include "constants.h"
#include "SOLVE/CDiffEvol.h"
#include "Controler/CControlerIter.h"
#include "Controler/CControlerTime.h"
void v_test_method(CSolver& c_solver, CProblem& c_problem, CControler& c_controler)
{
    c_solver.bSetProblem(c_problem);
    c_solver.bSetControler(c_controler);

    std::vector<double> v_solution;
    v_solution = c_solver.cSolve();

    bool b_succ;
    //std::cout << MSG_ROZWIAZANIE << std::endl;
    for (int i = 0; i<v_solution.size(); i++) {
        std::cout << c_problem.getMin(i) << " < " << v_solution[i] << " < " << c_problem.getMax(i) << std::endl;
    }
    std::cout << std::endl;
    std::cout << MSG_QUALITY << c_problem.dGetQuality(v_solution, b_succ) << ", " << MSG_SUCCESS << b_succ << std::endl;
    std::cout << MSG_POPRAWNOSC << c_problem.bConstraintsSatisfied(v_solution, b_succ) << ", " << MSG_SUCCESS << b_succ
              << std::endl;

}

void runSimulation()
{
    CMscnProblem c_problem;
    c_problem.vGenerateInstance(I_SEED, I_PROBLEM_D, I_PROBLEM_F, I_PROBLEM_M, I_PROBLEM_S);
    //c_problem.bLoad(S_FILE_PROBLEM_LOAD);
    c_problem.bSave(S_FILE_PROBLEM_SAVE);

    //------------------DIFF EVOL----------------------------------------------------
    CSolver* c_solver = new CDiffEvol(I_SEED);
    //CControler* c_controler = new CControlerTime(I_DEFAULT_TIME);
    CControler* c_controler = new CControlerIter(I_DEFAULT_ITERATIONS);

    v_test_method(*c_solver, c_problem, *c_controler);

    delete c_solver;

    //-------------------------RANDOM-------------------------------------------------

    c_solver = new CRandomSearch(I_SEED);

    v_test_method(*c_solver, c_problem, *c_controler);

    delete c_solver;
    delete c_controler;

}

int main()
{
    runSimulation();
}