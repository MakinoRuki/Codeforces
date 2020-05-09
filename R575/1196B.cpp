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
#define N 200005
using namespace std;
typedef long long ll;
int q, n, k;
int a[N];
int main() {
	cin>>q;
	for (int i = 1; i <= q; ++i) {
		cin>>n>>k;
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
		}
		vector<int> ans;
		ll sum=0;
		ans.clear();
		for (int i = 1; i <= n; ++i) {
			sum += a[i];
			if (sum % 2) {
				if (ans.size() < k) {
					ans.push_back(i);
					sum = 0;
				}
			}
		}
		if (sum > 0) {
			if (sum % 2 == 0) {
				if (ans.empty()) {
					cout<<"NO"<<endl;
					continue;
				}
				ans.back() = n;
			} else {
				cout<<"NO"<<endl;
				continue;
			}
		}
		if (ans.size() != k) {
			cout<<"NO"<<endl;
			continue;
		}
		cout<<"YES"<<endl;
		for (int i = 1; i <= ans.size(); ++i) {
			printf("%d", ans[i-1]);
			if (i < ans.size()) cout<<" ";
			else cout<<endl;
		}
	}
	return 0;
}
