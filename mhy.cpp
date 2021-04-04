#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;

string str;
int _index = 0;

struct node
{
    node* l = NULL;
    node* r = NULL;
    int value;
};

void addnode(node* p, int _index, int offset, int lr)
{
    node* tmp = new node;
    stringstream ss;
    int nu;
    ss << str.substr(_index, offset);
    ss >> nu;
    tmp -> value = nu;
    if (lr == 0)
    {
        p -> l = tmp;
        return;
    }
    else
    {
        p -> r = tmp;
        return;
    }
}

void bl(node* n)
{
    if (n == NULL) return;
    
    bl(n -> l);
    cout << n->value << " ";
    bl(n -> r);
}

void bc(node* n)
{
    int len = -1;
    bool flag = true;
    while (1)
    {
        len++;
        _index++;
        _index = _index;
        if (str[_index] == '(')
        {
            if (flag)
            {
                addnode(n, _index - len, len, 0);
                len = -1;
                bc(n -> l);
            }
            else {
                addnode(n, _index - len, len, 1);
                len = -1;
                bc(n -> r);
            }
            
        }
        else if (str[_index] == ')') {
            if (len == 0) return;
            addnode(n, _index - len, len, 1);
            len = -1;
            return;
        }else if (str[_index] == ',') {
            flag = false;
            if (len == 0) {len--; continue;}
            addnode(n, _index - len, len, 0);
            len = -1;
        }
    }
}

int main()
{  
    cin >> str;
    node* root = new node;
    root -> value = 14;
    while (true)
    {
        _index++;
        if (str[_index] == '(')
        {
            bc(root);
            break;
        }
    }
    bl(root);
    cin >> str;
    return 0;
}