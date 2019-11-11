//
// Created by legusie on 11/8/19.
//

#ifndef TEP3_CFILEERRCODE_H
#define TEP3_CFILEERRCODE_H
#include <string>
#include <vector>

class CFileErrCode {
 public:
  CFileErrCode();
  CFileErrCode(std::string sFileName, bool &pbSucc);
  ~CFileErrCode();
  bool bOpenFile(std::string sFileName);
  bool bCloseFile();
  bool bPrintLine(std::string sText);
  bool bPrintManyLines(std::vector<std::string> sText);
 private:
  FILE *pf_file;
};

#endif //TEP3_CFILEERRCODE_H
