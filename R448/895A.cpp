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
#define N 500
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t;
int n,m,k;
int a[N];
int main() {
	cin>>n;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	int tot=0;
	int minv=360;
	for (int i = 0; i < n; ++i) {
		int sum=0;
		for (int j = 0; j < n; ++j) {
			sum = sum + a[(i+j)%n];
			minv=min(minv, abs(360-sum-sum));
		}
	}
	cout<<minv<<endl;
	return 0;
}
