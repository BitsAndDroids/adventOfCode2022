//
// Created by DaveRiedel on 2-12-2022.
//
#include "RESULTENUM.h"
#include "RPCENUM.h"
#ifndef ADVENTOFCODE2022_RESULT_H
#define ADVENTOFCODE2022_RESULT_H
class Result{
public:

    int getResult(){
        return result;
    }

    Result(int playerA, int playerB){
        this->playerA = playerA;
        this->playerB = playerB;
        calcResult();
    }

    Result(int playerA, int playerB,RESULT result){
        this->playerA = playerA;
        this->result = result;
        calcPlayed();
    }

    int getPlayedValue(){
        return playerB;
    }


private:
    int playerA;
    int playerB;
    RESULT result;
    int calcPlayed(){
        if(result == DRAW){
            playerB = playerA;
        }
        else if(result == LOSS){
            playerB = playerA - 1;
            if(playerB == 0){
                playerB = 3;
            }
        }
        else if (result == WIN){
            playerB = playerA + 1;
            if(playerB == 4){
                playerB = 1;
            }
        }
    }
    int calcResult(){

        if(playerA == playerB){
            result = DRAW;
        } else if(playerA < playerB){
            if(playerA == ROCK && playerB == SCISSORS){
                result = LOSS;
            } else {
                result = WIN;
            }
        } else{
            if(playerA == SCISSORS && playerB == ROCK){
                result = WIN;
            } else {
                result = LOSS;
            }
        }
    }

};
#endif //ADVENTOFCODE2022_RESULT_H
