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
#define N 200
using namespace std;
typedef long long ll;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n, m;
int t;
int a[N];
int cnt[N];
int cnt1[N], cnt2[N];
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d", &n);
		memset(cnt, 0, sizeof(cnt));
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
			cnt[a[i]]++;
		}
		int tot=0;
		int res=0;
		memset(cnt1, 0, sizeof(cnt1));
		memset(cnt2, 0, sizeof(cnt2));
		for (int i = 0; i <= 100; ++i) {
			if (cnt[i] > 0) {
				cnt1[i]++;
				cnt[i]--;
			}
		}
		for (int i = 0; i <= 100; ++i) {
			if (cnt[i]>0) {
				cnt2[i]++;
				cnt[i]--;
			}
		}
		for (int i = 0; i <= 101; ++i) {
			if (cnt1[i]==0) {
				res+=i;
				break;
			}
		}
		for (int i = 0; i <= 101; ++i) {
			if (cnt2[i]==0) {
				res += i;
				break;
			}
		}
		cout<<res<<endl;
	}
	return 0;
}
