#include "Split.hpp"

Split::Split(int b)
{   
    this->a = b;
}

void Split::split(string a, string b)
{
    int signal = 0;
    int count = 0;
    string stringToSplit = a;
    string delims = b;
    int length = stringSplit.length();
    int lengthOfDelims = delims.length();
    string temp = "";
    string temp2 = "";
    for(int i = 0; i < length; ++i)
    {   
        char stringAti = stringSplit.at(i);
        
        for(int j = 0; j < lengthOfDelims; ++j )
        {
            char delimAti = delims.at(j);
            if(stringAti != delimAti) //not a delimeter
            {
                temp = stringAti;
                signal = 1;
            }
            else //a delimeter
            {
                signal = 0;
                if(temp2 != "")
                {
                    this->stringArray[count] = temp2;
                    ++count;
                }
                temp = stringAti;
                this->stringArray[count] = temp;
                ++count;
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
        this->stringArray[count] = temp2;
        ++count;
    }
}