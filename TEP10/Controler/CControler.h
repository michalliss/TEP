//
// Created by legusie on 1/12/20.
//

#ifndef TEP9_CCONTROLER_H
#define TEP9_CCONTROLER_H

class CControler {
public:
    virtual bool bContinue() = 0;
    virtual void vUpdate() = 0;
    virtual void vStart() = 0;
    virtual ~CControler();
};

#endif //TEP9_CCONTROLER_H
