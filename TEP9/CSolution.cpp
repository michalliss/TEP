//
// Created by przydasie on 12/14/19.
//

#include "CSolution.h"
bool CSolution::bLoad(std::string sFilename) {
  if (sFilename=="") return false;
  std::string s_ignore;
  std::ifstream f_file(sFilename);
  if (!f_file.good()) return false;
  int i_d;
  int i_f;
  int i_m;
  int i_s;
  f_file >> s_ignore;
  f_file >> i_d;
  f_file >> s_ignore;
  f_file >> i_f;
  f_file >> s_ignore;
  f_file >> i_m;
  f_file >> s_ignore;
  f_file >> i_s;

  f_file >> s_ignore;
  c_xd.bLoadFromStream(f_file, i_d, i_f);
  f_file >> s_ignore;
  c_xf.bLoadFromStream(f_file, i_f, i_m);
  f_file >> s_ignore;
  c_xm.bLoadFromStream(f_file, i_m, i_s);
  if (!f_file.good()) return false;
  return true;
}

bool CSolution::bFromArray(double *pdSolution, int iD, int iF, int iM, int iS) {
  return c_xd.bLoadFromArray(pdSolution, iD, iF, 0) &&
      c_xf.bLoadFromArray(pdSolution, iF, iM, iD*iF) &&
      c_xm.bLoadFromArray(pdSolution, iM, iS, iD*iF + iF*iM);
}
