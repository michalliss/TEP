#include <iostream>
#include "CMscnProblem.h"
#include "Utils.h"
#include "constants.h"
void runFile(std::string s_problem_file, std::string s_solution_file){
  CMscnProblem problem;
  problem.bLoad(s_problem_file);

  bool b_succ;
  int i_len = Utils::iGetSolutionLength(s_solution_file);
  double sol[i_len];
  if(!Utils::bLoadSolution2(s_solution_file, sol)){
    std::cout << "Błędne dane!";
    return;
  }



  std::cout << S_QUAL << problem.dGetQuality(sol, i_len, b_succ) << S_SUCC << b_succ << std::endl;
  std::cout << S_POPR << problem.bConstraintsSatisfied(sol, i_len, b_succ) << S_SUCC << b_succ << std::endl;
  std::cout << std::endl;
  if(b_succ){
    std::cout << S_OGR << std::endl;
    for (int i = 0; i < i_len; i++) {
      std::cout << problem.getMin(i) << " < " <<  sol[i] << " < " << problem.getMax(i) << std::endl;
    }

    problem.bSave(S_FILE3);
  }

}

int main() {
  runFile(S_FILE1, S_FILE2);
}