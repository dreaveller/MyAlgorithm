#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> vec;

int main()
{
    int t, n, tmp, count;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        for (int j = 0; j < 2 * n; j++)
        {
            cin >> tmp;
            vec.push_back(tmp);
        }
        sort(vec.begin(), vec.end());

        tmp = vec[2 * n - 1];
        count = 0;
        for (int j = 2 * n - 2; j > -1; j--)
        {
            if (vec[j] == 0)
            {
                continue;
            }
            for (int k = 0; k < j; k++)
            {
                if (vec[k] == 0)
                {
                    continue;
                }
                if (vec[j] + vec[k] == tmp)
                {
                    tmp = vec[j];
                    cout << vec[j] << " " << vec[k] << endl;
                    vec[j] = vec[k] = 0;
                    break;
                }
                if (k == j - 1)
                {
                    for (int m = k; m > -1; m--)
                    {
                        if(vec[m] != 0)
                        {
                            tmp = vec[m];
                        }
                    }
                    count++;
                }
            }
            if (count > 1)
            {
                cout << "NO" <<endl;
                break;
            }
        }
        vec.clear();
    }
    return 0;
}