#include <iostream>
#include <string>

using namespace std;

int Decode(const char* CodeString, int Position, int PreviousValue) {
    // When we have reached the end of the string
    if(CodeString[Position] == '\0') return(0);

    int NextValue = 0;
    switch (CodeString[Position]) {
        case 'M': NextValue = 1000;  break;
        case 'D': NextValue = 500;  break;
        case 'C': NextValue = 100;  break;
        case 'L': NextValue = 50;   break;
        case 'X': NextValue = 10;   break;
        case 'V': NextValue = 5;    break;
        case 'I': NextValue = 1;    break;
    }
    if(PreviousValue < NextValue) NextValue -= PreviousValue * 2;
    return(NextValue + Decode(CodeString, Position+1, NextValue));
}

int main()
{
    cout << "Please enter a value as valid formated Roman numerals ";
    string UserInput = "";
    cin >> UserInput;
    int Answer = Decode(UserInput.c_str(), 0, 0);
    cout << "The answer is " << Answer << endl;
    return 0;
}
