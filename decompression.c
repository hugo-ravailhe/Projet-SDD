#include <stdio.h>
#include <stdlib.h>
#include "structures.h"
#include "decompression.h"
#include "Fonctions/creation.h"
#include "Fonctions/AVL.h"
#include "Fonctions/fonctions.h"
#include "Fonctions/print_structures.h"

///Decodage du dico
Node* CreationHuffmanTreeByDico(const char* dico, int *i, char c, Node *B){
    if (dico[*i] == '1'){
        (*i)++;
        if (B == NULL){
            B = CreationNode('\0', 0);
        }
        B->left = CreationHuffmanTreeByDico(dico, i, c, B->left);
    }else if (dico[*i] == '0'){
        (*i)++;
        if (B == NULL){
            B = CreationNode('\0', 0);
        }
        B->right = CreationHuffmanTreeByDico(dico, i, c, B->right);
    } else{
        return CreationNode(c, 0);
    }
    return B;
}

Node* DecodeDico(const char* dico){
    int i = 0;
    Node *B = NULL;
    while (dico[i + 1] != '\0'){
        i++;
        B = CreationHuffmanTreeByDico(dico, &i, dico[i - 1], B);
        i++;
    }
    return B;
}

char HuffmanChar(Node *B, char* binary, int *i){
    if (B != NULL){
        if (B->data != '\0')
            return B->data;
        else{
            if (binary[*i] == '1'){
                (*i)++;
                return HuffmanChar(B->left, binary, i);
            }
            (*i)++;
            return HuffmanChar(B->right, binary, i);
        }
    }
    return '\0';
}

char* DecodeBinary(Node *B, char* binary){
    int i = 0, length = 0;
    char* txt = NULL;
    while (binary[i + 1] != '\0'){
        char c = HuffmanChar(B, binary, &i);
        length++;
        txt = realloc(txt, length);
        txt[length - 1] = c;
    }
    txt = realloc(txt, length + 1);
    txt[length] = '\0';
    return txt;
}

void Decompression(char* bin, char* dico){
    Node *D = DecodeDico(dico);
    char *txt = DecodeBinary(D, bin);
    WriteTxt(txt, "txtdecompress.txt");
}