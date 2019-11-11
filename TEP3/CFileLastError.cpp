//
// Created by legusie on 11/8/19.
//

#include <cstdio>
#include "CFileLastError.h"

bool CFileLastError::b_last_error = false;

CFileLastError::CFileLastError() : pf_file(NULL) {

}

CFileLastError::CFileLastError(std::string sFileName) : pf_file(NULL) {
  pf_file = std::fopen(sFileName.c_str(), "w+");
  b_last_error = pf_file==NULL ? true : false;
}

CFileLastError::~CFileLastError() {
  vCloseFile();
}

bool CFileLastError::bGetLastError() {
  return b_last_error;
}

void CFileLastError::vOpenFile(std::string sFileName) {
  b_last_error = false;
  if (pf_file==NULL) {
    pf_file = std::fopen(sFileName.c_str(), "w+");
    b_last_error = pf_file==NULL ? true : false;
  } else {
    b_last_error = true;
  }
}

void CFileLastError::vCloseFile() {
  b_last_error = false;
  if (pf_file==NULL) {
    std::fclose(pf_file);
    pf_file==NULL;
  } else {
    b_last_error = true;
  }
}

void CFileLastError::vPrintLine(std::string sText) {
  b_last_error = false;
  if (pf_file!=NULL) {
    std::fprintf(pf_file, sText.c_str());
  } else {
    b_last_error = true;
  }
}
void CFileLastError::vPrintManyLines(std::vector<std::string> sText) {
  b_last_error = false;
  bool b_error_flag = false;

  if (pf_file!=NULL) {
    for (int i = 0; i < sText.size(); i++) {
      vPrintLine(sText[i]);
      if(b_last_error == true)  b_error_flag = true;
    }
    b_last_error = b_error_flag;
  } else {
    b_last_error = true;
  }

}


