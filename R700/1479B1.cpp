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
#define eps 1e-7
#define M 21
#define N 100005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int q;
int t, n, m;
int a[N];
int main() {
	cin>>n;
	for (int i =1 ; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	vector<pair<int,int>> sgs;
	sgs.clear();
	vector<int> v1, v2;
	v1.clear();
	v2.clear();
	int cnt=0;
	for (int i = 1; i <= n; ++i) {
		if (i == 1 || a[i] == a[i-1]) {
			cnt++;
		} else {
			sgs.push_back(make_pair(a[i-1], cnt));
			cnt = 1;
		}
	}
	if (cnt > 0) {
		sgs.push_back(make_pair(a[n], cnt));
	}
	if (sgs[0].second > 1) {
		v1.push_back(sgs[0].first);
		v2.push_back(sgs[0].first);
	} else {
		v1.push_back(sgs[0].first);
	}
	for (int i = 1; i < sgs.size(); ++i) {
		int num = sgs[i].first;
		int cnt = sgs[i].second;
		if (cnt > 1) {
			v1.push_back(num);
			v2.push_back(num);
		} else {
			if (!v1.empty() && !v2.empty()) {
				if (v1.back() == num) {
					v2.push_back(num);
				} else if (v2.back() == num) {
					v1.push_back(num);
				} else if (i+1<sgs.size() && v1.back()==sgs[i+1].first) {
					v1.push_back(num);
				} else {
					v2.push_back(num);
				}
			} else if (!v1.empty()) {
				v1.push_back(num);
			} else {
				v2.push_back(num);
			}
		}
	}
	int tot=0;
	for (int i = 0; i < v1.size(); ++i) {
		if (i == 0 || v1[i] != v1[i-1]) {
			tot++;
		}
	}
	for (int i = 0; i <v2.size(); ++i) {
		if (i==0 || v2[i] != v2[i-1]) {
			tot++;
		}
	}
	printf("%d\n", tot);
  return 0;
}
