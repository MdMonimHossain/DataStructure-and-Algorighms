#include<bits/stdc++.h>
using namespace std;

struct treeNode
{
    int data;
    treeNode *left;
    treeNode *right;
    treeNode *parent;
};

treeNode* CreateTreeNode(int item)
{
    treeNode *newNode = new treeNode;

    newNode->data = item;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->parent = NULL;

    return newNode;
}

void AddLeftChild(treeNode *parentNode, treeNode *childNode)
{
    parentNode->left = childNode;
    if(childNode != NULL)
        childNode->parent = parentNode;
}

void AddRightChild(treeNode *parentNode, treeNode *childNode)
{
    parentNode->right = childNode;
    if(childNode != NULL)
        childNode->parent = parentNode;
}

treeNode* Insert(treeNode *root, int data)
{
    treeNode *newNode = CreateTreeNode(data);

    if(root == NULL)
        return newNode;

    treeNode *parentNode = NULL;
    treeNode *currentNode = root;

    while(currentNode != NULL)
    {
        parentNode = currentNode;
        if(newNode->data < currentNode->data)
            currentNode = currentNode->left;
        else
            currentNode = currentNode->right;
    }

    if(newNode->data < parentNode->data)
        AddLeftChild(parentNode, newNode);
    else
        AddRightChild(parentNode, newNode);

    return root;
}

treeNode* Search(treeNode *root, int data)
{
    if(root == NULL)
        return NULL;

    treeNode *currentNode = root;

    while(currentNode != NULL)
    {
        if(data == currentNode->data)
            return currentNode;
        else if(data < currentNode->data)
            currentNode = currentNode->left;
        else
            currentNode = currentNode->right;
    }

    return NULL;
}

treeNode* Transplant(treeNode *root, treeNode *currentNode, treeNode *newNode)
{
    if(currentNode == root)
        return newNode;
    else if(currentNode == currentNode->parent->left)
        AddLeftChild(currentNode->parent, newNode);
    else
        AddRightChild(currentNode->parent, newNode);

    return root;
}

treeNode* MinimumNode(treeNode *root)
{
    if(root == NULL)
        return NULL;

    treeNode *minimumNode = root;

    while(minimumNode->left != NULL)
        minimumNode = minimumNode->left;

    return minimumNode;
}

treeNode* Delete(treeNode *root, int data)
{
    treeNode *node = Search(root, data);
    if(node == NULL)
        return root;

    if(node->left == NULL)
        root = Transplant(root, node, node->right);
    else if(node->right == NULL)
        root = Transplant(root, node, node->left);
    else
    {
        treeNode *successorNode = MinimumNode(node->right);

        if(successorNode->parent != node)
        {
            root = Transplant(root, successorNode, successorNode->right);
            AddRightChild(successorNode, node->right);
        }
        root = Transplant(root, node, successorNode);
        AddLeftChild(successorNode, node->left);
    }

    delete node;
    return root;
}

void Inorder(treeNode *node)
{
    if(node->left != NULL)
        Inorder(node->left);
    cout << node->data << " ";
    if(node->right != NULL)
        Inorder(node->right);
}

int main()
{
    treeNode *root = NULL;

    root = Insert(root, 8);
    root = Insert(root, 3);
    root = Insert(root, 10);
    root = Insert(root, 1);
    root = Insert(root, 6);
    root = Insert(root, 14);
    root = Insert(root, 4);
    root = Insert(root, 7);
    root = Insert(root, 13);

    int data = 15;
    if(Search(root, data) != NULL)
        cout << data << " found\n";
    else
        cout << data << " not found\n";

    cout << "\nInorder:" << "\n";
    Inorder(root);
    cout << "\n";

    root = Delete(root, 8);
    root = Delete(root, 6);

    cout << "\nInorder after deletion:" << "\n";
    Inorder(root);
    cout << "\n";

    return 0;
}
