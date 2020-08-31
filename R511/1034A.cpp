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
#define N 300005
//#define M 10005
#define inf 1000000000
#define pii pair<int, int>
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n;
int a[N];
int cnt[15000002];
bool pr[15000002];
int getgcd(int x, int y) {
	return y==0 ? x : getgcd(y, x%y);
}
int main() {
	cin>>n;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	memset(cnt, 0, sizeof(cnt));
	int g = a[1];
	for (int i = 2; i <= n; ++i) {
		g = getgcd(g, a[i]);
	}
	for (int i = 1; i <= n; ++i) {
		a[i] /= g;
		cnt[a[i]]++;
	}
	memset(pr, false, sizeof(pr));
	int ans=0;
	for (int i = 2; i * i <= 15000002; ++i) {
		if (!pr[i]) {
			for (int j = i*i; j <= 15000002; j+=i) {
				pr[j] = true;
			}
		}
	}
	for (int i = 2; i <= 15000002; ++i) {
		if (!pr[i]) {
			int tot=0;
			for (int j = i; j < 15000002; j += i) {
				tot += cnt[j];
			}
			ans = max(ans, tot);
		}
	}
	if (ans == 0) {
		cout<<-1<<endl;
	} else { 
		printf("%d\n", n-ans);
	}
	return 0;
}
