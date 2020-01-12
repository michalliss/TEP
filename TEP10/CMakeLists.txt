cmake_minimum_required(VERSION 3.15)
project(TEP9)

set(CMAKE_CXX_STANDARD 14)

add_executable(TEP9 main.cpp MSCN/CMscnProblem.cpp MSCN/CMscnProblem.h CMatrix.cpp CMatrix.h MSCN/CSolution.cpp MSCN/CSolution.h Utils.cpp Utils.h CRandom.cpp CRandom.h SOLVE/CRandomSearch.cpp SOLVE/CRandomSearch.h constants.h SOLVE/CSolver.cpp SOLVE/CSolver.h CProblem.cpp CProblem.h SOLVE/CDiffEvol.cpp SOLVE/CDiffEvol.h SOLVE/CIndividual.cpp SOLVE/CIndividual.h SOLVE/CPopulation.cpp SOLVE/CPopulation.h Controler/CControler.cpp Controler/CControler.h Controler/CControlerIter.cpp Controler/CControlerIter.h Controler/CControlerTime.cpp Controler/CControlerTime.h)