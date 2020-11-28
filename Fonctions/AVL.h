#ifndef MAIN_C_AVL_H
#define MAIN_C_AVL_H

int HeightTree(Node* B);

Node* RotationLeft(Node* B);

Node* RotationRight(Node* D);

Node* RotationRightLeft(Node* B);

Node* RotationLeftRight(Node* F);

Node* Balancing(Node* B);

int HeightTreeCode(NodeCode* B);

NodeCode* RotationLeftCode(NodeCode* B);

NodeCode* RotationRightCode(NodeCode* D);

NodeCode* RotationRightLeftCode(NodeCode* B);

NodeCode* RotationLeftRightCode(NodeCode* F);

NodeCode* BalancingCode(NodeCode* B);

#endif //MAIN_C_AVL_H
