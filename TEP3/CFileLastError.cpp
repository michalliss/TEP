//
// Created by legusie on 11/8/19.
//

#include <cstdio>
#include "CFileLastError.h"

bool CFileLastError::b_last_error = false;

CFileLastError::CFileLastError() : pf_file(NULL) {

}

CFileLastError::CFileLastError(std::string sFileName) : pf_file(NULL) {
  vOpenFile(sFileName);
}

CFileLastError::~CFileLastError() {
  if (pf_file!=NULL) {
    vCloseFile();
  }
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
  if (pf_file!=NULL) {
    std::fclose(pf_file);
    pf_file = NULL;
  } else {
    b_last_error = true;
  }
}

void CFileLastError::vPrintLine(std::string sText) {
  b_last_error = false;
  if (pf_file!=NULL) {
    std::fprintf(pf_file, (sText + S_NEWLINE).c_str());
  } else {
    b_last_error = true;
  }
}
void CFileLastError::vPrintManyLines(std::vector<std::string> sText) {
  b_last_error = false;

  for (int i = 0; i < sText.size() and !b_last_error; i++) {
    vPrintLine(sText[i]);
  }
}




