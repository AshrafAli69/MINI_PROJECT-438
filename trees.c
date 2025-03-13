/*AIM: write a c program on trees for structure,Insert Function,Traversal Function,Search Function,Height Function,Delete Function,Print Tree Function,Menu-Driven Interface

EXPLANATION:
This program implements a binary tree with basic operations such as insertion, traversal, search, deletion, and finding the height of the tree. Here is a breakdown of the program's components:

1.Structure Definition (TreeNode):

The program defines a TreeNode structure that represents a node in the binary tree. Each node contains an integer value (data), and pointers to the left and right child nodes (left, right).
2.Insert Function (insertLevelOrder):

This function inserts elements into the tree in level-order (breadth-first). It uses an array to represent the tree and recursively places nodes in the correct positions based on the level-order input.
3.Traversal Functions:

Pre-order Traversal: Visits the root node first, then recursively traverses the left and right subtrees.
In-order Traversal: Recursively visits the left subtree, then the root, and finally the right subtree.
Post-order Traversal: Recursively traverses the left and right subtrees, then visits the root node.
Level-order Traversal: Traverses the tree level by level (breadth-first), using a queue to visit each node.
4.Search Function:

This function searches for a specific value in the binary tree by recursively checking each node and its children.
5.Height Function:

This function calculates the height of the binary tree by recursively finding the maximum depth of the left and right subtrees.
6.Delete Function (deleteNode):

The function deletes a node with a specific value. If the node has no children, it simply removes it. If it has one child, it links the parent to the child. If it has two children, it replaces the node with its in-order successor.
7.Print Tree Function:

This function prints the tree using level-order traversal, showing the structure of the tree.
8.Menu-Driven Interface:

The program offers a menu allowing users to choose from various operations such as different types of traversals, searching for a value, calculating the tree height, deleting a node, and printing the tree structure.
code:*/

#include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 
 struct TreeNode {
     int data;
     struct TreeNode* left;
     struct TreeNode* right;
 };
 
 // Function prototypes
 struct TreeNode* insertLevelOrder(struct TreeNode* root, int arr[], int i, int n);
 void preOrder(struct TreeNode* root);
 void inOrder(struct TreeNode* root);
 void postOrder(struct TreeNode* root);
 void levelOrder(struct TreeNode* root);
 struct TreeNode* search(struct TreeNode* root, int value);
 int height(struct TreeNode* root);
 struct TreeNode* deleteNode(struct TreeNode* root, int key);
 struct TreeNode* minValueNode(struct TreeNode* node);
 void printTree(struct TreeNode* root);
 
 int main() {
     char input[1024];
     int choice, value, n, i = 0;
 
     printf("Enter the elements of the binary tree in level order (space-separated, use 'null' for empty nodes):\n");
     fgets(input, sizeof(input), stdin);
     
     // Parse the input string into an array of integers
     char* token = strtok(input, " ");
     int arr[100];
     n = 0;
     while (token != NULL) {
         if (strcmp(token, "null") == 0) {
             arr[n++] = -1;  // Use -1 to represent null nodes
         } else {
             arr[n++] = atoi(token);
         }
         token = strtok(NULL, " ");
     }
 
     struct TreeNode* root = NULL;
     root = insertLevelOrder(root, arr, 0, n);
 
     while (1) {
         printf("\nMenu:\n");
         printf("1. Pre-order Traversal\n");
         printf("2. In-order Traversal\n");
         printf("3. Post-order Traversal\n");
         printf("4. Level-order Traversal\n");
         printf("5. Search for a value\n");
         printf("6. Find height of tree\n");
         printf("7. Delete a node\n");
         printf("8. Print Tree\n");
         printf("9. Exit\n");
         printf("Enter your choice: ");
         scanf("%d", &choice);
 
         switch (choice) {
             case 1:
                 printf("Pre-order Traversal: ");
                 preOrder(root);
                 printf("\n");
                 break;
             case 2:
                 printf("In-order Traversal: ");
                 inOrder(root);
                 printf("\n");
                 break;
             case 3:
                 printf("Post-order Traversal: ");
                 postOrder(root);
                 printf("\n");
                 break;
             case 4:
                 printf("Level-order Traversal: ");
                 levelOrder(root);
                 printf("\n");
                 break;
             case 5:
                 printf("Enter value to search: ");
                 scanf("%d", &value);
                 struct TreeNode* result = search(root, value);
                 if (result != NULL) {
                     printf("Found node with value: %d\n", value);
                 } else {
                     printf("Node with value %d not found.\n", value);
                 }
                 break;
             case 6:
                 printf("Height of tree: %d\n", height(root));
                 break;
             case 7:
                 printf("Enter value to delete: ");
                 scanf("%d", &value);
                 root = deleteNode(root, value);
                 break;
             case 8:
                 printf("Tree Structure:\n");
                 printTree(root);
                 break;
             case 9:
                 printf("Exiting...\n");
                 exit(0);
             default:
                 printf("Invalid choice! Please try again.\n");
         }
     }
 
     return 0;
 }
 
 // Function to insert nodes in level order
 struct TreeNode* insertLevelOrder(struct TreeNode* root, int arr[], int i, int n) {
     if (i < n) {
         if (arr[i] == -1) {
             return NULL;
         }
         struct TreeNode* temp = (struct TreeNode*)malloc(sizeof(struct TreeNode));
         temp->data = arr[i];
         temp->left = insertLevelOrder(root, arr, 2 * i + 1, n);
         temp->right = insertLevelOrder(root, arr, 2 * i + 2, n);
         root = temp;
     }
     return root;
 }
 
 // Pre-order traversal (Root -> Left -> Right)
 void preOrder(struct TreeNode* root) {
     if (root == NULL) return;
     printf("%d ", root->data);
     preOrder(root->left);
     preOrder(root->right);
 }
 
 // In-order traversal (Left -> Root -> Right)
 void inOrder(struct TreeNode* root) {
     if (root == NULL) return;
     inOrder(root->left);
     printf("%d ", root->data);
     inOrder(root->right);
 }
 
 // Post-order traversal (Left -> Right -> Root)
 void postOrder(struct TreeNode* root) {
     if (root == NULL) return;
     postOrder(root->left);
     postOrder(root->right);
     printf("%d ", root->data);
 }
 
 // Level-order traversal (Breadth-First Search)
 void levelOrder(struct TreeNode* root) {
     if (root == NULL) {
         printf("Tree is empty.\n");
         return;
     }
     struct TreeNode* queue[100];
     int front = 0, rear = 0;
     int isFirstNode = 1;
 
     queue[rear++] = root;
     while (front < rear) {
         struct TreeNode* node = queue[front++];
         if (node != NULL) {
             if (!isFirstNode) {
                 printf(" ");
             }
             printf("%d", node->data);
             isFirstNode = 0;
             queue[rear++] = node->left;
             queue[rear++] = node->right;
         }
     }
     printf("\n");
 }
 
 // Function to search a value in the binary tree
 struct TreeNode* search(struct TreeNode* root, int value) {
     if (root == NULL || root->data == value) {
         return root;
     }
     struct TreeNode* leftResult = search(root->left, value);
     if (leftResult != NULL) {
         return leftResult;
     }
     return search(root->right, value);
 }
 
 // Function to find the height of the binary tree
 int height(struct TreeNode* root) {
     if (root == NULL) {
         return 0;
     }
     int leftHeight = height(root->left);
     int rightHeight = height(root->right);
     return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
 }
 
 // Function to delete a node in the binary tree
 struct TreeNode* deleteNode(struct TreeNode* root, int key) {
     if (root == NULL) {
         return root;
     }
 
     if (key < root->data) {
         root->left = deleteNode(root->left, key);
     } else if (key > root->data) {
         root->right = deleteNode(root->right, key);
     } else {
         // Node to be deleted found
         printf("Deleting node with value: %d\n", root->data);  // Print the deleted value
         if (root->left == NULL) {
             struct TreeNode* temp = root->right;
             free(root);
             return temp;
         } else if (root->right == NULL) {
             struct TreeNode* temp = root->left;
             free(root);
             return temp;
         }
 
         // Node with two children
         struct TreeNode* temp = minValueNode(root->right);
         root->data = temp->data;
         root->right = deleteNode(root->right, temp->data);
     }
     return root;
 }
 
 // Function to find the minimum value node in the tree
 struct TreeNode* minValueNode(struct TreeNode* node) {
     struct TreeNode* current = node;
     while (current && current->left != NULL) {
         current = current->left;
     }
     return current;
 }
 
 // Function to print the tree structure (Level order)
 void printTree(struct TreeNode* root) {
     if (root == NULL) {
         printf("Tree is empty.\n");
         return;
     }
     printf("Level order traversal:\n");
     struct TreeNode* queue[100];
     int front = 0, rear = 0;
     int isFirstNode = 1;
 
     queue[rear++] = root;
     while (front < rear) {
         struct TreeNode* node = queue[front++];
         if (node != NULL) {
             if (!isFirstNode) {
                 printf(" ");
             }
             printf("%d", node->data);
             isFirstNode = 0;
             queue[rear++] = node->left;
             queue[rear++] = node->right;
         }
     }
     printf("\n");
 }

/*output:
Enter the elements of the binary tree in level order (space-separated, use 'null' for empty nodes):
12

Menu:
1. Pre-order Traversal
2. In-order Traversal
3. Post-order Traversal
4. Level-order Traversal
5. Search for a value
6. Find height of tree
7. Delete a node
8. Print Tree
9. Exit
Enter your choice: 1
Pre-order Traversal: 12 

Menu:
1. Pre-order Traversal
2. In-order Traversal
3. Post-order Traversal
4. Level-order Traversal
5. Search for a value
6. Find height of tree
7. Delete a node
8. Print Tree
9. Exit
Enter your choice: 2
In-order Traversal: 12 

Menu:
1. Pre-order Traversal
2. In-order Traversal
3. Post-order Traversal
4. Level-order Traversal
5. Search for a value
6. Find height of tree
7. Delete a node
8. Print Tree
9. Exit
Enter your choice: 3
Post-order Traversal: 12 

Menu:
1. Pre-order Traversal
2. In-order Traversal
3. Post-order Traversal
4. Level-order Traversal
5. Search for a value
6. Find height of tree
7. Delete a node
8. Print Tree
9. Exit
Enter your choice: 4
Level-order Traversal: 12


Menu:
1. Pre-order Traversal
2. In-order Traversal
3. Post-order Traversal
4. Level-order Traversal
5. Search for a value
6. Find height of tree
7. Delete a node
8. Print Tree
9. Exit
Enter your choice: 5
Enter value to search: 12
Found node with value: 12

Menu:
1. Pre-order Traversal
2. In-order Traversal
3. Post-order Traversal
4. Level-order Traversal
5. Search for a value
6. Find height of tree
7. Delete a node
8. Print Tree
9. Exit
Enter your choice: 6
Height of tree: 1

Menu:
1. Pre-order Traversal
2. In-order Traversal
3. Post-order Traversal
4. Level-order Traversal
5. Search for a value
6. Find height of tree
7. Delete a node
8. Print Tree
9. Exit
Enter your choice: 7
Enter value to delete: 12
Deleting node with value: 12

Menu:
1. Pre-order Traversal
2. In-order Traversal
3. Post-order Traversal
4. Level-order Traversal
5. Search for a value
6. Find height of tree
7. Delete a node
8. Print Tree
9. Exit
Enter your choice: 8
Tree Structure:
Tree is empty.

Menu:
1. Pre-order Traversal
2. In-order Traversal
3. Post-order Traversal
4. Level-order Traversal
5. Search for a value
6. Find height of tree
7. Delete a node
8. Print Tree
9. Exit
Enter your choice: 9
Exiting...


=== Code Execution Successful ===
*/
