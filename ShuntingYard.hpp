#include <string>
#include <iostream>
#include "Queue.hpp"
#include "Stack.hpp"
using namespace std;

class ShuntingYard
{
    private:

    public:
    
    Queue* split(string a, string b);

    Queue* outQ(Queue* inputQ);
    int convertToPrecedence(string op);

}; 