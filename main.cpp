#include <iostream>
#include "HammingScore.h"
#include "RandomSequence.h"
#include "AMS.h"

int main() {
    RandomSequence rd;
    AMS ams(rd.symbol_sequence(20), 20, 1, 15);
    std::cout << ams.simulate();
    return 0;
}
