//
// Created by Kutay Şenyiğit on 29.12.2021.
//
#include <sstream>
#include "AlgebraicExpression.h"
#include "Stack.h"


string infix2prefix(const string exp) {
    string postfix = infix2postfix(exp);
        return postfix2prefix(postfix);
}
string infix2postfix(const string exp) {
    string result = "";
    Stack<string> s;
    for (int i = 0; i < exp.size(); ++i) {
        string curr = charToString(exp[i]);

        if (isCorrectOperator(curr)) {
            string currChar;
            s.getTop(currChar);

            while (!s.isEmpty() && currChar != "(" && precedence(curr) <= precedence(currChar)) {
                result += " " + currChar;
                s.pop();
                s.getTop(currChar);
            }
            s.push(curr);
        }
        else if(curr == "(") {
            s.push(curr);
        }
        else if(curr == ")") {
            string currStr;
            s.getTop(currStr );
            while (currStr != "(") {
                result += " ";
                result +=  currStr;
                s.pop();
                s.getTop(currStr);
            }


        }

        else if (isdigit(exp[i])) {
            if (result.size() >= 1)
                result = result + " ";
            while (exp[i] != ' ' && exp[i] != '\0' && exp[i] != ')') {
                result += exp[i] ;
                i++;
            }


        }


    }
    while (!s.isEmpty()) {
        string top;
        s.getTop(top);
        if (top != "(" ) {
            result += " ";
            result += top ;
        }
        s.pop();
        s.getTop(top);
    }

    return result;
}
string prefix2infix(const string exp) {
    string postfix = prefix2postfix(exp);
    return postfix2infix(postfix);
}
string prefix2postfix(const string exp) {


    Stack<string> nums;

    for (int i = exp.size()-1 ; i >= 0; i--) {
        if (isdigit(exp[i])) {
            string num;
            while (exp[i] != ' ') {
                num += charToString(exp[i]);
                i--;
            }
            // TODO REVERSE num
            char  *rev = &num[0];
            string  res;
            reverseString(rev , res);
            num = res;
            nums.push(num );

        }
        else if (isCorrectOperator(charToString(exp[i]))) {
            string temp = "";
            string op = "o";
            op[0] = exp[i];


            string num1, num2;
            nums.pop(num1);
            nums.pop(num2);

            temp =  num1 + " " + num2 + " " + op ;


            nums.push(temp);
        }

    }
    string resultSt = "";
    while (!nums.isEmpty()) {
        string curr;
        nums.pop(curr);
        resultSt +=  curr;
    }
    return resultSt;


}

string postfix2infix(const string exp) {

    Stack<string> nums;

    for (int i = 0 ; i < exp.size(); ++i) {
        if (isdigit(exp[i])) {

            string num;
            while (exp[i] != ' ') {
                num += charToString(exp[i]);
                i++;
            }
            nums.push(num);

        }
        else if (isCorrectOperator(charToString(exp[i]))) {
            string temp = "";
            string op = "o";
            op[0] = exp[i];


            string num1, num2;
            nums.pop(num1);
            nums.pop(num2);

            temp = "( " + num2 + " " + op +  " " + num1 + " )";


            nums.push(temp);
        }

    }
    string resultSt = "";
    while (!nums.isEmpty()) {
        string curr;
        nums.pop(curr);
        resultSt +=  curr;
    }
    return resultSt;
}

string postfix2prefix(const string exp) {

    Stack<string> nums;

    for (int i = 0 ; i < exp.size(); ++i) {
        if (isdigit(exp[i])) {

            string num;
            while (exp[i] != ' ') {
                num += charToString(exp[i]);
                i++;
            }
            nums.push(num);

        }
        else if (isCorrectOperator(charToString(exp[i]))) {
            string temp = "o";
            temp[0] = exp[i];

                string num1, num2;
                nums.pop(num1);
                nums.pop(num2);

                temp += " " + num2 + " " + num1 ;


            nums.push(temp);
        }

    }
    string resultSt = "";
    while (!nums.isEmpty()) {
        string curr;
        nums.pop(curr);
        resultSt +=  curr + " ";
    }
    return resultSt;
}

double evaluateInfix(const string exp) {
    string postfix = infix2postfix(exp);
    return evaluatePostfix(postfix);
}

double evaluatePrefix(const string exp) {
    string postfix = prefix2postfix(exp);
    return evaluatePostfix(postfix);
}

double evaluatePostfix(const string exp) {

    Stack<int> nums;
    double result;

    for (int i = 0; i < exp.size(); ++i) {

        if (isdigit(exp[i])) {
            string num;
            while (exp[i] != ' ') {
                num += charToString(exp[i]);
                i++;
            }
            nums.push(stringToInt(num));
        }

        else if(isCorrectOperator(charToString(exp[i])) && !nums.isEmpty()) {
            int exp1 , exp2;
            nums.pop(exp1);
            nums.pop(exp2);
            if (exp[i] == '+') {
                result = exp2 + exp1;
            }
            else if (exp[i] == '-') {
                result = exp2 - exp1;
            }
            else if (exp[i] == '/') {
                result = exp2 / exp1;
            }
            else if (exp[i] == '*') {
                result = exp2 * exp1;
            }

            nums.push(result);
        }
    }
    return result;
}


string charToString(char x) {
    string a = "s";
    a[0] = x;
    return a;
}


bool isCorrectOperator(string x) {
    if(x == "+" || x == "-" || x == "*" || x == "/") {
        return true;
    }
    return false;

}

int precedence(string x) {
    if (isCorrectOperator(x) ) {
        if (x == "+" || x == "-") {
            return 1;
        }
        else if (x == "*" || x == "/") {
            return 2;
        }
    }
}

int stringToInt(string x) {
    stringstream numb(x);
    int r;
    numb >> r;
    return r;
}

 void reverseString(char *x , string& res) {
    if ( x[0] == '\0' )
        return;
    reverseString( x + 1, res );
    res += charToString(x[0]);
}