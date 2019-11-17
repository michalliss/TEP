//
// Created by przydasie on 11/16/19.
//

#ifndef TEP5__CTREEDYNAMIC_H_
#define TEP5__CTREEDYNAMIC_H_

#include <iostream>
#include <vector>
class CTreeDynamic {
  class CNodeDynamic {
   public:
    CNodeDynamic() {
      i_val = 0;
      pc_parent_node = NULL;
    };
    CNodeDynamic(const CNodeDynamic &cNode);
    ~CNodeDynamic();

    CNodeDynamic &operator=(const CNodeDynamic &cNode);
    bool operator==(const CNodeDynamic &rhs) const;
    bool operator!=(const CNodeDynamic &rhs) const;

    void vSetValue(int iNewVal) { i_val = iNewVal; };
    int iGetChildrenNumber() { return (v_children.size()); };
    void vAddNewChild();
    void vAddNewChild(CNodeDynamic *c_new_child);
    CNodeDynamic *pcGetChild(int iChildOffset);
    void vPrint() { std::cout << " " << i_val << "(" << pc_parent_node << ")"; };
    void vPrintAllBelow();
    void vPrintUp();
    void vPrintNice();
    CNodeDynamic *pcGetRoot();
    CNodeDynamic *pcUnpin();
   private:
    void vPrintNice(CNodeDynamic &node, int depth);
    std::vector<CNodeDynamic *> v_children;
    CNodeDynamic *pc_parent_node = NULL;
    int i_val;

  };

 public:
  CTreeDynamic();
  ~CTreeDynamic();
  CNodeDynamic *pcGetRoot() { return (pc_root); }
  void vPrintTree();
  void vPrintNice();
  bool bMoveSubtree(CNodeDynamic *pcParentNode, CNodeDynamic *pcNewChildNode);
 private:
  CNodeDynamic *pc_root;

};

#endif //TEP5__CTREEDYNAMIC_H_
