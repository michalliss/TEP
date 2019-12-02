//
// Created by przydasie on 11/16/19.
//

#include "CTreeDynamic.h"

template<typename T>
CNodeDynamic<T>::CNodeDynamic(const CNodeDynamic<T> &cNode)
    : t_val(cNode.t_val), pc_parent_node(cNode.pc_parent_node), v_children(cNode.v_children) {
  std::cout << "k";
  for (int i = 0; i < cNode.v_children.size(); i++) {
    this->v_children[i]->pc_parent_node = this;
  }

}

template<typename T>
CNodeDynamic<T>::~CNodeDynamic() {
  for (int i = 0; i < v_children.size(); i++) {
    delete v_children[i];
  }
}

template<typename T>
CNodeDynamic<T> &CNodeDynamic<T>::operator=(const CNodeDynamic<T> &cNode) {
  this->pc_parent_node = cNode.pc_parent_node;
  this->t_val = cNode.t_val;
  this->v_children = cNode.v_children;

  for (int i = 0; i < cNode.v_children.size(); i++) {
    this->v_children[i]->pc_parent_node = this;
  }
  return *this;
}

template<typename T>
bool CNodeDynamic<T>::operator==(const CNodeDynamic<T> &rhs) const {
  return v_children == rhs.v_children &&
      pc_parent_node == rhs.pc_parent_node &&
      t_val == rhs.t_val;
}

template<typename T>
bool CNodeDynamic<T>::operator!=(const CNodeDynamic<T> &rhs) const {
  return !(rhs == *this);
}

template<typename T>
void CNodeDynamic<T>::vAddNewChild() {
  v_children.push_back(new CNodeDynamic());
  v_children[v_children.size() - 1]->pc_parent_node = this;

}

template<typename T>
void CNodeDynamic<T>::vAddNewChild(CNodeDynamic<T> *c_new_child) {
  this->v_children.push_back(c_new_child);
  this->v_children[v_children.size() - 1]->pc_parent_node = this;
}

template<typename T>
CNodeDynamic<T> *CNodeDynamic<T>::pcUnpin() {
  if (this->pc_parent_node == NULL) return this;
  std::vector<CNodeDynamic<T> *> &v_nodes = this->pc_parent_node->v_children;
  typename std::vector<CNodeDynamic<T> *>::iterator it_pos;
  it_pos = std::find(v_nodes.begin(), v_nodes.end(), this);
  v_nodes.erase(it_pos);
  return this;
}

template<typename T>
CNodeDynamic<T> *CNodeDynamic<T>::pcGetRoot() {
  if (pc_parent_node == NULL) return this;
  else return pc_parent_node->pcGetRoot();
}

template<typename T>
CNodeDynamic<T> *CNodeDynamic<T>::pcGetChild(int iChildOffset) {
  if (iChildOffset >= 0 && iChildOffset < v_children.size()) {
    return v_children[iChildOffset];
  } else return NULL;
}

template<typename T>
void CNodeDynamic<T>::vPrintAllBelow() {
  this->vPrint();
  for (int i = 0; i < v_children.size(); i++) {
    v_children[i]->vPrintAllBelow();
  }
}

template<typename T>
void CNodeDynamic<T>::vPrintUp() {
  this->vPrint();
  if (pc_parent_node != NULL) {
    pc_parent_node->vPrintUp();
  }
}

template<typename T>
void CNodeDynamic<T>::vPrintNice(CNodeDynamic<T> &node, int depth) {
  for (int i = 0; i < depth; i++) std::cout << "    ";
  node.vPrint();
  std::cout << std::endl;
  for (int i = 0; i < node.v_children.size(); i++) {
    vPrintNice(*node.v_children[i], depth + 1);
  }
}

template<typename T>
void CNodeDynamic<T>::vPrintNice() {
  vPrintNice(*this, 0);
}

template<typename T>
int CNodeDynamic<T>::iLeafNumber() {
  if (v_children.empty()) return 1;
  int i_sum = 0;
  for (int i = 0; i < v_children.size(); i++) {
    i_sum += v_children[i]->iLeafNumber();
  }
  return i_sum;
}

template<typename T>
bool CTreeDynamic<T>::bMoveSubtree(CNodeDynamic<T> *pcParentNode, CNodeDynamic<T> *pcNewChildNode) {
  if (pcParentNode->pcGetRoot() == pcNewChildNode->pcGetRoot()) return false;
  pcParentNode->vAddNewChild(pcNewChildNode->pcUnpin());
  return true;
}

template<typename T>
CTreeDynamic<T>::CTreeDynamic() {
  this->pc_root = new CNodeDynamic<T>();
}

template<typename T>
CTreeDynamic<T>::~CTreeDynamic() {
  delete pc_root;
}

template<typename T>
void CTreeDynamic<T>::vPrintTree() {
  this->pc_root->vPrintAllBelow();
}

template<typename T>
void CTreeDynamic<T>::vPrintNice() {
  this->pc_root->vPrintNice();
}

