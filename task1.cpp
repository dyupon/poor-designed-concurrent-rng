//
// Created by User on 12/16/2017.
//

#include <random>
#include "task1.h"


void task1::generate(std::vector<double>& sample, int threadId) {
    pcg64 rng(1);
    std::uniform_real_distribution<double> dist(0, 10);
    int size = N / K;
    rng.discard(static_cast<pcg_extras::pcg128_t>(threadId * size));
    int beginIter = threadId * size;
    int endIter = beginIter + size;
    for (int i = beginIter; i < endIter; ++i){
        double t = dist(rng);
        sample[i] = t;
    }
}

task1::task1(int _N, int _K) : K(_K), N(_N) {
}
