#include <stdio.h>
#include <stdlib.h>
#include "structures.h"
#include "AVL.h"
#include "fonctions.h"

int HeightTree(Node* B){
    if (B == NULL){
        return 0;
    } else{
        return 1 + Maximum(HeightTree(B->left), HeightTree(B->right));
    }
}

Node* RotationLeft(Node* B){
    Node *D, *C;
    D = B->right;
    C = D->left;
    D->left = B;
    B->right = C;
    return D;
}

Node* RotationRight(Node* D){
    Node *B, *C;
    B = D->left;
    C = B->right;
    B->right = D;
    D->left = C;
    return B;
}

Node* RotationRightLeft(Node* B){
    Node *F, *D, *C, *E;
    F = B->right;
    D = F->left;
    C = D->left;
    E = D->right;
    D->left = B;
    D->right = F;
    B->right = C;
    F->left = E;
    return D;
}

Node* RotationLeftRight(Node* F){
    Node *B, *D, *C, *E;
    B = F->left;
    D = B->right;
    C = D->left;
    E = D->right;
    D->left = B;
    B->right = C;
    D->right = F;
    F->left = E;
    return D;
}

Node* Balancing(Node* B){
    if (B != NULL){
        int equilibrage = HeightTree(B->right) - HeightTree(B->left);
        if (equilibrage == 2){
            equilibrage = HeightTree(B->right->right) - HeightTree(B->right->left);
            if (equilibrage == -1)
                return RotationRightLeft(B);
            return RotationLeft(B);
        } if (equilibrage == -2){
            equilibrage = HeightTree(B->left->right) - HeightTree(B->left->left);
            if (equilibrage == 1)
                return RotationLeftRight(B);
            return RotationRight(B);
        }
        return B;
    }
    return NULL;
}

int HeightTreeCode(NodeCode* B){
    if (B == NULL){
        return 0;
    } else{
        return 1 + Maximum(HeightTreeCode(B->left), HeightTreeCode(B->right));
    }
}

NodeCode* RotationLeftCode(NodeCode* B){
    NodeCode *D, *C;
    D = B->right;
    C = D->left;
    D->left = B;
    B->right = C;
    return D;
}

NodeCode* RotationRightCode(NodeCode* D){
    NodeCode *B, *C;
    B = D->left;
    C = B->right;
    B->right = D;
    D->left = C;
    return B;
}

NodeCode* RotationRightLeftCode(NodeCode* B){
    NodeCode *F, *D, *C, *E;
    F = B->right;
    D = F->left;
    C = D->left;
    E = D->right;
    D->left = B;
    D->right = F;
    B->right = C;
    F->left = E;
    return D;
}

NodeCode* RotationLeftRightCode(NodeCode* F){
    NodeCode *B, *D, *C, *E;
    B = F->left;
    D = B->right;
    C = D->left;
    E = D->right;
    D->left = B;
    B->right = C;
    D->right = F;
    F->left = E;
    return D;
}

NodeCode* BalancingCode(NodeCode* B){
    if (B != NULL){
        int equilibrage = HeightTreeCode(B->right) - HeightTreeCode(B->left);
        if (equilibrage == 2){
            equilibrage = HeightTreeCode(B->right->right) - HeightTreeCode(B->right->left);
            if (equilibrage == -1)
                return RotationRightLeftCode(B);
            return RotationLeftCode(B);
        } if (equilibrage == -2){
            equilibrage = HeightTreeCode(B->left->right) - HeightTreeCode(B->left->left);
            if (equilibrage == 1)
                return RotationLeftRightCode(B);
            return RotationRightCode(B);
        }
        return B;
    }
    return NULL;
}