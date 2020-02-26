// divide.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

using namespace std;
/*
int divide(int dividend, int divisor) {
    int cnt = 0;


    if (dividend > 0 && divisor > 0)
    {
        if (dividend == 2147483647 && divisor == 1) return 2147483647;
        while (dividend >= 0)
        {
            dividend -= divisor;
            cnt++;
        }
        return cnt - 1;
    }

    else if (dividend > 0 && divisor < 0)
    {
        while (dividend >= 0)
        {
            dividend += divisor;
            cnt--;
        }
        return cnt + 1;
    }

    else if (dividend < 0 && divisor > 0)
    {
        if (dividend == -2147483648 && divisor == 1) return -2147483648;
        while (dividend <= 0)
        {
            dividend += divisor;
            cnt--;
        }
        return cnt + 1;
    }

    else if (dividend < 0 && divisor < 0)
    {
        if (dividend == -2147483648 && divisor == -1) return 2147483647;
        while (dividend <= 0)
        {
            dividend -= divisor;
            cnt++;
        }
        return cnt - 1;
    }
    else return 0;

}
*/

int divide(int dividend, int divisor) {
    int ans = 0, first, second;
    if (dividend == INT_MIN && divisor == -1) return INT_MAX;
    first = dividend >= 0 ? -dividend : dividend;
    second = divisor > 0 ? -divisor : divisor;
    while (first <= second)
    {
        int cnt = -1, base = second;
        while (first <= (base << 1))
        {
            if (base < INT_MIN >> 1) break;
            cnt <<= 1;
            base <<= 1;
        }
        ans += cnt;
        first -= base;
    }
    ans = ((dividend < 0) ^ (divisor < 0)) == 1 ? ans : -ans;

    return ans;
}


int main()
{
    int divident = -10, divisor = 3;//2147483647
    cout << divide(divident, divisor) << endl;
    return 0;
}

