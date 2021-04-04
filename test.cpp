#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<int> vec = {1, 2, 3};
vector<int> vec2 = vec;

int main()
{
    map<int, char> mapp;
    mapp[1] = 'a';
    mapp[4] = 'b';

    bool a = (mapp.count(3) == 0);

    int n;
    cin >> n;
}