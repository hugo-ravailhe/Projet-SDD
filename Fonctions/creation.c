#include <stdio.h>
#include <stdlib.h>
#include "structures.h"
#include "creation.h"

List* CreationList(char c){
    List *P = malloc(sizeof(List));
    P->data = c;
    P->occu = 1;
    P->next = NULL;
    return P;
}

Node* CreationNode(char c, int occu){
    Node *B;
    B = malloc(sizeof(Node));
    B->data = c;
    B->occu = occu;
    B->left = NULL;
    B->right = NULL;
    return B;
}

ListNode* CreationListNode(char c, int occu){
    ListNode *P = malloc(sizeof(List));
    P->data = CreationNode(c, occu);
    P->next = NULL;
    return P;
}

ListCode* CreationListCode(char c, Code* code){
    ListCode *B;
    B = malloc(sizeof(Node));
    B->data = c;
    B->code = code;
    B->next = NULL;
    return B;
}

NodeCode* CreationNodeCode(char c, Code* code){
    NodeCode *B;
    B = malloc(sizeof(Node));
    B->data = c;
    B->code = code;
    B->left = NULL;
    B->right = NULL;
    return B;
}

Code* CreationCode(char c){
    Code *P = malloc(sizeof(Code));
    P->data = c;
    P->next = NULL;
    return P;
}