#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <map>
#include <algorithm>

//
// Created by DaveRiedel on 1-12-2022.
//
struct compare_str_length{
    bool operator()(const std::string& a, const std::string& b) const {
        return a.length() < b.length();
    }
};
int getValue(char c){
    //ASCII value of A is 65
    //ASCII value of a is 97
    if(int(c) < 91){
        return int(c) - 38;
    } else {
        return int(c) - 96;
    }
}


char getMatch(std::string strs[3]){
    char match = ' ';
    std::sort(strs, strs + 3, compare_str_length());
    for(char i : strs[0]){
        if(strs[1].find(i) != std::string::npos){
            if(strs[2].find(i) != std::string::npos){
                match = i;
                std::cout<<"Match val: "<<int(match)<<std::endl;
                return match;
            }

        }
    }
    std::cout<<"Match: "<<match<<std::endl;
    return match;
}



int main(){

    //start timer
    auto start = std::chrono::high_resolution_clock::now();
    std::map<std::string, int> map;
    //Read file into string
    std::ifstream file("day3.txt");
    std::string text;
    int priorities = 0;
    int rows = 0;
    std::string rucksacks[3];
    while (std::getline(file, text)) {
        if (text.empty()) {

        } else {
            if(rows == 3){
                char match = getMatch(rucksacks);
                priorities += getValue(match);
                rows = 0;
            }
           rucksacks[rows] = text;
           rows++;
           std::cout<<text<<std::endl;
        }

    }
    //Last set of rucksacks (bit sloppy but it works)
    char match = getMatch(rucksacks);
    priorities += getValue(match);
    std::cout<<"Priorities: "<<priorities<<std::endl;
    //end timer
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    //in ....
    std::cout <<"Answer: "<< "in: " << elapsed.count() << std::endl;
        return 0;


}


