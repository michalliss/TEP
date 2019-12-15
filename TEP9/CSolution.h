//
// Created by przydasie on 12/14/19.
//

#ifndef TEP9__CSOLUTION_H_
#define TEP9__CSOLUTION_H_

#include "CMatrix.h"
struct CSolution {
  CMatrix c_xd;
  CMatrix c_xf;
  CMatrix c_xm;

  bool bLoad(std::string sFilename);
  bool bFromArray(double* pdSolution, int iD, int iF, int iM, int iS);
};

#endif //TEP9__CSOLUTION_H_
