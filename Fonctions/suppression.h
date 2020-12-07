/*****************************************************************//**
 * \file   suppression.h
 * \brief  Fichier pour la suppresion.
 * 
 * \author Groupe 2 - R
 * \date   November 2020
 *********************************************************************/
#ifndef MAIN_C_SUPPRESSION_H
#define MAIN_C_SUPPRESSION_H

 /**
  * \brief fonction qui supprime un code.
  * \param code: le code qui va être supprimé.
  */
void SuppressionCode(Code **C);

/**
 * \brief fonction qui supprime une liste de code.
 * \param L: la liste de code qui va etre supprimé.
 */
void SuppressionListCode(ListCode **L);

/**
 * \brief fonction qui supprime une liste.
 * \param L: la liste qui va etre supprimé.
 */
void SuppressionList(List **L);

/**
 * \brief fonction qui supprime un Node.
 * \param B: la Node qui va etre supprimé.
 */
void SuppressionNode(Node **B);

/**
 * \brief fonction qui supprime un Node de code.
 * \param B: la Node de code qui va etre supprimé.
 */
void SuppressionNodeCode(NodeCode **B);

/**
 * \brief fonction qui supprime une liste de Node.
 * \param L: la list de Node qui va etre supprimé.
 */
void SuppressionListNode(ListNode **L);

#endif //MAIN_C_SUPPRESSION_H
