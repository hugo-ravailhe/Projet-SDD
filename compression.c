#include <stdio.h>
#include <stdlib.h>
#include "structures.h"
#include "compression.h"
#include "Fonctions/creation.h"
#include "Fonctions/AVL.h"
#include "Fonctions/fonctions.h"
#include "Fonctions/print_structures.h"

///AVL Occurence
ListNode* AVLToListOccu(Node* B){
    ListNode* L = NULL, *K = NULL;
    if (B != NULL){
        L = CreationListNode(B->data, B->occu);
        K = L;
        if (B->left != NULL){
            L->next = AVLToListOccu(B->left);
            while (L->next != NULL){
                L = L->next;
            }
        } if (B->right != NULL){
            L->next = AVLToListOccu(B->right);
        }
    }
    return K;
}

Node* AddAVLOccurence(Node* B, char c, int* change){
    if (B == NULL){
        *change = 1;
        return CreationNode(c, 1);
    }
    else{
        if (B->data == c)
            B->occu++;
        else if (B->data > c)
            B->left = AddAVLOccurence(B->left, c, change);
        else
            B->right = AddAVLOccurence(B->right, c, change);
        if (*change == 1){
            B = Balancing(B);
        }
        return B;
    }
}

ListNode* CreationListOccurence(char* tab){
    int i = 0, changement;
    Node* B = NULL;
    while (tab[i] != '\0'){
        changement = 0;
        B = AddAVLOccurence(B, tab[i], &changement);
        i++;
    }
    return AVLToListOccu(B);
}

///Création Arbre Huffman pour AVL
void BubbleSort(ListNode **L){
    if (*L != NULL){
        ListNode *P = *L;
        ListNode *Limit = NULL;
        int Stop = 0;
        while(Stop == 0 && (*L)->next->next != Limit){
            Stop = 1;
            ListNode *Q = *L;
            while(Q->next->next != Limit){
                if(Q == *L && Q->data->occu > Q->next->data->occu){
                    ListNode *Temp = Q->next;
                    Q->next = Q->next->next;
                    *L = Temp;
                    (*L)->next = Q;
                    Q = *L;
                    Stop = 0;
                } else if(Q->next->data->occu > Q->next->next->data->occu){
                    ListNode *Temp = Q->next->next;
                    Q->next->next = Q->next->next->next;
                    Temp->next = Q->next;
                    Q->next = Temp;
                    Q = Q->next;
                    Stop = 0;
                } else{
                    Q = Q->next;
                }
            }
            Limit = Q->next;
        }
    }
}

Node* CreationABRHuffman(ListNode *L){
    if (L != NULL){
        ListNode *P = NULL;
        P = CopyListNode(L);
        while(P->next != NULL){
            BubbleSort(&P);
            ListNode *A, *B;
            A = Recuperation(&P);
            B = Recuperation(&P);
            Node *New = CreationNode('\0', A->data->occu + B->data->occu);
            New->left = A->data;
            New->right = B->data;
            free(B);
            A->data = New;
            A->next = P;
            P = A;
        }
        return P->data;
    }
    return NULL;
}

///AVL Dictionnaire
Code* LetterToBinaryCode(Node* B, char letter, char c){
    if (B->data != '\0'){
        if (B->data != letter)
            return NULL;
        return CreationCode(c);
    } else{
        Code* L = CreationCode(c);
        L->next = LetterToBinaryCode(B->left, letter, '1');
        if (L->next != NULL){
            return L;
        }
        L->next = LetterToBinaryCode(B->right, letter, '0');
        if (L->next != NULL){
            return L;
        }
        else
            return NULL;
    }
}

ListCode* TreeToList(Node *B, ListNode* Occu){
    ListCode *L = NULL, *K = NULL;
    if (B != NULL){
        L = CreationListCode(Occu->data->data, LetterToBinaryCode(B, Occu->data->data, Occu->data->data));
        K = L;
        Occu = Occu->next;
        while (Occu != NULL){
            L->next = CreationListCode(Occu->data->data, LetterToBinaryCode(B, Occu->data->data, Occu->data->data));
            L = L->next;
            Occu = Occu->next;
        }
    }

    return K;
}

NodeCode* AddAVLDico(NodeCode* B, char c, Code* code, int* changement){
    if (B == NULL){
        *changement = 1;
        return CreationNodeCode(c, code);
    }
    else{
        if (B->data > c)
            B->left = AddAVLDico(B->left, c, code,changement);
        else if (B->data < c)
            B->right = AddAVLDico(B->right, c, code,changement);
        if (*changement == 1)
            B = BalancingCode(B);
        return B;
    }
}

NodeCode* CreationAVLDico(Node* B, ListNode* N){
    NodeCode *C = NULL;
    ListCode *L = TreeToList(B, N), *K = NULL;
    int changement;
    while (L != NULL){
        changement = 0;
        C = AddAVLDico(C, L->data, L->code->next, &changement);
        K = L;
        L = L->next;
        ///Free Le maillon
    }
    return C;
}

///AVL Encodage
Code* CodeCompression(char c, NodeCode *B){
    if (B != NULL){
        if (B->data == c)
            return B->code;
        if (B->data > c)
            return CodeCompression(c, B->left);
        return CodeCompression(c, B->right);
    }
    return NULL;
}

char* EncodeTextAVL(char* txt, NodeCode* B){
    int i = 0;
    int length = 0;
    char* bin = NULL;
    Code* L = NULL;
    while (txt[i] != '\0'){
        L = CodeCompression(txt[i], B);
        while (L != NULL){
            length++;
            bin = realloc(bin, length);
            bin[length - 1] = L->data;
            L = L->next;
        }
        i++;
    }
    bin = realloc(bin, length + 1);
    bin[length] = '\0';
    return bin;
}

///Sauvegarde du dico
Code* DicoAVLToBinary(NodeCode* B) {
    Code *L = NULL;
    if (B != NULL) {
        Code *K, *J = NULL;
        L = CreationCode(B->data);
        K = L;
        J = B->code;
        while (J->next != NULL) {
            L->next = J;
            L = L->next;
            J = J->next;
        }
        L->next = J;
        L = L->next;
        L->next = CreationCode('\n');
        L->next->next = DicoAVLToBinary(B->left);
        while (L->next != NULL) {
            L = L->next;
        }
        L->next = DicoAVLToBinary(B->right);
        while (L->next != NULL) {
            L = L->next;
        }
        return K;
    }
    return NULL;
}

char* EncodeDico(NodeCode* B){
    Code* C = DicoAVLToBinary(B);
    char* dico = NULL;
    int length = 0;
    while (C != NULL){
        length++;
        dico = realloc(dico, length);
        dico[length - 1] = C->data;
        C = C->next;
    }
    dico = realloc(dico, length + 1);
    dico[length] = '\0';
    return dico;
}

///AVL Compression
void Compression(char* txt){
    if (*txt != '\0'){
        ///Initialisation
        ListNode *Occu = NULL;
        Node* B = NULL;
        NodeCode* C = NULL;

        ///Occurence
        Occu = CreationListOccurence(txt);
        printf("Success: Occurence\n");

        ///Arbre Huffman
        B = CreationABRHuffman(Occu);
        printf("Success: Arbre Huffman\n");

        ///Dictionnaire
        C = CreationAVLDico(B, Occu);
        printf("Success: Creation dictionnaire\n");

        ///Encodage texte
        char* bin = EncodeTextAVL(txt, C);
        printf("Success: Encodage texte\n");

        ///Exportation des fichiers
        char huffmanpath[] = "huffman.txt";
        WriteTxt(bin, huffmanpath);
        char* dico = EncodeDico(C);
        char dicopath[] = "dico.txt";
        WriteTxt(dico, dicopath);
        printf("Success: Exportation des fichiers\n");
    } else{
        printf("Failed\n");
    }
}