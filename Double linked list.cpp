#include <stdio.h>
#include <stdlib.h>


struct tnode {
    int x;
    struct tnode *next, *prev;
} *head, *tail;


void pushFront(int value) {
    struct tnode *node = (struct tnode*) malloc(sizeof(struct tnode));
    node->x = value;
    node->prev = NULL; 
    
    if (head == NULL) {  
        head = tail = node;
        node->next = NULL;
    } else {
        node->next = head;
        head->prev = node;
        head = node;
    }
}


void pushBack(int value) {
    struct tnode *node = (struct tnode*) malloc(sizeof(struct tnode));
    node->x = value;
    node->next = NULL; 

    if (head == NULL) {  
        head = tail = node;
        node->prev = NULL;
    } else {
        tail->next = node;
        node->prev = tail;
        tail = node;
    }
}


void pushMid(int value, int searchKey) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct tnode *curr = head;
    while (curr != NULL) {
        if (curr->x == searchKey) {
            struct tnode *node = (struct tnode*) malloc(sizeof(struct tnode));
            node->x = value;

            if (curr == tail) {  
                pushBack(value);
            } else {
                node->next = curr->next;
                node->prev = curr;
                if (curr->next != NULL)
                    curr->next->prev = node;
                curr->next = node;
            }
            return;
        }
        curr = curr->next;
    }
    printf("Data %d not found in the linked list\n", searchKey);
}


void delFront() {
    if (head == NULL) {
        printf("There is no data\n");
        return;
    }

    struct tnode *del = head;
    if (head == tail) {  
        head = tail = NULL;
    } else {
        head = head->next;
        head->prev = NULL;
    }
    free(del);
}

void delBack() {
    if (head == NULL) {
        printf("There is no data\n");
        return;
    }

    struct tnode *del = tail;
    if (head == tail) {  
        head = tail = NULL;
    } else {
        tail = tail->prev;
        tail->next = NULL;
    }
    free(del);
}


void delMid(int value) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct tnode *curr = head;

  
    while (curr != NULL) {
        if (curr->x == value) {
            if (curr == head) { 
                delFront();
            } else if (curr == tail) { 
                tail = tail->prev;
                tail->next = NULL;
                free(curr);
            } else { 
                curr->prev->next = curr->next;
                curr->next->prev = curr->prev;
                free(curr);
            }
            return;
        }
        curr = curr->next;
    }
    printf("Data %d not found in the linked list\n", value);
}


void printList() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct tnode *curr = head;
    printf("Linked List: ");
    while (curr != NULL) {
        printf("%d ", curr->x);
        curr = curr->next;
    }
    printf("\n");
}

// Main function
int main() {
    printf("Doubly Linked List\n");
    
    pushBack(13);
    pushBack(1);
    pushBack(3);
    pushBack(1);
    pushBack(2);
    pushBack(3);
    pushBack(4);
    printList(); 

    delFront();
    printList();  

    pushBack(99);
    pushFront(7);
    printList();  

    delMid(3);
    printList();  

    delMid(99);
    printList(); 
      
    delBack();
    printList(); 
    

    return 0;
}

