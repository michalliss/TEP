//
// Created by legusie on 1/11/20.
//

#ifndef TEP9_CDIFFEVOL_H
#define TEP9_CDIFFEVOL_H

#include "COptimizer.h"
#include "CIndividual.h"

#define I_DEFAULT_POP 10
#define D_DEFAULT_DIFF 0.3
#define D_DEFAULT_CROSS 0.5

#define D_REPAIR_RANGE 0.1

class CDiffEvol : public COptimizer {
public:
    std::vector<double> cSolve() override;
    CDiffEvol();
    explicit CDiffEvol(int iSeed);
    CDiffEvol(int iSeed, int iPopulation, double dCross, double dDiff);
    CDiffEvol(int iPopulation, double dCross, double dDiff);
private:

    double d_diff_weight;
    int i_population_size;
    double d_cross_prob;
    CRandom c_random;
    void v_repair_genotype(CIndividual& c_individual);
};

#endif //TEP9_CDIFFEVOL_H
