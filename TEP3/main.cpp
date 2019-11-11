#include <iostream>
#include "CFileErrCode.h"
#include "CFileLastError.h"
#include "CFileThrowEx.h"
void v_open_test(){
  CFileLastError c_file1;
  for(int i = 0; i < 10; i++){
    c_file1.vOpenFile("asdf.txt");
  }

  std::cout << c_file1.bGetLastError();
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}