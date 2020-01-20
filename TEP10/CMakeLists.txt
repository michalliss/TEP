cmake_minimum_required(VERSION 3.15)
project(TEP9)

set(CMAKE_CXX_STANDARD 14)

add_executable(TEP9 main.cpp MSCN/CMscnProblem.cpp MSCN/CMscnProblem.h CMatrix.cpp CMatrix.h MSCN/CSolution.cpp MSCN/CSolution.h Utils.cpp Utils.h CRandom.cpp CRandom.h OPTIMIZER/CRandomSearch.cpp OPTIMIZER/CRandomSearch.h constants.h OPTIMIZER/COptimizer.cpp OPTIMIZER/COptimizer.h CProblem.cpp CProblem.h OPTIMIZER/CDiffEvol.cpp OPTIMIZER/CDiffEvol.h OPTIMIZER/CIndividual.cpp OPTIMIZER/CIndividual.h OPTIMIZER/CPopulation.cpp OPTIMIZER/CPopulation.h CONTROLER/CControler.cpp CONTROLER/CControler.h CONTROLER/CControlerIter.cpp CONTROLER/CControlerIter.h CONTROLER/CControlerTime.cpp CONTROLER/CControlerTime.h)