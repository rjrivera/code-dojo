#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<string>
using namespace std;

enum Token_value {
    NAME, NUMBER, END,
    PLUS='+', MINUS='-', MUL='*', DIV='/',
    PRINT=';', ASSIGN='=', LP='(', RP=')'
}

Token_value curr_tok = PRINT;

double number_value;
string string_value;

double expr(bool get);

double term(bool get);

double prim(bool get);

double expr(bool get)
{

    double left = term(get);

    for(;;)
        switch(curr_tok){
            case PLUS:
                left += term(true);
                break;
            case MINUS:
                left -= term(true);
                break;
            default:
                return left;
        }
}

double term(bool get)
{
    double left = prim(get);
    for(;;)
        switch(curr_tok){

            case MUL:
                left *= prim(true);
                break;
            case DIV:
                if(double d = prim(true)){
                    left /= d;
                    break;
                }
                return error("divide by 0");
            default:
                return left;

        }

}

double prim(bool get)
{

    if (get get_token();

            switch(curr_tok){
            case NUMBER:
            {
                double v = number_value;
                get_token();
                return v;
            }
            case NAME:
            {
                double& v = table[string_value];
                get_token();
                return v;
            }
            case MINUS: 
                return -prim(true);
            case LP:
            {
                double e = expr(true);
                if(curr_tok !=RP) return error("')' expected");
                get_token(); //eat')'
                return e;//proceed.

            }
            default:
                return error("primary expected");
            }

}
