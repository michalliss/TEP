//
// Created by przydasie on 11/16/19.
//

#ifndef TEP5__CTREEDYNAMIC_H_
#define TEP5__CTREEDYNAMIC_H_

#include <iostream>
#include <vector>
#include <algorithm>

template<typename T>
class CTreeDynamic;

template<typename T>
class CNodeDynamic {
 public:
  CNodeDynamic() {
    t_val = T();
    pc_parent_node = NULL;
  };
  CNodeDynamic(const CNodeDynamic &cNode);
  ~CNodeDynamic();

  CNodeDynamic &operator=(const CNodeDynamic &cNode);
  bool operator==(const CNodeDynamic &rhs) const;
  bool operator!=(const CNodeDynamic &rhs) const;

  void vSetValue(T tNewVal) { t_val = tNewVal; };
  int iGetChildrenNumber() { return (v_children.size()); };
  void vAddNewChild();
  CNodeDynamic<T> *pcGetChild(int iChildOffset);
  void vPrint() { std::cout << " " << t_val << "(" << pc_parent_node << ")"; };
  void vPrintAllBelow();
  void vPrintUp();
  void vPrintNice();
  CNodeDynamic<T> *pcGetRoot();
  int iLeafNumber();

 private:
  std::vector<CNodeDynamic<T> *> v_children;
  CNodeDynamic<T> *pc_parent_node;
  T t_val;

  void vAddNewChild(CNodeDynamic *c_new_child);
  CNodeDynamic<T> *pcUnpin();
  void vPrintNice(CNodeDynamic &node, int depth);

  friend class CTreeDynamic<T>;
};

template<typename T>
class CTreeDynamic {
 public:
  CTreeDynamic();
  ~CTreeDynamic();
  CNodeDynamic<T> *pcGetRoot() { return (pc_root); }
  void vPrintTree();
  void vPrintNice();
  bool bMoveSubtree(CNodeDynamic<T> *pcParentNode, CNodeDynamic<T> *pcNewChildNode);
 private:
  CNodeDynamic<T> *pc_root;

};

#include "CTreeDynamic.tpp"

#endif //TEP5__CTREEDYNAMIC_H_
