#include <stdio.h>
#include <stdlib.h>
#include "structures.h"
#include "suppression.h"

void SuppressionCode(Code **C){
    Code *D, *E;
    D = *C;
    while (D != NULL){
        E = D;
        D = D->next;
        free(E);
        E = NULL;
    }
}

void SuppressionListCode(ListCode **L){
    ListCode *J, *K;
    J = *L;
    while (J != NULL){
        K = J;
        J = J->next;
        SuppressionCode(&K->code);
        free(K);
        K = NULL;
    }
}

void SuppressionList(List **L){
    List *J, *K;
    J = *L;
    while (J != NULL){
        K = J;
        J = J->next;
        free(K);
        K = NULL;
    }
}

void SuppressionNode(Node **B){
    if (*B != NULL){
        SuppressionNode(&(*B)->left);
        SuppressionNode(&(*B)->left);
        free(B);
    }
}

void SuppressionNodeCode(NodeCode **B){
    if (*B != NULL){
        SuppressionNodeCode(&(*B)->left);
        SuppressionNodeCode(&(*B)->left);
        SuppressionCode(&(*B)->code);
        free(B);
    }
}

void SuppressionListNode(ListNode **L){
    ListNode *J, *K;
    J = *L;
    while (J != NULL){
        K = J;
        J = J->next;
        SuppressionNode(&K->data);
        free(K);
        K = NULL;
    }
}