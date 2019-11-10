#define DEFAULT_CTABLE_NAME "default table"
#define DEFAULT_CTABLE_SIZE 5
#include <string>
#include <iostream>

class CTable {
private:
    std::string s_name;
    int* pi_tab;
    int i_size;
public:
    CTable();
    CTable (std::string sName, int iTableLen);
    CTable (CTable &pcOther);
    ~CTable();
    void vSetName(std::string sName);
    bool bSetNewSize(int iTableLen);
    CTable *pcClone();
};

