//
// Created by pc on 5/12/2023.
//

#ifndef POLYNOMIALEXPRESSIONS_MAIN_H
#define POLYNOMIALEXPRESSIONS_MAIN_H


struct node {
    int coef;
    int power;
    node* next;
};

node * creatTerm(int coef,int pow);
void insertTerm(node** head, int coef, int pow);
//node* sum_polynomials(node* head1, node* head2);
//node* multiply_polynomials(node* head1, node* head2);
//int evaluate_polynomial(node* head, int x);


void printPolynomial(node* head);

#endif //POLYNOMIALEXPRESSIONS_MAIN_H
