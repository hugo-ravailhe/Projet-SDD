/*****************************************************************//**
 * \file   print_structures.h
 * \brief  Fichier pour les fonctions d'affichage'
 *
 * \author Groupe 2 - R
 * \date   November 2020
 *********************************************************************/
#ifndef MAIN_C_PRINT_STRUCTURES_H
#define MAIN_C_PRINT_STRUCTURES_H







/**
 * \brief Fonction qui permet d'afficher la liste ListCode.
 * \param L est un pointeur liste.

 *         \n Example :
 *         \code{.c}
 *         
 *         \endcode
 *
 */
void PrintListCode(ListCode *L);





/**
 * \brief Fonction qui permet d'afficher le tableau de caractere.
 * \param tab est un pointeur liste.

 *         \n Example :
 *         \code{.c}
 *         
 *         \endcode
 *
 */
void PrintTabChar(char* tab);




/**
 * \brief Fonction qui permet d'afficher la liste Code.
 * \param C est un pointeur 

 *         \n Example :
 *         \code{.c}
 *         
 *         \endcode
 *
 */
void PrintCode(Code* C);




/**
 * \brief Fonction qui permet d'afficher la liste Liste.
 * \param L est un pointeur liste.

 *         \n Example :
 *         \code{.c}
 *         
 *         \endcode
 *
 */
void PrintList(List* L);





/**
 * \brief Fonction qui permet d'afficher la liste ListNode.
 * \param L est un pointeur liste.

 *         \n Example :
 *         \code{.c}
 *         
 *         \endcode
 *
 */
void PrintListNode(ListNode* L);



/**
 * \brief Fonction qui permet d'afficher l'arbre Node.
 * \param N est un pointeur d'arbre.

 *         \n Example :
 *         \code{.c}
 *         
 *         \endcode
 *
 */
void PrintABR(Node* N);



/**
 * \brief Fonction qui permet d'afficher l'arbre Nodecode.
 * \param B est un pointeur d'arbre.

 *         \n Example :
 *         \code{.c}
 *         
 *         \endcode
 *
 */
void PrintABRCode(NodeCode *B);

#endif //MAIN_C_PRINT_STRUCTURES_H
