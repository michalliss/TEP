#include <iostream>
#include "CMySmartPointer.h"
#include "constants.h"
int main() {
  CMySmartPointer<int> pInt(new int);
  *pInt = I_VAL_0;
  CMySmartPointer<int> p2(new int);
  p2 = pInt;
  std::cout << *p2 << std::endl;


  CMySmartPointer<std::string> pString(new std::string(S_VAL_0));
  CMySmartPointer<std::string> pString2(new std::string);
  pString2 = pString.cDuplicate();
  std::cout << *pString2;
}