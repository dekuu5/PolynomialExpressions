#include "main.h"
#include <stdio.h>

int main(){


    node * expression1 = nullptr;
    node * expression2 = nullptr;
    node * summation = nullptr;
    node * product = nullptr;
    node * term = nullptr;
    int choice;
    while (1) {
        printf("\nMENU\n");
        printf("1. Insert a term to expression A(x)\n");
        printf("2. Insert a term to expression B(x)\n");
        printf("3. Print expression A(x)\n");
        printf("4. Print expression B(x)\n");
        printf("5. Sum of the two expressions\n");
        printf("6. Product of the two expressions\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        fflush(stdin);

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
                printf("A(x) + B(x) = ");
                //struct Node* sum_head = add_polynomials(expr1_head, expr2_head);
                //print_polynomial(sum_head);
                //free_polynomial(sum_head);
                break;
            case 6:
                printf("A(x) * B(x) = ");
                //struct Node* product_head = multiply_polynomials(expr1_head, expr2_head);
                //print_polynomial(product_head);
                //free_polynomial(product_head);
                break;
            case 7:
                printf("\nGoodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}