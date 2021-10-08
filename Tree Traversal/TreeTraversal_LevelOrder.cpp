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

struct queueNode
{
    treeNode *node;
    queueNode *next;
};

queueNode* CreateQueueNode(treeNode *node, queueNode *next)
{
    queueNode *newNode = new queueNode;
    newNode->node = node;
    newNode->next = next;
    return newNode;
}

bool isEmpty(queueNode *headRef)
{
    if(headRef == NULL)
        return true;
    return false;
}

void Enqueue(queueNode **headRef, treeNode *node)
{
    queueNode *newNode = CreateQueueNode(node, NULL);
    queueNode *current = *headRef;
    if(current == NULL)
    {
        *headRef = newNode;
    }
    else
    {
        while(current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNode;
    }
}

queueNode* Dequeue(queueNode **headRef)
{
    if(!isEmpty(*headRef))
    {
        queueNode *node = *headRef;
        *headRef = (*headRef)->next;
        return node;
    }
    return NULL;
}

void LevelOrder(treeNode *root)
{
    queueNode *Queue = NULL;
    Enqueue(&Queue, root);

    while(!isEmpty(Queue))
    {
        queueNode *temp = Dequeue(&Queue);
        treeNode *p = temp->node;
        delete temp;

        if(p != NULL)
        {
            cout << p->data << " ";
            Enqueue(&Queue, p->left);
            Enqueue(&Queue, p->right);
        }
    }
}

int main()
{
    treeNode *root = CreateTree();

    cout << "Level Order:" << "\n";
    LevelOrder(root);

    return 0;
}
