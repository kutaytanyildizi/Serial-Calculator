#include<iostream>
#include<cstring>

using namespace std;

class calculator
{
    private:
    string operation;
    int result;

    public:
    calculator();
    ~calculator(){}
    void setStringOperation();
    string getStringOperation() const{return operation;}
    bool controlStringOperation(string tempOp);
    int calculateOperation();
    int getNumber(int i, int lastLoc);
    char getOperator(int i);
    void displayResult();
};