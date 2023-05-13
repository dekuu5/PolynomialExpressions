//
// Created by pc on 5/12/2023.
//

#ifndef POLYNOMIALEXPRESSIONS_MAIN_H
#define POLYNOMIALEXPRESSIONS_MAIN_H
#define lli  long long int

struct node {
    int coef;
    int power;
    node* next;
};

node * creatTerm(int coef,int pow);
void insertTerm(node** head, node *term);
//node* sum_polynomials(node* head1, node* head2);
//node* multiply_polynomials(node* head1, node* head2);
lli evaluatePolynomial(node* head, int x);
int powerX(int x , int p);

void printPolynomial(node* head);
node* getTerm();


#endif //POLYNOMIALEXPRESSIONS_MAIN_H
