#include <iostream>
#include <algorithm>
using namespace std;

int price[100000];

int main()
{
    int size = 0;
    char tmp;
    for (int i = 0; i < 100000; i++)
    {
        scanf("%c", &tmp);
        if (tmp == '\n') break;
        if (tmp == 'b') price[i] = 1;
        else price[i] = -1;
        size++;
    }
    int num = 0;
    int asize = 0;
    bool flag = false;
    for (int i = 0; i < size; i++)
    {
        if (!flag && price[i] == 1) continue;
        if (!flag && price[i] == -1)
        {
            flag = true;
            continue;
        }
        if (flag && price[i] > 0)
        {
            num += (int)(pow(2, asize) - 1);
            num = num % 1000000007;
        }
        if (flag && price[i] < 0)
        {
            asize++;
        }
    }
    cout << num;
    cout << 11;
}