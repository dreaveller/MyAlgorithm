#include <iostream>
#include <cmath>
using namespace std;

int primer(int n)
{
    if (n == 1)
        return 0;
    if (n == 2 || n == 3)
        return 1;

    if (n % 6 == 5 || n % 6 == 1)
    {
        for (int i = 5; i <= sqrt(n); i += 6)
        {
            if (n % i == 0 || n % (i + 2) == 0)
                return 0;
        }
        return 1;
    }
    else
        return 0;
}

int main()
{
    int t, a;
    cin >> t;
    int tmp, tmp2;
    int flag;
    for (int i = 0; i < t; i++)
    {
        cin >> a;
        tmp = a + 1;
        //cout << '1' << a + 1 << 2 * a + 1 << (a + 1) * (2 * a + 1) << endl;
        //cout << 1 + 3 * a + 2 + (a + 1) * (2 * a + 1) << endl;
        flag = 0;
        while (true)
        {
            if (primer(tmp))
            {
                break;
            }
            tmp++;
        }
        tmp2 = tmp + a;
        flag = 0;
        while (true)
        {
            if (primer(tmp2))
            {
                break;
            }
            tmp2++;
        }
        cout << tmp * tmp2 << endl;
    }
    return 0;
}