#include "Interpreter.h"
#include <iostream>
using namespace std;

Context::Context()
{
}

void Context::addElement(string &name, int num)
{
    _map[name] = num;
}

int Context::getElement(string &name)
{
    // TODO: check if the element exist in the map or not
    return _map[name];
}

NumberTerminalExpression::NumberTerminalExpression(int num): num(num)
{
}

int NumberTerminalExpression::Interpret(Context &c)
{
    return this->num;
}

AddNonterminalExpression::AddNonterminalExpression(
        AbstractExpression &left,
        AbstractExpression &right
): left(left), right(right)
{
}

int AddNonterminalExpression::Interpret(Context &c)
{
    return left.Interpret(c) + right.Interpret(c);
}

Client::Client()
{
}

void Client::Operation()
{
    string str1 = "a";
    string str2 = "b";
    Context context;
    context.addElement(str1, 1);
    context.addElement(str2, 2);
    NumberTerminalExpression num1(context.getElement(str1));
    NumberTerminalExpression num2(context.getElement(str2));
    AddNonterminalExpression sum(num1, num2);
    cout << sum.Interpret(context) << endl;
}


