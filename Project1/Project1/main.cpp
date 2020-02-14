#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> results;
    if (nums.size() < 4) return results;
    sort(nums.begin(), nums.end());

    for (auto m = nums.begin(); m != nums.end() - 3; ++m)
    {
        if (m != nums.begin() && *m == *(m - 1)) continue;

        int sum = 0;
        for (auto n = m + 1; n != nums.end() - 2; ++n)
        {
            if (n != m + 1 && *n == *(n - 1)) continue;
            auto p = n + 1, q = nums.end() - 1;
            while (p < q)
            {
                //while (p!=n+1 && *p == *(p-1)) ++p;
                //while (q!=nums.end()-1 && *q == *(q+1)) --q;
                sum = *m + *n + *p + *q;
                if (sum == target)
                {
                    vector<int> result = { *m, *n, *p, *q };
                    results.push_back(result);
                    ++p; --q;
                    while (p < q && *p == *(p - 1) && *q == *(q + 1)) { ++p, --q; }
                }
                else if (sum < target)
                    ++p;
                else
                    --q;


            }
        }
    }
    return results;
}


int main(int argc, char* argv[])
{
    vector<int> nums = { 1,0,-1,0,-2,2};
    int target = 0;
    vector<vector<int>> results = fourSum(nums, target);
    for (int i = 0; i != results.size(); ++i)
    {
        for (int j = 0; j != results[i].size(); ++j)
            cout << results[i][j] << " ";
        cout << endl;
    }

    return 0;
}