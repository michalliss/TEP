//
// Created by legusie on 1/11/20.
//

#include <iostream>
#include "CPopulation.h"
std::vector<CIndividual>& CPopulation::getVPpopulation()
{
    return v_population;
}

void CPopulation::vInitialize(int iSize, CRandom& cRandom)
{
    for (int i = 0; i<iSize; i++) {
        v_population.push_back(c_get_random_good_ind(cRandom));
        std::cout << "osobnik: " << i << std::endl;
    }
}
CIndividual CPopulation::c_get_random_ind(CRandom &cRandom)
{
    if (pc_problem==NULL) return CIndividual();
    CIndividual c_ind(pc_problem->getSize());

    std::vector<double>& v_ind = c_ind.v_genotype;
    for (int i = 0; i<v_ind.size(); i++) {
        v_ind[i] = cRandom.dGetDouble(pc_problem->getMin(i), pc_problem->getMax(i));
    }
    return c_ind;
}

CIndividual CPopulation::c_get_random_good_ind(CRandom &cRandom)
{
    if (pc_problem==NULL) return CIndividual();
    CIndividual c_ind = c_get_random_ind(cRandom);
    bool b_succ = true;
    while (!pc_problem->bConstraintsSatisfied(c_ind.v_genotype, b_succ)) {
        c_ind = c_get_random_ind(cRandom);
    }
    return c_ind;
}

CPopulation::CPopulation(CProblem& cProblem, CRandom& cRandom)
{
    pc_problem = &cProblem;
    vInitialize(I_DEFAULT_POPULATION_SIZE, cRandom);
}
CPopulation::CPopulation(int iSize, CProblem& cProblem, CRandom &cRandom)
{
    pc_problem = &cProblem;
    vInitialize(iSize, cRandom);
}

CIndividual& CPopulation::getRandom(CRandom& cRandom)
{
    return v_population[cRandom.iGetInt(0, v_population.size()-1)];
}

CIndividual CPopulation::getBest()
{
    int i_best_index = 0;
    bool b_succ;
    for (int i = 1; i<v_population.size(); i++) {
        if (pc_problem->dGetQuality(v_population[i].v_genotype, b_succ)
                >pc_problem->dGetQuality(v_population[i_best_index].v_genotype, b_succ)) {
            i_best_index = i;
        }
    }
    return v_population[i_best_index];
}
void CPopulation::vSetProblem(CProblem& cProblem)
{
    pc_problem = &cProblem;
}

std::ostream& operator<<(std::ostream& os, const CPopulation& population)
{
    os << " v_population: ";
    for(int i = 0; i < population.v_population.size(); i++){
        os << population.v_population[i] << std::endl;
    }
    return os;
}
