//
// Created by legusie on 1/11/20.
//

#ifndef TEP9_CPOPULATION_H
#define TEP9_CPOPULATION_H

#include <ostream>
#include "../CProblem.h"
#include "CIndividual.h"
#include "../CRandom.h"
#define I_DEFAULT_POPULATION_SIZE 10
class CPopulation {
private:
    CProblem* pc_problem;
    std::vector<CIndividual> v_population;
    CIndividual c_get_random_good_ind();
    CIndividual c_get_random_ind();
public:
    CPopulation(CProblem &cProblem);
    CPopulation(int iSize, CProblem& cProblem);
    void vInitialize(int iSize);
    void vSetProblem(CProblem& cProblem);
    std::vector<CIndividual>& getVPpopulation();
    int iSize() { return v_population.size(); }
    CIndividual& getRandom(CRandom& cRandom);
    CIndividual getBest();
    friend std::ostream& operator<<(std::ostream& os, const CPopulation& population);

};

#endif //TEP9_CPOPULATION_H
