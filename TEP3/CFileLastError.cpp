//
// Created by legusie on 11/8/19.
//

#include <cstdio>
#include "CFileLastError.h"

bool CFileLastError::b_last_error = false;

CFileLastError::CFileLastError() : pf_file(NULL), b_is_open(false) {

}

CFileLastError::CFileLastError(std::string sFileName) : pf_file(NULL), b_is_open(false) {
    b_last_error = false;
    if (!b_is_open) {
        pf_file = std::fopen(sFileName.c_str(), "w+");
        b_is_open = true;
    } else {
        b_last_error = true;
    }
}

CFileLastError::~CFileLastError() {

}

bool CFileLastError::bGetLastError() {
    return b_last_error;
}

void CFileLastError::vOpenFile(std::string sFileName) {
    if(!b_is_open){
        pf_file = std::fopen(sFileName.c_str(), "w+");
        b_is_open = true;
    }else{
        b_last_error = false;
    }

}

void CFileLastError::vCloseFile() {
    std::fclose(pf_file);

}


