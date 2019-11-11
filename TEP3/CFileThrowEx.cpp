//
// Created by legusie on 11/8/19.
//

#include <cstdio>
#include "CFileThrowEx.h"

CFileThrowEx::CFileThrowEx() : pf_file(NULL) {}
CFileThrowEx::CFileThrowEx(std::string sFileName) : pf_file(NULL) {
  vOpenFile(sFileName);
}
CFileThrowEx::~CFileThrowEx() {
  if(pf_file != NULL){
    vCloseFile();
  }
}
void CFileThrowEx::vOpenFile(std::string sFileName) {
  if (pf_file==NULL) {
    pf_file = std::fopen(sFileName.c_str(), "w+");
    if (pf_file==NULL) throw 1;
  } else throw 1;
}
void CFileThrowEx::vCloseFile() {
  if (pf_file!=NULL) {
    std::fclose(pf_file);
    pf_file = NULL;
  } else throw 1;

}
void CFileThrowEx::vPrintLine(std::string sText) {
  if (pf_file!=NULL) {
    std::fprintf(pf_file, sText.c_str());
  } else throw 1;
}
void CFileThrowEx::vPrintManyLines(std::vector<std::string> sText) {
  if (pf_file!=NULL) {
    for (int i = 0; i < sText.size(); i++) {
      vPrintLine(sText[i]);
    }
  } else throw 2;
}
