/*
 * 单源最短路径
 * AC60%，不知道错在哪里
 */

#include <iostream>
using namespace std;

int mapp[6][6] = {-1};
int distance2[6];
bool flag[6] = {false};

int main()
{
    for (int i = 0; i < 6; i++)
    {
        distance2[i] = 1000000;
    }

    distance2[0] = 0;
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            cin >> mapp[i][j];
        }
    }
    for (int i = 0; i < 6; i++)
    {
        if (mapp[0][i] != -1 && mapp[0][i] < distance2[i])
        {
            distance2[i] = mapp[0][i];
        }
    }

    for (int j = 0; j < 5; j++)
    {
        int min = 5000000;
        int index = 0;
        for (int i = 1; i < 6; i++)
        {
            if (min > distance2[i] && !flag[i])
            {
                min = distance2[i];
                index = i;
            }
        }
        flag[index] = true;

        for (int i = 1; i < 6; i++)
        {
            if (mapp[index][i] != -1)
            {
                if (distance2[i] > distance2[index] + mapp[index][i])
                {
                    distance2[i] = distance2[index] + mapp[index][i];
                }
            }
        }
    }

    for (int i = 1; i < 6; i++)
    {
        if (distance2[i] != 1000000)
        {
            cout << distance2[i] << endl;
        }
        else
        {
            cout << "-1" << endl;
        }
    }
    return 0;
}