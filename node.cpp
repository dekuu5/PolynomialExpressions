#include "main.h"
#include <stdio.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <math.h>
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



