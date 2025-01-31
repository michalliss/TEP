//
// Created by przydasie on 12/14/19.
//

#include <fstream>

#include "CMscnProblem.h"

CMscnProblem::CMscnProblem()
{
    i_d = I_DEFAULT_SIZE;
    i_f = I_DEFAULT_SIZE;
    i_m = I_DEFAULT_SIZE;
    i_s = I_DEFAULT_SIZE;

    bSetD(I_DEFAULT_SIZE);
    bSetF(I_DEFAULT_SIZE);
    bSetM(I_DEFAULT_SIZE);
    bSetS(I_DEFAULT_SIZE);
}

bool CMscnProblem::bSetD(int iD)
{
    if (iD<0) return false;
    i_d = iD;
    c_sd.bResize(1, i_d);
    c_cd.bResize(i_d, i_f);
    c_ud.bResize(1, i_d);
    c_xdminmax.bResize(i_d, 2*i_f);
    return true;
}

bool CMscnProblem::bSetF(int iF)
{
    if (iF<0) return false;
    i_f = iF;
    c_sf.bResize(1, i_f);
    c_cd.bResize(i_d, i_f);
    c_cf.bResize(i_f, i_m);
    c_uf.bResize(1, i_f);
    c_xdminmax.bResize(i_d, 2*i_f);
    c_xfminmax.bResize(i_f, 2*i_m);
    return true;
}

bool CMscnProblem::bSetM(int iM)
{
    if (iM<0) return false;
    i_m = iM;
    c_sm.bResize(1, i_m);
    c_cf.bResize(i_f, i_m);
    c_cm.bResize(i_m, i_s);
    c_um.bResize(1, i_d);
    c_xfminmax.bResize(i_f, 2*i_m);
    c_xmminmax.bResize(i_m, 2*i_s);
    return true;
}

bool CMscnProblem::bSetS(int iS)
{
    if (iS<0) return false;
    i_s = iS;
    c_ss.bResize(1, i_s);
    c_cm.bResize(i_m, i_s);
    c_p.bResize(1, i_s);
    c_xmminmax.bResize(i_m, 2*i_s);
    return false;
}

bool CMscnProblem::bSetSD(int iIndex, double dVal)
{
    if (!c_sd.bCheckBounds(iIndex)) return false;
    c_sd(0, iIndex) = dVal;
    return true;
}

bool CMscnProblem::bSetSF(int iIndex, double dVal)
{
    if (!c_sf.bCheckBounds(iIndex)) return false;
    c_sf(0, iIndex) = dVal;
    return true;
}

bool CMscnProblem::bSetSM(int iIndex, double dVal)
{
    if (!c_sf.bCheckBounds(iIndex)) return false;
    c_sm(0, iIndex) = dVal;
    return true;
}

bool CMscnProblem::bSetSS(int iIndex, double dVal)
{
    if (!c_sf.bCheckBounds(iIndex)) return false;
    c_ss(0, iIndex) = dVal;
    return true;
}

bool CMscnProblem::bSetCD(int iRow, int iCol, double dVal)
{
    if (!c_cd.bCheckBounds(iRow, iCol)) return false;
    c_cd(iRow, iCol) = dVal;
    return true;
}

bool CMscnProblem::bSetCF(int iRow, int iCol, double dVal)
{
    if (!c_cf.bCheckBounds(iRow, iCol)) return false;
    c_cf(iRow, iCol) = dVal;
    return true;
}

bool CMscnProblem::bSetCM(int iRow, int iCol, double dVal)
{
    if (!c_cm.bCheckBounds(iRow, iCol)) return false;
    c_cm(iRow, iCol) = dVal;
    return true;
}

double CMscnProblem::dGetQuality(CSolution cSolution, bool& pb_succ)
{
    if (!bTechCheck(cSolution)) return false;
    pb_succ = true;
    return d_get_quality(cSolution);
}

double CMscnProblem::d_get_quality(CSolution& c_solution)
{
    return d_calc_P(c_solution.c_xm)-d_calc_Kt(c_solution.c_xd, c_solution.c_xf, c_solution.c_xm)
            -d_calc_Ku(c_solution.c_xd, c_solution.c_xf, c_solution.c_xm);
}

double CMscnProblem::d_calc_P(CMatrix& xm)
{
    double d_res = 0;
    for (int m = 0; m<i_m; m++) {
        for (int s = 0; s<i_s; s++) {
            d_res += c_p(s)*xm(m, s);
        }
    }
    return d_res;
}

double CMscnProblem::d_calc_Kt(CMatrix& xd, CMatrix& xf, CMatrix& xm)
{
    double d_res = 0;
    for (int d = 0; d<i_d; d++) {
        for (int f = 0; f<i_f; f++) {
            d_res += c_cd(d, f)*xd(d, f);
        }
    }

    for (int f = 0; f<i_f; f++) {
        for (int m = 0; m<i_m; m++) {
            d_res += c_cf(f, m)*xf(f, m);
        }
    }

    for (int m = 0; m<i_m; m++) {
        for (int s = 0; s<i_s; s++) {
            d_res += c_cm(m, s)*xm(m, s);
        }
    }

    return d_res;
}

int CMscnProblem::i_const_cost(CMatrix& matrix, int row)
{
    for (int i = 0; i<matrix.iGetCols(); i++) {
        if (matrix(row, i)>0) return 1;
    }
    return 0;
}

double CMscnProblem::d_calc_Ku(CMatrix& xd, CMatrix& xf, CMatrix& xm)
{
    double result = 0;

    for (int d = 0; d<i_d; d++) {
        if (i_const_cost(xd, d)) result += c_ud(d);
    }

    for (int f = 0; f<i_f; f++) {
        if (i_const_cost(xf, f)) result += c_uf(f);
    }

    for (int m = 0; m<i_m; m++) {
        if (i_const_cost(xm, m)) result += c_um(m);
    }

    return result;
}

bool CMscnProblem::b_minmax_satisfied(CSolution& c_solution)
{
    return bCheckMinMax(c_solution.c_xd, c_xdminmax) &&
            bCheckMinMax(c_solution.c_xf, c_xfminmax) &&
            bCheckMinMax(c_solution.c_xm, c_xmminmax);
}

bool CMscnProblem::bCheckMinMax(CMatrix& cMatrix, CMatrix& cMinMax)
{
    for (int i = 0; i<cMatrix.iGetRows(); i++) {
        for (int j = 0; j<cMatrix.iGetCols(); j++) {

            if (cMatrix(i, j)<cMinMax(i, 2*j) || cMatrix(i, j)>cMinMax(i, 2*j+1)) {
                return false;
            }
        }
    }
    return true;
}

bool CMscnProblem::bTechCheck(CSolution& cSolution)
{
    if (&cSolution==NULL) {
        return false;
    }

    if (cSolution.i_d!=i_d ||
            cSolution.i_f!=i_f ||
            cSolution.i_m!=i_m ||
            cSolution.i_s!=i_s) {
        return false;
    }

    if (!cSolution.c_xd.bAllPositive() ||
            !cSolution.c_xf.bAllPositive() ||
            !cSolution.c_xm.bAllPositive()) {
        return false;
    }

    return true;
}

bool CMscnProblem::bTechCheck(std::vector<double>& vSolution)
{
    if (&vSolution==NULL) return false;
    if (vSolution.size()!=getSize()) return false;
    if (!vAllPositive(vSolution)) return false;

    return true;
}

bool CMscnProblem::vAllPositive(std::vector<double> vSolution)
{
    for (int i = 0; i<vSolution.size(); i++) {
        if (vSolution[i]<0) return false;
    }
    return true;
}

bool CMscnProblem::bConstraintsSatisfied(CSolution& cSolution, bool& pb_succ)
{
    if (!bTechCheck(cSolution)) return false;
    pb_succ = true;
    return b_constraints_satisfied(cSolution);
}

bool CMscnProblem::b_constraints_satisfied(CSolution& c_solution)
{
    if (!b_minmax_satisfied(c_solution)) {
        return false;
    }

    for (int d = 0; d<i_d; d++) {
        if (c_solution.c_xd.dRowSum(d)>c_sd(d)) {
            return false;
        }
    }

    for (int f = 0; f<i_f; f++) {
        if (c_solution.c_xf.dRowSum(f)>c_sf(f)) {
            return false;
        }
    }

    for (int m = 0; m<i_m; m++) {
        if (c_solution.c_xm.dRowSum(m)>c_sm(m)) {
            return false;
        }
    }

    for (int s = 0; s<i_s; s++) {
        if (c_solution.c_xm.dColSum(s)>c_ss(s)) {
            return false;
        }
    }

    for (int f = 0; f<i_f; f++) {
        if (c_solution.c_xd.dColSum(f)<c_solution.c_xf.dRowSum(f)) {
            return false;
        }

    }

    for (int m = 0; m<i_m; m++) {
        if (c_solution.c_xf.dColSum(m)<c_solution.c_xm.dRowSum(m)) {
            return false;
        }

    }
    return true;
}

bool CMscnProblem::bLoad(std::string sFilename)
{
    if (sFilename.empty()) return false;

    std::string s_ignore;
    std::ifstream f_file(sFilename);
    if (!f_file.good()) return false;

    f_file >> s_ignore;
    f_file >> i_d;
    f_file >> s_ignore;
    f_file >> i_f;
    f_file >> s_ignore;
    f_file >> i_m;
    f_file >> s_ignore;
    f_file >> i_s;

    f_file >> s_ignore;
    c_sd.bLoadFromStream(f_file, i_d);
    f_file >> s_ignore;
    c_sf.bLoadFromStream(f_file, i_f);
    f_file >> s_ignore;
    c_sm.bLoadFromStream(f_file, i_m);
    f_file >> s_ignore;
    c_ss.bLoadFromStream(f_file, i_s);
    f_file >> s_ignore;
    c_cd.bLoadFromStream(f_file, i_d, i_f);
    f_file >> s_ignore;
    c_cf.bLoadFromStream(f_file, i_f, i_m);
    f_file >> s_ignore;
    c_cm.bLoadFromStream(f_file, i_m, i_s);
    f_file >> s_ignore;
    c_ud.bLoadFromStream(f_file, i_d);
    f_file >> s_ignore;
    c_uf.bLoadFromStream(f_file, i_f);
    f_file >> s_ignore;
    c_um.bLoadFromStream(f_file, i_m);
    f_file >> s_ignore;
    c_p.bLoadFromStream(f_file, i_s);

    f_file >> s_ignore;
    c_xdminmax.bLoadFromStream(f_file, i_d, 2*i_f);
    f_file >> s_ignore;
    c_xfminmax.bLoadFromStream(f_file, i_f, 2*i_m);
    f_file >> s_ignore;
    c_xmminmax.bLoadFromStream(f_file, i_m, 2*i_s);

    if (f_file.fail()) return false;
    return true;
}

bool CMscnProblem::bSave(std::string sFilename)
{
    if (sFilename.empty()) return false;
    std::ofstream f_file(sFilename);
    if (!f_file.good()) return false;

    f_file << "D " << i_d << std::endl;
    f_file << "F " << i_f << std::endl;
    f_file << "M " << i_m << std::endl;
    f_file << "S " << i_s << std::endl;

    f_file << "sd " << c_sd.sToString();
    f_file << "sf " << c_sf.sToString();
    f_file << "sm " << c_sm.sToString();
    f_file << "ss " << c_ss.sToString();

    f_file << "cd " << std::endl << c_cd.sToString();
    f_file << "cf " << std::endl << c_cf.sToString();
    f_file << "cm " << std::endl << c_cm.sToString();

    f_file << "ud " << c_ud.sToString();
    f_file << "uf " << c_uf.sToString();
    f_file << "um " << c_um.sToString();

    f_file << "p " << c_p.sToString();

    f_file << "xdminmax " << std::endl << c_xdminmax.sToString();
    f_file << "xfminmax " << std::endl << c_xfminmax.sToString();
    f_file << "xmminmax " << std::endl << c_xmminmax.sToString();

    if (f_file.fail()) return false;
    return true;
}

double CMscnProblem::getMin(int iIndex)
{
    if (iIndex>i_d*i_f+i_f*i_m+i_m*i_s) return 0;
    if (iIndex<i_d*i_f) {
        return c_xdminmax(iIndex/i_f, 2*(iIndex%i_f));
    }
    else if (iIndex<i_d*i_f+i_f*i_m) {
        int i_local_index = iIndex-i_d*i_f;
        return c_xfminmax(i_local_index/i_m, 2*(i_local_index%i_m));
    }
    else if (iIndex<i_d*i_f+i_f*i_m+i_m*i_s) {
        int i_local_index = iIndex-i_d*i_f-i_f*i_m;
        return c_xmminmax(i_local_index/i_s, 2*(i_local_index%i_s));
    }
}

double CMscnProblem::getMax(int iIndex)
{
    if (iIndex>i_d*i_f+i_f*i_m+i_m*i_s) return 0;
    if (iIndex<i_d*i_f) {
        return c_xdminmax(iIndex/i_f, 2*(iIndex%i_f)+1);
    }
    else if (iIndex<i_d*i_f+i_f*i_m) {
        int i_local_index = iIndex-i_d*i_f;
        return c_xfminmax(i_local_index/i_m, 2*(i_local_index%i_m)+1);
    }
    else if (iIndex<i_d*i_f+i_f*i_m+i_m*i_s) {
        int i_local_index = iIndex-i_d*i_f-i_f*i_m;
        return c_xmminmax(i_local_index/i_s, 2*(i_local_index%i_s)+1);
    }
}
void CMscnProblem::vGenerateInstance(int iInstanceSeed, int iD, int iF, int iM, int iS)
{
    bSetD(iD);
    bSetF(iF);
    bSetM(iM);
    bSetS(iS);

    CRandom c_random(iInstanceSeed);

    c_cd.vFillRandom(c_random, I_C_MIN, I_C_MAX);
    c_cf.vFillRandom(c_random, I_C_MIN, I_C_MAX);
    c_cm.vFillRandom(c_random, I_C_MIN, I_C_MAX);
    c_ud.vFillRandom(c_random, I_U_MIN, I_U_MAX);
    c_uf.vFillRandom(c_random, I_U_MIN, I_U_MAX);
    c_um.vFillRandom(c_random, I_U_MIN, I_U_MAX);
    c_sd.vFillRandom(c_random, I_S_MIN, I_S_MAX);
    c_sf.vFillRandom(c_random, I_S_MIN, I_S_MAX);
    c_sm.vFillRandom(c_random, I_S_MIN, I_S_MAX);
    c_ss.vFillRandom(c_random, I_S_MIN, I_S_MAX);
    c_p.vFillRandom(c_random, I_P_MIN, I_P_MAX);

    v_random_minmax(c_xdminmax, c_random, c_sd);
    v_random_minmax(c_xfminmax, c_random, c_sf);
    v_random_minmax(c_xmminmax, c_random, c_sm);

}

void CMscnProblem::v_random_minmax(CMatrix& cMatrix, CRandom& cRandom, CMatrix& cSBound)
{
    for (int i = 0; i<cMatrix.iGetRows(); i++) {
        for (int j = 0; j<cMatrix.iGetCols(); j = j+2) {
            cMatrix(i, j) = 0; //cRandom.dGetDouble(0, I_MIN);
            cMatrix(i, j+1) = cSBound(i)*D_MAX_VAL_RATIO/cSBound.iGetCols(); //cRandom.dGetDouble(cMatrix(i, j), I_MAX);
        }
    }
}

int CMscnProblem::iGetD() const
{
    return i_d;
}

int CMscnProblem::iGetF() const
{
    return i_f;
}

int CMscnProblem::iGetM() const
{
    return i_m;
}

int CMscnProblem::iGetS() const
{
    return i_s;
}

double CMscnProblem::d_get_min(CMatrix& c_minmax, int i_row, int i_col)
{
    return c_minmax(i_row, 2*i_col);
}
double CMscnProblem::d_get_max(CMatrix& c_minmax, int i_row, int i_col)
{
    return c_minmax(i_row, 2*i_col+1);
}

double CMscnProblem::dGetXDMin(int iRow, int iCol)
{
    return d_get_min(c_xdminmax, iRow, iCol);
}
double CMscnProblem::dGetXDMax(int iRow, int iCol)
{
    return d_get_max(c_xdminmax, iRow, iCol);
}
double CMscnProblem::dGetXFMin(int iRow, int iCol)
{
    return d_get_min(c_xfminmax, iRow, iCol);
}
double CMscnProblem::dGetXFMax(int iRow, int iCol)
{
    return d_get_max(c_xfminmax, iRow, iCol);
}
double CMscnProblem::dGetXMMin(int iRow, int iCol)
{
    return d_get_min(c_xmminmax, iRow, iCol);
}
double CMscnProblem::dGetXMMax(int iRow, int iCol)
{
    return d_get_max(c_xmminmax, iRow, iCol);
}

CMatrix& CMscnProblem::cGetXDminmax()
{
    return c_xdminmax;
}
CMatrix& CMscnProblem::cGetXFminmax()
{
    return c_xfminmax;
}
CMatrix& CMscnProblem::cGetXMminmax()
{
    return c_xmminmax;
}

double CMscnProblem::dGetQuality(std::vector<double>& vSolution, bool& bSucc)
{

    if (!bTechCheck(vSolution)) {
        bSucc = false;
        return false;
    }
    bSucc = true;
    CSolution c_solution(i_d, i_f, i_m, i_s);
    c_solution.bLoadFromVector(vSolution);
    v_repair_solution(c_solution);
    vSolution = c_solution.c_vector;
    return d_get_quality(c_solution);
}
bool CMscnProblem::bConstraintsSatisfied(std::vector<double>& vSolution, bool& bSucc)
{
    if (!bTechCheck(vSolution)) {
        bSucc = false;
        return false;
    }
    bSucc = true;
    CSolution c_solution(i_d, i_f, i_m, i_s);
    c_solution.bLoadFromVector(vSolution);
    return b_constraints_satisfied(c_solution);
}

void CMscnProblem::v_repair_solution(CSolution& c_solution)
{

    if (!b_constraints_satisfied(c_solution)) {

        for (int d = 0; d<i_d; d++) {
            if (c_solution.c_xd.dRowSum(d)>c_sd(d)) {
                v_reduce_row(c_solution.c_xd, d, (c_sd(d))/(1+c_solution.c_xd.dRowSum(d)));

            }
        }

        for (int f = 0; f<i_f; f++) {
            if (c_solution.c_xf.dRowSum(f)>c_sf(f)) {
                v_reduce_row(c_solution.c_xf, f, (c_sf(f))/(1+c_solution.c_xf.dRowSum(f)));

            }
        }

        for (int m = 0; m<i_m; m++) {
            if (c_solution.c_xm.dRowSum(m)>c_sm(m)) {
                v_reduce_row(c_solution.c_xm, m, (c_sm(m))/(1+c_solution.c_xm.dRowSum(m)));

            }
        }

        for (int s = 0; s<i_s; s++) {
            if (c_solution.c_xm.dColSum(s)>c_ss(s)) {
                v_reduce_col(c_solution.c_xm, s, (c_ss(s))/(1+c_solution.c_xm.dColSum(s)));

            }
        }

        for (int f = 0; f<i_f; f++) {
            if (c_solution.c_xf.dRowSum(f)>c_solution.c_xd.dColSum(f)) {
                v_reduce_row(c_solution.c_xf, f, (c_solution.c_xd.dColSum(f))/(1.0+c_solution.c_xf.dRowSum(f)));

            }
        }

        for (int m = 0; m<i_m; m++) {
            if (c_solution.c_xm.dRowSum(m)>c_solution.c_xf.dColSum(m)) {
                v_reduce_row(c_solution.c_xm, m, (c_solution.c_xf.dColSum(m))/(1.0+c_solution.c_xm.dRowSum(m)));

            }
        }

    }

    c_solution.vCalcVector();

}

void CMscnProblem::v_reduce_row(CMatrix& c_matrix, int i_row, double i_value)
{
    double div_val = c_matrix.dRowSum(i_row);
    for (int i = 0; i<c_matrix.iGetCols(); i++) {
        c_matrix(i_row, i) *= i_value;
    }
}

void CMscnProblem::v_reduce_col(CMatrix& c_matrix, int i_col, double i_value)
{
    for (int i = 0; i<c_matrix.iGetRows(); i++) {
        c_matrix(i, i_col) *= i_value;
    }
}

int CMscnProblem::getSize()
{
    return i_d*i_f+i_f*i_m+i_m*i_s;
}


