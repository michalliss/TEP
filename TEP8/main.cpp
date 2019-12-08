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


int main() {

    CTable c_tab_0, c_tab_1, c_tab_3, c_tab_4;
    c_tab_0.bSetNewSize(I_TEST_SIZE_4);
    c_tab_1.bSetNewSize(I_TEST_SIZE_5);
    for (int ii = 0; ii < c_tab_0.iGetSize(); ii++) {
        c_tab_0.bSetVal(ii, ii + I_TEST_OFFSET);
    }


    for (int ii = 0; ii < c_tab_1.iGetSize(); ii++) {
        c_tab_1.bSetVal(ii, ii + I_TEST_OFFSET_1);
    }

    c_tab_0.vShow();
    c_tab_1.vShow();

    c_tab_3 = c_tab_0 + c_tab_1;
    c_tab_3.vShow();

    c_tab_0 = c_tab_1;

    c_tab_1.bSetVal(I_TEST_OFFSET_2, I_TEST_VALUE_3);
    
    c_tab_0.vShow();
    c_tab_1.vShow();

    std::cout << "LIVE--------------------------------------------------------------" << std::endl;
    c_tab_0.vShow();
    c_tab_0/=I_TEST_DIVIDE_VAL;
    c_tab_0.vShow();

    c_tab_3.vShow();
    c_tab_4 = c_tab_3/=I_TEST_DIVIDE_VAL;
    c_tab_4.vShow();
}