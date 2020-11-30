/*****************************************************************//**
 * \file   compression.h
 * \brief  Fichier pour les fonctions de compression
 *
 * \author Groupe 2 - R
 * \date   November 2020
 *********************************************************************/
#ifndef TEST_COMPRESSION_H
#define TEST_COMPRESSION_H

 /**
  * \brief Fonction pour transformer l'AVL d'occurence en ListNode.
  * \param B est un pointeur Node qui contient l'AVL d'occurence.
  *         \n Example :
  *         \code{.c}
  *         ListNode *L = AVLToListOccu(B);
  *         \endcode
  * \return un pointeur de ListNode, qui contient le liste d'occurence.
  * \return \c NULL, si l'arbre est vide.
  */
ListNode* AVLToListOccu(Node* B);

/**
 * \brief Fonction pour ajouter une occurence à l'AVL d'occurence.
 * \param B est un pointeur Node, qui contient l'AVL d'occurence.
 * \param c est un caractère, il permet de dire quel caractère a une occurence en plus.
 * \param change est un pointeur d'entier, qui défini si il y a eu modification dans l'AVL et doit être équilibré.
 *         \n Example :
 *         \code{.c}
 *         Node *B = AddAVLOccurence(B, 'c', &1);
 *         \endcode
 * \return un pointeur de Node, qui contient le nouvel AVL d'occurence.
 */
Node* AddAVLOccurence(Node* B, char c, int* change);

/**
 * \brief Fonction qui créer l'AVL d'occurence et renvoie la list d'occurence.
 * \param tab est un tableau de caractère, qui contient le texte à traiter.
 *         \n Example :
 *         \code{.c}
 *         ListNode *B = CreationListOccurence(txt);
 *         \endcode
 * \return un pointeur de ListNode, qui contient la list des caractères avec leurs occurences.
 */
ListNode* CreationListOccurence(char* tab);

/**
 * \brief Fonction qui trie dans l'ordre croissant une ListNode en fonction de leurs occurences.
 * \param L est un double pointeur de ListNode, à trier.
 *         \n Example :
 *         \code{.c}
 *         BubbleSort(&L);
 *         \endcode
 */
void BubbleSort(ListNode** L);

/**
 * \brief Fonction qui crée l'arbre Huffman à partir d'une ListNode d'occurence.
 * \param est un pointeur de ListNode, à partir de duquel on crée l'arbre Huffman.
 *         \n Example :
 *         \code{.c}
 *         Node *B = CreationABRHuffman(L);
 *         \endcode
 * \return un pointeur de Node, qui contient l'arbre Huffman.
 */
Node* CreationABRHuffman(ListNode* L);

/**
 * \brief Fonction qui retourne le nouveau code binaire d'une lettre.
 * \param B est un pointeur de Node, qui contient l'arbre Huffman
 * \param letter est un caractère, à aller chercher dans l'arbre.
 * \param c est un caratère, à insérer dans la struture Code à retourner.
 *         \n Example :
 *         \code{.c}
 *         Code *C = LetterToBinaryCode(L, 'a', '1');
 *         \endcode
 * \return un pointeur de Code, qui contient la chaine de code binaire du la lettre.
 */
Code* LetterToBinaryCode(Node* B, char letter, char c);

/**
 * \brief Fonction qui convertit l'AVL Dico sous forme d'une ListCode.
 * \param est un pointeur de Node, qui contient l'AVL Dico.
 * \param est un pointeur de ListNode, qui contient les différents lettre du texte à convertir.
 *         \n Example :
 *         \code{.c}
 *         ListCode *K = TreeToList(B, L);
 *         \endcode
 * \return un pointeur de ListCode, qui contient la liste des caractères avec leur nouvel encodage binaire derrière.
 */
ListCode* TreeToList(Node* B, ListNode* Occu);

/**
 * \brief Fonction qui ajoute un caractère et son nouveau code binaire à l'AVL Dico.
 * \param est un pointeur de Node, qui contient l'AVL Dico.
 * \param est un caractère, à ajouter dans l'AVL Dico.
 * \param est pointeur de Code, list qui contient le nouveau code binaire de la lettre.
 * \param est pointeur d'entier, qui indique si il y a eu un changement dans l'AVL Dico au cours de l'insertion.
 *         \n Example :
 *         \code{.c}
 *         NodeCode *K = TreeToList(B, L);
 *         \endcode
 * \return un pointeur de NodeCode, qui contient le nouvel AVL Dico après l'ajout.
 */
NodeCode* AddAVLDico(NodeCode* B, char c, Code* code, int* changement);

/**
 * \brief Fonction qui crée l'AVL Dico.
 * \param B est un pointeur de Node, qui contient l'arbre Huffman.
 * \param N est un pointeur de ListNode, qui contient la liste des caractères à insérer dans l'AVL Dico.
 *         \n Example :
 *         \code{.c}
 *         NodeCode *K = CreationAVLDico(B, L);
 *         \endcode
 * \return un pointeur de NodeCode, qui contient l'AVL Dico final.
 */
NodeCode* CreationAVLDico(Node* B, ListNode* N);

/**
 * \brief Fonction qui retourne le nouveau code binaire d'un caractère.
 * \param c est un caratère, à convertir en binaire.
 * \param B est un pointeur de NodeCode, qui contient l'AVL Dico.
 *         \n Example :
 *         \code{.c}
 *         Code *C = CodeCompression('a', B);
 *         \endcode
 * \return un pointeur de Code, qui contient le nouveau code binaire de la lettre.
 */
Code* CodeCompression(char c, NodeCode* B);

/**
 * \brief Fonction qui retourne le nouveau code bianire du texte.
 * \param txt est un tableau de caratère, contenant le texte à compresser.
 * \param B est un pointeur de NodeCode, contenant l'AVL Dico.
 *         \n Example :
 *         \code{.c}
 *         char *tab = EncodeTextAVL("la texte à compresser", B);
 *         \endcode
 */
char* EncodeTextAVL(char* txt, NodeCode* B);

/**
 * \brief Fonction qui converti l'AVL Dico sous un list de Code.
 * \param B est un pointeur de NodeCode, contenant l'AVL Dico.
 *         \n Example :
 *         \code{.c}
 *         Code *C = DicoAVLToBinary(B);
 *         \endcode
 * \return un pointeur de Code, qui contient les lettre avec leur code binaire.
 */
Code* DicoAVLToBinary(NodeCode* B);

/**
 * \brief Fonction qui retourne le dico sous forme de texte.
 * \param B est un pointeur de NodeCode, contenant l'AVL Dico.
 *         \n Example :
 *         \code{.c}
 *         char *tab = EncodeDico(B);
 *         \endcode
 * \return un tableau de caratère, contenant le dico.
 */
char* EncodeDico(NodeCode* B);

/**
 * \brief Fonction qui compresse un texte.
 * param txt est un tableau de caratère, contenant le texte à compresser.
 *         \n Example :
 *         \code{.c}
 *         Compression("texte a compresser");
 *         \endcode
 */
void Compression(char* txt);

#endif //TEST_COMPRESSION_H
