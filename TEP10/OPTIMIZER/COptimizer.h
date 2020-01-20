//
// Created by legusie on 1/11/20.
//

#ifndef TEP9_COPTIMIZER_H
#define TEP9_COPTIMIZER_H

#include "../MSCN/CMscnProblem.h"
#include "../CProblem.h"
#include "../CONTROLER/CControler.h"
class COptimizer {
public:
    COptimizer();
    virtual ~COptimizer();
    bool bSetProblem(CProblem& cProblem);
    bool bSetControler(CControler& cControler);
    virtual std::vector<double> cSolve() = 0;
protected:
    CProblem* pc_problem;
    CControler* pc_controller;
};

#endif //TEP9_COPTIMIZER_H
