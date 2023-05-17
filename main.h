//
// Created by pc on 5/12/2023.
//

#ifndef POLYNOMIALEXPRESSIONS_MAIN_H
#define POLYNOMIALEXPRESSIONS_MAIN_H
#define lli  long long int
#include <iostream>

using namespace std;

struct node {
    int coef;
    int power;
    node* next;
};

node * creatTerm(int coef,int pow);
void insertTerm(node** head, node *term);
node * copyPolynomial(node * exp);
node * addPolynomials(node * exp1, node *exp2);
node * recMultiply(node *expr, node * term);
lli evaluatePolynomial(node* head, int x);
int powerX(int x , int p);
void freePolynomial(node* head);
void printPolynomial(node* head);
node* getTerm();
bool validate2(string input);
int getChoise();
int getChoise2();
void cheakEval(node * expr, string type,int x);

#endif //POLYNOMIALEXPRESSIONS_MAIN_H
