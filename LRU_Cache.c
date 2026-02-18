Implement the LRUCache class:

LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
int get(int key) Return the value of the key if the key exists, otherwise return -1.
void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache.
If the number of keys exceeds the capacity from this operation, evict the least recently used key.
The functions get and put must each run in O(1) average time complexity.

Example 1:
Input
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
Output
[null, null, null, 1, null, -1, null, -1, 3, 4]

#include <stdlib.h>

typedef struct Node {
    int key;
    int value;
    struct Node *prev;
    struct Node *next;
} Node;

typedef struct {
    int capacity;
    int size;
    Node **hash;
    int hashSize;
    Node *head;
    Node *tail;
} LRUCache;

Node *createNode(int key, int value) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->key = key;
    node->value = value;
    node->prev = NULL;
    node->next = NULL;
    return node;
}

void removeNode(Node *node) {
    node->prev->next = node->next;
    node->next->prev = node->prev;
}

void insertToHead(LRUCache *obj, Node *node) {
    node->next = obj->head->next;
    node->prev = obj->head;
    obj->head->next->prev = node;
    obj->head->next = node;
}

LRUCache *lRUCacheCreate(int capacity) {
    LRUCache *obj = (LRUCache *)malloc(sizeof(LRUCache));
    obj->capacity = capacity;
    obj->size = 0;
    obj->hashSize = 10001;
    obj->hash = (Node **)calloc(obj->hashSize, sizeof(Node *));
    obj->head = createNode(0, 0);
    obj->tail = createNode(0, 0);
    obj->head->next = obj->tail;
    obj->tail->prev = obj->head;
    return obj;
}

int lRUCacheGet(LRUCache *obj, int key) {
    Node *node = obj->hash[key];
    if (!node)
        return -1;
    removeNode(node);
    insertToHead(obj, node);
    return node->value;
}

void lRUCachePut(LRUCache *obj, int key, int value) {
    Node *node = obj->hash[key];
    if (node) {
        node->value = value;
        removeNode(node);
        insertToHead(obj, node);
    } else {
        Node *newNode = createNode(key, value);
        obj->hash[key] = newNode;
        insertToHead(obj, newNode);
        obj->size++;
        if (obj->size > obj->capacity) {
            Node *lru = obj->tail->prev;
            removeNode(lru);
            obj->hash[lru->key] = NULL;
            free(lru);
            obj->size--;
        }
    }
}

void lRUCacheFree(LRUCache *obj) {
    Node *curr = obj->head;
    while (curr) {
        Node *temp = curr;
        curr = curr->next;
        free(temp);
    }
    free(obj->hash);
    free(obj);
}


 
