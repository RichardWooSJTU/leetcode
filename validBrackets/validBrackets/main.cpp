#include <iostream>
#include <vector>
#include <string>

using namespace std;
/*
bool isValid(string s) {
    bool rst = true;
    if (empty(s)) return rst;
    if (s.size() == 1) return false;
    if (s[0] == ')' || s[0] == ']' || s[0] == '}') return false;
    int first = 0, second = 1;
    bool hasFound = false;
    int repeat = 0;
    while (second < s.size())
    {
        if (s[second] == s[first]) ++repeat;
        if (s[second] - s[first] <= 2 && s[second] - s[first] > 0)
        {
            if (repeat != 0)
            {
                --repeat;
                ++second;
                continue;
            }
            string subS = s.substr(first + 1, second - first - 1);
            bool subRst = isValid(subS);
            rst = subRst && rst;
            if (second == s.size() - 1)
            {
                hasFound = true;
                break;
            }
            else
            {
                first = second + 1;
                second = first + 1;
            }
        }

        else
            ++second;
    }
    return rst && hasFound;
}
*/
//上面的代码使用了递归的结构，耗时耗力，通过测试花费了88ms，排名后百分之10。
//关键还在于算法不够精妙   
//但是有一个强无敌的算法如下
bool isValid(string s)
{
    int i = 0;
    int diff, size = s.size();
    //while (i < s.size()-1)//这里一直报错，明明s.size()已经计算得0了， 这里还是判断为真进入了循环 问题在于string得size（）返回类型是无符号的，0-1之后是最大值，故不行
    while (i < size -1)
    {
        diff = s[i+1] - s[i];
        if (diff <= 2 && diff > 0)
        {
            s.erase(i, 2);
            size -= 2;
            if (i != 0) --i;
        }
        else ++i;
    }
    return s.empty();
}

//上面的代码通过测试耗费8ms，提升相当明显，但是排名仍然基本是后面的百分之15，但内存消耗得到有效遏制。
int main(int argc, char** argv)
{
    string s = "()";//"(([]){})";
    cout << isValid(s) << endl;
    return 0;
}

