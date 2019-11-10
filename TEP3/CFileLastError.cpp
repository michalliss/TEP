//
// Created by legusie on 11/8/19.
//

#include <cstdio>
#include "CFileLastError.h"

CFileLastError::CFileLastError() {
    b_last_error = false;
}

CFileLastError::CFileLastError(std::string sFileName) {
    b_last_error = false;
    pf_file = std::fopen(sFileName.c_str(), "w+");
    if (pf_file == NULL) {
        b_last_error = true;
    }
}

CFileLastError::~CFileLastError() {

}

bool CFileLastError::bGetLastError() {
    return b_last_error;
}

void CFileLastError::vOpenFile(std::string sFileName) {
    pf_file = std::fopen(sFileName.c_str(), "w+");
    if(pf_file == NULL){
        b_last_error = true;
    }
}

void CFileLastError::vCloseFile() {
    std::fclose(pf_file);

}


