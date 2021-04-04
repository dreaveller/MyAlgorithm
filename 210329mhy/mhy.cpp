/*
 * 米哈游笔试 根据字符串构建树 中序遍历
 * 例如 A(B(,C),D(E,))，表示的树结构为 A 有左孩子 B 和右孩子 D，B 有右孩子 C，D 有左孩子 E
 * 输入描述：
 * 字符串保证无 bug
 * 输出描述：
 * 中序遍历的顺序
 */

/*
 * 我太菜了，平时基本没写过题，笔试完后自己写发现就是一个递归而已，只不过中间的条件判断是有点难度
 * 所以写算法题思路一定要清晰，提前构建好程序执行框架
 */
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