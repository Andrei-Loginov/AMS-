//
// Created by andrei on 17.09.2020.
//

#include "HammingScore.h"


int hamming_score(char* left, char* right){
    if (strlen(left) != strlen(right)) return -1;
    int ans = 0;
    for (size_t i = 0; i < strlen(left); ans += (left[i] == right[i]),++i);
    return ans;
}
