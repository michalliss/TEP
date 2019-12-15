#include "ctable.h"
int CTable::i_copy_counter = 0;
int CTable::i_move_counter = 0;
CTable::CTable() : s_name(DEFAULT_CTABLE_NAME), pi_tab(new int[DEFAULT_CTABLE_SIZE]), i_size(DEFAULT_CTABLE_SIZE) {
    std::cout << this->s_name << std::endl;
}

CTable::CTable(std::string sName, int iTableLen) : s_name(sName) {
    if (iTableLen > 0) {
        this->i_size = iTableLen;
        this->pi_tab = new int[iTableLen];
    } else {
        this->i_size = DEFAULT_CTABLE_SIZE;
        this->pi_tab = new int[DEFAULT_CTABLE_SIZE];
    }
    std::cout << MSG_PARAMETER << this->s_name << std::endl;
}

CTable::CTable(const CTable &pcOther) : s_name(pcOther.s_name + NAME_COPY),
                                        pi_tab(new int[pcOther.i_size]),
                                        i_size(pcOther.i_size) {

    std::copy(pcOther.pi_tab, pcOther.pi_tab + i_size, this->pi_tab);
    std::cout << this->s_name << std::endl;
    i_copy_counter++;
}

CTable::CTable(CTable &&pcOther) :s_name(pcOther.s_name), pi_tab(pcOther.pi_tab), i_size(pcOther.i_size){
  pcOther.pi_tab = NULL;
  std::cout << "MOVE " << this->s_name << std::endl;
  i_move_counter++;
}

CTable::~CTable() {
  if(pi_tab != NULL){
    delete[] this->pi_tab;
  }
  std::cout << MSG_DELETE << this->s_name << std::endl;
}

CTable *CTable::pcClone() {
    CTable *c_cloned_table = new CTable(*this);
    c_cloned_table->vSetName(this->s_name);
    return c_cloned_table;
}


CTable& CTable::operator/=(int iVal) {
    if (iVal <= 1) {
        return *this;
    } else {
        int ii = 0;
        for(ii; ii*iVal < this->i_size; ii++){
            this->pi_tab[ii] = this->pi_tab[ii*iVal];
        }
        this->bSetNewSize(ii);
        return *this;
    }
}

CTable& CTable::operator=(CTable const &pcNewTab) {
    if(&pcNewTab != this){
        if(pi_tab != NULL) delete[] this->pi_tab;
        this->i_size = pcNewTab.i_size;
        this->vSetName(pcNewTab.s_name);
        this->pi_tab = new int[i_size];
        std::copy(pcNewTab.pi_tab, pcNewTab.pi_tab + i_size, this->pi_tab);
        i_copy_counter++;
        return *this;
    } else return *this;
}
/*CTable& CTable::operator=(CTable &&pcNewTab) {
  if(&pcNewTab != this){
    if(pi_tab != NULL) delete[] this->pi_tab;
    this->pi_tab = pcNewTab.pi_tab;
    this->i_size = pcNewTab.i_size;
    this->s_name = pcNewTab.s_name;
    pcNewTab.pi_tab = NULL;
    i_move_counter++;
    return *this;
  } else return *this;
}*/


CTable CTable::operator+(CTable const &pcNewTab) {
  CTable c_result_table(this->s_name + "_concat_" + pcNewTab.s_name, this->i_size + pcNewTab.i_size);
  std::copy(this->pi_tab, this->pi_tab + this->i_size, c_result_table.pi_tab);
  std::copy(pcNewTab.pi_tab, pcNewTab.pi_tab + pcNewTab.i_size, c_result_table.pi_tab + this->i_size);
  //return (std::move(c_result_table));
  return c_result_table;
}



void CTable::vShow() {
    std::cout << s_name << ": ";
    for (int ii = 0; ii < i_size; ii++) {
        std::cout << pi_tab[ii] << "; ";
    }
    std::cout << std::endl;
}

CTable CTable::pcGetPairSumsTable() {
    if (i_size > 0) {
        CTable c_pair_table(this->s_name + "PairSums", this->i_size - 1);
        for (int ii = 0; ii < c_pair_table.iGetSize(); ii++) {
            c_pair_table.bSetVal(ii, this->iGetVal(ii) + this->iGetVal(ii + 1));
        }
        return std::move(c_pair_table);
    } else return CTable();
}

void CTable::vSetName(std::string sName) {
    this->s_name = sName;
}

bool CTable::bSetNewSize(int iTableLen) {
    if (iTableLen > 0) {
        int *pi_new_tab = new int[iTableLen];
        int i_max_copy_size = (iTableLen > this->i_size) ? this->i_size : iTableLen;
        std::copy(this->pi_tab, this->pi_tab + i_max_copy_size, pi_new_tab);
        delete[] pi_tab;
        this->pi_tab = pi_new_tab;
        this->i_size = iTableLen;

        return true;
    } else {
        return false;
    }
}

int CTable::iGetSize() {
    return i_size;
}

int CTable::iGetVal(int iPos) {
    if (iPos >= 0 and iPos < this->i_size) {
        return this->pi_tab[iPos];
    } else return 0;

}

bool CTable::bSetVal(int iPos, int iVal) {
    if (iPos >= 0 and iPos < this->i_size) {
        this->pi_tab[iPos] = iVal;
        return true;
    } else return false;
}

std::string CTable::sGetName() {
    return this->s_name;
}
