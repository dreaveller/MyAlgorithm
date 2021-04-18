#include <iostream>
using namespace std;

int nums1[101];
int nums2[101];
int dp[101][101];

int main()
{
    int size1 = 0;
    int size2 = 0;
    for (int i = 0; i < 100; i++)
    {
        char tmp;
        scanf("%c", &tmp);
        if (tmp == '\n') break;
        nums1[i] = (tmp - 48) % 2;
        size1++;
    }

    for (int i = 0; i < 100; i++)
    {
        char tmp;
        scanf("%c", &tmp);
        if (tmp == '\n') break;
        nums2[i] = (tmp - 48) % 2;
        size2++;
    }
    
    for (int i = 1; i < size1; i++)
    {
        for (int j = 1; j < size2; j++)
        {
            dp[i][j]
        }
    }
    
}