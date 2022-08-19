using namespace std;
#include <bits/stdc++.h>

class Node {
 public:
  int data;
  Node *next;
};

void printList(Node *n) {
  while (n != NULL) {
    cout << n->data << " ";
    n = n->next;
  }
  cout << endl;
}

void push(Node **head_ref, int new_data) {
  Node *new_node = new Node();

  new_node->data = new_data;

  new_node->next = (*head_ref);

  (*head_ref) = new_node;
}

void insertAfter(Node *prev_node, int new_data) {
  if (prev_node == NULL) {
    cout << "Previous node cannot be NULL" << endl;
    return;
  }
  Node *new_node = new Node();

  new_node->data = new_data;

  new_node->next = prev_node->next;

  prev_node->next = new_node;
}

void append(Node **head_ref, int new_data) {
  Node *new_node = new Node();

  Node *last = *head_ref;

  new_node->data = new_data;

  new_node->next = NULL;

  if (*head_ref == NULL) {
    *head_ref = new_node;
    return;
  }
  while (last->next != NULL) last = last->next;

  last->next = new_node;
  return;
}

void deleteNode(Node **head_ref, int key) {
  Node *temp = new Node();
  Node *prev = new Node();
  temp = *head_ref;

  if (temp != NULL && temp->data == key) {
    *head_ref = temp->next;
    free(temp);
  }
  while (*head_ref != NULL && temp->data != key) {
    prev = temp;
    temp = temp->next;
  }

  if (temp->next == NULL) return;
  prev->next = temp->next;
  free(temp);
}

void deleteNodeat(Node **head_ref, int position) {
  Node *temp = new Node();
  temp = *head_ref;

  if (position == 0) {
    *head_ref = temp->next;
    free(temp);
    return;
  }
  for (int i = 0; temp != NULL && i < position - 1; i++) temp = temp->next;

  if (temp == NULL || temp->next == NULL) return;

  Node *next = temp->next->next;
  free(temp->next);
  temp->next = next;
}

void deleteList(Node **head_ref) {
  Node *current = *head_ref;
  Node *next;

  while (current != NULL) {
    next = current->next;
    free(current);
    current = next;
  }

  *head_ref = NULL;
}

int getCount(Node **head_ref) {
  int count = 0;
  Node *current = *head_ref;
  while (current != NULL) {
    count++;
    current = current->next;
  }
  return count;
}

bool searchList(Node *head, int arg) {
  Node *current = head;

  while (current != NULL) {
    if (current->data == arg) return true;
    current = current->next;
  }
  return false;
}

int countElement(Node *head, int arg) {
  int count = 0;
  Node *current = head;
  while (current->next != NULL) {
    if (current->data == arg) count++;
    current = current->next;
  }
  return count;
}

int nthElement(Node *head, int n) {
  Node *current = head;
  for (int i = 0; i < n; i++) {
    current = current->next;
  }
  return current->data;
}

int nthfromlast(Node *head, int n) {
  Node *current = head;
  Node *last = head;
  for (int i = 0; i < n; i++) {
    last = last->next;
  }
  while (last->next != NULL) {
    current = current->next;
    last = last->next;
  }
  return current->data;
}

int middleElement(Node *head) {
  Node *current = head;
  int count = 0;
  while (head != NULL) {
    if (count & 1) current = current->next;
    count++;
    head = head->next;
  }
  return current->data;
}

int main() {
  Node *head = NULL;
  Node *second = NULL;
  Node *third = NULL;

  head = new Node();
  second = new Node();
  third = new Node();

  head->data = 1;
  head->next = second;

  second->data = 2;
  second->next = third;

  third->data = 3;
  third->next = NULL;

  append(&head, 4);
  append(&head, 5);
  insertAfter(head, 10);
  push(&head, 11);
  push(&head, 12);
  push(&head, 4);
  printList(head);
  cout << middleElement(head) << endl;
  cout << countElement(head, 4) << endl;

  return 0;
}

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void printList(ListNode *);