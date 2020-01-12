//
// Created by legusie on 1/11/20.
//

#include "CIndividual.h"
CIndividual::CIndividual(const std::vector<double>& genotype)
        :v_genotype(genotype)
{
}

CIndividual::CIndividual(const CIndividual& pcOther)
        :v_genotype(pcOther.v_genotype)
{
}

CIndividual::CIndividual(int iSize)
        :v_genotype(iSize, 0)
{
}
CIndividual::CIndividual() { }

void CIndividual::operator=(const CIndividual& pcOther)
{
    v_genotype = pcOther.v_genotype;
}

bool CIndividual::operator==(const CIndividual& rhs) const
{
    return v_genotype==rhs.v_genotype;
}
bool CIndividual::operator!=(const CIndividual& rhs) const
{
    return !(rhs==*this);
}

std::ostream& operator<<(std::ostream& os, const CIndividual& individual)
{
    os << "size: "<< individual.v_genotype.size() <<" v_genotype: " ;
    for (int i = 0; i<individual.v_genotype.size(); i++) {
        os << individual.v_genotype[i];
    }
    return os;
}
