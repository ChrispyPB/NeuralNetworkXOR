#pragma once

#include "include.h"

class CLA {
  public:
    static bool verbose;
    static std::vector<int> layers;

    static void parse(int argc, char** argv);
};
