#include <stdio.h>
#include <stdlib.h>

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

struct SingleLinkedList* newSingleLinkedList() {
    struct SingleLinkedList* list = (struct SingleLinkedList*) malloc(sizeof(struct SingleLinkedList));

    list->head = list->tail = NULL;
    return list;
}

struct SingleLinkedListNode* newSingleLinkedListNode(int value) {
    struct SingleLinkedListNode* node = (struct SingleLinkedListNode*) malloc(sizeof(struct SingleLinkedListNode));

    node->value = value;
    node->next = NULL;
    return node;
}

void insertSingleLinkedListNode(struct SingleLinkedList* list , int value) {
    struct SingleLinkedListNode* newNode = newSingleLinkedListNode(value);

    if (list->head == NULL && list->tail == NULL) {
        list->head = list->tail = newNode;
    } else if (list->head->value >= value) {
        newNode->next = list->head;
        list->head = newNode;
    } else if (list->tail->value <= value) {
        list->tail->next = newNode;
        list->tail = newNode;
    } else {
        struct SingleLinkedListNode* curr = list->head;
        while (curr != NULL) {
            if (curr->next->value > value) {
                newNode->next = curr->next;
                curr->next = newNode;
                break;
            }
            curr = curr->next;
        }
    }
}

void removeSingleLinkedListNode(struct SingleLinkedList* list, int value) {
    if (list->head == NULL && list->tail == NULL) return;
    else if (list->head == list->tail) list->head = list->tail = NULL;
    else if (list->head->value == value) {
        struct SingleLinkedListNode* temp = list->head;
        list->head = list->head->next;
        free(temp);
    } else if (list->tail->value == value) {
        struct SingleLinkedListNode* temp = list->tail;

        struct SingleLinkedListNode* curr = list->head;
        while (curr->next != NULL) {
            if (curr->next->value == temp->value) {
                list->tail = curr;
                list->tail->next = NULL;
                break;
            }
            curr = curr->next;
        }   
        free(temp);
    } else {
        struct SingleLinkedListNode* curr = list->head;
        while (curr->next != NULL) {
            if (curr->next->value == value) {
                struct SingleLinkedListNode* temp = curr->next;
                curr->next = temp->next;
                free(temp);
                break;
            }
            curr = curr->next;
        }
    }
} 

void printSingleLinkedList(struct SingleLinkedList* list) {
    struct SingleLinkedListNode* curr = list->head;
    while (curr != NULL) {
        printf("%d -> ", curr->value);
        curr = curr->next;
    }
    puts("");
}

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


struct DoubleLinkedList* newDoubleLinkedList() {
    struct DoubleLinkedList* list = (struct DoubleLinkedList*) malloc(sizeof(struct DoubleLinkedList));

    list->head = list->tail = NULL;
    return list;
}

struct DoubleLinkedListNode* newDoubleLinkedListNode(int value) {
    struct DoubleLinkedListNode* newNode = (struct DoubleLinkedListNode*) malloc(sizeof(struct DoubleLinkedListNode));

    newNode->value = value;
    newNode->next = newNode->prev = NULL;
    return newNode;
}

void insertDoubleLinkedListNode(struct DoubleLinkedList* list, int value) {
    struct DoubleLinkedListNode* newNode = newDoubleLinkedListNode(value);

    if (list->head == NULL && list->tail == NULL) {
        list->head = list->tail = newNode;
    } else if (list->head->value >= value) {
        newNode->next = list->head;
        list->head->prev = newNode;
        list->head = newNode;
    } else if (list->tail->value <= value) {
        list->tail->next = newNode;
        newNode->prev = list->tail;
        list->tail = newNode;
    } else {
        struct DoubleLinkedListNode* temp = list->head;
        while (temp != NULL) {
            if (temp->next->value >= value) {
                newNode->prev = temp;
                newNode->next = temp->next;
                temp->next->prev = newNode;
                temp->next = newNode;
                break;
            }
            temp = temp->next;
        }
    }
}

void removeDoubleLinkedListNode(struct DoubleLinkedList* list, int value) {
    if (list->head == NULL && list->tail == NULL) return;
    else if (list->head == list->tail) list->head = list->tail = NULL;
    else if (list->head->value == value) {
        struct DoubleLinkedListNode* temp = list->head;
        list->head = list->head->next;
        list->head->prev = NULL;
        free(temp);
    } else if (list->tail->value == value) {
        struct DoubleLinkedListNode* temp = list->tail;
        list->tail = list->tail->prev;
        list->tail->next = NULL;
        free(temp);
    } else {
        struct DoubleLinkedListNode* temp = list->head;
        while (temp->next->next != NULL) {
            if (temp->next->value == value) {
                struct DoubleLinkedListNode* removedNode = temp->next;
                temp->next = temp->next->next;
                temp->next->prev = temp;
                free(removedNode);
                break;
            }
            temp = temp->next;
        }
    }
}

void printDoubleLinkedList(struct DoubleLinkedList* list) {
    struct DoubleLinkedListNode* temp = list->head;
    while (temp != NULL) {
        printf("%d <-> ", temp->value);
        temp = temp->next;
    }
    puts("");
}

#endif