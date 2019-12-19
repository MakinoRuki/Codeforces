#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <map>
#include <set>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#define N 500005
using namespace std;
typedef long long ll;
int n;
vector<pair<int, int>> segs;
int par[N];
int find(int x) {
	return x==par[x] ? x : par[x] = find(par[x]);
}
int main() {
	cin>>n;
	segs.clear();
	for (int i = 0; i < n; ++i) {
		par[i] = i;
	}
	vector<pair<int, int>> rk;
	rk.clear();
	for (int i = 0; i < n; ++i) {
		int l, r;
		cin>>l>>r;
		segs.push_back(make_pair(l, r));
		rk.push_back(make_pair(l, i));
		rk.push_back(make_pair(r, i));
	}
	sort(rk.begin(), rk.end());
	map<int, int> idx;
	idx.clear();
	bool ok = true;
	for (int i = 0; i < rk.size(); ++i) {
		if (i > 0 && idx.empty()) {
			ok =false;
			break;
		}
		int v = rk[i].first;
		int id = rk[i].second;
		if (segs[id].first == v) {
			idx[-v] = id;
		} else {
			for (auto itr = idx.begin(); itr != idx.end(); ++itr) {
				if (-(itr->first) <= segs[id].first) {
					break;
				}
				int x = find(itr->second);
				int y = find(id);
				if (x == y) {
					ok = false;
					break;
				} else {
					par[x] = y;
				}
			}
			if (!ok) break;
			idx.erase(-segs[id].first);
		}
	}
	int cnt=0;
	for (int i = 0; i < n; ++i) {
		par[i] = find(i);
		if (par[i] == i) cnt++;
	}
	if (ok && cnt==1) {
		cout<<"YES"<<endl;
	} else {
		cout<<"NO"<<endl;
	}
	return 0;
}
