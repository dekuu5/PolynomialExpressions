#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
#include <iostream>
#define lli  long long int
using namespace std;

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

int countNodes(node* head) {
    int count = 0;
    node* current = head;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}

void deleteNode(node** head, node* toBeDeleted){
    if (*head == toBeDeleted) {
        *head = toBeDeleted->next;
        free(toBeDeleted);
        return;
    }

    node* current = *head;
    while (current != nullptr && current->next != toBeDeleted) {
        current = current->next;
    }

    if (current != nullptr) {
        current->next = toBeDeleted->next;
        free(toBeDeleted);
    }
}
int * getPowerInArray(node * head, int count){
    int * arr = (int *) malloc(sizeof(int)*count);
    int c = 0;
    node * p = head;
    while (p != nullptr){
        arr[c++] = p->power;
        p = p->next;
    }
    return arr;
}




vector<duplicate> findDuplicates(int *arr, int *arrCount) {
    vector<duplicate> duplicates;
    int size = *arrCount;
    sort(arr, arr + size);
    int count = 1;
    for (int i = 1; i < size; i++) {
        if (arr[i] == arr[i - 1]) {
            count++;
        } else {
            if (count > 1) {
                duplicate dup = {arr[i - 1], count};
                duplicates.push_back(dup);
            }
            count = 1;
        }
    }

    if (count > 1) {
        duplicate dup = {arr[size - 1], count};
        duplicates.push_back(dup);
    }

    int uniqueSize = distance(arr, std::unique(arr, arr + size));
    int* uniqueArr = (int *)malloc(sizeof(int)*uniqueSize);
    copy(arr, arr + uniqueSize, uniqueArr);
    arr = uniqueArr;
    *arrCount = uniqueSize;

    return duplicates;
}

node* getTail(node* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    node* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }

    return current;
}

void insertSorted(node** head, node * n) {

    node* current = *head;
    if (*head == nullptr || n->power < current->power) {
        n->next = *head;
        *head = n;
        return;
    }

    while (current->next != nullptr && current->next->power < n->power) {
        current = current->next;
    }

    n->next = current->next;
    current->next = n ;
}



node * sumTerms(node * head, vector<duplicate> dups){
    if (dups.size() == 0){
        return head;
    }
    node * newHead = nullptr;
    node *tmp2 = nullptr;
    newHead = tmp2;
    node *tmp = nullptr;
    int num = 0;
    int coef = 0;
    for (const auto& dup : dups) {
        num = dup.number;
        coef = 0;
        for (int j = 0; j < dup.frequency; ++j) {
            tmp = head;
            while (tmp != nullptr){
                if (tmp->power == num){
                    coef += tmp->coef;
                    deleteNode(&head, tmp);
                    break;
                }
                tmp = tmp->next;
            }

        }
        if (newHead == nullptr) {
            newHead = creatTerm(coef, num);
            tmp2 = newHead;
        } else {
            tmp2->next = creatTerm(coef, num);
            tmp2 = tmp2->next;
        }
    }
    tmp = head;
    while (tmp != nullptr){
        insertSorted(&newHead, tmp);
        tmp = tmp->next;
    }
    return newHead;

}