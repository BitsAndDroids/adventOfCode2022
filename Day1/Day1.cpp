#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
#include <ios>
#include <chrono>

#include <unistd.h>

//
// Created by DaveRiedel on 1-12-202
//
int main() {
    //start timer
    auto start = std::chrono::high_resolution_clock::now();
    int nrOfCalories = 0;
    int highestCalories = 0;
    int secondHighestElf = 0;
    int thirdHighestElf = 0;

    std::ifstream file("day1.txt");
    std::string text;

    while (std::getline(file, text)) {
        if (text.empty()) {
            if (nrOfCalories > highestCalories) {
                thirdHighestElf = secondHighestElf;
                secondHighestElf = highestCalories;
                highestCalories = nrOfCalories;
            }
            nrOfCalories = 0;
        } else {
            nrOfCalories += std::stoi(text);
        }
    }
    //end timer
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    //in 0.0009714
    std::cout<<"Answer A: " <<highestCalories << " Answer B: " << highestCalories + secondHighestElf + thirdHighestElf<<" in: " << elapsed.count() << std::endl;
    return 0;
}
