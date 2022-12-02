#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include "RPCENUM.h"
#include "Result.h"
//
// Created by DaveRiedel on 1-12-2022.
//
#define FIRSTROCK "A"
#define FIRSTPAPER "B"
#define FIRSTSCISSORS "C"
#define SECONDROCK "X"
#define SECONDPAPER "Y"
#define SECONDSCISSORS "Z"

int main(){
    auto start = std::chrono::high_resolution_clock::now();

    //Read file into string
    std::ifstream file("day2.txt");
    std::string text;
    int counter = 0;
    while (std::getline(file, text)) {

        if (text.empty()) {

        } else {
            std::string substring = text.substr(0, text.find(' '));
            std::string secondSubstring = text.substr(text.find(' ') + 1);

            int first = 0;
            int second = 0;
            if(substring == FIRSTROCK){
               first = ROCK;
            } else if(substring == FIRSTPAPER){
               first = PAPER;
            } else if(substring == FIRSTSCISSORS){
              first = SCISSORS;
            }
            if(secondSubstring == SECONDROCK){
                second = ROCK;
            } else if(secondSubstring == SECONDPAPER){
                second = PAPER;
            } else if(secondSubstring == SECONDSCISSORS){
                second = SCISSORS;
            }
            Result r = Result(first, second);
            counter += r.getResult();
            counter+= second;
        }
    }

    //end timer
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    //in 0.0009959
    std::cout <<"Answer: "<<counter<< " in: " << elapsed.count() << std::endl;
        return 0;

}

