#pragma GCC optimize(2)
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
#include <cmath>
#include <queue>
#include <time.h>
#define eps 1e-7
#define M 22
#define N 200005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, m, k;
string s;
int cnt[26];
bool check(string s, string& od, string& ss) {
	string t="";
	for (int i = 0; i < od.size(); ++i) {
		string s2 = s;
		t += s;
		s.clear();
		for (int j = 0; j < s2.size(); ++j) {
			if (s2[j] != od[i]) {
				s.push_back(s2[j]);
			}
		}
	}
	return t == ss;
}
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		cin>>s;
		memset(cnt, 0, sizeof(cnt));
		n = (int)s.size();
		set<int> ss;
		ss.clear();
		string od = "";
		for (int i = n-1; i >= 0; --i) {
			if (ss.find(s[i]-'a') == ss.end()) {
				od.push_back(s[i]);
				ss.insert(s[i]-'a');
			}
			cnt[s[i]-'a']++;
		}
		int tot=0;
		int sum=0;
		for (int i = 0; i < od.size()-1; ++i) {
			int num = (int)od.size()-i;
			int det = cnt[od[i]-'a'] / num;
			tot += det;
			sum += tot;
		}
		string s0 = s.substr(0, n-sum);
	//	cout<<sum<<" "<<s0<<endl;
		reverse(od.begin(), od.end());
		if (check(s0, od, s)) {
			cout<<s0<<" "<<od<<endl;
		} else {
			puts("-1");
		}
	}
  return 0;
}
