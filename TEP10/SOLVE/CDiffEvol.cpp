//
// Created by legusie on 1/11/20.
//

#include "CDiffEvol.h"
#include "CPopulation.h"
std::vector<double> CDiffEvol::cSolve()
{
    CPopulation c_population(I_POPULATION_SIZE, *pc_problem, c_random);
    std::cout << "populacja gotowa" << std::endl;

    pc_controller->vStart();
    while (pc_controller->bContinue()) {
        for (int i = 0; i<c_population.iSize() and pc_controller->bContinue(); i++) {
            CIndividual& c_ind = c_population.getVPpopulation()[i];
            CIndividual& c_ind_base = c_population.getRandom(c_random);
            CIndividual& c_ind_0 = c_population.getRandom(c_random);
            CIndividual& c_ind_1 = c_population.getRandom(c_random);
            if (c_ind!=c_ind_base && c_ind!=c_ind_0 && c_ind!=c_ind_1
                    && c_ind_base!=c_ind_0 && c_ind_base!=c_ind_1
                    && c_ind_0!=c_ind_1) {
                CIndividual c_new(pc_problem->getSize());
                for (int i_gene_offset = 0; i_gene_offset<pc_problem->getSize(); i_gene_offset++) {
                    if (c_random.dGetDouble(0, 1)<D_CROSS_PROB) {
                        c_new.v_genotype[i_gene_offset] = c_ind_base.v_genotype[i_gene_offset]
                                +D_DIFF_WEIGHT*(c_ind_0.v_genotype[i_gene_offset]-c_ind_1.v_genotype[i_gene_offset]);
                    }
                    else {
                        c_new.v_genotype[i_gene_offset] = c_ind.v_genotype[i_gene_offset];
                    }
                }
                bool b_succ;

                // vRepairGenotype(c_new);
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

void CDiffEvol::vRepairGenotype(CIndividual& cIndividual)
{
    bool b_succ;
    while (!pc_problem->bConstraintsSatisfied(cIndividual.v_genotype, b_succ)) {
        for (int i = 0; i<cIndividual.v_genotype.size(); i++) {

        }
    }
}
CDiffEvol::CDiffEvol()
        :CSolver()
{

}

CDiffEvol::CDiffEvol(int iSeed)
        :CSolver(), c_random(iSeed)
{

}


