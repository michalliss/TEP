//
// Created by legusie on 1/11/20.
//

#ifndef TEP9_CSOLVER_H
#define TEP9_CSOLVER_H

#include "../MSCN/CMscnProblem.h"
#include "../CProblem.h"
#include "../Controler/CControler.h"
class CSolver {
public:
    CSolver();
    virtual ~CSolver();
    bool bSetProblem(CProblem& cProblem);
    bool bSetControler(CControler& cControler);
    virtual std::vector<double> cSolve() = 0;
protected:
    CProblem* pc_problem;
    CControler* pc_controller;
};

#endif //TEP9_CSOLVER_H
