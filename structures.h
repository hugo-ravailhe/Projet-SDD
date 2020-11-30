#ifndef TEST_STRUCTURES_H
#define TEST_STRUCTURES_H

/**
 * \struct List
 * \brief Structures contenant un caract�re data, son entier occurence et le pointeur vers le prochain maillon.
 * 
 * La structure permet de lister des caract�res et leur nombre d'occurence.
 */
typedef struct list{
    char data;
    int occu;
    struct list *next;
}List;

/**
 * \struct Code
 * \brief Structure contenant un caract�re data et le pointeur vers le prochain maillon.
 * 
 * La structure permet de lister des caract�res. Principalement utilis� pour repr�senter le nouveau code binaire d'un carat�re.
 */
typedef struct code {
    char data;
    struct code *next;
}Code;

/**
 * \struct Node
 * \brief Struture contenant un carat�re data, son entier occurence et les pointeurs vers le fils gauche et le fils droit de l'arbre.
 * 
 * La struture permet la repr�sentation d'un arbre binaire, utilis� pour le dictionnaire.
 */
typedef struct node{
    char data;
    int occu;
    struct node *left;
    struct node *right;
}Node;

/**
 * \struct ListNode
 * \brief Structure contenant un pointeur de Node data et le pointeur vers le prochain maillon.
 * 
 * La structure permet de la lister des arbres bianires Node.
 */
typedef struct listnode{
    Node *data;
    struct listnode *next;
}ListNode;

/**
 * \struct NodeCode
 * \brief Structure contenant un caract�re data, son Code code et les pointeurs vers le fils gauche et le fils droit de l'arbre.
 * 
 * La structure permet de repr�senter un arbre contenant des caract�res avec leur nouveau code binaire.
 */
typedef struct nodecode{
    char data;
    Code* code;
    struct nodecode *left;
    struct nodecode *right;
}NodeCode;

/**
 * \struct ListCode
 * \brief Structure contenant un caract�re data, son Code code et le pointeur vers le prochain maillon.
 * 
 * La structure permet de lister des caract�res avec leur nouveau code binaire.
 */
typedef struct listcode{
    char data;
    Code* code;
    struct listcode* next;
}ListCode;

#endif //TEST_STRUCTURES_H
