//
// Created by przydasie on 11/16/19.
//

#ifndef TEP5__CTREESTATIC_H_
#define TEP5__CTREESTATIC_H_

#include <iostream>
#include <vector>
#include <algorithm>

class CTreeStatic {

 public:
  class CNodeStatic {
    friend class CTreeStatic;

   public:
    CNodeStatic() {
      i_val = 0;
      pc_parent_node = NULL;
    };
    ~CNodeStatic();
    CNodeStatic(const CNodeStatic &cNode);

    CNodeStatic &operator=(const CNodeStatic &cNode);
    bool operator==(const CNodeStatic &rhs) const;
    bool operator!=(const CNodeStatic &rhs) const;

    void vSetValue(int iNewVal) { i_val = iNewVal; };
    int iGetChildrenNumber() { return (v_children.size()); };
    void vAddNewChild();
    CNodeStatic *pcGetChild(int iChildOffset);
    void vPrint() { std::cout << " " << i_val << "(" << pc_parent_node << ")"; };
    void vPrintAllBelow();
    void vPrintUp();
    void vPrintNice();
    CNodeStatic *pcGetRoot();

   private:
    std::vector<CNodeStatic> v_children;
    CNodeStatic *pc_parent_node;
    int i_val;
    CNodeStatic cUnpin();
    void vAddNewChild(CNodeStatic cNewChild);
    void vPrintNice(CNodeStatic &node, int depth);
  };

  CTreeStatic();
  ~CTreeStatic();
  CNodeStatic *pcGetRoot() { return (&c_root); }
  void vPrintNice();
  void vPrintTree();
  bool bMoveSubtree(CNodeStatic *pcParentNode, CNodeStatic *pcNewChildNode);

 private:
  CNodeStatic c_root;

};

#endif //TEP5__CTREESTATIC_H_



