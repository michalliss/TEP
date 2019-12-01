#include <iostream>
#include "CMySmartPointer.h"

int main() {


  CMySmartPointer<int> pInt(new int);

  *pInt = 4;

  CMySmartPointer<int> p2(new int);

  p2 = pInt;

  std::cout << *p2 << std::endl;


}