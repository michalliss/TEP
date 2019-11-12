#include <iostream>
#include "CFileErrCode.h"
#include "CFileLastError.h"
#include "CFileThrowEx.h"
#include "constants.h";

void v_open_test() {
  CFileLastError c_file1;
  for (int i = 0; i < 10; i++) {
    c_file1.vOpenFile(S_FILE_1);
    c_file1.vPrintLine(S_TEXT);
  }
  std::cout << c_file1.bGetLastError() << std::endl;


  CFileThrowEx c_file2;
  try {
    for (int i = 0; i < 10; i++) {
     c_file2.vOpenFile(S_FILE_2);
     c_file2.vPrintLine(S_TEXT);
     c_file2.vCloseFile();
    }
  } catch (int e) {
    std::cout << S_ERR_MESSAGE;
  }


  bool b_err;
  bool b_err_2;
  CFileErrCode c_file3(S_FILE_3, b_err);
  for (int i = 0; i < 10; i++) {
    b_err_2 = c_file3.bPrintLine(S_TEXT);
  }
  std::cout << b_err << " " << b_err_2;
}

int main() {
  v_open_test();
}