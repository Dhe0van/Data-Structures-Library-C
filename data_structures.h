#ifndef DATA_STRUCTURES_H
#define DATA_STRUCTURES_H

#ifndef SINGLE_LINKED_LIST
#define SINGLE_LINKED_LIST
struct SingleLinkedListNode {
    int value;
    struct SingleLinkedListNode* next;
};

struct SingleLinkedList {
    struct SingleLinkedListNode* head;
    struct SingleLinkedListNode* tail;
};

struct SingleLinkedList* newSingleLinkedList();
struct SingleLinkedListNode* newSingleLinkedListNode(int value);
void insertSingleLinkedListNode(struct SingleLinkedList* list , int value);
void removeSingleLinkedListNode(struct SingleLinkedList* list, int value);
void printSingleLinkedList(struct SingleLinkedList* list);

#endif

#ifndef DOUBLE_LINKED_LIST
#define DOUBLE_LINKED_LIST

struct DoubleLinkedListNode {
    int value;
    struct DoubleLinkedListNode* next;
    struct DoubleLinkedListNode* prev;
};

struct DoubleLinkedList {
    struct DoubleLinkedListNode* head;
    struct DoubleLinkedListNode* tail;
};

struct DoubleLinkedList* newDoubleLinkedList();
struct DoubleLinkedListNode* newDoubleLinkedListNode(int value);
void insertDoubleLinkedListNode(struct DoubleLinkedList* list, int value);
void removeDoubleLinkedListNode(struct DoubleLinkedList* list, int value);
void printDoubleLinkedList(struct DoubleLinkedList* list);

#endif

#endif