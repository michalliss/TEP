//
// Created by legusie on 1/11/20.
//

#ifndef TEP9_CINDIVIDUAL_H
#define TEP9_CINDIVIDUAL_H

#include <vector>
#include <ostream>
struct CIndividual {
  CIndividual();
  CIndividual(const CIndividual& pcOther);
  explicit CIndividual(int iSize);
  explicit CIndividual(const std::vector<double>& vGenotype);

  std::vector<double> v_genotype;

  bool operator==(const CIndividual& rhs) const;
  bool operator!=(const CIndividual& rhs) const;
  void operator=(const CIndividual& pcOther);
  friend std::ostream& operator<<(std::ostream& os, const CIndividual& individual);
};

#endif //TEP9_CINDIVIDUAL_H
