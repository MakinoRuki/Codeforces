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
int t, n, l, r;
int a[N];
int id1[N], id2[N];
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) {
			id1[i] = 0;
			id2[i] = 0;
		}
		map<int, vector<int>> mp;
		mp.clear();
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
			mp[a[i]].push_back(i);
		}
		set<int> ss;
		ss.clear();
		for (int i = 1; i <= n; ++i) {
			ss.insert(i);
		}
		for (auto& itr : mp) {
			int x= itr.first;
			auto& v = itr.second;
			id1[v.back()] = x;
			id2[x] = v.back();
			v.pop_back();
	//		cout<<"x="<<x<<endl;
			ss.erase(x);
		}
	//	cout<<"sz1="<<ss.size()<<endl;
		vector<int> vv;
		vv.clear();
		for (auto itr : mp) {
			auto v = itr.second;
			for (int i = 0; i < v.size(); ++i) {
			//	cout<<"v[i]="<<v[i]<<endl;
				if (ss.find(v[i]) != ss.end()) {
					vv.push_back(v[i]);
					id1[v[i]] = v[i];
					id2[v[i]] = v[i];
					ss.erase(v[i]);
				}
			}
		}
	//	cout<<"sz2="<<ss.size()<<endl;
		for (auto itr : mp) {
			auto v = itr.second;
			for (int i = 0; i < v.size(); ++i) {
				if (id1[v[i]] > 0) continue;
				id1[v[i]] = *ss.begin();
				id2[id1[v[i]]] = v[i];
				ss.erase(ss.begin());
			}
		}
	//	cout<<"size="<<vv.size()<<endl;
		if (vv.size() == 1) {
			int x = a[vv[0]];
			int y = id2[x];
			swap(id1[y], id1[vv[0]]);
		} else if ((int)vv.size() % 2 == 0) {
			for (int i = 0; i < vv.size(); i += 2) {
				swap(id1[vv[i]], id1[vv[i+1]]);
			}
		} else {
			for (int i = 0; i < vv.size(); i += 2) {
				if (i+2 == vv.size()-1) {
					swap(id1[vv[i]], id1[vv[i+2]]);
					swap(id1[vv[i+1]], id1[vv[i+2]]);
					break;
				} else {
					swap(id1[vv[i]], id1[vv[i+1]]);
				}
			}
		}
		int cnt=0;
		for (int i = 1; i <= n; ++i) {
			if (id1[i] == a[i]) {
				cnt++;
			}
		}
		printf("%d\n", cnt);
		for (int i = 1; i <= n; ++i) {
			printf("%d", id1[i]);
			if (i < n) cout<<" ";
			else cout<<endl;
		}
	}
  return 0;
}
