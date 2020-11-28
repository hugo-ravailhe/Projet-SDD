#include <stdio.h>
#include <stdlib.h>
#include "structures.h"
#include "print_structures.h"

void PrintListCode(ListCode *L){
    while(L != NULL){
        printf("%c ", L->data);
        L = L->next;
    }
    printf("NULL\n");
}

void PrintTabChar(char* tab){
    int i = 0;
    while (tab[i] != '\0'){
        printf("%c", tab[i]);
        i++;
    }
}

void PrintCode(Code* C){
    while(C != NULL){
        printf("%c ", C->data);
        C = C->next;
    }
    printf("NULL\n");
}

void PrintList(List* L){
    while(L != NULL){
        printf("( %c, %d ) -> ", L->data, L->occu);
        L = L->next;
    }
    printf("NULL\n");
}

void PrintListNode(ListNode* L){
    while(L != NULL){
        printf("( %c, %d ) -> ", L->data->data, L->data->occu);
        L = L->next;
    }
    printf("NULL\n");
}

void printABR(Node *B, int x){
    int i;
    for(i = 0; i < x; i++){
        printf("\t");
    }
    if(x != 0)
        printf("|---");
    if(B == NULL){
        printf(" NULL \n");
    }else if(B->data != '\0'){
        printf(" %c, %d \n", B->data, B->occu);
        printABR(B->left, x + 1);
        printABR(B->right, x + 1);
    } else{
        printf(" NULL, %d \n", B->occu);
        printABR(B->left, x + 1);
        printABR(B->right, x + 1);
    }
}

void PrintTree(Node* B){
    if (B != NULL)
        printABR(B, 0);
    else
        printf("Arbre vide");
}

void printABRCode(NodeCode *B, int x){
    int i;
    for(i = 0; i < x; i++){
        printf("\t");
    }
    if(x != 0)
        printf("|---");
    if(B == NULL){
        printf(" NULL \n");
    }else if(B->data != '\0'){
        printf(" %c, ", B->data);
        PrintCode(B->code);
        printf("\n");
        printABRCode(B->left, x + 1);
        printABRCode(B->right, x + 1);
    }
}

void PrintABRCode(NodeCode *B){
    if (B != NULL)
        printABRCode(B, 0);
    else
        printf("Arbre vide");
}