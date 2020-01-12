//
// Created by legusie on 1/11/20.
//

#include "CSolver.h"
CSolver::CSolver()
{
    pc_problem = NULL;
}

bool CSolver::bSetProblem(CProblem& cProblem)
{
    if (&cProblem==NULL) return false;
    pc_problem = &cProblem;
    return true;
}
bool CSolver::bSetControler(CControler& cControler)
{
    if (&cControler==NULL) return false;
    pc_controller = &cControler;
    return true;
}
CSolver::~CSolver()
{

}
