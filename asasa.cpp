#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> vec0;
vector<int> vec1;
vector<vector<int>> vec;
vector<int> tmpvec;

vector<int> cmp(vector<int> a, vector<int> b) {
    if (a[0] > b[0])
    {
        return a;
    }
    else return b;
    
}

int main()
{
    int c;
    cin >> c;
    int n;
    int tmp;
    for (int i = 0; i < c; i++)
    {
        cin >> n;
        for (int j = 0; j < n; j++)
        {
            cin >> tmp;
            vec0.push_back(tmp);
        }
        for (int j = 0; j < n; j++)
        {
            cin >> tmp;
            vec1.push_back(tmp);
        }

        for (int j = 0; j < n; j++)
        {
            tmpvec.push_back(vec0[j]);
            tmpvec.push_back(vec1[j]);
            vec.push_back(tmpvec);
            tmpvec.clear();
        }
        
        sort(vec.begin(), vec.end(), cmp);

        int sum = 0;
        int max = 0;
        int index;
        int shenyu = 0;
        for (int j = 0; j < n; j++)
        {
            /* code */
        }
        

        for (int j = n; j > 0; j--)
        {
            max = 0;
            index = -1;
            for (int k = 0; k < n; k++)
            {
                if (vec0[k] >= j)
                {
                    if (max < vec1[k])
                    {
                        max = vec1[k];
                        index = k;
                    }
                    
                }
            }
            if (index != -1)
            {
                vec1[index] = 0;
            }
            sum += max;
            
        }
        for (int k = 0; k < n; k++)
        {
            sum -= vec1[k];
        }
        
        cout << sum << endl;

        vec0.clear();
        vec1.clear();
        
    }
}