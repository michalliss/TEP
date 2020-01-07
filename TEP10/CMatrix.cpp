//
// Created by przydasie on 12/14/19.
//

#include "CMatrix.h"
#include "CRandom.h"

CMatrix::CMatrix() {
  i_row = I_DEFAULT_MATRIX_SIZE;
  i_col = I_DEFAULT_MATRIX_SIZE;
  pd_tab = pd_alloc_tab(i_row, i_col);
}

CMatrix::CMatrix(int iRow, int iCol) : i_row(iRow), i_col(iCol) {
  pd_tab = pd_alloc_tab(i_row, i_col);
}

CMatrix::CMatrix(const CMatrix &pcOther) : i_row(pcOther.i_row), i_col(pcOther.i_col) {
  pd_tab = pd_alloc_tab(i_row, i_col);
  for (int i = 0; i < i_row; i++) {
    std::copy(pcOther.pd_tab[i], pcOther.pd_tab[i] + i_col, pd_tab[i]);
  }
}

void CMatrix::operator=(const CMatrix &pcOther) {
  if (&pcOther == this) return;
  i_row = pcOther.i_row;
  i_col = pcOther.i_col;
  pd_tab = pd_alloc_tab(i_row, i_col);
  for (int i = 0; i < i_row; i++) {
    std::copy(pcOther.pd_tab[i], pcOther.pd_tab[i] + i_col, pd_tab[i]);
  }
}

CMatrix::~CMatrix() {
  if (pd_tab != NULL) removeTab();
}

double &CMatrix::operator()(int iRow, int iCol) {
  return pd_tab[iRow][iCol];
}

double &CMatrix::operator()(int iIndex) {
  return pd_tab[0][iIndex];
}

void CMatrix::removeTab() {
  for (int i = 0; i < i_row; i++) {
    delete[] pd_tab[i];
  }
  delete[] pd_tab;
}

bool CMatrix::bResize(int iNewRow, int iNewCol) {
  double **pd_new_tab = pd_alloc_tab(iNewRow, iNewCol);
  int i_min_row = i_row < iNewRow ? i_row : iNewRow;
  int i_min_col = i_col < iNewCol ? i_col : iNewCol;

  for (int i = 0; i < i_min_row; i++) {
    std::copy(pd_tab[i], pd_tab[i] + i_min_col, pd_new_tab[i]);
  }

  removeTab();
  i_row = iNewRow;
  i_col = iNewCol;
  pd_tab = pd_new_tab;
  return true;
}

double **CMatrix::pd_alloc_tab(int i_row, int i_col) {
  double **pd_tab = new double *[i_row];
  for (int i = 0; i < i_row; i++) {
    pd_tab[i] = new double[i_col];
  }
  return pd_tab;
}

bool CMatrix::bLoadFromStream(std::ifstream &sStream, int iRow, int iCol) {
  if (iRow < 0 || iCol < 0 || !sStream.good()) return false;
  bResize(iRow, iCol);
  for (int i = 0; i < iRow; i++) {
    for (int j = 0; j < iCol; j++) {
      sStream >> pd_tab[i][j];
    }
  }
  return true;
}

bool CMatrix::bLoadFromStream(std::ifstream &sStream, int iCol) {
  return bLoadFromStream(sStream, 1, iCol);
}

bool CMatrix::bLoadFromArray(double *pdArray, int iRow, int iCol, int iIndex) {
  if (iRow < 0 || iCol < 0) return false;

  bResize(iRow, iCol);
  for (int i = 0; i < i_row; i++) {
    for (int j = 0; j < i_col; j++) {
      pd_tab[i][j] = pdArray[iIndex];
      iIndex++;
    }
  }
  return true;
}

void CMatrix::vPushToVector(std::vector<double> &cVector) {
  for (int i = 0; i < i_row; i++) {
    for (int j = 0; j < i_col; j++) {
      cVector.push_back(pd_tab[i][j]);
    }
  }
}

bool CMatrix::bCheckBounds(int iRow, int iCol) {
  if (iRow < 0 || iRow >= i_row) return false;
  if (iCol < 0 || iCol >= i_col) return false;
  return true;
}

bool CMatrix::bCheckBounds(int iCol) {
  return bCheckBounds(0, iCol);
}

bool CMatrix::bAllPositive() {
  for (int i = 0; i < i_row; i++) {
    for (int j = 0; j < i_col; j++) {
      if (pd_tab[i][j] < 0) return false;
    }
  }
  return true;
}

void CMatrix::vFillRandom(CRandom &cRandom, int iFrom, int iTo) {
  for (int i = 0; i < i_row; i++) {
    for (int j = 0; j < i_col; j++) {
      pd_tab[i][j] = cRandom.dGetDouble(iFrom, iTo);
    }
  }

}

double CMatrix::dRowSum(int iRow) {
  double d_res = 0;
  for (int i = 0; i < i_col; i++) {
    d_res += pd_tab[iRow][i];
  }
  return d_res;
}
double CMatrix::dColSum(int iCol) {
  double d_res = 0;
  for (int i = 0; i < i_row; i++) {
    d_res += pd_tab[i][iCol];
  }
  return d_res;
}

int CMatrix::iGetRows() const {
  return i_row;
}

int CMatrix::iGetCols() const {
  return i_col;
}

std::string CMatrix::sToString() {
  std::stringstream s_output;
  for (int i = 0; i < i_row; i++) {
    for (int j = 0; j < i_col; j++) {
      s_output << pd_tab[i][j] << " ";
    }
    s_output << std::endl;
  }
  return s_output.str();
}



