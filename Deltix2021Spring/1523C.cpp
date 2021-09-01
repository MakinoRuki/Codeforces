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
#include <time.h>
#define eps 1e-7
#define M 52
#define N 2000
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n;
int a[N];
bool used[N];
vector<string> ans;
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
			//a[i] = i;
		}
		vector<int> stk;
		stk.clear();
		ans.clear();
		for (int i = 0; i < n; ++i) {
			ans.push_back("");
		}
		ans[0] = "1";
		stk.push_back(1);
		for (int i = 2; i <= n; ++i) {
			if (a[i] == 1) {
				ans[i-1] = ans[i-2] + ".1";
			} else {
				while(!stk.empty() && a[stk.back()]+1 != a[i]) {
					stk.pop_back();
				}
				int id = stk.back();
				stk.pop_back();
				string pre = "";
				int j;
				for (j = ans[id-1].size()-1; j >= 0 && ans[id-1][j] != '.'; --j) {
					pre.push_back(ans[id-1][j]);
				}
				reverse(pre.begin(), pre.end());
				pre = (j < 0 ? "" : ans[id-1].substr(0,j+1)) + to_string(stoi(pre)+1);
				ans[i-1] = pre;
			}
			stk.push_back(i);
		//	cout<<"i="<<i<<" "<<ans[i-1]<<endl;
		}
		// for (int i = 1; i <= n; ++i) {
		// 	cout<<"i="<<i<<" "<<nxt[i]<<" "<<op[i]<<endl;
		// }
		for (int i = 0; i < n; ++i) {
			cout<<ans[i]<<endl;
		}
	}
  return 0;
}
