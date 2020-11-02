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
#define M 20005
#define N 200005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t,n;
int a[N];
string s;
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d", &n);
		cin>>s;
		int tot0=0;
		int tot1=0;
		int cnt=0;
		int cur=-1;
		for (int i = 0; i < n; ++i) {
			if (i==0) {
				cnt++;
				cur=s[i]-'0';
			} else {
				if (s[i]==s[i-1]) cnt++;
				else {
					if (cur==0) tot0 += cnt-1;
					else tot1 += cnt-1;
					cnt=1;
					cur=s[i]-'0';
				}
			}
		}
		if (cur==0) tot0 += cnt-1;
		else tot1 += cnt-1;
		printf("%d\n", max(tot0, tot1));
	}
	return 0;
}
