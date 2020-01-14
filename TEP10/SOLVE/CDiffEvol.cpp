//
// Created by legusie on 1/11/20.
//

#include "CDiffEvol.h"
#include "CPopulation.h"
std::vector<double> CDiffEvol::cSolve()
{
    CPopulation c_population(i_population_size, *pc_problem, c_random);
    std::cout << "populacja gotowa" << std::endl;

    pc_controller->vStart();
    while (pc_controller->bContinue()) {
        for (int i = 0; i<c_population.iSize() and pc_controller->bContinue(); i++) {
            CIndividual& c_ind = c_population.getVPpopulation()[i];
            CIndividual& c_ind_base = c_population.getRandom(c_random);
            CIndividual& c_ind_0 = c_population.getRandom(c_random);
            CIndividual& c_ind_1 = c_population.getRandom(c_random);
            if (&c_ind!=&c_ind_base && &c_ind!=&c_ind_0 && &c_ind!=&c_ind_1
                    && &c_ind_base!=&c_ind_0 && &c_ind_base!=&c_ind_1
                    && &c_ind_0!=&c_ind_1) {
                CIndividual c_new(pc_problem->getSize());
                for (int i_gene_offset = 0; i_gene_offset<pc_problem->getSize(); i_gene_offset++) {
                    if (c_random.dGetDouble(0, 1)<d_cross_prob) {
                        c_new.v_genotype[i_gene_offset] = c_ind_base.v_genotype[i_gene_offset]
                                +d_diff_weight*(c_ind_0.v_genotype[i_gene_offset]-c_ind_1.v_genotype[i_gene_offset]);
                    }
                    else {
                        c_new.v_genotype[i_gene_offset] = c_ind.v_genotype[i_gene_offset];
                    }
                }
                bool b_succ;

                v_repair_genotype(c_new);

                pc_controller->vUpdate();
                if (pc_problem->bConstraintsSatisfied(c_new.v_genotype, b_succ)
                        && pc_problem->dGetQuality(c_new.v_genotype, b_succ)
                                >pc_problem->dGetQuality(c_ind.v_genotype, b_succ)) {
                    //std::cout << "poprawa";
                    c_ind = c_new;
                }
            }
        }
    }

    return c_population.getBest().v_genotype;
}

void CDiffEvol::v_repair_genotype(CIndividual& c_individual)
{
    for (int i = 0; i<c_individual.v_genotype.size(); i++) {
        if (c_individual.v_genotype[i]<pc_problem->getMin(i)) {
            c_individual.v_genotype[i] = pc_problem->getMin(i)
                    +D_REPAIR_RANGE*c_random.dGetDouble(pc_problem->getMin(i), pc_problem->getMax(i));
        }
        if (c_individual.v_genotype[i]>pc_problem->getMax(i)) {
            c_individual.v_genotype[i] = pc_problem->getMax(i)
                    -D_REPAIR_RANGE*c_random.dGetDouble(pc_problem->getMin(i), pc_problem->getMax(i));
        }
    }
}

CDiffEvol::CDiffEvol()
        :CSolver(), i_population_size(I_DEFAULT_POP), d_diff_weight(D_DEFAULT_DIFF), d_cross_prob(D_DEFAULT_CROSS)
{

}

CDiffEvol::CDiffEvol(int iSeed)
        :CSolver(), c_random(iSeed), i_population_size(I_DEFAULT_POP), d_diff_weight(D_DEFAULT_DIFF),
         d_cross_prob(D_DEFAULT_CROSS)
{

}

CDiffEvol::CDiffEvol(int iSeed, int iPopulation, double dCross, double dDiff)
        :CSolver(), c_random(iSeed), i_population_size(iPopulation), d_cross_prob(dCross), d_diff_weight(dDiff)
{

}
CDiffEvol::CDiffEvol(int iPopulation, double dCross, double dDiff)
        :CSolver(), i_population_size(iPopulation), d_cross_prob(dCross), d_diff_weight(dDiff)
{

}


