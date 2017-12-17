//
// Created by User on 12/16/2017.
//

#include <cmath>
#include "task2.h"

task2::task2(int _N, int _K) : K(_K), N(_N) {
}

void task2::calculateSin(std::vector<double> &sample, int threadId) {
    int size = N / K;
    int beginIter = threadId * size;
    for (int i = beginIter; i < beginIter + size; i++) {
        sample[i] = std::sin(sample[i]);
    }

}
