#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#define N 200005
using namespace std;
typedef long long ll;
const ll mod = 998244353LL;
int n, m;
int t[N];
int cnt[102];
int main() {
	cin>>n>>m;
	for (int i = 1; i <= n; ++i) {
		cin>>t[i];
	}
	memset(cnt, 0, sizeof(cnt));
	int sum=0;
	for (int i = 1; i <= n; ++i) {
		int tot = sum;
		int res=0;
		for (int j = 100 ; j >= 1; --j) {
			if (tot + t[i] <= m) break;
			int det = tot+t[i]-m;
			int num = (det+j-1)/j;
			res += min(num, cnt[j]);
			tot -= min(num, cnt[j]) * j;
		}
		cout<<res;
		if (i < n) cout<<" ";
		else cout<<endl;
		sum += t[i];
		cnt[t[i]]++;
	}
	return 0;
}
