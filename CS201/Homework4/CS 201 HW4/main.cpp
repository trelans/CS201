//
// Created by Kutay Şenyiğit on 5.01.2022.
//
#include "AlgebraicExpression.h"

int main () {


        cout << infix2prefix("45 + 21 * ( 32 - 21 )") << endl;
        cout << infix2postfix("45 + 21 * ( 32 - 21 )") << endl;
        cout << evaluateInfix("45 + 21 * ( 32 - 21 )") << endl;
        cout << prefix2infix("* + / 400 - 6 4 60 2") << endl;
        cout << prefix2postfix("* + / 400 - 6 4 60 2") << endl;
        cout << evaluatePrefix("* + / 400 - 6 4 60 2") << endl;
        cout << postfix2infix("400 6 4 - 8 + / 4 *") << endl;
        cout << postfix2prefix("400 6 4 - 8 + / 4 *") << endl;
        cout << evaluatePostfix("400 6 4 - 8 + / 4 *") << endl;


        return 0 ;
    }


