#include "ShuntingYard.hpp"

Queue* ShuntingYard::split(string a, string b)
{
    Queue* qOfStrings = new Queue();
    int signal = 0;
    string stringToSplit = a;
    string delims = b;
    int length = stringToSplit.length();
    int lengthOfDelims = delims.length();
    string temp = "";
    string temp2 = "";
    for(int i = 0; i < length; ++i)
    {   
        char stringAti = stringToSplit.at(i);
        
        for(int j = 0; j < lengthOfDelims; ++j )
        {
            char delimAti = delims.at(j);
            if(stringAti != delimAti)
            {
                temp = stringAti;
                signal = 1;
            }
            else 
            {
                signal = 0;
                if(temp2 != "")
                {
                    qOfStrings->addEnd(temp2);
                    
                }
                temp = stringAti;
                qOfStrings->addEnd(temp);
                
                temp = "";
                temp2 = "";
                break;
            }
        }
        if(signal != 0)
        {
            temp2 = temp2 + temp;
        }
    } 
    if(temp2 != "")
    {
        qOfStrings->addEnd(temp2);
    }
    return qOfStrings;
}

Queue* ShuntingYard::outQ(Queue* inputQ)
{
    
    Queue* outQ = new Queue();
    Stack* operatorStack = new Stack();
    operatorStack->push(" ");
    string temp;
    int count = inQ->count;
    
    for(int i = 0; i < count; i++)
    {
        temp = inQ->getFront();
        
        
        if(temp != "*" && temp != "/" && temp != "+" && temp != "-")
        {
            outQ->addEnd(temp);
                
        }
        else
        {
            int tempPrecedence = this->convertToPrecedence(temp);

            if(!operatorStack->top)
            {
                operatorStack->push(temp);
            }
            else
            {
                while(this->convertToPrecedence(operatorStack->peek()) >= tempPrecedence )
                {
                    outQ->addEnd(operatorStack->pop());
                }
                operatorStack->push(temp);
            }
        } 
    }
    int opCount = operatorStack->count;
    for(int j = 0; j < opCount; j++)
    {
        string temp1 = operatorStack->pop();
        outQ->addEnd(temp1);
        
    }
    
    return outQ;
}


int ShuntingYard::convertToPrecedence(string op)
{
    if(op == "*")
    {
        return 3;
    }
    else if(op == "/")
    {
        return 3;
    }
    else if(op == " ")
    {
        return 1;
    }
    else
    {
        return 2;
    }
}