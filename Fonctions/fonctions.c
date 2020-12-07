#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <sys/stat.h>
#include "structures.h"
#include "fonctions.h"
#include "creation.h"

void WriteTxt(char* txt, char* path){
    FILE *filepath = NULL;
    filepath = fopen(path,"w+");
    fprintf(filepath,"%s\n",txt);
    fclose(filepath);
}

void WriteTxtWithoutSupp(char* txt, char* path){
    FILE *filepath = NULL;
    filepath = fopen(path,"a+");
    if (filepath != NULL){
        fprintf(filepath,"%s\n",txt);
        fclose(filepath);
    }
    else{
        printf("Fichier introuvable\n");
    }
}

int get_size(char *filename){
    struct stat st;
    int size;
    stat(filename, &st);
    size = st.st_size;
    return size;
}

void ReadTxt(char* txt, char* path){
    FILE *filepath;
    int x = get_size(path);
    txt = realloc(txt, x);
    filepath = fopen(path, "a+");
    if (filepath != NULL){
        fscanf(filepath,"%[^\0]", txt);
        fclose(filepath);
    }
}

char* LetterToBinary(char lettre, char *tab, int length){
    int x;
    x = lettre;
    int cpt = 1;
    tab = realloc(tab, length);
    while (x != 0){
        if(x%2 == 0){
            tab[length - cpt] = '0';
        }
        if(x%2 != 0){
            tab[length - cpt] = '1';
        }
        x = x/2;
        cpt++;

    }
    for (;cpt < 9;cpt++){
        tab[length - cpt]='0';
    }
    return tab;
}

char* WordToBinary(const char* text){
    int cpt = 0;
    int length = 0;
    char *tab = NULL;
    while(text[cpt] != '\0'){
        length += 8;
        tab = LetterToBinary(text[cpt], tab, length);
        cpt++;
    }
    tab = realloc(tab, length + 1);
    tab[length] = '\0';
    return tab;
}

int Maximum(int a, int b) {
    if (a > b)
        return a;
    return b;
}

ListNode* Recuperation(ListNode **L){
    ListNode *P = *L;
    *L = (*L)->next;
    return P;
}

ListNode* CopyListNode(ListNode *L){
    ListNode *P = NULL, *K = NULL;
    if (L != NULL){
        P = CreationListNode(L->data->data, L->data->occu);
        K = P;
        L = L->next;
        while (L != NULL){
            P->next = CreationListNode(L->data->data, L->data->occu);
            P = P->next;
            L = L->next;
        }
    }
    return K;
}

char *Concatenation(const char *first, int firstlength, const char *second, int secondlength){
    int i = 0;
    char *output = (char*)malloc((firstlength + secondlength + 2) *sizeof(char));
    if (first != NULL){
        for (i; i < firstlength; i++){
            output[i] = first[i];
        }
        i++;
    }
    i--;
    if (second != NULL){
        for (int j = 0; j < secondlength; j++){
            output[i] = second[j];
            i++;
        }
    }
    output[firstlength + secondlength] = '\0';
    return output;
}