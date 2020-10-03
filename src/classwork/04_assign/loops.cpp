//cpp

#include "loops.h"

int factorial(int num) {
    for (int i = num - 1; i > 0; i--) {
        num *= i;
    }
    return num;
}

