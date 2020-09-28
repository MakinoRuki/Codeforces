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
#define N 200005
using namespace std;
typedef long long ll;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n, k;
int main() {
	cin>>n;
	set<string> ss;
	ss.clear();
	for (int i = 1; i <= n; ++i) {
		string s;
		cin>>s;
		sort(s.begin(), s.end());
		string t="";
		for (int i = 0; i < s.size(); ++i) {
			if (i==0 || s[i]!=s[i-1]) {
				t.push_back(s[i]);
			}
		}
		ss.insert(t);
	}
	int res=(int)ss.size();
	cout<<res<<endl;
	return 0;
}
