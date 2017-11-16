#include <iostream>

int add(int param1, int param2) {
    return param1 + param2;
}


int centuryFromYear(int year) {
    float value = (float)year / 100;
    //convert to float
    //test if the float value is == to the orginal value / 100
    if(value == year /100){
        return value;
    }
    return (year / 100) + 1;

}


bool checkPalindrome(std::string inputString) {

    if(inputString.length() == 1){
        return true;
    }

    int i = 0, j = inputString.length() -1;
    while(i < j){
        if(inputString[i] != inputString[j]){
            return false;
        }
        ++i;
        --j;
    }
    return true;
}


int main() {
    return 0;
}