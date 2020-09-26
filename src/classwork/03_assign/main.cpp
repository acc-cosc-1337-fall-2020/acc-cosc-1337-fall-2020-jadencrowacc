//Write the include statement for decisions.h here
#include <decision.h>
//Write namespace using statements for cout and cin
#include <iostream>

using namespace std;

int main() {
    int grade;
    cout << "Numeric Grade: ";
    cin >> grade;
    cout << "Letter Grade: " << get_letter_grade_using_if(grade) << "\n";
}

