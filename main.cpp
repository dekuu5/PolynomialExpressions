#include "main.h"
#include <stdio.h>
#include "IO.h"
#include "node.h"


int main(){
    node * head  = creatTerm(4,5);
    int coef,exp;
    int size;
    scanf("%d",&size);
    for (int i = 0; i < size; ++i) {
        scanf("%d", &coef);
        scanf("%d", &exp);
        insertTerm(&head,coef,exp);
    }
    printPolynomial(head);
    return 0;
}