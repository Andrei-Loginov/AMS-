#include "RandomSequence.h"

RandomSequence::RandomSequence()
{
    std::random_device rd;
    random_generator.seed(rd());
}

char* RandomSequence::acids_sequence(const size_t &len){
    char *ans = new char[len + 1];
    ans[len] = '\0';
    for (size_t i = 0; i < len; ++i)
        ans[i] = aminoAcidsAlphabet[random_generator() % 22];
    return ans;
}

char* RandomSequence::symbol_sequence(const size_t &len) {
    char *ans = new char[len + 1];
    ans[len] = '\0';
    for (size_t i = 0; i < len; ++i)
        ans[i] = char(int('a') + random_generator() % 26);
    return ans;
}

char RandomSequence::symbol() {
    return char(int('a') + random_generator() % 26);
}