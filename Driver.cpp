#include <string>
#include <iostream>
using namespace std;
#include "Split.hpp"


int main()
{
    string expression;
    string delims;
    cin >> expression;
    cin >> delims;

    Split* split = new Split(1);
    split->split(expression, delims);
    for(int i = 0; i <= expression.length(); ++i)
    {
        cout << split->stringArray[i] << "\n";
    }
    return 0;
}