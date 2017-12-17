#ifndef TASK1_TASK1_H
#define TASK1_TASK1_H


#include <vector>
#include "pcg_random.hpp"

class task1 {
public:
    task1(int _N, int _K);
    void generate(std::vector<double> &sample, int threadId);
private:
    const int N;
    const int K;
};


#endif //TASK1_TASK1_H
