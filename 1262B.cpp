#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#define N 1000005
using namespace std;
typedef long long ll;
int t, n;
vector<int> q;
int main() {
	cin>>t;
	for (int cas = 1; cas <= t; ++cas) {
		cin>>n;
		set<int> ss;
		ss.clear();
		q.clear();
		for (int i = 0; i < n; ++i) {
			int x;
			cin>>x;
			q.push_back(x);
		}
		for (int i =1; i <= n; ++i) {
			ss.insert(i);
		}
		vector<int> ans;
		ans.push_back(q[0]);
		ss.erase(q[0]);
		for (int i = 1; i < n; ++i) {
			if (q[i] == q[i-1]) {
				int b = *ss.begin();
				if (b >= q[i]) {
					break;
				}
				ans.push_back(b);
				ss.erase(b);
			} else {
				ans.push_back(q[i]);
				ss.erase(q[i]);
			}
		}
		if (ans.size() < n) cout<<"-1"<<endl;
		else {
			for (int i = 0; i < n; ++i) {
				cout<<ans[i];
				if (i == n-1) cout<<endl;
				else cout<<" ";
			}
		}
	}
	return 0;
}
