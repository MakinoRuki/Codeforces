#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#define N 200005
using namespace std;
int n;
set<int> edges[N];
int main() {
	cin>>n;
	queue<int> q;
	for (int i = 1; i < n; ++i) {
		int x, y;
		cin>>x>>y;
		edges[x].insert(y);
		edges[y].insert(x);
	}
	bool ok = true;
	for (int i = 1; i <= n; ++i) {
		int a;
		cin>>a;
		if (i == 1 && a != 1) {
			ok = false;
			break;
		}
		if (i > 1) {
			while(!q.empty()) {
				int x = q.front();
				if (edges[x].find(a) == edges[x].end()) {
					q.pop();
				} else {
					break;
				}
			}
			if (q.empty()) ok = false;
		}
		q.push(a);
	}
	cout<<(ok ? "Yes" : "No")<<endl;
	return 0;
}
