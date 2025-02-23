//
// Created by przydasie on 12/15/19.
//

#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include "Utils.h"
bool Utils::bLoadSolution(std::string sFilename, double *pdSolution) {
  if (sFilename=="") return false;
  std::ifstream f_file(sFilename);
  if(!f_file.good()) return false;
  std::string s_ignore;
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


  int i_index = 0;

  for (int i = 0; i < i_d*i_f; i++) {
    f_file >> pdSolution[i_index];
    i_index++;
  }

  f_file >> s_ignore;

  for (int i = 0; i < i_f*i_m; i++) {
    f_file >> pdSolution[i_index];
    i_index++;
  }

  f_file >> s_ignore;

  for (int i = 0; i < i_m*i_s; i++) {
    f_file >> pdSolution[i_index];
    i_index++;
  }

  if (f_file.fail()) return false;
  return true;
}

bool Utils::bLoadSolution2(std::string sFilename, double *pdSolution) {
  if (sFilename=="") return false;
  std::ifstream f_file(sFilename);
  if(!f_file.good()) return false;
  std::string s_ignore;
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


  int i_index = 0;
  std::string s_current;
  for (int i = 0; i < i_d*i_f; i++) {
    getline(f_file, s_current, ';');
    std::stringstream ss(s_current);
    ss >> pdSolution[i_index];
    if(ss.fail()) return 0;
    i_index++;
  }

  f_file >> s_ignore;

  for (int i = 0; i < i_f*i_m; i++) {
    getline(f_file, s_current, ';');
    std::stringstream ss(s_current);
    ss >> pdSolution[i_index];
    if(ss.fail()) return 0;
    i_index++;
  }

  f_file >> s_ignore;

  for (int i = 0; i < i_m*i_s; i++) {
    getline(f_file, s_current, ';');
    std::stringstream ss(s_current);
    ss >> pdSolution[i_index];
    if(ss.fail()) return 0;
    i_index++;
  }

  if (f_file.fail()) return false;
  return true;
}




int Utils::iGetSolutionLength(std::string sFilename) {
  std::ifstream f_file(sFilename);
  std::string s_ignore;
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

  return i_d*i_f + i_f*i_m + i_m*i_s;
}
