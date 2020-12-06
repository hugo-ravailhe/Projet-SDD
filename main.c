#include <stdio.h>
#include <stdlib.h>
#include "structures.h"
#include "compression.h"
#include "decompression.h"
#include "Fonctions/fonctions.h"

int main(){
    int choix;


    int temp = 1;
    printf("-----------------------------------------------------------------------------------\n");
    while(temp == 1){
        temp = 1;
        printf("Bienvenue sur notre compresseur\n");
        printf("-Si vous Voulez compresser le fichier texte |Tappez 1|\n-Si vous voulez decompresser le fichier texte |Tappez 2|\n-si vous voulez quitter l'application |Tappez 3|\n");
        printf("-----------------------------------------------------------------------------------\n");
        printf("Donnez votre reponse: ");
        scanf("%d",&choix);
        printf("\n");
        printf("-----------------------------------------------------------------------------------\n");

        if(choix == 1){
            char input[] = "input.txt";
            char *tabtxt = NULL;
            int length = get_size(input);
            tabtxt = realloc(tabtxt, length);
            ReadTxt(tabtxt,input);
            char *txtbinary = WordToBinary(tabtxt);
            WriteTxt(txtbinary, "binary.txt");
            free(txtbinary);
            Compression(tabtxt);
            printf("-----------------------------------------------------------------------------------\n");
        }

        if(choix == 2){
            char dicopath[] = "dico.txt";
            char huffmanpath[] = "huffman.txt";
            char *dico = NULL;
            char *bin = NULL;
            int lengthdico = get_size(dicopath);
            dico = realloc(dico, lengthdico);
            int lengthhuffman = get_size(huffmanpath);
            bin = realloc(bin, lengthhuffman);
            ReadTxt(dico, dicopath);
            ReadTxt(bin, huffmanpath);
            Decompression(bin, dico);
            printf("-----------------------------------------------------------------------------------\n");
        }
        if(choix == 3){
            printf("Bonne continuation.\n");
            temp = 0;
            printf("-----------------------------------------------------------------------------------\n");
        }
    }
}