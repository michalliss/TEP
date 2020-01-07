//
// Created by przydasie on 12/14/19.
//

#ifndef TEP9__CMSCNPROBLEM_H_
#define TEP9__CMSCNPROBLEM_H_

#include "CMatrix.h"
#include "CSolution.h"
#define I_DEFAULT_SIZE 2
class CMscnProblem {
 private:
  int i_d;
  int i_f;
  int i_m;
  int i_s;

  CMatrix c_sd;
  CMatrix c_sf;
  CMatrix c_sm;
  CMatrix c_ss;

  CMatrix c_cd;
  CMatrix c_cf;
  CMatrix c_cm;

  CMatrix c_ud;
  CMatrix c_uf;
  CMatrix c_um;

  CMatrix c_p;

  CMatrix c_xdminmax;
  CMatrix c_xfminmax;
  CMatrix c_xmminmax;

  double d_calc_P(CMatrix &xm);
  double d_calc_Kt(CMatrix &xd, CMatrix &xf, CMatrix &xm);
  double d_calc_Ku(CMatrix &xd, CMatrix &xf, CMatrix &xm);
  int i_const_cost(CMatrix &matrix, int row);
  bool bMinMaxSatisfied(CSolution &cSolution);
  bool bConstraintsSatisfied(CSolution &cSolution);
  double dGetQuality(CSolution &cSolution);

 public:
  CMscnProblem();
  double dGetQuality(double *pdSolution, int i_length, bool &pb_succ);
  bool bConstraintsSatisfied(double *pdSolution, int i_length, bool &pb_succ);

  bool bSetD(int iD);
  bool bSetF(int iF);
  bool bSetM(int iM);
  bool bSetS(int iS);

  bool bSetSD(int iIndex, double dVal);
  bool bSetSF(int iIndex, double dVal);
  bool bSetSM(int iIndex, double dVal);
  bool bSetSS(int iIndex, double dVal);

  bool bSetCD(int iRow, int iCol, double dVal);
  bool bSetCF(int iRow, int iCol, double dVal);
  bool bSetCM(int iRow, int iCol, double dVal);

  bool bSave(const std::string &sFilename);
  bool bLoad(std::string sFilename);

  bool bCheckMinMax(CMatrix &cMatrix, CMatrix &cMinMax);

  double getMin(int iIndex);
  double getMax(int iIndex);
  bool bTechCheck(double *pdSolution, int i_length);
};

#endif //TEP9__CMSCNPROBLEM_H_
