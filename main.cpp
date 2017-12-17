#include <iostream>
#include <random>
#include <cstddef>
#include <thread>
#include "pcg_random.hpp"
#include "task1.h"
#include "task2.h"
#include "task3.h"



const int N = 10000000;
const int K = 4;


void generateSingle(std::vector<double> &sample, pcg64 &rng) {
    std::uniform_real_distribution<double> dist(0, 10);
    for (int i = 0; i < N; ++i) {
        double t = dist(rng);
        sample.emplace_back(t);
    }
}

void calculateSinSingle(std::vector<double> &sample) {
    for (int i = 0; i < N; ++i) {
        double sinI = std::sin(sample[i]);
        sample[i] = sinI;
    }
}

double calculateSampleMeanSingle(std::vector<double> sample) {
    double result = 0;
    for (int i = 0; i < N; i++) {
        result += sample[i] / N;
    }
    return result;
}

void print(std::vector<double> &sample, bool multithrd) {
    std::string output;
    if (!multithrd) {
        output = "1 thread:\n";
    } else output = std::to_string(K) + " threads:\n";
    std::cout << output;
    for (int i = 0; i < N; ++i) {
        std::cout << sample[i] << " ";
    }
    std::cout << std::endl;
}


int main() {
    pcg64 rng(1);
    pcg64 rng_copy = rng;
    std::vector<double> multipleThreadResult(N);
    task1 t1 = task1(N, K);
    std::vector<std::thread> threadsTask1, threadsTask2, threadsTask3;

    /** sample generation **/
    clock_t begin_time = clock();
    for (int numberOfThread = 0; numberOfThread < K; ++numberOfThread) {
        threadsTask1.emplace_back(std::thread(&task1::generate, &t1, std::ref(multipleThreadResult), numberOfThread));
    }
    for (auto &tcur : threadsTask1) {
        tcur.join();
    }
    std::cout << "Generated sample of " << N << " random numbers in " << K << " threads in: "
              << float(clock() - begin_time) << std::endl;
    //print(multipleThreadResult, true);
    std::vector<double> singleThreadResult(N);
    singleThreadResult.clear();
    begin_time = clock();
    generateSingle(singleThreadResult, rng);
    std::cout << "Generated sample of " << N << " random numbers in the single thread in: "
              << float(clock() - begin_time) << std::endl;
    //print(singleThreadResult, false);

    /** sin calculation **/
    task2 t2 = task2(N, K);
    begin_time = clock();
    for (int numberOfThread = 0; numberOfThread < K; ++numberOfThread) {
        threadsTask2.emplace_back(
                std::thread(&task2::calculateSin, &t2, std::ref(multipleThreadResult), numberOfThread));
    }
    for (auto &tcur : threadsTask2) {
        tcur.join();
    }
    std::cout << "Calculated sin of " << N << " random numbers in " << K << " threads in: "
              << float(clock() - begin_time) << std::endl;
    //print(multipleThreadResult, true);

    begin_time = clock();
    calculateSinSingle(singleThreadResult);
    std::cout << "Calculated sin of " << N << " random numbers in the single thread in: "
              << float(clock() - begin_time) << std::endl;
    //print(singleThreadResult, false);



    /** sample mean calculation **/
    task3 t3 = task3(N, K);
    double sampleMeanMultithread = 0;
    std::vector<double> subSampleMean(K);
    begin_time = clock();
    for (int numberOfThread = 0; numberOfThread < K; ++numberOfThread) {
        threadsTask3.emplace_back(
                std::thread(&task3::fillSampleMean, &t3, std::ref(multipleThreadResult), std::ref(subSampleMean),
                            numberOfThread));
    }
    for (auto &tcur : threadsTask3) {
        tcur.join();
    }
    for (int i = 0; i < K; i++) {
        sampleMeanMultithread += subSampleMean[i];
    }
    std::cout << "Calculated sample mean of " << N << " random numbers in " << K << " threads in: "
              << float(clock() - begin_time) << std::endl;
    begin_time = clock();
    double sampleMeanSingle = calculateSampleMeanSingle(singleThreadResult);
    std::cout << "Calculated sample mean of " << N << " random numbers in the single thread in: "
              << float(clock() - begin_time) << std::endl;
    std::cout << "sampleMeanMultithread: " << sampleMeanMultithread << std::endl;
    std::cout << "sampleMeanSingle: " << sampleMeanSingle << std::endl;
    return 0;
}





