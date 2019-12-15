#define DEFAULT_CTABLE_NAME "default table"
#define DEFAULT_CTABLE_SIZE 5
#define MSG_PARAMETER "parametr: "
#define NAME_COPY "_copy"
#define MSG_DELETE "usuwam: "

#include <string>
#include <iostream>
#include <cstring>

class CTable {
 private:
  std::string s_name;
  int *pi_tab;
  int i_size;

 public:
  static int i_copy_counter;
  static int i_move_counter;
  CTable();
  CTable(std::string sName, int iTableLen);
  CTable(const CTable &pcOther);
  //CTable(CTable &&pcOther);
  ~CTable();

  void vSetName(std::string sName);
  bool bSetNewSize(int iTableLen);
  CTable pcGetPairSumsTable();
  CTable *pcClone();

  int iGetVal(int iPos);
  bool bSetVal(int iPos, int iVal);
  int iGetSize();
  void vShow();
  std::string sGetName();

  CTable operator+(CTable const &pcNewTab);
  CTable &operator/=(int iVal);
  CTable &operator=(CTable const &pcNewTab);
  //CTable &operator=(CTable &&pcNewTab);
};

