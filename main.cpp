#include "main.h"
#include <stdio.h>
#define lli  long long int

int getChoise(){
    int choice;

    printf("1. Insert a term to expression A(x)\n");
    printf("2. Insert a term to expression B(x)\n");
    printf("3. Print expression A(x)\n");
    printf("4. Print expression B(x)\n");
    printf("5. substitute with x\n");
    printf("6. Sum of the two expressions\n");
    printf("7. Product of the two expressions\n");
    printf("8. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    fflush(stdin);
    return choice;
}

int getChoise2(){
    int choice;
    printf("1. Compute A(x) \n");
    printf("2. Compute B(x) \n");
    printf("3. Compute the sum of A(x) and B(x)\n");
    printf("4. Compute the product of A(x) and B(x)\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    fflush(stdin);
    return choice;
}
int main(){
    node * expression1 = nullptr;
    node * expression2 = nullptr;
    node * summation = nullptr;
    node * product = nullptr;
    node * term = nullptr;
    int choice;
    printf("\nMENU\n");
    while (1) {
        choice = getChoise();

        switch (choice) {
            case 1:
                term = getTerm();
                insertTerm(&expression1, term);
                break;
            case 2:
                term = getTerm();
                insertTerm(&expression2, term);
                break;
            case 3:
                printf("\nA(x) = ");
                printPolynomial(expression1);
                break;
            case 4:
                printf("\nF(x) = ");
                printPolynomial(expression2);
                break;
            case 5:
                int c, x;
                c = getChoise2();
                x = 0;
                printf("Enter the value of x: ");
                scanf("%d",&x);
                fflush(stdin);
                lli result;
                switch (c) {
                    case 1:
                        if (expression1 == nullptr){
                            printf("can't evaluate an empty Polynomial\n");
                        }else{
                            result = evaluatePolynomial(expression1,x);
                            printf("the value of A( %d ) = %lld\n", x, result);
                        }
                        break;
                    case 2:
                        if (expression2 == nullptr){
                            printf("can't evaluate an empty Polynomial\n");
                        }else{
                            result = evaluatePolynomial(expression2,x);
                            printf("the value of B( %d ) = %lld\n", x, result);
                        }
                        break;
                    case 3:
                        if (summation == nullptr){
                            printf("can't evaluate an empty Polynomial\n");
                        }else{
                            result = evaluatePolynomial(summation,x);
                            printf("the value of summation( %d ) = %lld\n", x, result);
                        }
                        break;
                    case 4:
                        if (product == nullptr){
                            printf("can't evaluate an empty Polynomial\n");
                        }else{
                            result = evaluatePolynomial(product,x);
                            printf("the value of product( %d ) = %lld\n", x, result);
                        }
                        break;
                    default:
                        printf("Invalid choice. Please try again.\n");

                }
                break;
            case 6:
                printf("A(x) + B(x) = ");
                //struct Node* sum_head = add_polynomials(expr1_head, expr2_head);
                //print_polynomial(sum_head);
                //free_polynomial(sum_head);
                break;
            case 7:
                printf("A(x) * B(x) = ");
                //struct Node* product_head = multiply_polynomials(expr1_head, expr2_head);
                //print_polynomial(product_head);
                //free_polynomial(product_head);
                break;
            case 8:
                printf("\nGoodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}