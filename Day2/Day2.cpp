#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
//
// Created by DaveRiedel on 1-12-2022.
//
int main(){
    auto start = std::chrono::high_resolution_clock::now();
        std::cout << "Hello, World2!" << std::endl;

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout <<"Answer: "<< "in: " << elapsed.count() << std::endl;
        return 0;
}
