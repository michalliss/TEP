#include <iostream>
#include "constants.h"


void v_alloc_table_add5(int *&piTab, int iSize) {
    if (iSize >= 0) {
        piTab = new int[iSize];

        for (int ii = 0; ii < iSize; ii++) {
            piTab[ii] = ii + ADD_VALUE;
        }
    }
}

void v_print_1d_int_table(int *&piTab, int iSize) {
    if (iSize >= 0) {
        for (int ii = 0; ii < iSize; ii++) {
            std::cout << piTab[ii] << " ";
        }
    }
    std::cout << std::endl;
}

bool b_alloc_table_2_dim(int ***piTable, int iSizeX, int iSizeY) {
    if (iSizeX >= 0 && iSizeY >= 0) {
        *piTable = new int *[iSizeX];
        for (int ii = 0; ii < iSizeX; ii++) {
            (*piTable)[ii] = new int[iSizeY];
        }
        return true;
    } else return false;
}

bool b_dealloc_table_2_dim(int ***piTable, int iSizeX) {
    if (iSizeX >= 0) {
        for (int ii = 0; ii < iSizeX; ii++) {
            delete[] (*piTable)[ii];
        }
        delete[] *piTable;
        return true;
    } else return false;
}

void v_print_2d_int_table(int **&piTab, int iSizeX, int iSizeY) {
    if (iSizeX >= 0 && iSizeY >= 0) {
        for (int ii = 0; ii < iSizeX; ii++) {
            for (int jj = 0; jj < iSizeY; jj++) {
                std::cout << piTab[ii][jj] << " ";
            }
            std::cout << std::endl;
        }
    }
}

bool b_show_table_2_dim(int **&piTab, int iSizeX, int iSizeY) {
    if (iSizeX >= 0 && iSizeY >= 0) {
        for (int ii = 0; ii < iSizeX; ii++) {
            for (int jj = 0; jj < iSizeY; jj++) {
                std::cout << piTab[ii][jj] << "; ";
            }
            std::cout << std::endl;
        }
        return true;
    } else return false;
}

bool b_fill_increasing_table_2_dim(int **&piTab, int iSizeX, int iSizeY) {
    if (iSizeX >= 0 && iSizeY >= 0) {
        int i_counter = 0;
        for (int ii = 0; ii < iSizeX; ii++) {
            for (int jj = 0; jj < iSizeY; jj++) {
                piTab[ii][jj] = i_counter;
                i_counter++;
            }
        }
        return true;
    } else return false;
}

bool b_copy_values_table_2_dim(int **&piTabA, int **&piTabB, int iSizeXA, int iSizeYA, int iSizeXB, int iSizeYB){
    if(iSizeXA >= 0 && iSizeYA >= 0 && iSizeXB >= 0 && iSizeYB >= 0){
        int i_min_row = iSizeXA;
        int i_min_col = iSizeYA;

        if(iSizeXB < i_min_row) i_min_row = iSizeXB;
        if(iSizeYB < i_min_col) i_min_row = iSizeYB;

        for (int ii = 0; ii < i_min_row; ii++) {
            for (int jj = 0; jj < i_min_col; jj++) {
                piTabB[ii][jj] = piTabA[ii][jj];
            }
        }
        return true;
    }else return false;

}

int main() {
    int *pi_tab;
    v_alloc_table_add5(pi_tab, TAB_A_X);
    v_print_1d_int_table(pi_tab, TAB_A_X);
    std::cout << std::endl;
    delete[] pi_tab;

    int **pi_table;
    b_alloc_table_2_dim(&pi_table, TAB_A_X, TAB_A_Y);
    b_fill_increasing_table_2_dim(pi_table, TAB_A_X, TAB_A_Y);
    b_show_table_2_dim(pi_table, TAB_A_X, TAB_A_Y);
    std::cout << std::endl;

    int **pi_table_2;
    b_alloc_table_2_dim(&pi_table_2, TAB_B_X, TAB_B_Y);
    b_fill_increasing_table_2_dim(pi_table_2, TAB_B_X, TAB_B_Y);
    b_show_table_2_dim(pi_table_2, TAB_B_X, TAB_B_Y);
    std::cout << std::endl;

    b_copy_values_table_2_dim(pi_table_2, pi_table, TAB_B_X, TAB_B_Y, TAB_A_X, TAB_A_Y);
    b_show_table_2_dim(pi_table, TAB_A_X, TAB_A_Y);
    std::cout << std::endl;

    std::cout << "--------------------------" << std::endl;

    b_fill_increasing_table_2_dim(pi_table, TAB_A_X, TAB_A_Y);
    b_copy_values_table_2_dim(pi_table, pi_table_2, TAB_A_X, TAB_A_X, TAB_B_X, TAB_B_Y);
    b_show_table_2_dim(pi_table_2, TAB_B_X, TAB_B_Y);
    std::cout << std::endl;

    b_dealloc_table_2_dim(&pi_table, TAB_A_X);
    b_dealloc_table_2_dim(&pi_table_2, TAB_B_X);


    return 0;
}