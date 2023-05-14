#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#define lli  long long int

node * creatTerm(int coef,int pow){
    node * n = (node *)malloc(sizeof(node));
    n->coef = coef;
    n->power= pow;
    n->next = nullptr;
    return n;
}
int powerX(int x , int p){
    int result = 1;
    for (int i = 0; i < p; ++i) {
        result *= x;
    }
    return result;
}

void insertTerm(node** head, node *term){
    if (*head == nullptr){
        (*head) = term;
        return;
    }
    node *p = *head;
    while (p->next != nullptr) p = p->next;
    p->next = term;
}

lli evaluatePolynomial(node* head, int x){
    if (head == nullptr){
        printf("can't evaluate an empty Polynomial\n");
        return -0;
    }
    lli result = 0;
    node * p = head;
    while (p != nullptr){
        result += (p->coef) * powerX(x,p->power) ;
        p = p->next;
    }
    return result;
}


node * copyPolynomial(node * expr){
    node * copy = creatTerm(expr->coef,expr->power);
    node *p = expr->next;
    node *tmp = copy;
    while (p!= nullptr){
        tmp->next = creatTerm(p->coef,p->power);
        tmp = tmp->next;
        p = p->next;
    }
    return copy;

}
node * addPolynomials(node * exp1, node *exp2){
    node* copy1 = copyPolynomial(exp1);
    node* copy2 = copyPolynomial(exp2);
    node * tmp = copy1;
    while (tmp->next != nullptr) tmp = tmp->next;
    tmp->next = copy2;
    return copy1;
}
node * recMultiply(node *expr, node * term){
    if(term == nullptr){
    } else {
        node * tmp = expr;
        while (tmp != nullptr){
            tmp->coef *= term->coef;
            tmp->power += term->power;
            tmp = tmp->next;
        }
        recMultiply(expr, term->next);
    }
    return expr;
}
void freePolynomial(node* head){
    node* p ;
    while (head != nullptr) {
        p = head;
        head = head->next;
        free(p);
    }
}


