// AdventOfCode_9.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <queue>
#include <list>
#include <unordered_set>
#include <algorithm>
using namespace std;

ifstream in("input.txt");
const int range = 25;

bool twoSum(const unordered_set<long long int>& set, int value) {
    for (auto i : set) {
        auto res = set.find(value - i);
        if (res != set.end()) {
            if (*res != i) {
                return true;
            }
        }
    }
    return false;
}

int checkSum(unordered_set<long long int>& set, list<long long int>& list) 
{
    if (range < list.size()) {
        if (!twoSum(set, list.back())) {
            return list.back();
        }
        else {
            set.erase(list.front());
            list.erase(list.begin());
        }
    }
    return 0;
}

int getSequencesSum(list<long long int>& list, int value)
{
    int sum = 0, minValue = INT_MAX, maxValue = INT_MIN;
    for (auto i = list.begin(); i != list.end(); ++i) {
        for (auto j = i; j != list.end(); ++j) {
            sum += *j;
            
            minValue = min<long long int>(*j, minValue);
            maxValue = max<long long int>(*j, maxValue);
            
            if (sum == value) {
                return minValue + maxValue;
            }
            else if (sum > value) {
                minValue = INT_MAX;
                maxValue = INT_MIN;
                sum = 0;
                break;
            }
        }
    }
    return 0;
}

int main()
{
    list<long long int> allNrs;
    list<long long int> list;
    unordered_set<long long int> set;
    int part1Value = 0;
    long long input;
    while (!in.eof()) {
        in >> input;
        set.insert(input);
        list.push_back(input);
        allNrs.push_back(input);
        if (part1Value == 0) {
            part1Value = checkSum(set, list);
        }
    }
    std::cout << part1Value << "\n";
    std::cout << getSequencesSum(allNrs, part1Value) << "\n";
}