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
//����Ĵ���ʹ���˵ݹ�Ľṹ����ʱ������ͨ�����Ի�����88ms��������ٷ�֮10��
//�ؼ��������㷨��������   
//������һ��ǿ�޵е��㷨����
bool isValid(string s)
{
    int i = 0;
    int diff, size = s.size();
    //while (i < s.size()-1)//����һֱ��������s.size()�Ѿ������0�ˣ� ���ﻹ���ж�Ϊ�������ѭ�� ��������string��size���������������޷��ŵģ�0-1֮�������ֵ���ʲ���
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

//����Ĵ���ͨ�����Ժķ�8ms�������൱���ԣ�����������Ȼ�����Ǻ���İٷ�֮15�����ڴ����ĵõ���Ч���ơ�
int main(int argc, char** argv)
{
    string s = "()";//"(([]){})";
    cout << isValid(s) << endl;
    return 0;
}

