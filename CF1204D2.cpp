// 形如10, 1(1010)0这样的string只有一种拼法。
// 所以我们把这样的去掉之后就会剩下000...111。
// 这时候要找出所有没有后缀0的1，这些1没有必要是1。因此可以改成0。
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
int n;
string s;
int main() {
	cin>>s;
	n = s.size();
	int cnt = 0;
	string t = s;
	for (int i = n-1; i >= 0; --i) {
		if (s[i] == '0') cnt--;
		else cnt++;
		if (cnt > 0) {
			t[i] = '0';
			cnt--;
		}
	}
	cout<<t<<endl;
	return 0;
}
