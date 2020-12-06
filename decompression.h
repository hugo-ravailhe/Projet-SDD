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
 * \brief Fonction pour créer un arbre Huffman à partir d'un Dico sous forme de texte.
 * \param dico est un tableau de caratères, contenant le dico.
 * \param i est un pointeur d'entier, qui indique la position dans le tableau.
 * \param B est un pointeur de Node, contenant le tableau Huffman qui se crée.
 *         \n Example :
 *         \code{.c}
 *         Node *B = CreationHuffmanTreeByDico(dico, &i, letter, B);
 *         \endcode
 * \return un pointeur de Node contenant l'arbre Huffman.
 */
Node* CreationHuffmanTreeByDico(const char* dico, int *i, char c, Node *B);

/**
 * \brief Fonction qui décode le dico sous forme d'un texte en arbre Huffman.
 * \param dico est un tableau de caratères, contenant le dico.
 *         \n Example :
 *         \code{.c}
 *         Node *B = DecodeDico(dico);
 *         \endcode
 */
Node* DecodeDico(const char* dico);

/**
 * \brief Fonction qui retourne le caratère qui correspond au chemin donné en paramètre.
 * \param B est un pointeur de Node, contenant l'arbre Huffman.
 * \param binary est un tableau de caractères, contenant le texte à décoder.
 * \param i est un pointeur d'entier, qui indique la position dans le tableau.
 *         \n Example :
 *         \code{.c}
 *         char letter = HuffmanChar(B, dico, &i);
 *         \endcode
 * \return un caractère, associé au chemin.
 */
char HuffmanChar(Node *B, char* binary, int *i);

/**
 * \brief Fonction qui retourne le texte décoder.
 * \param B est un pointeur de Node, contenant l'arbre Huffman.
 * \param binary un tableau de caratères, contenant le texte à décoder.
 *         \n Example :
 *         \code{.c}
 *         char *txt = DecodeBinary(B, binary);
 *         \endcode
 */
char* DecodeBinary(Node *B, char* binary);

/**
 * \brief Fonction qui permet de décompresser un texte binaire.
 * \param bin est un tableau de caractères, contenant le texte binaire à décompresser.
 * \param dico est un tableau de caractères, contenant le dico de la compression.
 *         \n Example :
 *         \code{.c}
 *         Decompression(bin, dico);
 *         \endcode
 */
void Decompression(char* bin, char* dico);

#endif //TEST_DECOMPRESSION_H
