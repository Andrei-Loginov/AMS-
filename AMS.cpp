//
// Created by andrei on 23.09.2020.
//

#include "AMS.h"

AMS::AMS(char* sequence, size_t total_particles, size_t resampled_particles_, int level) : target_sequence_(sequence), target_level_(level),
                                        resampled_particles_number_(resampled_particles_), total_particles_number_(total_particles) {
    length_ = strlen(target_sequence_);
    particles_.resize(total_particles_number_);
    for (auto& item: particles_)
        item = symbol_sequence(length_);
    std::ofstream fout("service.txt", std::ios::out);
    fout << target_sequence_ << "\n" << particles_ << "\n";
    fout.close();
}

int AMS::simulate() {
    int k = 0;
    while (condition_){
        make_step();
        ++k;
    }
    return k;
}

void AMS::make_step() {
    std::sort(particles_.begin(), particles_.end(), [this](char* left, char* right){
        return (hamming_score(target_sequence_, left) < hamming_score(target_sequence_, right));
    });
    condition_ = hamming_score(particles_[resampled_particles_number_], target_sequence_) < target_level_;
    for (size_t i = 0; i < resampled_particles_number_; ++i)
        particles_[i] = resample_particle();
    //std::cout << particles_ << "\n";
    for (auto item: particles_)
        std::cout << hamming_score(target_sequence_, item) << " ";
    std::cout << "\n";
    std::fstream fout("service.txt", std::ios::app);
    fout << particles_ << "\n";
}


char* AMS::resample_particle() {
    char* ans = new char[length_ + 1];
    ans[length_] = '\0';
    for (size_t i = 0; i < length_; ++i)
        ans[i] = (target_sequence_[i] == particles_[resampled_particles_number_][i]) ? particles_[resampled_particles_number_][i] : symbol();
    return ans;
}






