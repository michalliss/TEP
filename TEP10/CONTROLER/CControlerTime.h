//
// Created by legusie on 1/12/20.
//

#ifndef TEP9_CCONTROLERTIME_H
#define TEP9_CCONTROLERTIME_H

#include <chrono>
#include "CControler.h"
class CControlerTime : public CControler {
private:
public:
    CControlerTime(int iDuration);

    void vUpdate() override;
    bool bContinue() override;
    void vStart() override;
private:
    std::chrono::steady_clock::time_point t_begin;
    std::chrono::duration<int, std::milli> t_max_duration;

};

#endif //TEP9_CCONTROLERTIME_H
