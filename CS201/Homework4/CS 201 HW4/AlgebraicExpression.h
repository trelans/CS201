//
// Created by Kutay Şenyiğit on 29.12.2021.
//

#ifndef HOMEWORK4_ALGEBRAICEXPRESSION_H
#define HOMEWORK4_ALGEBRAICEXPRESSION_H
#include <iostream>

using namespace std;


    // It converts an infix expression exp to its equivalent prefix form.
    string infix2prefix( const string exp );
// It converts an infix expression exp to its equivalent postfix form.
    string infix2postfix( const string exp );
// It converts a prefix expression exp to its equivalent infix form.
    string prefix2infix( const string exp );
// It converts a prefix expression exp to its equivalent postfix form.
    string prefix2postfix( const string exp );
// It converts a postfix expression exp to its equivalent infix form.
    string postfix2infix( const string exp );
// It converts a postfix expression exp to its equivalent prefix form.
    string postfix2prefix( const string exp );
//It evaluates an infix expression.
    double evaluateInfix( const string exp );
//It evaluates a prefix expression.
    double evaluatePrefix( const string exp );
//It evaluates a postfix expression.
    double evaluatePostfix( const string exp );




   bool isCorrectOperator(string x);
   int precedence(string x);
   string charToString(char x);
   int stringToInt(string x);
   void reverseString(char* x , string& result);




#endif //HOMEWORK4_ALGEBRAICEXPRESSION_H
