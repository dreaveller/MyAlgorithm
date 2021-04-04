#include <iostream>
#include <vector>
using namespace std;

vector<int> vec;

int main()
{
    int t, n, num, tmp;
    cin >> t;
    bool flag;
    for (int i = 0; i < t; i++)
    {
        cin >> n >> num;
        for (int j = 0; j < n; j++)
        {
            cin >> tmp;
            flag = 1;
            if (tmp > num * 10)
            {
                cout << "YES" << endl;
            }else
            {
                while (tmp > 0)
                {
                    if(tmp % num != 0) tmp = tmp - 10;
                    else
                    {
                        cout << "YES" << endl;
                        flag = 0;
                        break;
                    }
                    
                }
                
                if (flag)
                {
                    cout << "NO" << endl;
                }
            }
        }
    }
}