//
// Created by legusie on 1/11/20.
//

#ifndef TEP9_CDIFFEVOL_H
#define TEP9_CDIFFEVOL_H

#include "CSolver.h"
#include "CIndividual.h"

#define D_CROSS_PROB 0.3
#define D_DIFF_WEIGHT 0.1
#define I_POPULATION_SIZE 50

class CDiffEvol : public CSolver {
public:
    std::vector<double> cSolve() override;
private:
    CRandom c_random;
    void vRepairGenotype(CIndividual& cIndividual);
};

#endif //TEP9_CDIFFEVOL_H
