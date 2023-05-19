#include "main.h"
#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;


bool validate(string input, const string type){
    char c;
    if (input.length()< 1 || input.length()> 7){
        return false;
    }
    if(type == "coef"){
        int dashCount = 0;
        for (int i = 0; i < input.length(); ++i) {
            c = input[i];
            if (!(isdigit(c) || c == '-')  || dashCount > 1) {
                cout << "Invalid input. Please enter a non-zero integer." << endl;
                fflush(stdin);
                return false;
            } else if (c == '-'){
                dashCount++;
            }
        }
    } else if (type == "power"){
        for (int i = 0; i < input.length(); ++i) {
            if (!isdigit(input[i])) {
                cout << "Invalid input. Please enter a non-zero integer." << endl;
                fflush(stdin);
                return false;
            }
        }
    }
    return true;
}
node* getTerm(){
    int coef, pow;
    string input;

    while (true) {
        cout << "Enter the coefficient: ";
        getline(cin, input);
        if (validate(input,"coef")){
            coef = stoi(input);
        } else continue;

        if (coef == 0) {
            cout << "Invalid input. Please enter a non-zero integer." << endl;

            continue;
        }

        break;
    }

    while (true) {
        cout << "Enter the exponent: ";
        getline(cin, input);
        if (validate(input,"power")){
            pow = stoi(input);
        } else continue;

        if (pow < 0) {
            cout << "Invalid input. Please enter a non-negative integer." << endl;
            continue;
        }

        break;
    }
    node * n = creatTerm(coef,pow);
    return n;
}


void printPolynomial(node* head){
    node* current = head;
    if (current == NULL) {
        printf("Polynomial is empty.\n");
        return;
    }
    if (current->power == 0){
        if (current->coef > 0) {
            printf(" %d", current->coef);
        } else if (current->coef < 0) {
            printf(" - %dx", -1 * current->coef);
        }
    }else {
        if (current->coef > 0) {
        printf("%dx^%d", current->coef, current->power);
    } else if (current->coef < 0) {
        printf("- %dx^%d", -1 * current->coef, current->power);
    }}
    current = current->next;
    while (current != nullptr) {
        if (current->power == 0){
            if (current->coef > 0) {
                printf(" + %d", current->coef);
            } else if (current->coef < 0) {
                printf(" - %dx", -1 * current->coef);
            }
        }
        else {
            if (current->coef > 0) {
            printf(" + %dx^%d", current->coef, current->power);
        } else if (current->coef < 0) {
            printf(" - %dx^%d", -1 * current->coef, current->power);
        }

    }
        current = current->next;
    }
    printf("\n");
}
bool validate2(string input){
    if (input.length()< 1){
        return false;
    }
    for (int i = 0; i < input.length(); ++i) {
        if (!isdigit(input[i])) {
            return false;
        }
    }

    return true;
}
int getChoise(){
    string choice;
    int c;
    printf("\n-------------------------------------------\n");
    printf("1. Insert a term to expression A(x)       #\n");
    printf("2. Insert a term to expression B(x)       #\n");
    printf("3. Print expression A(x)                  #\n");
    printf("4. Print expression B(x)                  #\n");
    printf("5. substitute with x                      #\n");
    printf("6. Sum of the two expressions             #\n");
    printf("7. Product of the two expressions         #\n");
    printf("8. free an expression                     #\n");
    printf("9. Exit                                   #\n");
    printf("-------------------------------------------\n");
    printf("Enter your choice: ");
    getline(cin, choice);
    fflush(stdin);
    if (validate2(choice)){
        c = stoi(choice);
        return c;
    } else {
        return -1;
    }

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