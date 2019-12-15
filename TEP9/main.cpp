#include <iostream>
#include "CMscnProblem.h"
#include "CSolution.h"
#include "Utils.h"

int main() {
  CMscnProblem problem;
  problem.bLoad("test.txt");

  bool b_succ;
  int i_len = Utils::iGetSolutionLength("sol.txt");
  double sol[i_len];
  Utils::bLoadSolution("sol.txt", sol);

  //problem.bSetD(3);
  //std::cout << problem.c_cd.sToString();


  std::cout << "Organiczenia: " << std::endl;
  for (int i = 0; i < i_len; i++) {
    std::cout << problem.getMin(sol, i) << " <-> " << problem.getMax(sol, i) << std::endl;
  }
  std::cout << std::endl;
  std::cout << "Quality: " << problem.dGetQuality(sol, i_len, b_succ) << ", Success: " << b_succ << std::endl;
  std::cout << "Poprawność: " << problem.bConstraintsSatisfied(sol, i_len, b_succ) << ", Success: " << b_succ << std::endl;



  problem.bSave("savetest.txt");
}