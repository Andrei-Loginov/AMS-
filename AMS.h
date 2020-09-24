//
// Created by andrei on 23.09.2020.
//

#ifndef COURSEWORK3_AMS_H
#include <iostream>
#include <fstream>
#include <vector>
#include "RandomSequence.h"
#include "HammingScore.h"
#include <algorithm>
#define COURSEWORK3_AMS_H

template <typename T>
std::ostream& operator<<(std::ostream& stream, const std::vector<T> &v);

class AMS : public RandomSequence{
public:
    AMS(char* sequence, size_t total_patricles, size_t resampled_particles, int level);
    int simulate();

private:

    char* target_sequence_;
    size_t total_particles_number_, resampled_particles_number_, length_;
    std::vector<char*> particles_;
    int iterations_number_ = 1000, target_level_;
    bool condition_ = true;

    char* resample_particle();
    void make_step();

};


template <typename T>
std::ostream& operator<<(std::ostream& stream, const std::vector<T> &v){
    for (const auto &item: v)
        stream << item << " ";
    return stream;
}
#endif //COURSEWORK3_AMS_H
