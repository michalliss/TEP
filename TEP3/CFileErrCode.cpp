//
// Created by legusie on 11/8/19.
//


#include "CFileErrCode.h"

CFileErrCode::CFileErrCode() : pf_file(NULL) {

}
CFileErrCode::CFileErrCode(std::string sFileName, bool &pbSucc) : pf_file(NULL) {
  pbSucc = bOpenFile(sFileName);
}
CFileErrCode::~CFileErrCode() {
  if (pf_file!=NULL) {
    bCloseFile();
  }
}
bool CFileErrCode::bOpenFile(std::string sFileName) {
  if (pf_file!=NULL) return true;

  pf_file = std::fopen(sFileName.c_str(), "w+");
  if (pf_file==NULL) return true;
  else return false;
}
bool CFileErrCode::bCloseFile() {
  if (pf_file==NULL) return true;

  std::fclose(pf_file);
  pf_file = NULL;
  return false;
}
bool CFileErrCode::bPrintLine(std::string sText) {
  if (pf_file==NULL) return true;

  std::fprintf(pf_file, (sText + S_NEWLINE).c_str());
  return false;
}
bool CFileErrCode::bPrintManyLines(std::vector<std::string> sText) {
  if (pf_file==NULL) return true;

  bool b_err_flag = false;
  for (int i = 0; i < sText.size() and !b_err_flag; i++) {
    b_err_flag = bPrintLine(sText[i]);
  }
  return b_err_flag;
}
