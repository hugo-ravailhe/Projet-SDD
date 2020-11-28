#ifndef TEST_COMPRESSION_H
#define TEST_COMPRESSION_H

///AVL Occurence
ListNode* AVLToListOccu(Node* B);

Node* AddAVLOccurence(Node* B, char c, int* change);

ListNode* CreationListOccurence(char* tab);

///Création Arbre Huffman pour AVL
Node* CreationABRHuffman(ListNode *L);

///AVL Dictionnaire
Code* LetterToBinaryCode(Node* B, char letter, char c);

ListCode* TreeToList(Node *B, ListNode* Occu);

NodeCode* AddAVLDico(NodeCode* B, char c, Code* code, int* changement);

NodeCode* CreationAVLDico(Node* B, ListNode* N);

///AVL Encodage
Code* CodeCompression(char c, NodeCode *B);

char* EncodeTextAVL(char* txt, NodeCode* B);

///Sauvegarde du dico
Code* DicoAVLToBinary(NodeCode* B);

char* EncodeDico(NodeCode* B);

///AVL Compression
void Compression(char* txt);

#endif //TEST_COMPRESSION_H
