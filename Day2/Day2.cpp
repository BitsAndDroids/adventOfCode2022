#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
//
// Created by DaveRiedel on 1-12-2022.
//
int main(){
    auto start = std::chrono::high_resolution_clock::now();

    //Read file into string
    std::ifstream file("day2.txt");
    std::string text;
    while (std::getline(file, text)) {
        if (text.empty()) {

        } else {
            std::cout<<text<<std::endl;
        }
    }

    //end timer
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    //in ....
    std::cout <<"Answer: "<< "in: " << elapsed.count() << std::endl;
        return 0;
}
