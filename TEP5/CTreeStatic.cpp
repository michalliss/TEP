//
// Created by przydasie on 11/16/19.
//

#include "CTreeStatic.h"


CTreeStatic::CNodeStatic::CNodeStatic(const CTreeStatic::CNodeStatic &cNode)
    : i_val(cNode.i_val), pc_parent_node(cNode.pc_parent_node), v_children(cNode.v_children) {

  for (int i = 0; i < cNode.v_children.size(); i++) {
    this->v_children[i].pc_parent_node = this;
  }
}

CTreeStatic::CNodeStatic::~CNodeStatic() {}

CTreeStatic::CNodeStatic &CTreeStatic::CNodeStatic::operator=(const CTreeStatic::CNodeStatic &cNode) {
  this->pc_parent_node = cNode.pc_parent_node;
  this->i_val = cNode.i_val;
  this->v_children = cNode.v_children;

  for (int i = 0; i < cNode.v_children.size(); i++) {
    this->v_children[i].pc_parent_node = this;
  }
  return *this;
}
bool CTreeStatic::CNodeStatic::operator==(const CTreeStatic::CNodeStatic &rhs) const {
  return v_children==rhs.v_children &&
      pc_parent_node==rhs.pc_parent_node &&
      i_val==rhs.i_val;
}
bool CTreeStatic::CNodeStatic::operator!=(const CTreeStatic::CNodeStatic &rhs) const {
  return !(rhs==*this);
}

void CTreeStatic::CNodeStatic::vAddNewChild() {
  v_children.push_back(CNodeStatic());
  v_children[v_children.size() - 1].pc_parent_node = this;
}

void CTreeStatic::CNodeStatic::vAddNewChild(CTreeStatic::CNodeStatic cNewChild) {
  v_children.push_back(cNewChild);
  v_children[v_children.size() - 1].pc_parent_node = this;
}

CTreeStatic::CNodeStatic CTreeStatic::CNodeStatic::cUnpin() {
  if(this->pc_parent_node == NULL) return CNodeStatic();
  std::vector<CNodeStatic> &v_nodes = this->pc_parent_node->v_children;
  std::vector<CNodeStatic>::iterator it_pos;
  it_pos = std::find(v_nodes.begin(), v_nodes.end(), *this);
  CNodeStatic c_temp = *this;
  v_nodes.erase(it_pos);
  return c_temp;
}

void CTreeStatic::CNodeStatic::vPrintAllBelow() {
  this->vPrint();
  for (int i = 0; i < v_children.size(); i++) {
    v_children[i].vPrintAllBelow();
  }
}

void CTreeStatic::CNodeStatic::vPrintUp() {
  this->vPrint();
  if (pc_parent_node!=NULL) {
    pc_parent_node->vPrintUp();
  }
}

void CTreeStatic::CNodeStatic::vPrintNice() {
  vPrintNice(*this, 0);
}

void CTreeStatic::CNodeStatic::vPrintNice(CTreeStatic::CNodeStatic &node, int depth) {
  for (int i = 0; i < depth; i++) std::cout << "    ";
  node.vPrint();
  std::cout << std::endl;
  for (int i = 0; i < node.v_children.size(); i++) {
    vPrintNice(node.v_children[i], depth + 1);
  }
}

CTreeStatic::CNodeStatic *CTreeStatic::CNodeStatic::pcGetChild(int iChildOffset) {
  if (iChildOffset >= 0 && iChildOffset < v_children.size()) {
    return &v_children[iChildOffset];
  } else return NULL;
}
CTreeStatic::CNodeStatic *CTreeStatic::CNodeStatic::pcGetRoot() {
  if(pc_parent_node == NULL) return this;
  else return pc_parent_node->pcGetRoot();
}

CTreeStatic::CTreeStatic(){
}
CTreeStatic::~CTreeStatic() {

}
void CTreeStatic::vPrintTree() {
  c_root.vPrintAllBelow();
}

bool CTreeStatic::bMoveSubtree(CTreeStatic::CNodeStatic *pcParentNode, CTreeStatic::CNodeStatic *pcNewChildNode) {
  if(pcParentNode->pcGetRoot() == pcNewChildNode->pcGetRoot()) return false;
  pcParentNode->vAddNewChild(pcNewChildNode->cUnpin());
  return true;
}
void CTreeStatic::vPrintNice() {
  this->c_root.vPrintNice();
}
