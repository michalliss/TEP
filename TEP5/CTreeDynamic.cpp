//
// Created by przydasie on 11/16/19.
//

#include "CTreeDynamic.h"


CTreeDynamic::CNodeDynamic::CNodeDynamic(const CTreeDynamic::CNodeDynamic &cNode)
    : i_val(cNode.i_val), pc_parent_node(cNode.pc_parent_node), v_children(cNode.v_children) {
  std::cout << "k";
  for (int i = 0; i < cNode.v_children.size(); i++) {
    this->v_children[i]->pc_parent_node = this;
  }

}
CTreeDynamic::CNodeDynamic::~CNodeDynamic() {
  for (int i = 0; i < v_children.size(); i++) {
    delete v_children[i];
  }
}

CTreeDynamic::CNodeDynamic &CTreeDynamic::CNodeDynamic::operator=(const CTreeDynamic::CNodeDynamic &cNode) {
  this->pc_parent_node = cNode.pc_parent_node;
  this->i_val = cNode.i_val;
  this->v_children = cNode.v_children;

  for (int i = 0; i < cNode.v_children.size(); i++) {
    this->v_children[i]->pc_parent_node = this;
  }
  return *this;
}
bool CTreeDynamic::CNodeDynamic::operator==(const CTreeDynamic::CNodeDynamic &rhs) const {
  return v_children==rhs.v_children &&
      pc_parent_node==rhs.pc_parent_node &&
      i_val==rhs.i_val;
}
bool CTreeDynamic::CNodeDynamic::operator!=(const CTreeDynamic::CNodeDynamic &rhs) const {
  return !(rhs==*this);
}

void CTreeDynamic::CNodeDynamic::vAddNewChild() {
  v_children.push_back(new CNodeDynamic());
  v_children[v_children.size() - 1]->pc_parent_node = this;

}

void CTreeDynamic::CNodeDynamic::vAddNewChild(CTreeDynamic::CNodeDynamic *c_new_child) {
  this->v_children.push_back(c_new_child);
  this->v_children[v_children.size() - 1]->pc_parent_node = this;
}

CTreeDynamic::CNodeDynamic *CTreeDynamic::CNodeDynamic::pcUnpin() {
  if (this->pc_parent_node==NULL) return NULL;
  std::vector<CNodeDynamic *> &v_nodes = this->pc_parent_node->v_children;
  std::vector<CNodeDynamic *>::iterator it_pos;
  it_pos = std::find(v_nodes.begin(), v_nodes.end(), this);
  v_nodes.erase(it_pos);
  return this;
}

CTreeDynamic::CNodeDynamic *CTreeDynamic::CNodeDynamic::pcGetRoot() {
  if (pc_parent_node==NULL) return this;
  else return pc_parent_node->pcGetRoot();
}

CTreeDynamic::CNodeDynamic *CTreeDynamic::CNodeDynamic::pcGetChild(int iChildOffset) {
  if (iChildOffset >= 0 && iChildOffset < v_children.size()) {
    return v_children[iChildOffset];
  } else return NULL;
}

void CTreeDynamic::CNodeDynamic::vPrintAllBelow() {
  this->vPrint();
  for (int i = 0; i < v_children.size(); i++) {
    v_children[i]->vPrintAllBelow();
  }
}
void CTreeDynamic::CNodeDynamic::vPrintUp() {
  this->vPrint();
  if (pc_parent_node!=NULL) {
    pc_parent_node->vPrintUp();
  }
}
void CTreeDynamic::CNodeDynamic::vPrintNice(CTreeDynamic::CNodeDynamic &node, int depth) {
  for (int i = 0; i < depth; i++) std::cout << "    ";
  node.vPrint();
  std::cout << std::endl;
  for (int i = 0; i < node.v_children.size(); i++) {
    vPrintNice(*node.v_children[i], depth + 1);
  }
}
void CTreeDynamic::CNodeDynamic::vPrintNice() {
  vPrintNice(*this, 0);
}

bool CTreeDynamic::bMoveSubtree(CTreeDynamic::CNodeDynamic *pcParentNode, CTreeDynamic::CNodeDynamic *pcNewChildNode) {
  if (pcParentNode->pcGetRoot()==pcNewChildNode->pcGetRoot()) return false;
  pcParentNode->vAddNewChild(pcNewChildNode->pcUnpin());
  return true;
}

CTreeDynamic::CTreeDynamic() {
  this->pc_root = new CNodeDynamic();
}
CTreeDynamic::~CTreeDynamic() {
  delete pc_root;
}
void CTreeDynamic::vPrintTree() {
  this->pc_root->vPrintAllBelow();
}

void CTreeDynamic::vPrintNice() {
  this->pc_root->vPrintNice();
}
