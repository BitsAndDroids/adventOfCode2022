#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <map>

//
// Created by DaveRiedel on 1-12-2022.
//
int main(){
    //start timer
    auto start = std::chrono::high_resolution_clock::now();
    std::map<std::string, int> map;
    //Read file into string
    std::ifstream file("day3.txt");
    std::string text;
    int priorities = 0;
    while (std::getline(file, text)) {
        if (text.empty()) {

        } else {
            std::string firstCompartment = text.substr(0, text.length() / 2);
            std::string secondCompartment = text.substr(text.length() / 2);
            std::cout<<"First: "<<firstCompartment << " "<<firstCompartment.length()<<std::endl;
            std::cout<<"Second: "<<secondCompartment << " "<<secondCompartment.length()<<std::endl;
            char match = ' ';
            for(char i : firstCompartment){
                if(secondCompartment.find(i) != std::string::npos){
                    match = i;
                    std::cout<<"Match val: "<<int(match)<<std::endl;
                    //Asci values uppercase
                    if(int(match) < 91){
                        priorities += int(match) - 38;

                    } else {
                        priorities += int(match) - 96;
                    }
                    break;
                }
            }
            std::cout<<"Match: "<<match<<std::endl;
        }
        std::cout<<"Priorities: "<<priorities<<std::endl;
    }

    //end timer
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    //in ....
    std::cout <<"Answer: "<< "in: " << elapsed.count() << std::endl;
        return 0;
}
