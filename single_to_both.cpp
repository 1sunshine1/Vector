#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prior;
} Node, *LinkedList;

Node insert(LinkedList head, int value, int index) {
    Node *p, ret;
    int raw_index = index, len = 0;
    p = head;
    ret.data = 0;
    while (p && index--) {
        p = p->next;
        len++;
        if (p == head) break;
    }
    if (index == 0) {
        Node *new_node = (Node *)malloc(sizeof(Node));
        new_node->next = new_node;
        new_node->data = value;
        new_node->prior = NULL;
        if (p != NULL) {
            new_node->next = p->next;
            p->next = new_node;
        }
        if (p == head && len == raw_index) {
            head = new_node;
        }
        ret.data = 1;
    }
    ret.next = head;
    return ret;
}
LinkedList build(LinkedList head) {
    Node *p, *q;
    if (head == NULL) {
        return head;
    }
    p = head;
    q = head->next;
    do {
        q->prior = p;
        p = p->next;
        q = q->next;
    } while (p != head);
    return head;
}
void output(LinkedList head, int m) {
    Node *p, *q;
    p = head;
    while (p->data != m) {
        p = p->next;
    }
    printf("%d\n", p->data);
    q = p;
    p = p->prior;
    while (p != q) {
        printf("%d\n", p->data);
        p = p->prior;
    }
    return ;
}
void clear(LinkedList head) {
    Node *p, *q;
    p = head;
    while (p) {
        q = p->next;
        free(p);
        p = q;
    }
    return ;
}
int main() {
    LinkedList l = NULL;
    Node ret;
    int n, m, num;
    scanf("%d\n", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d\n", &num);
        ret = insert(l, num, i);
        if (ret.data == 0) {
            printf("ERROR\n");
            return 1;
        }
        l = ret.next;
    }
    l = build(l);
    scanf("%d\n", &m);
    output(l, m);
    fflush(stdout);
    clear(l);
    return 0;
}
