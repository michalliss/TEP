//
// Created by przydasie on 12/14/19.
//

#include <iostream>
#include "CSolution.h"

bool CSolution::bLoad(std::string sFilename) {
    if (sFilename == "") return false;
    std::string s_ignore;
    std::ifstream f_file(sFilename);
    if (!f_file.good()) return false;
    f_file >> s_ignore;
    f_file >> i_d;
    f_file >> s_ignore;
    f_file >> i_f;
    f_file >> s_ignore;
    f_file >> i_m;
    f_file >> s_ignore;
    f_file >> i_s;

    f_file >> s_ignore;
    c_xd.bLoadFromStream(f_file, i_d, i_f);
    f_file >> s_ignore;
    c_xf.bLoadFromStream(f_file, i_f, i_m);
    f_file >> s_ignore;
    c_xm.bLoadFromStream(f_file, i_m, i_s);

    if (f_file.fail()) return false;
    vCalcVector();

    return true;
}

int CSolution::iLenght() {
    return i_d * i_f + i_f * i_m + i_m * i_s;
}

void CSolution::vCalcVector() {
    c_xd.vPushToVector(c_vector);
    c_xf.vPushToVector(c_vector);
    c_xm.vPushToVector(c_vector);
}

CSolution::CSolution(int iD, int iF, int iM, int iS) : i_d(iD), i_f(iF), i_m(iM), i_s(iS), c_xd(iD, iF), c_xf(iF, iM),
                                                       c_xm(iM, iS) {

}

CSolution::CSolution() {
    CSolution(1,1,1,1);
}


