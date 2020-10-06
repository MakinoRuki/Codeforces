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
#define M 20005
#define N 100005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n;
int a[N];
string s;
int main() {
	cin>>n;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	cin>>s;
	int l = -inf;
	int r = inf;
	for (int i = 4; i < n; ++i) {
		if (s[i-1]=='0' && s[i-2]=='0' && s[i-3]=='0' && s[i-4] == '0') {
			if (s[i]=='1') {
				int maxv=a[i];
				for (int j = 1;j<=4; ++j) {
					maxv=max(maxv,a[i-j]);
				}
				l=max(l, maxv+1);
			}
		} else if (s[i-1]=='1' && s[i-2]=='1' && s[i-3]=='1' && s[i-4]=='1') {
			if (s[i]=='0') {
				int minv=a[i];
				for (int j = 1; j<=4; ++j) {
					minv=min(minv, a[i-j]);
				}
				r=min(r, minv-1);
			}
		}
	}
	cout<<l<<" "<<r<<endl;
	return 0;
}
