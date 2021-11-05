#include <stdio.h>
#include <stdlib.h>

// struct ListNode {
//     int val;
//     struct ListNode * next;
// };

typedef struct ListNode {
    int val;
    struct ListNode* next;
} ListNode;


// struct ListNode *head = NULL;
ListNode* head = NULL;

/**
 * get created single node
 * 
 * @param integer number
 * 
 * @return ListNode
 */
struct ListNode* getNode(int number) {
    struct ListNode* tmpNode = (struct ListNode *) malloc(sizeof(struct ListNode));

    tmpNode->val = number;
    tmpNode->next = NULL;

    return tmpNode;
}

/**
 * add to last node: find outputNode last position and add inputNode to that position
 * 
 * if head is null than initial head with passing value
 * update tmp node to record next node
 * 
 * @param integer number
 * 
 * @return void
 */
void addToLastNode(int number) {

    struct ListNode* tmp = head;
    // if head is null, init head node with passing value
    if (head == NULL) {
        head = getNode(number);
    } else {
        // replace tmp with next node position
        while (tmp->next != NULL) {
            tmp = tmp->next;
        }
        // add to next node(found last node when skip while loop)
        tmp->next = getNode(number);
    }
}


/**
 * get middel node from head
 * 
 * @return NodeList
 */
struct ListNode* findMiddleNodeByHalf() {
    ListNode* currentNode = head;

    int counter = 0;
    while (currentNode->next != NULL) {
        currentNode = currentNode->next;
        counter = counter + 1;
        // printf("%d: %d", counter, head->val);
    }

    // printf("%d: ", counter/2);
    ListNode* resultNode = head;
    for (int i=0; i<counter/2; i++) {
        if (resultNode->next != NULL) {
            resultNode = resultNode->next;
        }
    }
    
    return resultNode;
}

struct ListNode* findMiddleNodeByHare() {
    ListNode* fastNode = head;
    ListNode* slowNode = head;

    while(fastNode->next != NULL && fastNode->next->next != NULL) {
        fastNode = fastNode->next->next;
        slowNode = slowNode->next;

        // printf("%d:", slowNode->val);
    }

    return slowNode;
}

int main() {
    int data[] = {3, 3, 6, 7, 8, 9, 11, 33, 123};
    int length = sizeof(data)/ sizeof(data[0]);

    struct ListNode* tmp = NULL;
    for (int i=0; i<length; i++) {
        addToLastNode(data[i]);
    }

    // ListNode* middle = findMiddleNodeByHalf();
    ListNode* middle = findMiddleNodeByHare();

    printf("%d", middle->val);

    return 0;
}


