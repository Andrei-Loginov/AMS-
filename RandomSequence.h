#ifndef COURSEWORK3_RANDOMSEQUENCE_H
#include <iostream>
#include <vector>
#include <cstring>
#include <random>
#define COURSEWORK3_RANDOMSEQUENCE_H

/*
 * This class generates random symbol sequences
 */

const char aminoAcidsAlphabet[] = {'A', 'R', 'N', 'D', 'B', 'C', 'E', 'Q', 'Z',
                                   'G', 'H', 'I', 'L', 'K', 'M', 'F', 'P', 'S',
                                   'T', 'W', 'Y', 'V'};


class RandomSequence {
public:
    RandomSequence();
    char *acids_sequence(const size_t &len);
    char *symbol_sequence(const size_t &len);
    char symbol();
private:
    std::mt19937 random_generator;
};


#endif //COURSEWORK3_RANDOMSEQUENCE_H
