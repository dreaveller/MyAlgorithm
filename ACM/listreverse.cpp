/*
 * 双向链表 反转链表
 * 
 */
#include <iostream>
#include <vector>
#include <deque>
#include <stack>
using namespace std;

struct node
{
    node* next = NULL;
    node* head = this;
    node* tail = this;
    char ch = NULL;
    int num = NULL;
    node() {};
    node(char ch) : ch(ch) {};
    node(int num) : num(num) {};
} ;

node* nodes[100001];

struct treenode
{
    treenode* left = NULL;
    treenode* right = NULL;
    int value = NULL;
    int flag;
    treenode() {};
    treenode(int a) : value(a) {}
};
treenode* treenodes[100001];


stack<treenode*> sta;

void dfs(treenode* n,int flag)
{
    if (flag)
    {
        if (n->right != NULL)
        {
            dfs(n->right, flag - 1);
        }
        if (n->left != NULL)
        {
            dfs(n->left, flag - 1);
        }
        if (n->value != NULL)
        { 
            cout << n->value << " " ;
        }
        
    }
    else
    {
        if (n->left != NULL)
        {
            dfs(n->left, flag - 1);
        }
        if (n->right != NULL)
        {
            dfs(n->right, flag - 1);
        }
        if (n->value != NULL)
        {
            cout << n->value << " ";
        }
    }
}

void cle(treenode* tn)
{
    if (tn->left != NULL)
    {
        tn = tn->left;
    }
    if (tn->left != NULL)
    {
        tn = tn->right;
    }
    delete(tn);
}
    

int main()
{
    while (1)
    {
        int n, m;
        cin >> n >> m;
        int tmpa, tmpb;
        for (int i = 1; i < n + 1; i++)
        {
            nodes[i] = new node(i);
        }

        for (int i = 0; i < m; i++)
        {
            cin >> tmpa >> tmpb;
            if (nodes[tmpa]->ch == NULL && nodes[tmpa]->num == NULL)
            {
                node* n = new node('(');
                n->next = nodes[tmpb];
                nodes[tmpb]->tail->next = new node(')');
                n->tail = nodes[tmpb]->tail->next;
                nodes[tmpa] = n;
                nodes[tmpb] = new node();
                continue;
            }
            if (nodes[tmpb]->ch == NULL && nodes[tmpb]->num == NULL)
            {
                node* n = new node('(');
                n->next = nodes[tmpa];
                nodes[tmpa]->tail->next = new node(')');
                n->tail = nodes[tmpa]->tail->next;
                nodes[tmpa] = n;
                continue;
            }
            node* n = new node('(');
            n->next = nodes[tmpa];
            nodes[tmpa]->tail->next = nodes[tmpb]->head;
            nodes[tmpb]->tail->next = new node(')');
            n->tail = nodes[tmpb]->tail->next;
            nodes[tmpa] = n;
            nodes[tmpb] = new node();
        }

        node* nn = nodes[1]->next;
        treenode* tree = new treenode();
        treenode* root = tree;
        sta.push(tree);
        int num = 0;
        while (nn != NULL)
        {
            if (nn->ch == '(')
            {
                if (tree->left == NULL)
                {
                    tree->left = new treenode();
                    tree = tree->left;
                    sta.push(tree);
                }
                else
                {
                    tree->right = new treenode();
                    tree = tree->right; 
                    sta.push(tree);
                }
            }
            else if (nn->ch == ')')
            {
                sta.pop();
                if (sta.empty())
                {
                    break;
                }
                tree = sta.top();
            }
            else if (nn->num != NULL)
            {
                if (tree->left == NULL)
                {
                    tree->left = new treenode();
                    tree->left->value = nn->num;
                }
                else
                {
                    tree->right = new treenode();
                    tree->right->value = nn->num;
                }
                num++;
            }
            nn = nn->next;
            
        }
        cout << num << " ";
        dfs(root, 1);

        for (int i = 1; i < n + 1; i++)
        {
            node* nnn = nodes[i];
            node* tmp = nnn;
            while (nnn != NULL)
            {
               
                nnn = nnn->next;
                delete(tmp);
                tmp = nnn;
            }
        }

        cle(root);
        

        
    }
    cout << "";
}