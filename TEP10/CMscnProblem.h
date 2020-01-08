//
// Created by przydasie on 12/14/19.
//

#ifndef TEP9__CMSCNPROBLEM_H_
#define TEP9__CMSCNPROBLEM_H_

#include "CMatrix.h"
#include "CSolution.h"
#include <iostream>

#define I_DEFAULT_SIZE 2
#define I_C_MIN 1
#define I_C_MAX 200
#define I_U_MIN 1
#define I_U_MAX 1000
#define I_S_MIN 1000
#define I_S_MAX 100000
#define I_P_MIN 1
#define I_P_MAX 1000
#define I_MIN 1
#define I_MAX 1000

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

    double d_calc_P(CMatrix& xm);
    double d_calc_Kt(CMatrix& xd, CMatrix& xf, CMatrix& xm);
    double d_calc_Ku(CMatrix& xd, CMatrix& xf, CMatrix& xm);
    int i_const_cost(CMatrix& matrix, int row);
    bool bMinMaxSatisfied(CSolution& cSolution);
    void vRandomMinmax(CMatrix& cMatrix, CRandom& cRandom);
    double dGetQuality(CSolution& cSolution);
    bool bConstraintsSatisfied(CSolution& cSolution);
    double dGetMin(CMatrix& c_minmax, int i_row, int i_col);
    double dGetMax(CMatrix& c_minmax, int i_row, int i_col);

public:
    CMscnProblem();
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

    bool bSave(std::string sFilename);
    bool bLoad(std::string sFilename);
    bool bCheckMinMax(CMatrix& cMatrix, CMatrix& cMinMax);
    double getMin(int iIndex);
    double getMax(int iIndex);

    double dGetQuality(CSolution cSolution, bool& pb_succ);
    bool bTechCheck(CSolution& cSolution);
    bool bConstraintsSatisfied(CSolution& cSolution, bool& pb_succ);
    void vGenerateInstance(int iInstanceSeed, int iD, int iF, int iM, int iS);

    int iGetD() const;
    int iGetF() const;
    int iGetM() const;
    int iGetS() const;

    double dGetXDMin(int iRow, int iCol);
    double dGetXDMax(int iRow, int iCol);
    double dGetXFMin(int iRow, int iCol);
    double dGetXFMax(int iRow, int iCol);
    double dGetXMMin(int iRow, int iCol);
    double dGetXMMax(int iRow, int iCol);
    CMatrix& cGetXDminmax();
    CMatrix& cGetXFminmax();
    CMatrix& cGetXMminmax();
};

#endif //TEP9__CMSCNPROBLEM_H_
