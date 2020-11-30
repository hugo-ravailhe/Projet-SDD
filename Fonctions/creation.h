/*****************************************************************//**
 * \file   creation.h
 * \brief  file for the creation.
 *
 * \author Groupe 2 - R
 * \date   November 2020
 *********************************************************************/
#ifndef MAIN_C_CREATION_H
#define MAIN_C_CREATION_H
/**
 * \brief function that create a list with a char as data.
 * \param c: the char put in the list as data.
 * \return the list.
 */
List* CreationList(char c);
/**
 * \brief function that create a Node with a char as data and and his occu.
 * \param c: the char put in the Node as data.
 * occu: the occurrence of the letter.
 * \return the node.
 */
Node* CreationNode(char c, int occu);
/**
 * \brief function that create a Node with a char as data and and his occu.
 * \param c: the char put in the Node as data.
 * occu: the occurrence of the letter.
 * \return the node.
 */
ListNode* CreationListNode(char c, int occu);
/**
 * \brief function that create a list of code with a char as data.
 * \param c: the char put in the list as data.
 * \return the list of code.
 */
ListCode* CreationListCode(char c, Code* code);
/**
 * \brief function that create a node of code with a char as data.
 * \param c: the char put in the node as data.
 * code the code.
 * \return the node of code.
 */
NodeCode* CreationNodeCode(char c, Code* code);
/**
 * \brief function that create a code.
 * \param c: the char put in the code as data.
 * \return the code.
 */
Code* CreationCode(char c);

#endif //MAIN_C_CREATION_H
