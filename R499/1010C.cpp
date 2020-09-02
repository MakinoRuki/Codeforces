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
#define eps 1e-6
//#define M 10005
#define inf 1000000000
#define pii pair<int, int>
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, k;
int a[N];
int getgcd(int x, int y) {
	return y==0?x:getgcd(y,x%y);
}
int main() {
	cin>>n>>k;
	int g=k;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		g=getgcd(g, a[i]);
	}
	int tot=0;
	vector<int> ans;
	for (int i = 0; i < k; ++i) {
		if (i%g==0) {
			tot++;
			ans.push_back(i);
		}
	}
	printf("%d\n", tot);
	for (int i = 0; i < ans.size(); ++i) {
		printf("%d", ans[i]);
		if (i < ans.size()-1) cout<<" ";
		else cout<<endl;
	}
	return 0;
}
