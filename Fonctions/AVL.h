/*****************************************************************//**
 * \file   AVL.h
 * \brief  Fichier pour les fonctions d'AVL
 * 
 * \author Groupe 2 - R
 * \date   November 2020
 *********************************************************************/
#ifndef MAIN_C_AVL_H
#define MAIN_C_AVL_H

/**
 * \brief Fonction qui retourne la hauteur de l'arbre.
 * \param B est un pointeur de Node, contenant l'arbre.
 *         \n Example :
 *         \code{.c}
 *         int heigth = HeightTree(B);
 *         \endcode
 * \return un entier, qui est la hauteur de l'arbre.
 */
int HeightTree(Node* B);

/**
 * \brief Fonction qui effectue un rotation gauche.
 * \param B est un pointeur de Node, contenant l'arbre.
 *         \n Example :
 *         \code{.c}
 *         Node *B = RotationLeft(B);
 *         \endcode
 * \return un pointeur de Node contenant la rotation.
 */
Node* RotationLeft(Node* B);

/**
 * \brief Fonction qui effectue un rotation droite.
 * \param B est un pointeur de Node, contenant l'arbre.
 *         \n Example :
 *         \code{.c}
 *         Node *B = RotationRight(B);
 *         \endcode
 * \return un pointeur de Node contenant la rotation.
 */
Node* RotationRight(Node* D);

/**
 * \brief Fonction qui effectue un rotation droite gauche.
 * \param B est un pointeur de Node, contenant l'arbre.
 *         \n Example :
 *         \code{.c}
 *         Node *B = RotationRightLeft(B);
 *         \endcode
 * \return un pointeur de Node contenant la rotation.
 */
Node* RotationRightLeft(Node* B);

/**
 * \brief Fonction qui effectue un rotation gauche droite.
 * \param B est un pointeur de Node, contenant l'arbre.
 *         \n Example :
 *         \code{.c}
 *         Node *B = RotationLeftRight(B);
 *         \endcode
 * \return un pointeur de Node contenant la rotation.
 */
Node* RotationLeftRight(Node* F);

/**
 * \brief Fonction qui effectue l'équilibrage d'un AVL.
 * \param B est un pointeur de Node, contenant l'AVL à équilibrer.
 *         \n Example :
 *         \code{.c}
 *         Node *B = Balancing(B);
 *         \endcode
 * \return un pointeur de Node contenant l'AVL équilibré.
 */
Node* Balancing(Node* B);

/**
 * \brief Fonction qui retourne la hauteur de l'arbre.
 * \param B est un pointeur de NodeCode, contenant l'arbre.
 *         \n Example :
 *         \code{.c}
 *         int heigth = HeightTree(B);
 *         \endcode
 * \return un entier, qui est la hauteur de l'arbre.
 */
int HeightTreeCode(NodeCode* B);

/**
 * \brief Fonction qui effectue un rotation gauche.
 * \param B est un pointeur de NodeCode, contenant l'arbre.
 *         \n Example :
 *         \code{.c}
 *         Node *B = RotationLeftCode(B);
 *         \endcode
 * \return un pointeur de Node contenant la rotation.
 */
NodeCode* RotationLeftCode(NodeCode* B);

/**
 * \brief Fonction qui effectue un rotation droite.
 * \param B est un pointeur de NodeCode, contenant l'arbre.
 *         \n Example :
 *         \code{.c}
 *         Node *B = RotationRightCode(B);
 *         \endcode
 * \return un pointeur de Node contenant la rotation.
 */
NodeCode* RotationRightCode(NodeCode* D);

/**
 * \brief Fonction qui effectue un rotation droite gauche.
 * \param B est un pointeur de NodeCode, contenant l'arbre.
 *         \n Example :
 *         \code{.c}
 *         Node *B = RotationRightLeftCode(B);
 *         \endcode
 * \return un pointeur de Node contenant la rotation.
 */
NodeCode* RotationRightLeftCode(NodeCode* B);

/**
 * \brief Fonction qui effectue un rotation gauche droite.
 * \param B est un pointeur de NodeCode, contenant l'arbre.
 *         \n Example :
 *         \code{.c}
 *         Node *B = RotationLeftRightCode(B);
 *         \endcode
 * \return un pointeur de Node contenant la rotation.
 */
NodeCode* RotationLeftRightCode(NodeCode* F);

/**
 * \brief Fonction qui effectue l'équilibrage d'un AVL.
 * \param B est un pointeur de NodeCode, contenant l'AVL à équilibrer.
 *         \n Example :
 *         \code{.c}
 *         Node *B = BalancingCode(B);
 *         \endcode
 * \return un pointeur de Node contenant l'AVL équilibré.
 */
NodeCode* BalancingCode(NodeCode* B);

#endif //MAIN_C_AVL_H
