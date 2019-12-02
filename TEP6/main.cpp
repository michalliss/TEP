#include <iostream>
#include "constants.h"
#include "CTreeDynamic.h"

void v_tree_test2() {
  CTreeDynamic<int> c_tree;
  CTreeDynamic<int> c_tree2;

  c_tree.pcGetRoot()->vAddNewChild();
  c_tree.pcGetRoot()->vAddNewChild();
  c_tree.pcGetRoot()->pcGetChild(0)->vSetValue(I_VAL_0);
  c_tree.pcGetRoot()->pcGetChild(1)->vSetValue(I_VAL_1);
  c_tree.pcGetRoot()->pcGetChild(0)->vAddNewChild();
  c_tree.pcGetRoot()->pcGetChild(0)->vAddNewChild();
  c_tree.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vSetValue(I_VAL_2);
  c_tree.pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vSetValue(I_VAL_3);
  c_tree.pcGetRoot()->pcGetChild(1)->vAddNewChild();
  c_tree.pcGetRoot()->pcGetChild(1)->vAddNewChild();
  c_tree.pcGetRoot()->pcGetChild(1)->pcGetChild(0)->vSetValue(I_VAL_4);
  c_tree.pcGetRoot()->pcGetChild(1)->pcGetChild(1)->vSetValue(I_VAL_5);

  c_tree2.pcGetRoot()->vAddNewChild();
  c_tree2.pcGetRoot()->vAddNewChild();
  c_tree2.pcGetRoot()->pcGetChild(0)->vSetValue(I_VAL_6);
  c_tree2.pcGetRoot()->pcGetChild(1)->vSetValue(I_VAL_7);
  c_tree2.pcGetRoot()->pcGetChild(0)->vAddNewChild();
  c_tree2.pcGetRoot()->pcGetChild(0)->vAddNewChild();
  c_tree2.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vSetValue(I_VAL_8);
  c_tree2.pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vSetValue(I_VAL_9);
  c_tree2.pcGetRoot()->pcGetChild(1)->vAddNewChild();
  c_tree2.pcGetRoot()->pcGetChild(1)->vAddNewChild();
  c_tree2.pcGetRoot()->pcGetChild(1)->pcGetChild(0)->vSetValue(I_VAL_10);
  c_tree2.pcGetRoot()->pcGetChild(1)->pcGetChild(1)->vSetValue(I_VAL_11);

  c_tree.vPrintNice();

  std::cout << std::endl;

  c_tree.pcGetRoot()->pcGetChild(1)->pcGetChild(1)->vPrintUp();
  std::cout << std::endl;
  std::cout << std::endl;
  std::cout << std::endl;

  c_tree2.vPrintNice();

  c_tree.bMoveSubtree(c_tree.pcGetRoot()->pcGetChild(1), c_tree2.pcGetRoot()->pcGetChild(1));
  c_tree.vPrintNice();
  std::cout << std::endl;

  c_tree2.vPrintNice();
}

void v_tree_test() {
  CTreeDynamic<double> c_tree;
  CTreeDynamic<double> c_tree2;

  c_tree.pcGetRoot()->vAddNewChild();
  c_tree.pcGetRoot()->vAddNewChild();
  c_tree.pcGetRoot()->pcGetChild(0)->vSetValue(D_VAL_0);
  c_tree.pcGetRoot()->pcGetChild(1)->vSetValue(I_VAL_1);
  c_tree.pcGetRoot()->pcGetChild(0)->vAddNewChild();
  c_tree.pcGetRoot()->pcGetChild(0)->vAddNewChild();
  c_tree.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vSetValue(I_VAL_2);
  c_tree.pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vSetValue(I_VAL_3);
  c_tree.pcGetRoot()->pcGetChild(1)->vAddNewChild();
  c_tree.pcGetRoot()->pcGetChild(1)->vAddNewChild();
  c_tree.pcGetRoot()->pcGetChild(1)->pcGetChild(0)->vSetValue(I_VAL_4);
  c_tree.pcGetRoot()->pcGetChild(1)->pcGetChild(1)->vSetValue(I_VAL_5);

  c_tree2.pcGetRoot()->vAddNewChild();
  c_tree2.pcGetRoot()->vAddNewChild();
  c_tree2.pcGetRoot()->pcGetChild(0)->vSetValue(I_VAL_6);
  c_tree2.pcGetRoot()->pcGetChild(1)->vSetValue(I_VAL_7);
  c_tree2.pcGetRoot()->pcGetChild(0)->vAddNewChild();
  c_tree2.pcGetRoot()->pcGetChild(0)->vAddNewChild();
  c_tree2.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vSetValue(I_VAL_8);
  c_tree2.pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vSetValue(I_VAL_9);
  c_tree2.pcGetRoot()->pcGetChild(1)->vAddNewChild();
  c_tree2.pcGetRoot()->pcGetChild(1)->vAddNewChild();
  c_tree2.pcGetRoot()->pcGetChild(1)->pcGetChild(0)->vSetValue(I_VAL_10);
  c_tree2.pcGetRoot()->pcGetChild(1)->pcGetChild(1)->vSetValue(I_VAL_11);

  c_tree.vPrintNice();

  std::cout << std::endl;

  c_tree.pcGetRoot()->pcGetChild(1)->pcGetChild(1)->vPrintUp();
  std::cout << std::endl;
  std::cout << std::endl;
  std::cout << std::endl;

  c_tree2.vPrintNice();

  c_tree.bMoveSubtree(c_tree.pcGetRoot()->pcGetChild(1), c_tree2.pcGetRoot()->pcGetChild(1));
  c_tree.vPrintNice();
  std::cout << std::endl;

  c_tree2.vPrintNice();
}


void v_tree_test3() {
  CTreeDynamic<std::string> c_tree;

  CTreeDynamic<std::string> c_tree2;

  c_tree.pcGetRoot()->vAddNewChild();
  c_tree.pcGetRoot()->vAddNewChild();
  c_tree.pcGetRoot()->pcGetChild(0)->vSetValue(S_NAME_0);
  c_tree.pcGetRoot()->pcGetChild(1)->vSetValue(S_NAME_1);
  c_tree.pcGetRoot()->pcGetChild(0)->vAddNewChild();
  c_tree.pcGetRoot()->pcGetChild(0)->vAddNewChild();
  c_tree.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vSetValue(S_NAME_2);
  c_tree.pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vSetValue(S_NAME_3);
  c_tree.pcGetRoot()->pcGetChild(1)->vAddNewChild();
  c_tree.pcGetRoot()->pcGetChild(1)->vAddNewChild();
  c_tree.pcGetRoot()->pcGetChild(1)->pcGetChild(0)->vSetValue(S_NAME_4);
  c_tree.pcGetRoot()->pcGetChild(1)->pcGetChild(1)->vSetValue(S_NAME_5);

  c_tree2.pcGetRoot()->vAddNewChild();
  c_tree2.pcGetRoot()->vAddNewChild();
  c_tree2.pcGetRoot()->pcGetChild(0)->vSetValue(S_NAME_6);
  c_tree2.pcGetRoot()->pcGetChild(1)->vSetValue(S_NAME_7);
  c_tree2.pcGetRoot()->pcGetChild(0)->vAddNewChild();
  c_tree2.pcGetRoot()->pcGetChild(0)->vAddNewChild();
  c_tree2.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vSetValue(S_NAME_8);
  c_tree2.pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vSetValue(S_NAME_9);
  c_tree2.pcGetRoot()->pcGetChild(1)->vAddNewChild();
  c_tree2.pcGetRoot()->pcGetChild(1)->vAddNewChild();
  c_tree2.pcGetRoot()->pcGetChild(1)->pcGetChild(0)->vSetValue(S_NAME_10);
  c_tree2.pcGetRoot()->pcGetChild(1)->pcGetChild(1)->vSetValue(S_NAME_11);

  c_tree.vPrintNice();

  std::cout << std::endl;

  c_tree.pcGetRoot()->pcGetChild(1)->pcGetChild(1)->vPrintUp();
  std::cout << std::endl;
  std::cout << std::endl;
  std::cout << std::endl;

  c_tree2.vPrintNice();

  c_tree.bMoveSubtree(c_tree.pcGetRoot()->pcGetChild(1), c_tree2.pcGetRoot()->pcGetChild(1));
  c_tree.vPrintNice();
  std::cout << std::endl;

  c_tree2.vPrintNice();

  std::cout << "Liczba liści drzewo 1: " << c_tree.pcGetRoot()->iLeafNumber() << std::endl;
  std::cout << "Liczba liści drzewo 2: " << c_tree2.pcGetRoot()->iLeafNumber();
}

int main() {
  v_tree_test();
  std::cout << "-------------------" << std::endl;
  v_tree_test2();
  std::cout << "-------------------" << std::endl;
  v_tree_test3();
}