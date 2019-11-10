#include <iostream>
#include "CTable.h"

void v_mod_tab(CTable *pcTab, int iNewSize){
    pcTab->bSetNewSize(iNewSize);
}
void v_mod_tab(CTable cTab, int iNewSize){
    cTab.bSetNewSize(iNewSize);
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}