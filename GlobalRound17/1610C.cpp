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
#define M 1000005
#define N 200005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
string s;
int t;
int n;
int a[N];
int b[N];
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) {
			scanf("%d%d", &a[i], &b[i]);
		}
		int l = 1, r = n;
		while(l < r) {
			int mid = (l+r+1)/2;
			int tot=mid;
			int cnt=0;
			for (int i = 1; i <= n; ++i) {
				if (cnt <= b[i] && tot-cnt-1<=a[i]) {
					cnt++;
				}
			}
			if (cnt >= mid) {
				l = mid;
			} else {
				r = mid-1;
			}
		}
		printf("%d\n", r);
	}
  return 0;
}

