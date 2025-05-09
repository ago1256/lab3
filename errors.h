#pragma once

#include<iostream>
#include <stdexcept>
#include <string>

enum class Error{
    OK = 0,
    IMMUT_SEQ = 1,
    INVALID_INDEX = 2,
    INVALID_ARGUMENT = 3,
    EMPTY_SEQ = 4,
    INCOMPATIBLE_TYPES = 5
};

void errors_detection(Error error);
