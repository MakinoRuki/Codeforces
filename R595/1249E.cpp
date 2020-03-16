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
int n,c;
int a[N], b[N];
int suma[N], sumb[N];
int dp[N];
int main() {
	cin>>n>>c;
	for (int i =1; i< n; ++i) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i < n; ++i) {
		scanf("%d", &b[i]);
	}
	memset(suma, 0, sizeof(suma));
	memset(sumb, 0, sizeof(sumb));
	for (int i = n-1; i >= 1; --i) {
		suma[i] = suma[i+1] + a[i];
		sumb[i] = sumb[i+1] + b[i];
	}
	deque<int> qa, qb;
	dp[1] = 0;
	qa.push_back(1);
	qb.push_back(1);
	for (int i = 2; i <= n; ++i) {
		int ida = qa.front();
		int idb = qb.front();
		dp[i] = min(dp[ida] + suma[ida]-suma[i], dp[idb] + sumb[idb]-sumb[i] + c);
		while(!qa.empty() && dp[i] < dp[qa.back()] + suma[qa.back()]-suma[i]) {
			qa.pop_back();
		}
		qa.push_back(i);
		while(!qb.empty() && dp[i] < dp[qb.back()] + sumb[qb.back()]-sumb[i]) {
			qb.pop_back();
		}
		qb.push_back(i);
	}
	for (int i = 1; i <= n; ++i) {
		cout<<dp[i];
		if (i < n) cout<<" ";
		else cout<<endl;
	}
	return 0;
}
