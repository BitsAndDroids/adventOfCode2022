#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include "RESULTENUM.h"
#include "RPCENUM.h"
#include "Result.h"
//
// Created by DaveRiedel on 1-12-2022.
//
#define FIRSTROCK "A"
#define FIRSTPAPER "B"
#define FIRSTSCISSORS "C"
//Alternative solution
int move[8][3] = {
        {ROCK, PAPER, SCISSORS},
        {SCISSORS, ROCK, PAPER},
        {},
        {},
        {ROCK, PAPER, SCISSORS},
        {},
        {},
        {PAPER, SCISSORS, ROCK},
};

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
            RESULT second;
            if(substring == FIRSTROCK){
                first = ROCK;
            } else if(substring == FIRSTPAPER){
                first = PAPER;
            } else if(substring == FIRSTSCISSORS){
                first = SCISSORS;
            }
            if(secondSubstring == "X"){
                second = LOSS;
            } else if(secondSubstring == "Y"){
                second = DRAW;
            } else {
                second = WIN;
            }
            //Building upon day 1. This solution is a bit bloated, but it works.
            //Result r = Result(first,0,second);
            //counter += second;
            //counter+= r.getPlayedValue();

            //Another compacter way to do this
            counter += second;
            counter += move[second + 1][first - 1];

        }
    }
    //end timer
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    //in 0.0009985
    std::cout <<"Answer: "<<counter<< " in: " << elapsed.count() << std::endl;
    return 0;

}

