//
// Created by przydasie on 12/15/19.
//

#ifndef TEP9__UTILS_H_
#define TEP9__UTILS_H_

class Utils {
 public:
  static bool bLoadSolution(std::string sFilename, double pdSolution[]);
  static bool bLoadSolution2(std::string sFilename, double pdSolution[]);
  static int iGetSolutionLength(std::string sFilename);
};

#endif //TEP9__UTILS_H_
