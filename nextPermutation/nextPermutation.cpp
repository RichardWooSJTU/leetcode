// nextPermutation.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <algorithm>

//此题的坑
/*
1. 得使用difference_type作为返回语句，迭代器是函数的局部变量，无法返回。
2. 最好使用值交换，erase再insert会把迭代器搞乱

*/

using namespace std;

vector<int>::difference_type biggerThanCurrent(vector<int>::iterator beg, vector<int>::iterator end, int current);

void nextPermutation(vector<int>& nums)
{
    auto beg = nums.begin();
    while (beg != nums.end())
        ++beg;
    while (--beg != nums.begin())
    {
        if (*(beg - 1) < *beg)
        {
            auto lastOne = beg - 1;
            auto res = biggerThanCurrent(beg, nums.end(), *lastOne);
            vector<int>::iterator min = beg + res;
            int tmp = *min;
            *min = *lastOne;
            *lastOne = tmp;
           
            sort(beg, nums.end());
            return;
        }
    }
    sort(beg, nums.end());
}

vector<int>::difference_type biggerThanCurrent(vector<int>::iterator beg, vector<int>::iterator end, int current)
{
    vector<int>::difference_type res = 0;
    int min = *beg;
    auto first = beg;
    while (beg != end)
    {
        if (*beg < min && *beg > current)
        {
            min = *beg;
            res = beg - first;
        }
        ++beg;
    }
    
    return res;
}

int main()
{
    vector<int> nums = { 1,2,3 };
    nextPermutation(nums);
    for (auto c : nums)
        cout << c << endl;
}

