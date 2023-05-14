#include "main.h"
#include <stdio.h>
#define lli  long long int
#include <iostream>

using namespace std;

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
void cheakEval(node * expr, string type,int x){
    lli result;
    if (expr == nullptr){
        printf("can't evaluate an empty Polynomial\n");
    }else{
        result = evaluatePolynomial(expr,x);
        printf("the value of %s( %d ) = %lld\n", type.data(), x, result);
    }
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
                switch (c) {
                    case 1:
                        cheakEval(expression1, "A", x);
                        break;
                    case 2:
                        cheakEval(expression2, "B", x);
                        break;
                    case 3:
                        cheakEval(summation, "summation", x);
                        break;
                    case 4:
                        cheakEval(product, "product", x);
                        break;
                    default:
                        printf("Invalid choice. Please try again.\n");

                }
                break;
            case 6:
                printf("A(x) + B(x) = ");
                summation = addPolynomials(expression1,expression2);
                printPolynomial(summation);
                break;
            case 7:
                printf("A(x) * B(x) = ");
                product = miniMultiply(copyPolynomial(expression1), copyPolynomial(expression2));
                printPolynomial(product);
                break;
            case 8:
                printf("\n1. free A(x)\n");
                printf("2. free B(x)\n");
                printf("3. free summation(x)\n");
                printf("4. free product(x)\n Enter Choise :");
                scanf("%d",choice);

            case 9:
                printf("\nGoodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}