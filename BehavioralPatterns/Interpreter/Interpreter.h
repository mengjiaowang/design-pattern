/* Interpreter Pattern
 * Given a language, define a represention for its grammer along
 * with an interpreter that uses the representation to interpret
 * sentences in the language.
 */

#ifndef INTERPRETER_H_
#define INTERPRETER_H_

#include <map>
using namespace std;

/* contains information that's global to the interpreter */
class Context
{
    public:
        Context();
        void addElement(string &name, int num);
        int getElement(string &name);
    private:
        std::map<string, int> _map;
};

/* declares an abstract Interpret operation that is common to all
 * nodes in the abstract syntax tree.
 */
class AbstractExpression
{
    public:
        virtual int Interpret(Context &c) = 0;
};

/* 1. implements an Interpret operation associated with terminal symbols
 * in the grammar.
 * 2. an instance is required for every terminal symbol in a sentence.
 */
class NumberTerminalExpression: public AbstractExpression
{
    public:
        NumberTerminalExpression(int num);
        virtual int Interpret(Context &c);
    private:
        int num;
};

/* 1. one such class is required for every rule R ::= R1R2...Rn in the
 * grammar.
 * 2. maintains instance variables of type AbstractExpression for each
 * of the symbols R1 through Rn.
 * 3. implements an Interpret operation for non-terminal symbols in the
 * grammar. Interpret typically calls itself recursively on the variables
 * representing R1 through Rn.
 */
class AddNonterminalExpression: public AbstractExpression
{
    public:
        AddNonterminalExpression(AbstractExpression &left, AbstractExpression &right);
        virtual int Interpret(Context &c);
    private:
        AbstractExpression &left;
        AbstractExpression &right;
};

/* 1. builds (or is given) an abstract syntax tree representing a particular
 * sentence in the language that the grammar defines. The abstract syntax
 * tree is assembled from instances of the NonterminalExpression and
 * TerminalExpression classes.
 * 2. invoke the Interpret operation.
 */
class Client
{
    public:
        Client();
        void Operation();
};

#endif
