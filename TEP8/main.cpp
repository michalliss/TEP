#include <iostream>
#include "ctable.h"
#include "constants.h"

void v_mod_tab(CTable *pcTab, int iNewSize) {
    pcTab->bSetNewSize(iNewSize);
}

void v_mod_tab(CTable cTab, int iNewSize) {
    cTab.bSetNewSize(iNewSize);
}

void v_print_table(CTable &pcTab) {
    for (int ii = 0; ii < pcTab.iGetSize(); ii++) {
        std::cout << pcTab.iGetVal(ii);
    }
    std::cout << std::endl;
}

void v_fill_table(CTable &pcTab) {
    for (int ii = 0; ii < pcTab.iGetSize(); ii++) {
        pcTab.bSetVal(ii, ii + 1);
    }
}


void v_lista_2_test_run() {
    CTable c_test_table;

    CTable c_test_param(S_TEST_NAME, I_TEST_SIZE);
    c_test_param.bSetVal(I_TEST_POS, I_TEST_VALUE);

    CTable c_test_kopia(c_test_param);
    c_test_kopia.bSetVal(I_TEST_POS_1, I_TEST_VALUE_2);

    CTable *c_clone;
    c_clone = c_test_kopia.pcClone();


    v_print_table(c_test_table);
    v_print_table(c_test_param);
    v_print_table(c_test_kopia);
    v_print_table(*c_clone);

    c_test_kopia.bSetNewSize(I_TEST_SIZE_3);
    v_print_table(c_test_kopia);

    v_mod_tab(c_test_table, I_TEST_SIZE_2);
    v_print_table(c_test_table);

    v_mod_tab(&c_test_table, I_TEST_SIZE_2);
    v_print_table(c_test_table);

    std::cout << "-----------------LIVE----------------------" << std::endl;

    v_fill_table(c_test_table);
    c_test_table.vShow();

    c_test_table.pcGetPairSumsTable().vShow();

    std::cout << "-----------------LIVE----------------------" << std::endl;

    delete c_clone;
}


void test_move(){
  CTable c_tab1("tab1", 4);
  CTable c_tab2("tab2", 4);
  CTable c_tab3("tab3", 4);

  c_tab3 = c_tab1 + c_tab2;
  c_tab3 = c_tab3 + c_tab3;
  c_tab3 = c_tab3 + c_tab3;

  std::cout << "copy: " << CTable::i_copy_counter << std::endl << "move: " << CTable::i_move_counter << std::endl;
}


int main() {
  test_move();
}