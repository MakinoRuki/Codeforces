#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_set>
#define N 200020
using namespace std;
int n, m;
int par[N];
int find(int u) {
	return u==par[u]?u:par[u]=find(par[u]);
}
int main() {
	cin>>n>>m;
	for (int i = 1; i <= n; ++i) {
		par[i] = i;
	}
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin>>u>>v;
		int pu = find(u);
		int pv = find(v);
		if (pu != pv) {
			if (pu < pv) par[pu] = pv;
			else par[pv] = pu;
		}
	}
	for (int i = 1; i <= n; ++i) {
		par[i] = find(i);
		//cout<<i<<" "<<par[i]<<endl;
	}
	unordered_set<int> pars;
	int end = 0;
	pars.clear();
	int tot=0;
	for (int i = 1; i <= n; ++i) {
		if (i > end) {
			if (pars.size()) tot += pars.size()-1;
			pars.clear();
			if (par[i] > i) {
				end = par[i];
				pars.insert(par[i]);
			}
		} else {
			end = max(end, par[i]);
			pars.insert(par[i]);
		}
	}
	if (pars.size()) tot += pars.size()-1;
	cout<<tot<<endl;
	return 0;
}
