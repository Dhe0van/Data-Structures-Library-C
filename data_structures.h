#ifndef DATA_STRUCTURES_H
#define DATA_STRUCTURES_H

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