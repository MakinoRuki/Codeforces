#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#define N 100005
//#define M 10005
#define inf 1000000000
#define pii pair<int, int>
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int t, n;
int a[N];
int cnt[N];
set<pair<int,int>> ss;
bool check(int d) {
	ss.clear();
	int cnt2[N];
	int pre[N];
	for (int i = 1; i <= n; ++i) {
		cnt2[i] = cnt[i];
		pre[i] = -1;
		if (cnt[i] > 0) {
			ss.insert(make_pair(-cnt[i], i));
		}
	}
	vector<int> ans;
	ans.clear();
	deque<int> dq;
	while(ans.size() < n) {
		if (ss.empty()) return false;
		auto top = *ss.begin();
		ss.erase(top);
		int x = top.second;
		ans.push_back(x);
		cnt2[x]--;
		pre[x] = ans.size()-1;
		if (cnt2[x]>0) {
			dq.push_back(x);
		}
		while(!dq.empty()) {
			int cur = dq.front();
			if (pre[cur] <= (int)ans.size()-1-d) {
				dq.pop_front();
				ss.insert(make_pair(-cnt2[cur], cur));
			} else {
				break;
			}
		}
	}
	return true;
}
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		cin>>n;
		for (int i = 1; i <= n; ++i) {
			cnt[i] = 0;
		}
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
			cnt[a[i]]++;
		}
		
		int l = 0, r = n-1;
		while(l < r) {
			int mid = (l+r+1)/2;
			if (check(mid)) {
				l = mid;
			} else {
				r = mid-1;
			}
		}
		cout<<r<<endl;
	}
	return 0;
}
