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
            int first = (substring == FIRSTROCK) ? ROCK : (substring == FIRSTPAPER) ? PAPER : SCISSORS;
            RESULT second = (secondSubstring == "X") ? LOSS : (secondSubstring == "Y") ? DRAW : WIN;
            //Another compacter way to do this
            counter += second;
            //The first row is the first player's move, the second row is the second player's move.
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

