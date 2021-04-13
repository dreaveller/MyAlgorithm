#include <iostream>
#include <vector>
using namespace std;

vector<int> getReverse(vector<int>& nums, int k)
{
    vector<int> vec(nums);
    for (int i = 0; i < nums.size(); i++)
    {
        vec[(i + k) % nums.size()] = nums[i];
    }
    return vec;
    
}

int main()
{
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(4);
    nums.push_back(5);
    nums.push_back(6);
    getReverse(nums, 3);
}