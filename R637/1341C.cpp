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
#define N 100005
using namespace std;
typedef long long ll;
int t, n, k;
int p[N];
int l[N], r[N];
int pos[N];
bool vis[N];
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		cin>>n;
		set<pair<int, int>> ss;
		ss.clear();
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &p[i]);
			pos[p[i]] = i;
			vis[i] = false;
		}
		memset(l, -1, sizeof(l));
		memset(r, -1, sizeof(r));
		for (int i = 1; i <= n; ++i) {
			l[i] = i-1;
			if (i < n) r[i] = i + 1;
		}
		for (int i = 1; i <= n; ++i) {
		//	if (i==1) ss.insert(make_pair(-1, i));
			ss.insert(make_pair(-(i-l[i]), i));
		}
		bool ok = true;
		for (int i = 1; i <= n; ++i) {
			auto tpr = *ss.begin();
			int top = 0;
			if (tpr.first<0) top = -tpr.first;
			int id = pos[i];
			int val = id-l[id];//(l[id]<0 ? 1 : id-l[id]);
		//	cout<<"i="<<i<<" "<<top<<" "<<val<<endl;
			if (val == top) {
				vis[id] = true;
				if (r[id] > 0 && !vis[r[id]]) {
					auto pr = make_pair(-(r[id]-l[r[id]]), r[id]);
					ss.erase(pr);
					l[r[id]] = l[id];
					ss.insert(make_pair(-(r[id]-l[r[id]]), r[id]));
				}
				if (l[id] > 0) {
					r[l[id]] = r[id];
				}
				ss.erase(make_pair(-val, id));
			} else {
				ok = false;
				break;
			}
		}
		if (!ok) cout<<"No"<<endl;
		else cout<<"Yes"<<endl;
	}
	return 0;
}
