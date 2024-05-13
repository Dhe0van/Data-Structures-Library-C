#include <stdio.h>
#include <stdlib.h>

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