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

int getMissingNumber(const int min, const int max, int sum)
{
    const int sumUntilMin = ((min - 1) * min) / 2;
    return (max * (max + 1)) / 2 - sumUntilMin - sum;
}

int main()
{
    string input;
    int row = 0, column = 0, maxValue = -1, minValue = INT_MAX, sum = 0;
    while (!in.eof()) {
        in >> input;
        reverse(input.begin(), input.end());

        row = convertBinaryToDecimal(input, 'F', 'B');
        column = convertBinaryToDecimal(input, 'L', 'R');

        int currentVal = row * 8 + column;
        maxValue = max(maxValue, currentVal);
        minValue = min(minValue, currentVal);
        sum += currentVal;
    }
    std::cout << maxValue << " \n";
    std::cout << getMissingNumber(minValue, maxValue, sum);
}
