//cpp
#include "decision.h"

char get_letter_grade_using_if(int grade) {
    if (grade > 90)
        return 'A';
    if (grade > 80)
        return 'B';
    if (grade > 70)
        return 'C';
    if (grade > 60)
        return 'D';
    return 'F';
    return 0;
}

char get_letter_grade_using_switch(int grade) {
    switch (grade / 10) {
        case 10:
            return 'A';
        case 9:
            return 'A';
        case 8:
            return 'B';
        case 7:
            return 'C';
        case 6:
            return 'D';
        case 5:
        case 4:
        case 3:
        case 2:
        case 1:
        case 0:
            return 'F';
        default:
            return 'I';//message to indicate invalid/must use string
    }
}

