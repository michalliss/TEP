#include <iostream>
#include "CTreeStatic.h"
#include "CTreeDynamic.h"
#include "constants.h"


bool b_from_same_tree(CTreeDynamic::CNodeDynamic &node1, CTreeDynamic::CNodeDynamic &node2){
  return node1.pcGetRoot() == node2.pcGetRoot();
}

bool b_from_same_tree(CTreeStatic::CNodeStatic &node1, CTreeStatic::CNodeStatic &node2){
  return node1.pcGetRoot() == node2.pcGetRoot();
}


void v_tree_test() {

  CTreeStatic c_tree, c_tree2;
  c_tree.pcGetRoot()->vAddNewChild();
  c_tree.pcGetRoot()->vAddNewChild();
  c_tree.pcGetRoot()->pcGetChild(0)->vSetValue(I_VAL_0);
  c_tree.pcGetRoot()->pcGetChild(1)->vSetValue(I_VAL_1);
  c_tree.pcGetRoot()->pcGetChild(0)->vAddNewChild();
  c_tree.pcGetRoot()->pcGetChild(0)->vAddNewChild();
  c_tree.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vSetValue(I_VAL_11);
  c_tree.pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vSetValue(I_VAL_12);
  c_tree.pcGetRoot()->pcGetChild(1)->vAddNewChild();
  c_tree.pcGetRoot()->pcGetChild(1)->vAddNewChild();
  c_tree.pcGetRoot()->pcGetChild(1)->pcGetChild(0)->vSetValue(I_VAL_21);
  c_tree.pcGetRoot()->pcGetChild(1)->pcGetChild(1)->vSetValue(I_VAL_22);

  c_tree2.pcGetRoot()->vAddNewChild();
  c_tree2.pcGetRoot()->vAddNewChild();
  c_tree2.pcGetRoot()->pcGetChild(0)->vSetValue(I_VAL_3);
  c_tree2.pcGetRoot()->pcGetChild(1)->vSetValue(I_VAL_4);
  c_tree2.pcGetRoot()->pcGetChild(0)->vAddNewChild();
  c_tree2.pcGetRoot()->pcGetChild(0)->vAddNewChild();
  c_tree2.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vSetValue(I_VAL_31);
  c_tree2.pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vSetValue(I_VAL_32);
  c_tree2.pcGetRoot()->pcGetChild(1)->vAddNewChild();
  c_tree2.pcGetRoot()->pcGetChild(1)->vAddNewChild();
  c_tree2.pcGetRoot()->pcGetChild(1)->pcGetChild(0)->vSetValue(I_VAL_41);
  c_tree2.pcGetRoot()->pcGetChild(1)->pcGetChild(1)->vSetValue(I_VAL_42);

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
  c_tree.pcGetRoot()->pcGetChild(0)->vSetValue(I_VAL_0);
  c_tree.pcGetRoot()->pcGetChild(1)->vSetValue(I_VAL_1);
  c_tree.pcGetRoot()->pcGetChild(0)->vAddNewChild();
  c_tree.pcGetRoot()->pcGetChild(0)->vAddNewChild();
  c_tree.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vSetValue(I_VAL_11);
  c_tree.pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vSetValue(I_VAL_12);
  c_tree.pcGetRoot()->pcGetChild(1)->vAddNewChild();
  c_tree.pcGetRoot()->pcGetChild(1)->vAddNewChild();
  c_tree.pcGetRoot()->pcGetChild(1)->pcGetChild(0)->vSetValue(I_VAL_21);
  c_tree.pcGetRoot()->pcGetChild(1)->pcGetChild(1)->vSetValue(I_VAL_22);

  c_tree2.pcGetRoot()->vAddNewChild();
  c_tree2.pcGetRoot()->vAddNewChild();
  c_tree2.pcGetRoot()->pcGetChild(0)->vSetValue(I_VAL_3);
  c_tree2.pcGetRoot()->pcGetChild(1)->vSetValue(I_VAL_4);
  c_tree2.pcGetRoot()->pcGetChild(0)->vAddNewChild();
  c_tree2.pcGetRoot()->pcGetChild(0)->vAddNewChild();
  c_tree2.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vSetValue(I_VAL_31);
  c_tree2.pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vSetValue(I_VAL_32);
  c_tree2.pcGetRoot()->pcGetChild(1)->vAddNewChild();
  c_tree2.pcGetRoot()->pcGetChild(1)->vAddNewChild();
  c_tree2.pcGetRoot()->pcGetChild(1)->pcGetChild(0)->vSetValue(I_VAL_41);
  c_tree2.pcGetRoot()->pcGetChild(1)->pcGetChild(1)->vSetValue(I_VAL_42);

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


  std::cout << b_from_same_tree(*c_tree.pcGetRoot(), *c_tree.pcGetRoot()->pcGetChild(0)) << std::endl;
  std::cout << b_from_same_tree(*c_tree.pcGetRoot(), *c_tree2.pcGetRoot()->pcGetChild(0));
}

int main() {
  v_tree_test();
  std::cout << "-------------------" << std::endl;
  v_tree_test2();
}