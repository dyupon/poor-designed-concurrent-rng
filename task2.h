//
// Created by User on 12/16/2017.
//

#ifndef TASK1_TASK2_H
#define TASK1_TASK2_H


#include <vector>

class task2 {
public:
    task2(int _N, int _K);

    void calculateSin(std::vector<double> &sample, int threadId);

private:
    const int N;
    const int K;
};


#endif //TASK1_TASK2_H
