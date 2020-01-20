//
// Created by przydasie on 12/14/19.
//

#ifndef TEP9__CSOLUTION_H_
#define TEP9__CSOLUTION_H_

#include <vector>
#include <ostream>
#include "../CMatrix.h"

struct CSolution {
  int i_d;
  int i_f;
  int i_m;
  int i_s;
  CMatrix c_xd;
  CMatrix c_xf;
  CMatrix c_xm;
  std::vector<double> c_vector;

  CSolution(int iD, int iF, int iM, int iS);
  CSolution();

  bool bLoad(std::string sFilename);
  bool bLoadFromVector(std::vector<double> vSolution);
  int iLenght();
  void vCalcVector();
    friend std::ostream& operator<<(std::ostream& os, const CSolution& solution);
};

#endif //TEP9__CSOLUTION_H_
