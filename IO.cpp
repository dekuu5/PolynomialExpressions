#include "main.h"
#include <stdio.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include "main.h"
#include <stdbool.h>
using namespace std;


bool validate(string input, const string type){
    char c;
    if(type == "coef"){
        for (int i = 0; i < input.length(); ++i) {
            c = input[i];
            if (!(isdigit(c) || c == '-')) {
                cout << "Invalid input. Please enter a non-zero integer." << endl;
                fflush(stdin);
                return false;
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
    if (current->coef > 0) {
        printf("%dx^%d", current->coef, current->power);
    } else if (current->coef < 0) {
        printf("- %dx^%d", -1 * current->coef, current->power);
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