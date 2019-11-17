#include <iostream>
#include "CTreeStatic.h"
#include "CTreeDynamic.h"



void v_tree_test() {

  CTreeStatic c_tree, c_tree2;
  c_tree.pcGetRoot()->vAddNewChild();
  c_tree.pcGetRoot()->vAddNewChild();
  c_tree.pcGetRoot()->pcGetChild(0)->vSetValue(1);
  c_tree.pcGetRoot()->pcGetChild(1)->vSetValue(2);
  c_tree.pcGetRoot()->pcGetChild(0)->vAddNewChild();
  c_tree.pcGetRoot()->pcGetChild(0)->vAddNewChild();
  c_tree.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vSetValue(11);
  c_tree.pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vSetValue(12);
  c_tree.pcGetRoot()->pcGetChild(1)->vAddNewChild();
  c_tree.pcGetRoot()->pcGetChild(1)->vAddNewChild();
  c_tree.pcGetRoot()->pcGetChild(1)->pcGetChild(0)->vSetValue(21);
  c_tree.pcGetRoot()->pcGetChild(1)->pcGetChild(1)->vSetValue(22);

  c_tree2.pcGetRoot()->vAddNewChild();
  c_tree2.pcGetRoot()->vAddNewChild();
  c_tree2.pcGetRoot()->pcGetChild(0)->vSetValue(3);
  c_tree2.pcGetRoot()->pcGetChild(1)->vSetValue(4);
  c_tree2.pcGetRoot()->pcGetChild(0)->vAddNewChild();
  c_tree2.pcGetRoot()->pcGetChild(0)->vAddNewChild();
  c_tree2.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vSetValue(31);
  c_tree2.pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vSetValue(32);
  c_tree2.pcGetRoot()->pcGetChild(1)->vAddNewChild();
  c_tree2.pcGetRoot()->pcGetChild(1)->vAddNewChild();
  c_tree2.pcGetRoot()->pcGetChild(1)->pcGetChild(0)->vSetValue(41);
  c_tree2.pcGetRoot()->pcGetChild(1)->pcGetChild(1)->vSetValue(42);

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

void v_tree_test2() {
  CTreeDynamic c_tree;

  CTreeDynamic c_tree2;

  c_tree.pcGetRoot()->vAddNewChild();
  c_tree.pcGetRoot()->vAddNewChild();
  c_tree.pcGetRoot()->pcGetChild(0)->vSetValue(1);
  c_tree.pcGetRoot()->pcGetChild(1)->vSetValue(2);
  c_tree.pcGetRoot()->pcGetChild(0)->vAddNewChild();
  c_tree.pcGetRoot()->pcGetChild(0)->vAddNewChild();
  c_tree.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vSetValue(11);
  c_tree.pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vSetValue(12);
  c_tree.pcGetRoot()->pcGetChild(1)->vAddNewChild();
  c_tree.pcGetRoot()->pcGetChild(1)->vAddNewChild();
  c_tree.pcGetRoot()->pcGetChild(1)->pcGetChild(0)->vSetValue(21);
  c_tree.pcGetRoot()->pcGetChild(1)->pcGetChild(1)->vSetValue(22);

  c_tree2.pcGetRoot()->vAddNewChild();
  c_tree2.pcGetRoot()->vAddNewChild();
  c_tree2.pcGetRoot()->pcGetChild(0)->vSetValue(3);
  c_tree2.pcGetRoot()->pcGetChild(1)->vSetValue(4);
  c_tree2.pcGetRoot()->pcGetChild(0)->vAddNewChild();
  c_tree2.pcGetRoot()->pcGetChild(0)->vAddNewChild();
  c_tree2.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vSetValue(31);
  c_tree2.pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vSetValue(32);
  c_tree2.pcGetRoot()->pcGetChild(1)->vAddNewChild();
  c_tree2.pcGetRoot()->pcGetChild(1)->vAddNewChild();
  c_tree2.pcGetRoot()->pcGetChild(1)->pcGetChild(0)->vSetValue(41);
  c_tree2.pcGetRoot()->pcGetChild(1)->pcGetChild(1)->vSetValue(42);

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

int main() {
  v_tree_test();
  std::cout << "-------------------" << std::endl;
  v_tree_test2();
}