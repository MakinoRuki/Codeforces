#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <queue>
#define N 202
using namespace std;
typedef long long ll;
int n;
string s;
string getres(string a, string b) {
	int l1 = a.size();
	int l2 = b.size();
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	int add=0;
	int i = 0;
	string res="";
	int sum=0;
	while(i < l1 && i < l2) {
		sum = a[i]-'0'+b[i]-'0'+add;
		add = sum/10;
		sum %= 10;
		res.push_back('0'+sum);
		i++;
	}
	while(i < l1) {
		sum = a[i]-'0'+add;
		add = sum/10;
		sum %= 10;
		res.push_back('0'+sum);
		i++;
	}
	while(i < l2) {
		sum = b[i]-'0'+add;
		add = sum/10;
		sum %= 10;
		res.push_back('0'+sum);
		i++;
	}
	if (add) {
		res.push_back('0'+add);
	}
	reverse(res.begin(), res.end());
	return res;
}
int main() {
	cin>>n>>s;
	int maxl = n;
	for (int i = 1; i < n; ++i) {
		if (s[i] != '0' && max(i, n-i) < maxl) {
			maxl = max(i, n-i);
		}
	}
	string ans="";
	for (int i = 1; i < n; ++i) {
		if (s[i] != '0' && max(i, n-i) == maxl) {
			auto res = getres(s.substr(0, i), s.substr(i));
			if (ans.empty()) {
				ans = res;
			} else {
				if (res.size() < ans.size()) ans = res;
				else if (res.size() == ans.size() && res<ans) ans = res;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
