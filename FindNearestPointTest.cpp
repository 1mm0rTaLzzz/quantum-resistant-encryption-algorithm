#include "FindNearestPoint.cpp"
#include <iostream>


void PrintVector(std::vector<double> a)
{
    for (double i : a)
        std::cout << i << ' ';
    std::cout << '\n'; 
}

int main()
{
    std::vector<double> a = {2, 2, 2};
    std::vector<double> b = {1, 1, 1};
    PrintVector(a*2);
    //TODO: write tests for all functions
}