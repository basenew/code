#pragma once
//#include "TutorialConfig.h"
#include <iostream>

int main(int argc, char **argv){
  std::cout << "entry main" << endl;
#if 0
  if (argc < 2) {
    // report version
    std::cout << argv[0] << " Version " << Tutorial_VERSION_MAJOR << "."
              << Tutorial_VERSION_MINOR << std::endl;
    std::cout << "Usage: " << argv[0] << " number" << std::endl;
  }
#endif
  return 0;
}
