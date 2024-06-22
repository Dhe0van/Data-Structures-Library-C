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

#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE

struct BinarySearchTree {
    int value;
    int count;
    struct BinarySearchTree* left;
    struct BinarySearchTree* right;
};

struct BinarySearchTree* newBST_node(int value);
struct BinarySearchTree* insertBST_node(struct BinarySearchTree* bst, int value);
struct BinarySearchTree* findPredecessorNode(struct BinarySearchTree* bst);
struct BinarySearchTree* deleteBST_node(struct BinarySearchTree* bst, int value);
void printInOrderBST(struct BinarySearchTree* bst);
void printPreOrderBST(struct BinarySearchTree* bst);
void printPostOrderBST(struct BinarySearchTree* bst);

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

struct AVLTreeNode* createNewAVLTreeNode(int key);
int getNodeHeight(struct AVLTreeNode* AVLNode);
int getNodeMaxHeight(struct AVLTreeNode* AVLNode);
int getNodeBalanceFactor(struct AVLTreeNode* AVLNode);
struct AVLTreeNode* rotateAVLTreeToRight(struct AVLTreeNode* parent);
struct AVLTreeNode* rotateAVLTreeToLeft(struct AVLTreeNode* parent);
struct AVLTreeNode* insertAVLTreeNode(struct AVLTreeNode* curr, int key);
struct AVLTreeNode* findPredecessorAVLNode(struct AVLTreeNode* curr);
struct AVLTreeNode* deleteAVLTreeNode(struct AVLTreeNode* curr, int key);
void printPreOrderAVLTree(struct AVLTreeNode* curr);
void printInOrderAVLTree(struct AVLTreeNode* curr);
void printPostOrderAVLTree(struct AVLTreeNode* curr);

#endif

#endif