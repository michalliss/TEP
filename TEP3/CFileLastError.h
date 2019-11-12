//
// Created by legusie on 11/8/19.
//

#ifndef TEP3_CFILELASTERROR_H
#define TEP3_CFILELASTERROR_H

#define S_NEWLINE "\n"

#include <string>
#include <vector>

class CFileLastError {
private:
    static bool b_last_error;
public:
    static bool bGetLastError();

    CFileLastError();

    CFileLastError(std::string sFileName);

    ~CFileLastError();

    void vOpenFile(std::string sFileName);

    void vCloseFile();

    void vPrintLine(std::string sText);

    void vPrintManyLines(std::vector<std::string> sText);

private:
    FILE *pf_file;
};


#endif //TEP3_CFILELASTERROR_H
