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

struct stackNode
{
    treeNode *node;
    int i;
    stackNode *next;
};

stackNode* CreateStackNode(treeNode *node, int i, stackNode *next)
{
    stackNode *newNode = new stackNode;
    newNode->node = node;
    newNode->i = i;
    newNode->next = next;
    return newNode;
}

bool isEmpty(stackNode *headRef)
{
    if(headRef == NULL)
        return true;
    return false;
}

void Push(stackNode **headRef, treeNode *node, int i)
{
    stackNode *newNode = CreateStackNode(node, i, *headRef);
    *headRef = newNode;
}

stackNode* Pop(stackNode **headRef)
{
    if(!isEmpty(*headRef))
    {
        stackNode *node = *headRef;
        *headRef = (*headRef)->next;
        return node;
    }
    return NULL;
}

void Preorder(treeNode *root)
{
    stackNode *Stack = NULL;
    Push(&Stack, root, 1);

    while(!isEmpty(Stack))
    {
        stackNode *temp = Pop(&Stack);
        treeNode *p = temp->node;
        int i = temp->i;
        delete temp;

        if(p != NULL)
        {
            switch(i)
            {
            case 1:
                Push(&Stack, p, 2);
                cout << p->data << " ";
                break;
            case 2:
                Push(&Stack, p, 3);
                Push(&Stack, p->left, 1);
                break;
            case 3:
                Push(&Stack, p->right, 1);
                break;
            }
        }
    }
}

void Inorder(treeNode *root)
{
    stackNode *Stack = NULL;
    Push(&Stack, root, 1);

    while(!isEmpty(Stack))
    {
        stackNode *temp = Pop(&Stack);
        treeNode *p = temp->node;
        int i = temp->i;
        delete temp;

        if(p != NULL)
        {
            switch(i)
            {
            case 1:
                Push(&Stack, p, 2);
                Push(&Stack, p->left, 1);
                break;
            case 2:
                Push(&Stack, p, 3);
                cout << p->data << " ";
                break;
            case 3:
                Push(&Stack, p->right, 1);
                break;
            }
        }
    }
}

void Postorder(treeNode *root)
{
    stackNode *Stack = NULL;
    Push(&Stack, root, 1);

    while(!isEmpty(Stack))
    {
        stackNode *temp = Pop(&Stack);
        treeNode *p = temp->node;
        int i = temp->i;
        delete temp;

        if(p != NULL)
        {
            switch(i)
            {
            case 1:
                Push(&Stack, p, 2);
                Push(&Stack, p->left, 1);
                break;
            case 2:
                Push(&Stack, p, 3);
                Push(&Stack, p->right, 1);
                break;
            case 3:
                cout << p->data << " ";
                break;
            }
        }
    }
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
