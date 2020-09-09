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
const ll mod2 = 998244353LL;
int n;
int a[N];
int main() {
	cin>>n;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	sort(a+1, a+n+1);
	int j = n;
	int tot=0;
	for (int i = n; i >= 1; --i) {
		while(j >= 1 && a[j] >= a[i]) {
			j--;
		}
		if (j>=1) tot++;
		j--;
	}
	cout<<tot<<endl;
	return 0;
}
