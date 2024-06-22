#include <math.h>
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

#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE

struct BinarySearchTree {
    int value;
    int count;
    struct BinarySearchTree* left;
    struct BinarySearchTree* right;
};


struct BinarySearchTree* newBST_node(int value) {
    struct BinarySearchTree* newNode = (struct BinarySearchTree*) malloc(sizeof(struct BinarySearchTree));

    newNode->value = value;
    newNode->count = 1;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct BinarySearchTree* insertBST_node(struct BinarySearchTree* bst, int value) {
    if (bst == NULL) bst = newBST_node(value);
    else if (bst->value > value) bst->left = insertBST_node(bst->left, value);
    else if (bst->value < value) bst->right = insertBST_node(bst->right, value);
    else if (bst->value == value) bst->count += 1;

    return bst;
}

struct BinarySearchTree* findPredecessorBSTNode(struct BinarySearchTree* bst) {
    while (bst->right != NULL) {
        bst = bst->right;
    }
    return bst;
}

struct BinarySearchTree* deleteBST_node(struct BinarySearchTree* bst, int value) {
    if (bst == NULL) return bst;
    else if (bst->value > value) bst->left = deleteBST_node(bst->left, value);
    else if (bst->value < value) bst->right = deleteBST_node(bst->right, value);
    else {
        if (bst->left == NULL && bst->right == NULL) {
            free(bst);
            bst = NULL;
        } else if (bst->left == NULL) {
            struct BinarySearchTree* temp = bst;
            bst = bst->right;
            free(temp);
        } else if (bst->right == NULL) {
            struct BinarySearchTree* temp = bst;
            bst = bst->left;
            free(temp);
        } else {
            struct BinarySearchTree* temp = findPredecessorBSTNode(bst->left);
            bst->value = temp->value;
            bst = deleteBST_node(temp, temp->value);
        }
    }
    return bst;
}

void printInOrderBST(struct BinarySearchTree* bst) {
    if (bst == NULL) return;

    printInOrderBST(bst->left);
    printf("%d ", bst->value);
    printInOrderBST(bst->right);
}


void printPreOrderBST(struct BinarySearchTree* bst) {
    if (bst == NULL) return;

    printf("%d ", bst->value);
    printInOrderBST(bst->left);
    printInOrderBST(bst->right);
}

void printPostOrderBST(struct BinarySearchTree* bst) {
    if (bst == NULL) return;

    printInOrderBST(bst->left);
    printInOrderBST(bst->right);
    printf("%d ", bst->value);
}
#endif

#ifndef AVL_TREE
#define AVL_TREE

struct AVLTreeNode {
    int key;
    int height;
    int count;
    struct AVLTreeNode* left;
    struct AVLTreeNode* right;
};

struct AVLTreeNode* createNewAVLTreeNode(int key) {
    struct AVLTreeNode* newNode = (struct AVLTreeNode*) malloc(sizeof(struct AVLTreeNode));

    newNode->key = key;
    newNode->height = newNode->count = 1;
    newNode->left = newNode->right = NULL;
    return newNode;
}

int getNodeHeight(struct AVLTreeNode* AVLNode) {
    return (AVLNode == NULL) ? 0 : AVLNode->height;
}

int getNodeMaxHeight(struct AVLTreeNode* AVLNode) {
    return (getNodeHeight(AVLNode->left) > getNodeHeight(AVLNode->right)) ?
            getNodeHeight(AVLNode->left) :
            getNodeHeight(AVLNode->right);
}

int getNodeBalanceFactor(struct AVLTreeNode* AVLNode) {
    return (AVLNode == NULL) ? 0 : getNodeHeight(AVLNode->left)-getNodeHeight(AVLNode->right);
}

struct AVLTreeNode* rotateAVLTreeToRight(struct AVLTreeNode* parent) {
    struct AVLTreeNode* leftChild = parent->left;
    struct AVLTreeNode* rightGrandChild = leftChild->right;

    leftChild->right = parent;
    parent->left = rightGrandChild;

    parent->height = 1 + getNodeMaxHeight(parent);
    leftChild->height = 1 + getNodeBalanceFactor(leftChild);
    return leftChild;
}

struct AVLTreeNode* rotateAVLTreeToLeft(struct AVLTreeNode* parent) {
    struct AVLTreeNode* rightChild = parent->right;
    struct AVLTreeNode* leftGrandChild = rightChild->left;

    rightChild->left = parent;
    parent->right = leftGrandChild;

    parent->height = 1 + getNodeMaxHeight(parent);
    rightChild->height = 1 + getNodeBalanceFactor(rightChild);
    return rightChild;
}

struct AVLTreeNode* insertAVLTreeNode(struct AVLTreeNode* curr, int key) {
    if (curr == NULL) return createNewAVLTreeNode(key);
    else if (key > curr->key) curr->right = insertAVLTreeNode(curr->right, key); 
    else if (key < curr->key) curr->left = insertAVLTreeNode(curr->left, key); 
    else if (key == curr->key) {
        curr->count += 1;
        return curr;
    }

    curr->height = 1 + getNodeMaxHeight(curr);
    int balanceFactor = getNodeBalanceFactor(curr);

    // Single right-rotate
    if (balanceFactor > 1 && getNodeBalanceFactor(curr->left) >= 0) {
        return rotateAVLTreeToRight(curr);
    }
    
    // Double left-right-rotate
    if (balanceFactor > 1 && getNodeBalanceFactor(curr->left) < 0) {
        curr->left = rotateAVLTreeToLeft(curr->left);
        return rotateAVLTreeToRight(curr);
    }

    // Single left-rotate
    if (balanceFactor < -1 && getNodeBalanceFactor(curr->right) <= 0) {
        return rotateAVLTreeToLeft(curr);
    }

    // Double right-left-rotate
    if (balanceFactor < -1 && getNodeBalanceFactor(curr->right) > 0) {
        curr->right = rotateAVLTreeToRight(curr->right);
        return rotateAVLTreeToLeft(curr);
    }

    return curr;
}

struct AVLTreeNode* findPredecessorAVLNode(struct AVLTreeNode* curr) {
    while (curr->right != NULL)
        curr = curr->right;
    return curr;
}

struct AVLTreeNode* deleteAVLTreeNode(struct AVLTreeNode* curr, int key) {
    if (curr == NULL) return curr;
    else if (key > curr->key) curr->right = deleteAVLTreeNode(curr->right, key);
    else if (key < curr->key) curr->left = deleteAVLTreeNode(curr->left, key);
    else {
        if (curr->count > 1) {
            curr->count -= 1;
            return curr;
        } else if (curr->left == NULL && curr->right == NULL) {
            free(curr);
            curr = NULL;
            return curr;
        } else if (curr->left == NULL) {
            struct AVLTreeNode* temp = curr;
            curr = curr->right;
            free(temp);
        } else if (curr->right == NULL) {
            struct AVLTreeNode* temp = curr;
            curr = curr->left;
            free(temp);
        } else {
            struct AVLTreeNode* temp = findPredecessorAVLNode(curr->left);
            curr->key = temp->key;
            curr->count = temp->count;
            temp->count = 1;
            curr->left = deleteAVLTreeNode(curr->left, temp->key);
        }
    }

    curr->height = 1 + getNodeMaxHeight(curr);
    int balanceFactor = getNodeBalanceFactor(curr);

    // Single right-rotate
    if (balanceFactor > 1 && getNodeBalanceFactor(curr->left) >= 0) {
        return rotateAVLTreeToRight(curr);
    }
    
    // Double left-right-rotate
    if (balanceFactor > 1 && getNodeBalanceFactor(curr->left) < 0) {
        curr->left = rotateAVLTreeToLeft(curr->left);
        return rotateAVLTreeToRight(curr);
    }

    // Single left-rotate
    if (balanceFactor < -1 && getNodeBalanceFactor(curr->right) <= 0) {
        return rotateAVLTreeToLeft(curr);
    }

    // Double right-left-rotate
    if (balanceFactor < -1 && getNodeBalanceFactor(curr->right) > 0) {
        curr->right = rotateAVLTreeToRight(curr->right);
        return rotateAVLTreeToLeft(curr);
    }

    return curr;
}

void printPreOrderAVLTree(struct AVLTreeNode* curr) {
    if (curr == NULL) return;

    printf("%d ", curr->key);
    printPreOrderAVLTree(curr->left);
    printPreOrderAVLTree(curr->right);
}

void printInOrderAVLTree(struct AVLTreeNode* curr) {
    if (curr == NULL) return;

    printInOrderAVLTree(curr->left);
    printf("%d ", curr->key);
    printInOrderAVLTree(curr->right);
}
void printPostOrderAVLTree(struct AVLTreeNode* curr) {
    if (curr == NULL) return;

    printPostOrderAVLTree(curr->left);
    printPostOrderAVLTree(curr->right);
    printf("%d ", curr->key);
}

#endif