Given a singly linked list, return a random node's value from the linked list. Each node must have the same probability of being chosen.

Implement the Solution class:
Solution(ListNode head) Initializes the object with the head of the singly-linked list head.
int getRandom() Chooses a node randomly from the list and returns its value. All the nodes of the list should be equally likely to be chosen.

#include <stdlib.h>

typedef struct {
    struct ListNode* head;
} Solution;

Solution* solutionCreate(struct ListNode* head) {
    Solution* obj = (Solution*)malloc(sizeof(Solution));
    obj->head = head;
    return obj;
}

int solutionGetRandom(Solution* obj) {
    struct ListNode* current = obj->head;
    int result = current->val;
    int n = 1;
    while(current != NULL){
        if(rand() % n == 0){
            result = current->val;
        }
        current = current->next;
        n++;
    }
    return result;
}

void solutionFree(Solution* obj) {
    free(obj);
}

 
