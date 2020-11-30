/*****************************************************************//**
 * \file   fonctions.h
 * \brief  file for the fonctions.
 * 
 * \author Groupe 2 - R
 * \date   November 2020
 *********************************************************************/
#ifndef MAIN_C_FONCTIONS_H
#define MAIN_C_FONCTIONS_H
/**
* \brief Function to write in a txt file.
* \param path: the file path.
*txt: the txt written in the file.
 */
void WriteTxt(char* txt, char* path);
/**
* \brief Function to get the file size.
* \param filename: the name of the file you want the size of.
* \return the file's size.
 */
int get_size(char *filename);
/**
* \brief Function to get the text in a file and put it in txt.
* \param path: the file path.
* txt: the text wich takes the text of the file.
 */
void ReadTxt(char* txt, char* path);
/**
* \brief function that translates a letter into binary and writes it to a text file.
* \param letter: the letter translated into binary.
* \return the tab with the binary.
 */
char* LetterToBinary(char* tab,int* len,char letter);
/**
* \brief function that starts the function LetterToBinary for as many letters as there are in the texte.
* \param text: the text you want to translate into binary.
* \return tab.
 */
char* WordToBinary(char* text,char* tab);
/**
* \brief function that function which calculates the maximum between two integers.
* \param a: the first integer.
* b the second integer.	
* \return the maximum.
 */

int Maximum(int a, int b);
/**
* \brief function that function that removes the first element from a list.
* \param L: the list used.
* \return the element removed.
 */

ListNode* Recuperation(ListNode **L);
/**
* \brief function that copies a list.
* \param L: the list used.
* \return the list.
 */
ListNode* CopyListNode(ListNode *L);

#endif //MAIN_C_FONCTIONS_H
