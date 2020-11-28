#ifndef TEST_STRUCTURES_H
#define TEST_STRUCTURES_H

typedef struct list{
    char data;
    int occu;
    struct list *next;
}List;

typedef struct code {
    char data;
    struct code *next;
}Code;

typedef struct node{
    char data;
    int occu;
    struct node *left;
    struct node *right;
}Node;

typedef struct listnode{
    Node *data;
    struct listnode *next;
}ListNode;

typedef struct nodecode{
    char data;
    Code* code;
    struct nodecode *left;
    struct nodecode *right;
}NodeCode;

typedef struct listcode{
    char data;
    Code* code;
    struct listcode* next;
}ListCode;

#endif //TEST_STRUCTURES_H
