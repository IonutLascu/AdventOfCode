#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

ifstream in("input.txt");

int convertBinaryToDecimal(string& input, char c1, char c2)
{
    int decimalNumber = 0, ct = 0, product = 0;
    for (auto i : input) {
        if (i == c1) {
            product = 0;
        }
        else if (i == c2) {
            product = 1;
        }
        else
            continue;
        decimalNumber += product * pow(2, ct++);
    }
    return decimalNumber;
}

int getMissingNumber(vector<int>& vct)
{
    const int minNumber = *min_element(vct.begin(), vct.end());
    const int maxNumber = *max_element(vct.begin(), vct.end());
    
    int sum = 0;
    for (auto i : vct) {
        sum += i;
    }

    const int sumUntilMin = ((minNumber - 1) * minNumber) / 2;
    return (maxNumber * (maxNumber + 1)) / 2 - sumUntilMin - sum;
    
}

int main()
{
    string input;
    int row = 0, column = 0, firstPart = -1;
    vector<int> vct;
    while (!in.eof()) {
        in >> input;
        reverse(input.begin(), input.end());

        row = convertBinaryToDecimal(input, 'F', 'B');
        column = convertBinaryToDecimal(input, 'L', 'R');

        int currentVal = row * 8 + column;
        if (firstPart < currentVal) {
            firstPart = currentVal;
        }
        vct.push_back(currentVal);
    }
    std::cout << firstPart << " \n";
    std::cout << getMissingNumber(vct);
}
