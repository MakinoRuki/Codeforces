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
#define N 102
using namespace std;
typedef long long ll;
int t,n;
int a[N], b[N];
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		cin>>n;
		vector<pair<int, int>> ark;
		vector<pair<int, int>> brk;
		ark.clear();
		brk.clear();
		for (int i = 1; i <= n; ++i) {
			cin>>a[i];
			ark.push_back(make_pair(a[i], i));
		}
		for (int i = 1; i <= n; ++i) {
			cin>>b[i];
			brk.push_back(make_pair(b[i], i));
		}
		sort(ark.begin(), ark.end());
		sort(brk.begin(), brk.end());
		for (int i = 1; i <= n; ++i) {
			cout<<ark[i-1].first;
			if (i < n) cout<<" ";
			else cout<<endl;
		}
		for (int i = 1; i <= n; ++i) {
			cout<<brk[i-1].first;
			if (i < n) cout<<" ";
			else cout<<endl;
		}
	}
	return 0;
}
