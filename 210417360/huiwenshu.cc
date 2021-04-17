#include <iostream>
using namespace std;

char str[202];
int price[4] = {100, 200, 200, 220};

int main()
{
    int size = 0;
    for (int i = 0; i < 100; i++)
    {
        
        scanf("%c",str + i);
        if (str[i] == '\n') break;
        size++;
    }

    char* begin = str;
    char* end = str + size - 1;

    int count = 0;
    while (begin < end)
    {
        if (*begin < *end)
        {
            if (*begin != '3')
            {
                count += ((int)*begin - 48) * 100;
                begin++;
            }
            else
            {
                count += ((int)*begin - 48) * 100;
                begin++;
            }
        }
        else if (*begin < *end)
        {
            count += ((int)*end - 48) * 100;
            end--;
        }
        else 
        {
            begin++; end--;
        }
        
    }
    cout << count;
    cout << 11;
}