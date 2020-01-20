//
// Created by legusie on 1/12/20.
//

#ifndef TEP9_CCONTROLERITER_H
#define TEP9_CCONTROLERITER_H

#include "CControler.h"
class CControlerIter : public CControler{
public:
    CControlerIter();
    CControlerIter(int i_iter_max);
    virtual ~CControlerIter();
    bool bContinue() override;
    void vUpdate() override;
    void vStart() override;
private:
    int i_iter_status;
    int i_iter_max;
};

#endif //TEP9_CCONTROLERITER_H
