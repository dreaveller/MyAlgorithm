#include <iostream>
using namespace std;

int a[101];

int main()
{
    int t, n;
    cin >> t;
    int tmp;
    for (int i = 0; i < t; i++)
    {
        for (int j = 0; j < 101; j++)
        {
            a[j] = 0;
        }

        cin >> n;

        for (int j = 0; j < n; j++)
        {
            cin >> tmp;
            a[tmp] ++;
        }

        int max = 0;
        for (int j = 0; j < 101; j++)
        {
            if (max < a[j])
            {
                max = a[j];
            }
        }
        cout << max << endl;
    }
    
    return 0;
}