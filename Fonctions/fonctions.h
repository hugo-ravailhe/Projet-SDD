#ifndef MAIN_C_FONCTIONS_H
#define MAIN_C_FONCTIONS_H

void WriteTxt(char* txt, char* path);

int get_size(char *filename);

void ReadTxt(char* txt, char* path);

char* LetterToBinary(char letter, char *tab, int length);

char* WordToBinary(const char* text);

int Maximum(int a, int b);

ListNode* Recuperation(ListNode **L);

ListNode* CopyListNode(ListNode *L);

#endif //MAIN_C_FONCTIONS_H
