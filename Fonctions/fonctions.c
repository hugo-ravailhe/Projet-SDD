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
    if (filepath != NULL){
        fprintf(filepath,"%s\n",txt);
        fclose(filepath);
    }
}

void WriteTxtWithoutSupp(char* txt, char* path){
    FILE *filepath = NULL;
    filepath = fopen(path,"a+");
    if (filepath != NULL){
        fprintf(filepath,"%s\n",txt);
        fclose(filepath);
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

char* LetterToBinary(char* tab, int* len, char lettre){
    *len=8;

    int x;
    tab = (char*) malloc((*len+1) * sizeof(char));
    char tabfinal[8];

    x = lettre;
    int cpt=*len-1;
    while (x!=0){

        if(x%2==0){
            tabfinal[cpt]='0';
        }
        if(x%2!=0){
            tabfinal[cpt]='1';
            printf("\n LAAAAA%c\n",tabfinal[cpt]);
        }
        x=x/2;
        cpt--;

    }

    for (cpt;cpt>=0;cpt--){
        tabfinal[cpt]='0';
        printf("test01\n");
    }
    tabfinal[*len]='\0';
    WriteTxtWithoutSupp(tabfinal, "binary.txt");

    return tabfinal;
}

char* WordToBinary(char* text,char* tab){
    int x;
    int len=0;
    int cpt=0;
    while(text[cpt]!='\0'){
        tab = LetterToBinary(tab,&len,text[cpt]);
        cpt++;

    }

    tab = (char*) malloc((len+1) * sizeof(char));

    tab[len]='\0';

    return  tab;
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
