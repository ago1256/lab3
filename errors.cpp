#include"errors.h"
#include<stdio.h>
#include<iostream>


void errors_detection(Error error) {
    if (error == Error::OK) {
        return;
    }
    else{
        if(error == Error::IMMUT_SEQ){
            std::cout << "Неизменяемая последовательность.\n";
        }
        if(error == Error::INVALID_INDEX){
            std::cout << "Неправильный индекс.\n";
        }
        if(error == Error::INVALID_ARGUMENT){
            std::cout << "Неправильный аргумент.\n";
        }
        if(error == Error::EMPTY_SEQ){
            std::cout << "Пустая последовательность.\n";
        }
        if(error == Error::INCOMPATIBLE_TYPES){
            std::cout << "Несовместимые типы.\n ";
        }
    }
}
