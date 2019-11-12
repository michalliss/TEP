//
// Created by legusie on 11/8/19.
//

#ifndef TEP3_CFILETHROWEX_H
#define TEP3_CFILETHROWEX_H

#define S_NEWLINE "\n"
#define EX_ERR_OPEN_FILE 1

#include <vector>
#include <bits/types/FILE.h>
#include <string>
#include <cstdio>

class CFileThrowEx{

 public:
  CFileThrowEx();
  CFileThrowEx(std::string sFileName);
  ~CFileThrowEx();
  void vOpenFile(std::string sFileName);
  void vCloseFile();
  void vPrintLine(std::string sText);
  void vPrintManyLines(std::vector<std::string> sText);
 private:
  FILE *pf_file;

};

#endif //TEP3_CFILETHROWEX_H
