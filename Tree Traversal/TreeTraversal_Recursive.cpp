#include<bits/stdc++.h>
using namespace std;

struct treeNode
{
    char data;
    treeNode *left;
    treeNode *right;
};

treeNode* CreateTreeNode(char item)
{
    treeNode *newNode = new treeNode;

    newNode->data = item;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

void AddLeftChild(treeNode *parentNode, treeNode *childNode)
{
    parentNode->left = childNode;
}

void AddRightChild(treeNode *parentNode, treeNode *childNode)
{
    parentNode->right = childNode;
}

treeNode* CreateTree()
{
    /*
              M
            /   \
           /     \
          G       T
         / \     / \
        D   K   R   W
       / \   \   \
      A   H   L   V
                 /
                U
    */
    treeNode *m = CreateTreeNode('M');
    treeNode *g = CreateTreeNode('G');
    treeNode *t = CreateTreeNode('T');
    AddLeftChild(m, g);
    AddRightChild(m, t);

    treeNode *d = CreateTreeNode('D');
    treeNode *k = CreateTreeNode('K');
    AddLeftChild(g, d);
    AddRightChild(g, k);

    treeNode *a = CreateTreeNode('A');
    treeNode *h = CreateTreeNode('H');
    AddLeftChild(d, a);
    AddRightChild(d, h);

    treeNode *l = CreateTreeNode('L');
    AddRightChild(k, l);

    treeNode *r = CreateTreeNode('R');
    treeNode *w = CreateTreeNode('W');
    AddLeftChild(t, r);
    AddRightChild(t, w);

    treeNode *v = CreateTreeNode('V');
    AddRightChild(r, v);

    treeNode *u = CreateTreeNode('U');
    AddLeftChild(v, u);

    return m;
}

void Preorder(treeNode *node)
{
    cout << node->data << " ";
    if(node->left != NULL)
        Preorder(node->left);
    if(node->right != NULL)
        Preorder(node->right);
}

void Inorder(treeNode *node)
{
    if(node->left != NULL)
        Inorder(node->left);
    cout << node->data << " ";
    if(node->right != NULL)
        Inorder(node->right);
}

void Postorder(treeNode *node)
{
    if(node->left != NULL)
        Postorder(node->left);
    if(node->right != NULL)
        Postorder(node->right);
    cout << node->data << " ";
}

int main()
{
    treeNode *root = CreateTree();

    cout << "Preorder:" << "\n";
    Preorder(root);
    cout << "\nInorder:" << "\n";
    Inorder(root);
    cout << "\nPostorder:" << "\n";
    Postorder(root);

    return 0;
}
