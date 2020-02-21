#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
/*
vector<string> hat(string s);
//vector<string> generateParenthesis(int n);


vector<string> hat(string s)
{
	int i = 0, j = 1;
	int cnt = 1;
	vector<string> h;
	string tmp = s;
	
	while (j < tmp.size())
	{
		if (tmp[j] == '(') ++cnt;
		else if(tmp[j] == ')') --cnt;

		if (cnt == 0)
		{
			tmp.insert(i, 1, '(');
			++j;
			tmp.insert(j + 1, 1, ')');
			h.push_back(tmp);
			tmp = s;
			i = j; j = i + 1;
			++cnt;
		}
		else 
			++j;

	}
	return h;
}


///*

vector<string> generateParenthesis(int n) 
{
	
	vector<string> result = { "()" }, tmp = {};
	if (n == 0) return tmp;
	for (int i = 1; i < n; ++i)
	{
		tmp = result;
		result.clear();
		for (auto s : tmp)
		{
			result.push_back("(" + s + ")");
			result.push_back("()" + s);
			result.push_back(s + "()");
			vector<string> h = hat(s);
			result.insert(result.end(),h.begin(),h.end());
		}
	}
	sort(result.begin(), result.end());
	result.erase(unique(result.begin(), result.end()), result.end());
	return result;
}
*/


//上述方法存在结构性问题，且较为繁琐
void func(vector<string>& vec, string s, int l, int r, int n)
{
	if (l > n || r > n || r > l) return;
	if (l == n && r == n)
	{
		vec.push_back(s);
		return;
	}
	func(vec, s + '(', l + 1, r, n);
	func(vec, s + ')', l, r + 1, n);
	return;
}
vector<string> generateParenthesis(int n)
{
	vector<string> vec;
	func(vec, "", 0, 0, n);
	return vec;
}

int main()
{
	int n = 3;
	vector<string> result = generateParenthesis(n);
	for (auto s : result)
		cout << s << endl;
	return 0;
}
//*/
/*

int main()
{
	//验证帽子函数的正确性
	string s = "()()";
	vector<string> h = hat(s);
	for (auto str : h)
		cout << str << endl;
}*/