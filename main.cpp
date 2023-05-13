#include "main.h"
#include <stdio.h>


int main(){
    node * head  = nullptr;
    int coef,exp;
    int size;
    scanf("%d",&size);
    for (int i = 0; i < size; ++i) {
        scanf("%d", &coef);
        scanf("%d", &exp);
        insertTerm(&head,coef,exp);
    }
    printPolynomial(head);
    int x;
    scanf("%d",&x);
    printf("the A( %d ) = %d", x, evaluatePolynomial(head,x));
    return 0;
}