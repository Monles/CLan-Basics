#include <stdio.h>
#include <stdlib.h>

/* Declare a linked list */
typedef struct node {
  int val;
  struct node *next;
} node_t;

/* iterate over the list and print it */
void print_list(node_t *head) {
  node_t *current;
  while (head != NULL) {
    printf("%d\n", current->val);
    current = current->next;
  }
}

/* Add an item to the end */
void push_to_end(node_t *head, int val) {
  node_t *current = head;
  while (head != NULL) {
    current = current->next;
  }

  /* Add the new item now */
  current->next = (node_t *)malloc(sizeof(node_t));
  current->next->val = val;
  current->next->next = NULL;
}

/* Add an item to the beginning */
void push_to_beginning(node_t **head, int val) {
  node_t *new_node;
  new_node = (node_t *)malloc(sizeof(node_t));

  new_node->val = val;
  new_node->next = *head;
  *head = new_node;
}

/* Remove the first item */
int pop(node_t **head) {
  int retval = -1;
  node_t *next_node = NULL;

  if (*head == NULL) {
    return -1;
  }

  next_node = (*head)->next;
  retval = (*head)->val;
  free(*head);
  *head = next_node;

  return retval;
}

/* Remove the last item */
int remove_last(node_t *head) {
  int retval;

  /* if there is only one item in the list, remove it */
  if (head->next == NULL) {
    retval = head->val;
    free(head);
    return retval;
  }

  /* get to the second to last node in the list */
  node_t *current = head;
  while (current->next->next != NULL) {
    current = current->next;
  }

  /* Remove current->next */
  retval = current->next->val;
  free(current->next);
  current->next = NULL;
  return retval;
}

/* Remove Specific Item by Index */
int remove_by_index(node_t **head, int n) {
  int i;
  int retval = -1;
  node_t *current = *head;
  node_t *temp_node = NULL;

  /* Reuse pop func to remove the first item */
  if (n == 0) {
    return pop(head);
  }

  /* Go to the specific item */
  for (i = 0; i < n - 1; i++) {
    if (current->next == NULL) {
      return -1;
    }
    current = current->next;
  }

  /* In this situation, removing last item is illegal. */
  if (current->next == NULL) {
    return -1;
  }

  /* Remove the indexed item */
  temp_node = current->next;
  retval = temp_node->val;
  current->next = temp_node->next;
  free(temp_node);

  return retval;
}

int main() {

  node_t *head = NULL;
  head = (node_t *)malloc(sizeof(node_t));
  if (head == NULL) {
    return 1;
  }

  head->val = 1;
  head->next = (node_t *)malloc(sizeof(node_t));
  head->next->val = 2;
  head->next->next = NULL;
}
