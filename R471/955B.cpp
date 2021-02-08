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
#define eps 1e-7
#define M 21
#define N 2602
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, k;
string s;
int cnt[27];
int main() {
	cin>>s;
	n = s.size();
	memset(cnt, 0, sizeof(cnt));
	for (int i = 0; i < n; ++i) {
		cnt[s[i]-'a']++;
	}
	vector<pair<int,int>> rk;
	rk.clear();
	for (int i = 0; i < 26; ++i) {
		if (cnt[i] > 0) {
			rk.push_back(make_pair(cnt[i], i));
		}
	}
	sort(rk.begin(), rk.end());
	if (rk.size() > 4) {
		cout<<"No"<<endl;
	} else if (rk.size() == 4) {
		cout<<"Yes"<<endl;
	} else if (rk.size() == 3) {
		if (rk.back().first > 1) {
			cout<<"Yes"<<endl;
		} else {
			cout<<"No"<<endl;
		}
	} else if (rk.size() == 2) {
		if (rk[0].first> 1) {
			cout<<"Yes"<<endl;
		} else {
			cout<<"No"<<endl;
		}
	} else {
		cout<<"No"<<endl;
	}
  return 0;
}
