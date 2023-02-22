#include<iostream>
#include "base.cpp"

using namespace std;

int main()
{
    system("clear");
    calculator calculate;
    calculate.setStringOperation();
    calculate.calculateOperation();
    calculate.displayResult();
}