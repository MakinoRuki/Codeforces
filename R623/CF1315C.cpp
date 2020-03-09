#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <algorithm>
#define N 105
using namespace std;
typedef long long ll;
int t, n;
int b[N];
int a[2*N];
int id[2*N];
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		cin>>n;
		memset(id, -1, sizeof(id));
		bool ok = true;
		for (int i = 1; i <= n; ++i) {
			cin>>b[i];
			if (id[b[i]] >= 0) ok = false;
			else id[b[i]] = i;
		}
		if (!ok) {
			cout<<-1<<endl;
			continue;
		}
		set<int> pos;
		pos.clear();
		for (int i =1; i <= 2*n; ++i) {
			if (id[i] >= 0) {
				a[2*id[i]-1] = i;
				pos.insert(2*id[i]);
			} else {
				if (pos.empty()) {
					ok = false;
					break;
				}
				int idx = *pos.begin();
				pos.erase(idx);
				a[idx] = i;
			}
		}
		if (!ok) {
			cout<<"-1"<<endl;
		} else {
			for (int i = 1; i <= 2* n; ++i) {
				cout<<a[i];
				if (i < 2*n) cout<<" ";
				else cout<<endl;
			}
		}
	}
	return 0;
}
