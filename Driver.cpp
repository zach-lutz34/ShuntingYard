#include <string>
#include <iostream>
using namespace std;
#include "ShuntingYard.hpp"


int main()
{
    string expression;
    string delims;
    cin >> expression;
    cin >> delims;

    ShuntingYard* shuntyard = new ShuntingYard();
    Queue* inQ = shuntyard->split(expression, delims);
    cout << std::to_string(inQ->count);
    cout << "\n";
    cout << "\n";
    inQ->display();
    cout << "\n";
    cout << inQ->peek();
    cout << "\n";
    cout << "\n";
    Queue* outQ = shuntyard->outQ(inQ);
    outQ->display();
    cout << "\n";
    cout << outQ->peek();
    cout << "\n";
    
    return 0;
}