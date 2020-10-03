//write includes statements
#include <loops.h>
#include <iostream>
//write using statements for cin and cout
using std::cin; using std::cout;

/*
Use a do while loop to prompt the user for
a number, call the factorial function, and display the number's
factorial.  Also, loop continues as long as user wants to.
*/
int main() {
    int num;
    do {
        cout << "Type a number from 1-10 or 0 to quit: \n";
        cin >> num;
        if (num > 0 && num <= 10)
            cout << factorial(num) << "\n";
        else if (num == 0)
            cout << "Quitting...\n";
        else
            cout << "Invalid  input.\n";
    } while (num != 0);
}