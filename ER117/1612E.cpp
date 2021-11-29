#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#define M 1000005
#define N 200005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
string s;
int t;
int n;
int k[N], m[N];
int cnt[N];
int main() {
	cin>>n;
	vector<pair<int,int>> rk;
	rk.clear();
	memset(cnt, 0, sizeof(cnt));
	for (int i= 1; i <= n; ++i) {
		scanf("%d%d", &m[i], &k[i]);
		rk.push_back(make_pair(k[i], i));
		cnt[m[i]]++;
	}
	set<pair<int,int>> s1, s2;
	s1.clear();
	s2.clear();
	for (int i = 1; i < N; ++i) {
		if (cnt[i] > 0) {
			s1.insert(make_pair(cnt[i], i));
		}
	}
	auto itr = *s1.rbegin();
	s2.insert(itr);
	s1.erase(itr);
	sort(rk.begin(), rk.end());
	ll tot=(*s2.begin()).first;
	ll ans= tot, nn = 1;
	reverse(rk.begin(), rk.end());
	while(!rk.empty() && rk.back().first <= 1) {
		rk.pop_back();
	}
	for (int i = 2; i <= n; ++i) {
		for (int j = 0; j < rk.size(); ++j) {
			int id = rk[j].second;
			int v = m[id];
			if (s2.find(make_pair(cnt[v], v)) != s2.end()) {
				s2.erase(make_pair(cnt[v], v));
				cnt[v]++;
				tot++;
				s2.insert(make_pair(cnt[v], v));
			} else {
				s1.erase(make_pair(cnt[v], v));
				cnt[v]++;
				if (cnt[v] <= (*s2.begin()).first) {
					s1.insert(make_pair(cnt[v], v));
				} else {
					s2.insert(make_pair(cnt[v], v));
					tot += cnt[v];
					auto tp = *s2.begin();
					tot -= tp.first;
					s2.erase(tp);
					s1.insert(tp);
				}
			}
		}
		while(!s1.empty() && s2.size() < i) {
			tot += (*s1.rbegin()).first;
			s2.insert(*s1.rbegin());
			s1.erase(--s1.end());
		}
		while(rk.size() > 0 && rk.back().first <= i) {
			rk.pop_back();
		}
		if (tot * nn > ans * i) {
			ans = tot;
			nn = i;
		}
	}
//	cout<<"nn="<<endl;
	rk.clear();
	memset(cnt, 0, sizeof(cnt));
	for (int i = 1; i <= n; ++i) {
		cnt[m[i]] += min(k[i], (int)nn);
	}
	for (int i = 1; i < N; ++i) {
		rk.push_back(make_pair(cnt[i], i));
	}
	sort(rk.begin(), rk.end());
	printf("%d\n", (int)nn);
	for (int i = 1; i <= nn; ++i) {
		printf("%d", rk[rk.size()-i].second);
		if (i < nn) cout<<" ";
		else cout<<endl;
	}
  return 0;
}

