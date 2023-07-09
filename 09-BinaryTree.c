#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int val;
  struct node *right;
  struct node *left;
} node_t;

void insert(node_t *tree, int val);
void print_tree(node_t * current);

void printDFS(node_t *current);

int main() {
  node_t *test = (node_t *)malloc(sizeof(node_t));
  test->val = 0;
  test->left = NULL;
  test->right = NULL;

  insert(test, 5);
  insert(test, 3);
  insert(test, 9);
  insert(test, 7);
  insert(test, 2);

  printDFS(test);
  printf("\n");

  return 0;
}

void insert(node_t *tree, int val) {
  /* Insert on current position (empty) */
  if (tree->val == 0) {
    tree->val = val;
  } else {
    /* Check the value sent is smaller than the root value */
    if (val < tree->val) {
      /* Insert Left */
      if (tree->left != NULL) {
        insert(tree->left, val);
      } else {
        tree->left = (node_t *)malloc(sizeof(node_t));

        tree->left->val = val;
        tree->left->left = NULL;
        tree->left->right = NULL;
      }
    } else {
      if (val >= tree->val) {
        /* insert right */
        if (tree->right != NULL) {
          insert(tree->right, val);
        } else {
          tree->right = (node_t *)malloc(sizeof(node_t));

          tree->right->val = val;
          tree->right->left = NULL;
          tree->right->right = NULL;
        }
      }
    }
  }
}
void printDFS(node_t *current) {
  if (current == NULL)
    return;
  if (current != NULL)
    printf("%d ", current->val);
  if (current->left != NULL)
    printDFS(current->left);
  if (current->right != NULL)
    printDFS(current->right);
}