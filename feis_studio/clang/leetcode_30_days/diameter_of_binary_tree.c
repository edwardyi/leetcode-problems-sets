#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

int maxDepth(struct TreeNode* node) {
    if (node == NULL) return 0;

    int leftMax = maxDepth(node->left);
    int rightMax = maxDepth(node->right);

    // add one for the node itself
    if (leftMax > rightMax) {
        return leftMax + 1;
    }

    // add one for the node itself
    return rightMax + 1;
}

int diameterOfBinaryTree (struct TreeNode* root) {
    if (root == NULL) return 0;

    // calculate middle call maxDepth recursively 
    int middle = maxDepth(root->left) + maxDepth(root->right);

    int left = diameterOfBinaryTree(root->left);
    int right = diameterOfBinaryTree(root->right);

    printf("node value: %d \n", (*root).val);
    printf("left: %d \n", left);
    printf("right: %d \n", right);
    printf("middle: %d \n", middle);

    int max = middle;
    if (left > max) {
        max = left;
    }

    if (right > max) {
        max = right;
    }

    return max;
}

struct TreeNode getNode(int number) {

    struct TreeNode* tmpNode = (struct TreeNode*) malloc(sizeof(struct TreeNode));
    (*tmpNode).val = number;
    (*tmpNode).left = NULL;
    (*tmpNode).right = NULL;

    return *tmpNode;
}

int main() {

    struct TreeNode node1 = getNode(1);
    struct TreeNode node2 = getNode(2);
    struct TreeNode node3 = getNode(3);
    struct TreeNode node4 = getNode(4);
    struct TreeNode node5 = getNode(5);
    struct TreeNode node6 = getNode(6);

    node1.left = &node2;
    node1.right = &node3;
    node2.left = &node4;
    node2.right = &node5;
    node3.left = &node6;

    // printf("%d \n", node1.val);
    printf("%d \n", diameterOfBinaryTree(&node1));

    return 0;
}