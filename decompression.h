/*****************************************************************//**
 * \file   decompression.h
 * \brief  Fichier pour les fonctions de decompression
 * 
 * \author Groupe 2 - R
 * \date   November 2020
 *********************************************************************/
#ifndef TEST_DECOMPRESSION_H
#define TEST_DECOMPRESSION_H

/**
 * \brief Fonction pour cr�er un arbre Huffman � partir d'un Dico sous forme de texte.
 * \param dico est un tableau de carat�res, contenant le dico.
 * \param i est un pointeur d'entier, qui indique la position dans le tableau.
 * \param B est un pointeur de Node, contenant le tableau Huffman qui se cr�e.
 *         \n Example :
 *         \code{.c}
 *         Node *B = CreationHuffmanTreeByDico(dico, &i, letter, B);
 *         \endcode
 * \return un pointeur de Node contenant l'arbre Huffman.
 */
Node* CreationHuffmanTreeByDico(const char* dico, int *i, char c, Node *B);

/**
 * \brief Fonction qui d�code le dico sous forme d'un texte en arbre Huffman.
 * \param dico est un tableau de carat�res, contenant le dico.
 *         \n Example :
 *         \code{.c}
 *         Node *B = DecodeDico(dico);
 *         \endcode
 */
Node* DecodeDico(const char* dico);

/**
 * \brief Fonction qui retourne le carat�re qui correspond au chemin donn� en param�tre.
 * \param B est un pointeur de Node, contenant l'arbre Huffman.
 * \param binary est un tableau de caract�res, contenant le texte � d�coder.
 * \param i est un pointeur d'entier, qui indique la position dans le tableau.
 *         \n Example :
 *         \code{.c}
 *         char letter = HuffmanChar(B, dico, &i);
 *         \endcode
 * \return un caract�re, associ� au chemin.
 */
char HuffmanChar(Node *B, char* binary, int *i);

/**
 * \brief Fonction qui retourne le texte d�coder.
 * \param B est un pointeur de Node, contenant l'arbre Huffman.
 * \param binary un tableau de carat�res, contenant le texte � d�coder.
 *         \n Example :
 *         \code{.c}
 *         char *txt = DecodeBinary(B, binary);
 *         \endcode
 */
char* DecodeBinary(Node *B, char* binary);

/**
 * \brief Fonction qui permet de d�compresser un texte binaire.
 * \param bin est un tableau de caract�res, contenant le texte binaire � d�compresser.
 * \param dico est un tableau de caract�res, contenant le dico de la compression.
 *         \n Example :
 *         \code{.c}
 *         Decompression(bin, dico);
 *         \endcode
 */
void Decompression(char* bin, char* dico, char* path, int last);

#endif //TEST_DECOMPRESSION_H
