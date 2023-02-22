#include "base.h"

using namespace std;

calculator::calculator()
{
    result = 0;
    cout<<"--------------------Serial Calculator---------------------"<<endl;
}

void calculator::setStringOperation()
{   
    string tempOp;
    cout<<"Enter the actions  you want to be performed, respectively."<<endl;
    getline(cin, tempOp);
    while(!(controlStringOperation(tempOp)))
    {
        cout<<"There is an invalid character(s) or definition(s) in your actions."<<endl;
        cout<<"Enter the actions  you want to be performed, respectively."<<endl;
        getline(cin, tempOp);
    }
    operation = tempOp;
}

bool calculator::controlStringOperation(string tempOp)
{
    for(int i=0; i<tempOp.length(); i++)
    {
        if(!((tempOp[i]>='0' && tempOp[i]<='9') || tempOp[i]=='+' || tempOp[i]=='-' || tempOp[i]=='*' || tempOp[i]=='/' || tempOp[i]=='='))
        {
            return false; 
        }

    }
    return true;
}

int calculator::getNumber(int i, int lastLoc)
{
    string number;
    int num;
    number = operation.substr(lastLoc,i);
    num = std::stoi(number);
    return num;
}

char calculator::getOperator(int i)
{
    char op;
    op = operation[i];
    return op;
}

int calculator::calculateOperation()
{
    char op;
    int lastLoc = 0;
    bool start = true;
    for(int i=0; i<operation.length(); i++)
    {
        if(operation[i]=='+' || operation[i]=='-' || operation[i]=='*' || operation[i]=='/' || operation[i]=='=')
        {
            if(start)
            {
                if(!(i==0 && operation[i]))
                {
                    result = getNumber(i, lastLoc);
                    op = getOperator(i);
                    start = false;
                    lastLoc = i+1;
                }
            }
            else
            {
                if(op=='+')
                {
                    result = result + getNumber(i,lastLoc);
                    lastLoc = i+1;
                    op = getOperator(i);
                }
                else if(op=='-')
                {
                    result = result - getNumber(i,lastLoc);
                    lastLoc = i+1;
                    op = getOperator(i);
                }
                else if(op=='*')
                {
                    result = result * getNumber(i,lastLoc);
                    lastLoc = i+1;
                    op = getOperator(i);
                }
                else if(op=='/')
                {
                    result = result / getNumber(i, lastLoc);
                    lastLoc = i+1;
                    op = getOperator(i);
                }
            }
        }
    }
    return result;
}

void calculator::displayResult()
{
    cout<<"="<<result<<endl;
}