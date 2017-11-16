#include <iostream>
#include <vector>
#include <stdlib.h>


using namespace std;

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

int adjacentElementsProduct(std::vector<int> inputArray) {

    int largest = 0, length = inputArray.size();
    int out = -1001;
    for(int i = 0; i < length - 1; ++i){
        largest = inputArray[i] * inputArray[i + 1];
        if(largest > out)
            out = largest;
    }
    return out;
}

int shapeArea(int n) {

    return pow(n,2) + pow(n - 1, 2);
}


int makeArrayConsecutive2(std::vector<int> statues) {
    //find the max and min of the vector
    int max = 0, min = INT_MAX;
    int count = 0,i;

    for(i = 0; i < statues.size(); ++i){
        if(statues[i] > max)
            max = statues[i];
        if(statues[i] < min)
            min = statues[i];
    }

    count = max - min - statues.size() + 1;

    return count;
}


//almostIncreasingSequence
int findBadIndex(std::vector<int> sequence, int index){
    if(0 < index && index < sequence.size() -1 ){
        if(sequence[index - 1] >= sequence[index + 1]){
            return index - 1;
        }
    }

    for(int i = index + 1; i < sequence.size() - 1; ++i){
        if(sequence[i] >= sequence[i + 1])
            return i;
    }

    //if no bad indexes
    return -1;
}

bool almostIncreasingSequence(std::vector<int> sequence) {
    //this involves iterating through the array
    //need to test if (i - 1) and (i + 1) are consecutive

    int index  = findBadIndex(sequence, -1);
    if(index == -1)
        return true;

    index = findBadIndex(sequence, index);
    if(index == -1)
        return true;

    index = findBadIndex(sequence, index + 1);
    if(index == -1)
        return true;

    return false;

}

//matrixElementsSum
void zeroOut(std::vector<std::vector<int>>& matrix, int row, int col){
    for(int i = row; i < matrix.size(); ++i){
        matrix[i][col] = 0;
    }

}
int matrixElementsSum(std::vector<std::vector<int>> matrix) {
    //column flag index idicates that all of that column cannot be used to live in
    // i = rows
    // j = cols
    int sum = 0;
    for(int i = 0; i < matrix.size(); ++i){
        for(int j = 0; j < matrix[i].size(); ++j){
            if(matrix[i][j] == 0){
                zeroOut(matrix, i, j);
            }
            sum += matrix[i][j];
        }
    }

    return sum;
}

std::vector<std::string> allLongestStrings(std::vector<std::string> inputArray) {
    int maxLength = (int)inputArray[0].size();
    vector<string> stringArray;
    stringArray.push_back(inputArray[0]);

    for(int i = 1; i < inputArray.size(); ++i){

        if(maxLength < inputArray[i].size()){
            maxLength = (int)inputArray[i].size();
            //clear queue
            stringArray.clear();
            //push back to queue
            stringArray.push_back(inputArray[i]);
        }

        else if(inputArray[i].size() == maxLength){
            stringArray.push_back(inputArray[i]);
        }
    }
    return stringArray;
}

int commonCharacterCount(std::string s1, std::string s2) {
    int numberOfChars = 26;
    int map1[numberOfChars];
    int map2[numberOfChars];
    int length1 = s1.size();
    int length2 = s2.size();
    int common;

    for(int i = 0; i < 26; ++i){
        map1[i] = 0;
    }
    for(int i = 0; i < 26; ++i){
        map2[i] = 0;
    }
    for(int i = 0; i < length1; ++i){
        map1[(int)s1[i] - 97] +=1;
    }

    for(int i = 0; i < length2; ++i){
        map2[(int)s2[i] - 97] +=1;
    }

    for(int i = 0; i < numberOfChars; ++i){
        if(map1[i] && map2[i]){
            if(map1[i] > map2[i]){
                common += map2[i];
            }
            else{
                common += map1[i];
            }
        }
    }


    return common;
}

std::vector<int> sortByHeight(std::vector<int> a){
    vector<int> people;
    for(int i = 0; i < a.size(); ++i){
        if(a[i] != -1){
            people.push_back(a[i]);
        }
    }

    int key, j;

    for(int i = 1; i < people.size(); ++i){
        key = people[i];
        j = i - 1;

        while(j >= 0 && people[j] > key){
            people[j + 1] = people[j];
            j = j - 1;
        }
        people[j + 1] = key;
    }
    int peopleIt = 0;

    for(int i = 0; i < a.size(); ++i){
        if(a[i] != -1){
            a[i] = people[peopleIt];
            ++peopleIt;
        }
    }
    return a;
}

std::vector<int> sortByHeight(std::vector<int> a){
    vector<int> people;
    for(int i = 0; i < a.size(); ++i){
        if(a[i] != -1){
            people.push_back(a[i]);
        }
    }

    int key, j;

    for(int i = 1; i < people.size(); ++i){
        key = people[i];
        j = i - 1;

        while(j >= 0 && people[j] > key){
            people[j + 1] = people[j];
            j = j - 1;
        }
        people[j + 1] = key;
    }
    int peopleIt = 0;

    for(int i = 0; i < a.size(); ++i){
        if(a[i] != -1){
            a[i] = people[peopleIt];
            ++peopleIt;
        }
    }
    return a;
}


std::string reverseParentheses(std::string s) {
    std::string _reverse = "";
    std::string output = "";
    int check = 0;
    for (int i = 0; i<s.size(); i++)
    {
        if (s[i] == '(')
        {
            _reverse += s[i];
            check++;
            continue;

        }
        else if(s[i] == ')')
        {
            std::reverse(_reverse.begin()+_reverse.find_last_of('('), _reverse.end());
            _reverse.erase(_reverse.end()-1);
            check--;
            if (check == 0)
            {
                output += _reverse;
                _reverse = "";
            }
            continue;
        }
        if (_reverse.find('(') != std::string::npos)
        {
            _reverse += s[i];
        }
        else {
            output += s[i];
        }
    }
    return output;
}

std::vector<int> alternatingSums(std::vector<int> a) {
    vector<int> out = {0,0};

    for(int i = 0; i < a.size(); ++i){
        if(i % 2 == 0)
            out[0] += a[i];
        else
            out[1] += a[i];
    }

    return out;
}

std::vector<std::string> addBorder(std::vector<std::string> picture) {
    //number of rows == number of words lenght of picture

    int rows = picture.size();
    int length = picture[0].size() + 2;
    vector<string> newPicture;

    //create new border string
    string borderString;
    for(int i = 0; i < length; ++i){
        borderString += '*';
    }

    newPicture.push_back(borderString);
    for(int i = 0; i < rows; ++i){
        string temp;
        temp += "*";
        temp += picture[i];
        temp += "*";
        newPicture.push_back(temp);
    }
    newPicture.push_back(borderString);


    return newPicture;
}

bool areSimilar(std::vector<int> a, std::vector<int> b) {
    int length = a.size();
    vector<int> stackish;
    int count = 0;
    for(int i = 0;  i < length; ++i){
        if(a[i] != b[i]){
            ++count;
            stackish.push_back(i);
        }
    }

    if(count == 0)
        return true;
    if(count == 2){
        if(a[stackish[0]] == b[stackish[1]] && a[stackish[1]] == b[stackish[0]])
            return true;
        else
            return false;
    }
    return false;
}

int arrayChange(std::vector<int> inputArray) {
    //is the current index less than the following? if not increment next until it, proceed to next index
    int length = inputArray.size() - 1;
    int count = 0;
    for(int i = 0; i < length; ++i){
        while(inputArray[i] >= inputArray[i + 1]){
            ++inputArray[i + 1];
            ++count;
        }
    }

    return count;
}

bool palindromeRearranging(std::string inputString) {
    sort(inputString.begin(), inputString.end());
    for(int i = 1; i < inputString.size(); ++i){
        if(inputString[i] == inputString[i - 1]){
            inputString.erase(i - 1, 2);
            --i;
        }
    }
    return inputString.size() <= 1;

}

bool areEquallyStrong(int yourLeft, int yourRight, int friendsLeft, int friendsRight) {
    bool equalStrength = false;

    if(yourLeft == friendsLeft && yourRight == friendsRight)
        return true;
    else if(yourRight == friendsLeft && yourLeft == friendsRight)
        return true;

    return false;

}

int arrayMaximalAdjacentDifference(std::vector<int> inputArray) {
    int max = 0;
    int temp  = 0;
    int length = inputArray.size();
    for(int i = 0; i < length - 1; ++i){
        temp =abs(inputArray[i + 1] - inputArray[i]);
        if(temp > max)
            max = temp;
    }

    return max;
}

int avoidObstacles(std::vector<int>& inputArray) {
    sort(inputArray.begin(), inputArray.end());
    int result = 0;

    queue<int> numberStack;
    int count = 2;
    int count2 = 0;

    while(count2 < inputArray.size()){
        while(count < inputArray[count2]){
            numberStack.push(count);
            ++count;
        }
        ++count;
        ++count2;
    }

    numberStack.push(count);

    count = 0;
    bool good = false;
    if(numberStack.size() ==1)
        return numberStack.front();

    while(!numberStack.empty() && !good){
        result = numberStack.front();
        numberStack.pop();
        count = 0;
        while(inputArray[count] % result != 0){
            ++count;
            if(count == inputArray.size())
                good = true;
        }
    }


    return result;
}

//box blur
int sum(std::vector<std::vector<int>> image, int i, int j)
{
    int sum = 0;
    for (int k = i - 1; k<i + 2; k++)
    {
        for (int f = j - 1; f<j + 2; f++)
        {
            sum = sum + image[k][f];
        }
    }
    return sum / 9;
}
std::vector<std::vector<int>> boxBlur(std::vector<std::vector<int>> image) {
    vector<vector<int>> v = {};
    vector<int> s = {};

    for (int i = 1; i<image.size() - 1; i++)
    {
        for (int j = 1; j< image[0].size() - 1; j++)
        {
            s.push_back(sum(image, i, j));
        }
        v.push_back(s);
        s.clear();
    }

    return v;
}

int mineCount(std::vector<std::vector<bool>> matrix, int i, int j){
    int count = 0;
    switch(matrix[i][j]){
        case matrix[i][j] && i > 1
    }

    return count;
}

std::vector<std::vector<int>> minesweeper(std::vector<std::vector<bool>> matrix) {
    std::vector<std::vector<int>> out(matrix.size());

    int mineCount = 0;
    //if a there is a mine in that cell value == 1

    //to determine the value for adjacent cells check
    for(int i = 0; i < matrix.size(); ++i){
        for(int j = 0; j < matrix[j].size(); ++j){
            if(matrix[i][j] == true)
                out[i].push_back(1);
            else if(matrix[i][j] == false){

            }
        }
    }

    return out;
}




int main() {
    return 0;
}