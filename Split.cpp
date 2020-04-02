#include "Split.hpp"

Queue* Split::split(string a, string b)
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