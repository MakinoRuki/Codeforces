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
#define M 52
#define N 200005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, k;
int p[N];
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &p[i]);
		}
		vector<int> stk;
		stk.clear();
		for (int i = n; i >= 1; --i) {
			while(!stk.empty() && p[i] > p[stk.back()]) {
				stk.pop_back();
			}
			stk.push_back(i);
		}
		int cnt=0;
		for (int i = 0; i <stk.size(); ++i) {
		//	cout<<"i="<<i<<" "<<stk[i]<<endl;
			int cur=stk[i];
			int ub= (i == 0? n : stk[i-1]-1);
			for (int j = cur; j <= ub; ++j) {
				printf("%d", p[j]);
				cnt++;
				if (cnt < n) cout<<" ";
				else cout<<endl;
			}
		}
	}
  return 0;
}
