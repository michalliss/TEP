#include <iostream>
#include "CMscnProblem.h"
#include "Utils.h"
#include "CRandomSearch.h"

void runFile(std::string s_problem_file, std::string s_solution_file){
  CMscnProblem problem;
  problem.vGenerateInstance(123, 3, 3, 3, 3);
  problem.bSave("savetest.txt");


  bool b_succ;

  CSolution c_solution;
  CRandomSearch c_rand;
  c_rand.bSetProblem(problem);
  c_solution = c_rand.solve();

  std::cout << c_solution.i_d;

  std::cout << std::endl;

  std::cout << "Organiczenia: " << std::endl;
  for (int i = 0; i < c_solution.iLenght(); i++) {
    std::cout << problem.getMin(i) << " < " <<  c_solution.c_vector[i] << " < " << problem.getMax(i) << std::endl;
  }
  std::cout << std::endl;
  std::cout << "Quality: " << problem.dGetQuality(c_solution, b_succ) << ", Success: " << b_succ << std::endl;
  std::cout << "Poprawność: " << problem.bConstraintsSatisfied(c_solution, b_succ) << ", Success: " << b_succ << std::endl;

  problem.bSave("savetest.txt");
}

int main() {
  runFile("test.txt", "sol.txt");
}