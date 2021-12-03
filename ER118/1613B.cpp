#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <set>
#include <map>
#include <list>
#include <queue>
#define M 1000005
#define N 200005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
//string s;
string s;
int t;
int n, q, m, k, e;
int a[N];
int getlen(int x) {
	int cnt=0;
	while(x) {
		cnt++;
		x/=10;
	}
	return cnt;
}
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
		}
		sort(a+1, a+n+1);
		for (int i = 1; i <= n/2; ++i) {
			printf("%d %d\n", a[n-i+1], a[1]);
		}
	}
  return 0;
}

