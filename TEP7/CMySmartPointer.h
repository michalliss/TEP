//
// Created by przydasie on 11/30/19.
//

#ifndef TEP7__CMYSMARTPOINTER_H_
#define TEP7__CMYSMARTPOINTER_H_
#include "CRefCounter.h"
template<typename T>
class CMySmartPointer {
 public:
  CMySmartPointer(T *pcPointer) {
    pc_pointer = pcPointer;
    pc_counter = new CRefCounter();
    pc_counter->iAdd();
  }
  CMySmartPointer(const CMySmartPointer<T> &pcOther) {
    pc_pointer = pcOther.pc_pointer;
    pc_counter = pcOther.pc_counter;
    pc_counter->iAdd();
  }
  ~CMySmartPointer() {
    if (pc_counter->iDec()==0) {
      delete pc_pointer;
      delete pc_counter;
    }//if (pc_counter->iDec())
  }
  T &operator*() { return (*pc_pointer); }
  T *operator->() { return (pc_pointer); }
  void operator=(const CMySmartPointer<T> &pcOther) {
    if (pc_counter->iDec()==0) {
      delete pc_pointer;
      delete pc_counter;
    }

    pc_pointer = pcOther.pc_pointer;
    pc_counter = pcOther.pc_counter;
    pc_counter->iAdd();
  }
 private:
  CRefCounter *pc_counter;
  T *pc_pointer;
};

#endif //TEP7__CMYSMARTPOINTER_H_
