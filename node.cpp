#include "node.h"
#include <stdio.h>
#include <iostream>
#include <string>
#include <stdlib.h>


node * creatTerm(int coef,int pow){
    node * n = (node *)malloc(sizeof(node));
    n->coef = coef;
    n->power= pow;
    n->next = nullptr;
    return n;
}

void insertTerm(node** head, int coef, int pow){
    node * term = creatTerm(coef,pow);
    if (*head == nullptr){
        (*head) = term;
        return;
    }
    node *p = *head;
    while (p->next != nullptr) p = p->next;
    p->next = term;
}