//
// Created by legusie on 1/11/20.
//

#include "COptimizer.h"
COptimizer::COptimizer()
{
    pc_problem = NULL;
}

bool COptimizer::bSetProblem(CProblem& cProblem)
{
    if (&cProblem==NULL) return false;
    pc_problem = &cProblem;
    return true;
}
bool COptimizer::bSetControler(CControler& cControler)
{
    if (&cControler==NULL) return false;
    pc_controller = &cControler;
    return true;
}
COptimizer::~COptimizer()
{

}
