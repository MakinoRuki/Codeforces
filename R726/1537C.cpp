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
int t, n, m;
int k;
int q;
int a[N];
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
		}
		sort(a+1, a+n+1);
		int det = INT_MAX;
		int ans = n-1;
		int id = -1;
		for (int i = 1; i < n; ++i) {
			if (i == 1) {
				det = min(det, a[2]-a[1]);
				if (a[n] <= a[2]) {
					ans = n-1;
					id = i;
				} else {
					ans = n-2;
					id = i;
				}
			} else if (i == n-1) {
				int cnt=0;
				if (a[n-1] <= a[1]) {
					cnt=n-1;
				} else {
					cnt = n-2;
				}
				if (a[i+1] - a[i] < det) {
					det = a[i+1]-a[i];
					id = i;
					ans = cnt;
				} else if (a[i+1] -a[i] == det) {
					if (cnt < ans) {
						ans = cnt;
						id = i;
					}
				}
			} else {
				int cnt=0;
				if (a[n] <= a[1]) {
					cnt= n-1;
				} else {
					cnt=n-2;
				}
				if (a[i+1] -a[i] < det) {
					det = a[i+1]-a[i];
					id = i;
					ans = cnt;
				} else if (a[i+1]-a[i] == det) {
					if (cnt < ans) {
						ans = cnt;
						id= i;
					}
				}
			}
			//cout<<i<<" "<<det<<" "<<id<<endl;
		}
		vector<int> ids;
		ids.clear();
		ids.push_back(a[id]);
		for (int i = id + 2; i <= n; ++i) {
			ids.push_back(a[i]);
		}
		for (int i = 1; i < id; ++i) {
			ids.push_back(a[i]);
		}
		ids.push_back(a[id+1]);
		for (int i = 0; i < ids.size(); ++i) {
			printf("%d", ids[i]);
			if (i < ids.size()-1) cout<<" ";
			else cout<<endl;
		}
	}
  return 0;
}
