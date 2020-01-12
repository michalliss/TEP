//
// Created by legusie on 1/12/20.
//

#include "CControlerIter.h"
CControlerIter::CControlerIter(int i_iter_max)
        :i_iter_status(0), i_iter_max(i_iter_max)
{

}
bool CControlerIter::bContinue()
{
    return i_iter_status<i_iter_max;
}
void CControlerIter::vUpdate()
{
    i_iter_status++;
}
void CControlerIter::vStart()
{
    i_iter_status = 0;
}
CControlerIter::~CControlerIter()
{

}
