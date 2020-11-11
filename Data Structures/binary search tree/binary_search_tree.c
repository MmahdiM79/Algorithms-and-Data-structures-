#include <stdio.h>
#include <stdlib.h>








        /*          Structs         */

typedef struct __NODE__
{
    int value;

    struct __NODE__ *p;
    struct __NODE__ *right;
    struct __NODE__ *left;

} NODE;

NODE *new_node(int value)
{
    NODE *output = (NODE *)malloc(sizeof(NODE));

    output->value = value;
    output->p = output->right = output->left = NULL;

    return output;
}




typedef struct __BINARY_SEARCH_TREE__
{
    NODE *root;
    int size;

} BST;

BST *new_bst()
{
    BST *output = (BST *)malloc(sizeof(BST));

    output->root = NULL;
    output->size = 0;

    return output;
}











            /*          functions           */


void tree_insert(BST *tree, NODE *node)
{
    NODE *current = tree->root;
    NODE *hold = NULL;

    while (current != NULL)
    {
        hold = current;

        if (node->value < current->value)
            current = current->left;
        else 
            current = current->right;
    }

    node->p = hold;

    if (hold == NULL)
        tree->root = node;
    
    else if (node->value < hold->value)
        hold->left = node;

    else 
        hold->right = node;



    tree->size++;
}




NODE *tree_search_recursive(BST *tree, int value)
{
    NODE *current = tree->root;
    NODE *output = NULL;


    if (current == NULL || current->value == value)
        return current;

    if (value < current->value)
    {
        tree->root = current->left;
        output = tree_search_recursive(tree, value);
        tree->root = current;

        return output;
    }
    else 
    {
        tree->root = current->right;
        output = tree_search_recursive(tree, value);
        tree->root = current;

        return output;
    }
}


NODE *tree_search(BST *tree, int value)
{
    NODE *current = tree->root;

    while (current != NULL)
    {
        if (current->value == value)
            return current;

        if (value < current->value)
            current = current->left;
        else
            current = current->right;
    }


    return NULL;
}


int tree_minimum(BST *tree)
{
    if (tree->root == NULL)
        return NULL;

    
    NODE *current = tree->root;
    
    while (current->left != NULL)
        current = current->left;

    
    return current->value;
}


int tree_maximum(BST *tree)
{
    if (tree->root == NULL)
        return NULL;

    
    NODE *current = tree->root;
    
    while (current->right != NULL)
        current = current->right;

    
    return current->value;
}


NODE *tree_successor(BST *tree)
{
    if (tree->root == NULL)
        return NULL;
    

    NODE *current = tree->root;

    if (current->right != NULL)
        return tree_minimum(tree);
    
    NODE *hold = current->p;
    while (hold != NULL && current == hold->right)
    {
        current = hold;
        hold = hold->p;
    }

    return hold;
}




void inorder_tree_walk(BST *tree)
{
    if (tree->root != NULL)
    {
        NODE *current = tree->root;


        tree->root = current->left;
        inorder_tree_walk(tree);

        printf("%d ", current->value);

        tree->root = current->right;
        inorder_tree_walk(tree);


        tree->root = current;
    }
}


void preorder_tree_walk(BST *tree)
{
    if (tree->root != NULL)
    {
        NODE *current = tree->root;


        printf("%d ", current->value);

        tree->root = current->left;
        inorder_tree_walk(tree);

        tree->root = current->right;
        inorder_tree_walk(tree);


        tree->root = current;
    }
}


void postorder_tree_walk(BST *tree)
{
    if (tree->root != NULL)
    {
        NODE *current = tree->root;


        tree->root = current->left;
        inorder_tree_walk(tree);

        tree->root = current->right;
        inorder_tree_walk(tree);

        printf("%d ", current->value);


        tree->root = current;
    }
}















int main()
{
    return 0;
}
