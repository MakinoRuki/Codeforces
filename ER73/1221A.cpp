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
#define N 200005
//#define M 10005
#define inf 1000000000
#define pii pair<int, int>
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int q, n;
ll s[N];
int cnt[32];
int main() {
	cin>>q;
	for (int cas=1; cas<=q; ++cas) {
		cin>>n;
		memset(cnt, 0, sizeof(cnt));
		for (int i = 1; i <= n; ++i) {
			scanf("%lld", &s[i]);
			int pw = 0;
			while((1LL<<pw) < s[i]) {
				pw++;
			}
			cnt[pw]++;
		}
		int need = 1;
		for (int i = 11; i>= 0; --i) {
			int det = min(need, cnt[i]);
			need -= det;
			if (need == 0) break;
			need *= 2;
		}
		if (need <= 0) {
			cout<<"YES"<<endl;
		} else {
			cout<<"NO"<<endl;
		}
	}
	return 0;
}
