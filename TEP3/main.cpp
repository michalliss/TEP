#include <iostream>
#include "CFileErrCode.h"
#include "CFileLastError.h"
#include "CFileThrowEx.h"
void v_open_test() {
  CFileLastError c_file1;
  for (int i = 0; i < 10; i++) {
    c_file1.vOpenFile("asdf1.txt");
    c_file1.vPrintLine("asdf");
  }

  std::cout << c_file1.bGetLastError();

  CFileThrowEx c_file2;
  try {
    for (int i = 0; i < 10; i++) {
     c_file2.vOpenFile("asdf2.txt");
     c_file2.vPrintLine("asdf");
     c_file2.vCloseFile();
    }
  } catch (int e) {
    std::cout << "error";
  }

  bool b_err;
  CFileErrCode c_file3("asdf3.txt", b_err);

  for (int i = 0; i < 10; i++) {
    c_file3.bPrintLine("33");
  }

  std::cout << b_err;


}

int main() {
  v_open_test();
}