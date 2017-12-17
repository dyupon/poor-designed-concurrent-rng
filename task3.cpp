//
// Created by User on 12/16/2017.
//

#include "task3.h"

task3::task3(int _N, int _K) : K(_K), N(_N) {
}

void task3::fillSampleMean(std::vector<double> &sample, std::vector<double> &sampleMean, int threadId) {
    int size = N / K;
    int beginIter = threadId * size;
    for (int i = beginIter; i < beginIter + size; i++) {
        sampleMean[threadId] += sample[i] / N;
    }
}
