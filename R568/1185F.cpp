#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#define N 100005
using namespace std;
typedef long long ll;
const ll mod = 998244353LL;
int n, m;
int a[N];
vector<pair<int,int>> p[1<<10];
int main() {
	cin>>n>>m;
	for (int i = 1; i <= n; ++i) {
		int f, b;
		cin>>f;
		a[i] = 0;
		for (int j = 1; j<=f; ++j) {
			cin>>b;
			a[i] |= (1<<(b-1));
		}
	}
	for (int i = 0; i < (1<<9); ++i) {
		p[i].clear();
	}
	for (int i = 1; i <= m; ++i) {
		int c;
		cin>>c;
		int r;
		cin>>r;
		int s=0;
		for (int j = 1; j <= r; ++j) {
			int x;
			cin>>x;
			s |= (1<<(x-1));
		}
		p[s].push_back(make_pair(c, i));
	}
	vector<pair<int, pair<int, int>>> ps;
	ps.clear();
	for (int s = 0; s < (1<<9); ++s) {
		sort(p[s].begin(), p[s].end());
		while(p[s].size() > 2) p[s].pop_back();
		for (int j = 0; j < p[s].size(); ++j) {
			ps.push_back(make_pair(s, p[s][j]));
		}
	}
	int maxa[1<<10];
	memset(maxa, 0, sizeof(maxa));
	for (int i = 0; i < (1<<9); ++i) {
		for (int j = 1; j <= n; ++j) {
			if ((i&a[j]) == a[j]) {
				maxa[i]++;
			}
		}
	}
	int max1 = 0;
	int min2 = 2000000002;
	int id1=-1;
	int id2=-1;
	for (int i = 0; i < ps.size(); ++i) {
		for (int j = 0; j < ps.size(); ++j) {
			if (i == j) continue;
			if (ps[i].second.first<2000000000 && ps[j].second.first < 2000000000) {
				int s= ps[i].first|ps[j].first;
				if (maxa[s] > max1) {
					max1 = maxa[s];
					min2 = ps[i].second.first+ps[j].second.first;
					id1 = ps[i].second.second;
					id2 = ps[j].second.second;
				} else {
					if (maxa[s] == max1) {
						if (ps[i].second.first+ps[j].second.first < min2) {
							min2 = ps[i].second.first+ps[j].second.first;
							id1 = ps[i].second.second;
							id2 = ps[j].second.second;
						}
					}
				}
			}
		}
	}
	cout<<id1<<" "<<id2<<endl;
	return 0;
}
