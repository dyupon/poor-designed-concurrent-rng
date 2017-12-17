//
// Created by User on 12/16/2017.
//

#ifndef TASK1_TASK3_H
#define TASK1_TASK3_H


#include <vector>

class task3 {
public:
    task3(int _N, int _K);

    void fillSampleMean(std::vector<double> &sample, std::vector<double> &sampleMean, int threadId);

private:
    const int N;
    const int K;

};


#endif //TASK1_TASK3_H
