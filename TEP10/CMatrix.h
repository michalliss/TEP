//
// Created by przydasie on 12/14/19.
//

#ifndef TEP9__CMATRIX_H_
#define TEP9__CMATRIX_H_
#define I_DEFAULT_MATRIX_SIZE 1
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "CRandom.h"

class CMatrix {
private:
    double** pd_tab;
    int i_row;
    int i_col;
    double** pd_alloc_tab(int i_row, int i_col);
    void removeTab();

public:
    CMatrix();
    CMatrix(const CMatrix& pcOther);
    CMatrix(int i_row, int i_col);
    virtual ~CMatrix();

    double& operator()(int x, int y);
    double& operator()(int index);
    void operator=(const CMatrix& pcOther);

    bool bResize(int i_row, int i_col);
    bool bCheckBounds(int iRow, int iCol);
    bool bCheckBounds(int iCol);
    bool bAllPositive();
    void vFillRandom(CRandom& cRandom, int iFrom, int iTo);

    int iGetRows() const;
    int iGetCols() const;
    double dRowSum(int iRow);
    double dColSum(int iCol);

    bool bLoadFromStream(std::ifstream& sStream, int iRow, int iCol);
    bool bLoadFromStream(std::ifstream& sStream, int iCol);
    bool bLoadFromArray(double* pdArray, int iRow, int iCol, int iIndex);
    void vPushToVector(std::vector<double>& cVector);

    std::string sToString();

};

#endif //TEP9__CMATRIX_H_
