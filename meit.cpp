#include <iostream>
#include <math.h>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct node
{
    int value;
    node* left = NULL;
    node* right = NULL;
};

void bc(node* n, int value)
{
    n = new node;
    n -> value = value;
}

int main()
{ 
    node* root = new node;
    root -> value = 1;
    bc(root -> left, 3);

    cout << "";

    return 0;
}