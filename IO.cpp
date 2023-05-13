#include "main.h"
#include <stdio.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include "node.h"


void printPolynomial(node* head){
    node* current = head;
    if (current == NULL) {
        printf("Polynomial is empty.\n");
        return;
    }
    if (current->coef > 0) {
        printf("\n A( x ) = %dx^%d", current->coef, current->power);
    } else if (current->coef < 0) {
        printf("\n A( x ) = - %dx^%d", -1 * current->coef, current->power);
    }
    current = current->next;
    while (current != nullptr) {
        if (current->coef > 0) {
            printf(" + %dx^%d", current->coef, current->power);
        } else if (current->coef < 0) {
            printf(" - %dx^%d", -1 * current->coef, current->power);
        }
        current = current->next;
    }
    printf("\n");
}