#include <stdio.h>
#include <stdlib.h>
#include <io.h>
#include <time.h>
#include "structures.h"
#include "compression.h"
#include "decompression.h"
#include "Fonctions/fonctions.h"

int main(){
    int choix;


    int temp = 1;
    while(temp == 1){
        temp = 1;
        printf("-----------------------------------------------------------------------------------\n");
        printf("Bienvenue sur notre compresseur\n");
        printf("-Si vous Voulez compresser le fichier texte |Tappez 1|\n-Si vous voulez decompresser le fichier texte |Tappez 2|\n-si vous voulez quitter l'application |Tappez 3|\n");
        printf("-----------------------------------------------------------------------------------\n");
        printf("Donnez votre reponse: ");
        scanf("%d",&choix);
        printf("-----------------------------------------------------------------------------------\n");
        float temps;
        clock_t t1, t2;

        if(choix == 1){
            printf("Inserez le chemin du fichier a compresser: (ex: H:\\\\Document\\\\fichier_a_compresser.txt)\n");
            char *input = (char*)malloc(200*sizeof(char));
            scanf("%s", input);
            t1 = clock();
            char *tabtxt = NULL;
            int length = get_size(input);
            tabtxt = realloc(tabtxt, length);
            ReadTxt(tabtxt,input);
            char *txtbinary = WordToBinary(tabtxt);
            int i = 0;
            int last = -1;
            while (input[i] != '\0'){
                if (input[i] == '\\' || input[i] == '/')
                    last = i;
                i++;
            }
            input = Concatenation(input, last + 1, "Huffman\\", 9);
            mkdir(input);
            WriteTxt(txtbinary, Concatenation(input, last + 9, "binary.txt\0", 11));
            free(txtbinary);
            Compression(tabtxt, input, last + 9);
            t2 = clock();
            temps = (float)(t2-t1)/CLOCKS_PER_SEC;
            printf("Taille: %d caracteres\n", length);
            int lengthcompress = get_size(Concatenation(input, last + 9, "huffman.txt", 11));
            printf("Ratio: %lf\n", (float)lengthcompress / (float)(length*8));
            printf("temps = %f Seconde(s)\n", temps);
            printf("Le dossier Huffman contenant les fichiers de compression se trouve dans le meme repertoire que le choisi.\n");
            printf("-----------------------------------------------------------------------------------\n\n");
        }

        else if(choix == 2){
            printf("Inserez le chemin du fichier a decompresser: (ex: H:\\\\Document\\\\Huffman\\\\huffman.txt)\n");
            char *huffmanpath = (char*)malloc(200*sizeof(char));
            scanf("%s", huffmanpath);
            t1 = clock();
            int i = 0;
            int last = -1;
            while (huffmanpath[i] != '\0'){
                if (huffmanpath[i] == '\\' || huffmanpath[i] == '/')
                    last = i;
                i++;
            }
            char *dicopath = Concatenation(huffmanpath, last + 1, "dico.txt", 9);
            char *dico = NULL;
            char *bin = NULL;
            int lengthdico = get_size(dicopath);
            dico = realloc(dico, lengthdico);
            int lengthhuffman = get_size(huffmanpath);
            bin = realloc(bin, lengthhuffman);
            ReadTxt(dico, dicopath);
            ReadTxt(bin, huffmanpath);
            Decompression(bin, dico, huffmanpath, last + 1);
            t2 = clock();
            temps = (float)(t2-t1)/CLOCKS_PER_SEC;
            printf("temps = %f Seconde(s)\n", temps);
            printf("Votre fichier decompresser se trouve dans le dossier Huffman.\n");
            printf("-----------------------------------------------------------------------------------\n\n");
        }

        else if(choix == 3){
            printf("Bonne continuation.\n");
            temp = 0;
            printf("-----------------------------------------------------------------------------------\n\n");
        }

        else{
            printf("Saisie incorrect.\n");
            printf("-----------------------------------------------------------------------------------\n");
        }
    }
}