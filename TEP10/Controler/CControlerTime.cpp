//
// Created by legusie on 1/12/20.
//

#include "CControlerTime.h"

CControlerTime::CControlerTime(int iDuration)
{
    t_max_duration = std::chrono::seconds(iDuration);
}

bool CControlerTime::bContinue()
{
    return std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - t_begin) < t_max_duration;
}
void CControlerTime::vUpdate()
{
}
void CControlerTime::vStart()
{
    t_begin = std::chrono::steady_clock::now();
}
