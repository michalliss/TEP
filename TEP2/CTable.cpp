#include "CTable.h"

CTable::CTable() : s_name(DEFAULT_CTABLE_NAME), pi_tab(new int[DEFAULT_CTABLE_SIZE]), i_size(DEFAULT_CTABLE_SIZE) {
    std::cout << this->s_name;
}

CTable::CTable(std::string sName, int iTableLen) : s_name(sName), pi_tab(new int[iTableLen]), i_size(iTableLen) {
    std::cout << this->s_name;
}

CTable::CTable(CTable &pcOther) : s_name(pcOther.s_name + "_copy"), pi_tab(new int[pcOther.i_size]),
                                  i_size(pcOther.i_size) {
    for (int ii = 0; ii < i_size; ii++) {
        this->pi_tab[ii] = pcOther.pi_tab[ii];
    }

    std::cout << this->s_name;
}

CTable::~CTable() {
    delete[] this->pi_tab;
    std::cout << "usuwam: " << this->s_name;
}

void CTable::vSetName(std::string sName) {
    this->s_name = sName;
}

bool CTable::bSetNewSize(int iTableLen) {
    if (iTableLen > 0) {
        int *pi_new_tab = new int[iTableLen];
        int i_max_copy_size = (iTableLen > this->i_size) ? iTableLen : this->i_size;
        for (int ii = 0; ii < i_max_copy_size; ii++) {
            pi_new_tab[ii] = pi_tab[ii];
        }
        delete[] pi_tab;
        this->pi_tab = pi_new_tab;
        this->i_size = iTableLen;

        return true;
    } else {
        return false;
    }
}

CTable *CTable::pcClone() {
    return new CTable(*this);
}
