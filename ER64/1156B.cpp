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
#define M 20005
#define N 200
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t;
string s;
string getres(vector<pair<int,int>>& rk) {
	int m = rk.size();
	string res="";
	if (m==2) {
		for (int i = 0; i < 2; ++i) {
			for (int j = 1; j <= rk[i].second; ++j) {
				res.push_back('a'+rk[i].first);
			}
		}
	} else if (m==3) {
		if (rk[0].first+1==rk[1].first) {
			for (int i = 1; i <= rk[0].second; ++i) {
				res.push_back('a'+rk[0].first);
			}
			for (int i = 1; i <= rk[2].second; ++i) {
				res.push_back('a'+rk[2].first);
			}
			for (int i = 1; i <= rk[1].second; ++i) {
				res.push_back('a'+rk[1].first);
			}
		} else {
			for (int i = 1; i <= rk[1].second; ++i) {
				res.push_back('a'+rk[1].first);
			}
			for (int i = 1; i <= rk[0].second; ++i) {
				res.push_back('a'+rk[0].first);
			}
			for (int i = 1; i <= rk[2].second; ++i) {
				res.push_back('a'+rk[2].first);
			}
		}
	} else {
		for (int i = 1; i < m; i += 2) {
			for (int j = 1; j <= rk[i].second; ++j) {
				res.push_back('a'+rk[i].first);
			}
		}
		for (int i = 0; i < m; i += 2) {
			for (int j = 1; j <= rk[i].second; ++j) {
				res.push_back('a'+rk[i].first);
			}
		}
	}
	return res;
}
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		cin>>s;
		int cnt[26];
		memset(cnt, 0, sizeof(cnt));
		int n = s.size();
		for (int i = 0; i < n; ++i) {
			cnt[s[i]-'a']++;
		}
		vector<pair<int,int>> rk;
		rk.clear();
		for (int i = 0; i < 26; ++i) {
			if (cnt[i]>0) {
				rk.push_back(make_pair(i, cnt[i]));
			}
		}
		sort(rk.begin(), rk.end());
		int m = rk.size();
		if (m==2) {
			if (rk[0].first+1==rk[1].first) {
				cout<<"No answer"<<endl;
			} else {
				cout<<getres(rk)<<endl;
			}
		} else if (m==3) {
			if (rk[0].first+1==rk[1].first && rk[1].first+1==rk[2].first) {
				cout<<"No answer"<<endl;
			} else {
				cout<<getres(rk)<<endl;
			}
		} else {
			cout<<getres(rk)<<endl;
		}
	}
	return 0;
}
