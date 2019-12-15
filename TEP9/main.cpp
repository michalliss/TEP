#include <iostream>
#include "CMscnProblem.h"
#include "Utils.h"

void runFile(std::string s_problem_file, std::string s_solution_file){
  CMscnProblem problem;
  problem.bLoad(s_problem_file);

  bool b_succ;
  int i_len = Utils::iGetSolutionLength(s_solution_file);
  double sol[i_len];
  Utils::bLoadSolution(s_solution_file, sol);

  std::cout << "Organiczenia: " << std::endl;
  for (int i = 0; i < i_len; i++) {
    std::cout << problem.getMin(sol, i) << " < " <<  sol[i] << " < " << problem.getMax(sol, i) << std::endl;
  }
  std::cout << std::endl;
  std::cout << "Quality: " << problem.dGetQuality(sol, i_len, b_succ) << ", Success: " << b_succ << std::endl;
  std::cout << "Poprawność: " << problem.bConstraintsSatisfied(sol, i_len, b_succ) << ", Success: " << b_succ << std::endl;

  problem.bSave("savetest.txt");
}

int main() {
  runFile("test.txt", "sol.txt");
}