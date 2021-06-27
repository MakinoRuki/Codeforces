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
#define M 22
#define N 510
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n;
int k;
int q;
int dis[N];
int pre[N];
int query(vector<int>& ids) {
	printf("?");
	for (int i = 0; i < ids.size(); ++i) {
		printf(" %d", ids[i]);
	}
	printf("\n");
	fflush(stdout);
	int x;
	scanf("%d", &x);
	return x;
}
int main() {
	cin>>n>>k;
	if (n%2 && k%2==0) {
		puts("-1");
	} else {
		if (k == n) {
			int res= 0 ;
			printf("?");
			for (int i = 1; i <= n; ++i) {
				printf(" %d", i);
			}
			printf("\n");
			fflush(stdout);
			scanf("%d", &res);
			printf("! %d\n", res);
			return 0;
		}
		for (int i = 0; i <= n; ++i) {
			dis[i] = inf;
		}
		memset(pre, -1, sizeof(pre));
		dis[0] = 0;
		queue<int> q;
		q.push(0);
		while(!q.empty()) {
			int cur=q.front();
			q.pop();
			for (int i = 0; i <= min(cur, k); ++i) {
				if (cur + k - i <= n) {
					if (dis[cur+k-2*i] > dis[cur]+1) {
						q.push(cur+k-2*i);
						pre[cur+k-2*i] = cur;
						dis[cur+k-2*i] = dis[cur]+1;
					}
				}
			}
		}
		if (dis[n] >= inf) {
			puts("-1");
			return 0;
		}
	//	cout<<"d="<<dis[n]<<endl;
		vector<int> st;
		st.clear();
		int cur= n ;
		while(cur>=0) {
			st.push_back(cur);
		//	cout<<"cur="<<cur<<" "<<pre[cur]<<endl;
			cur = pre[cur];
		}
		reverse(st.begin(), st.end());
		set<int> ss;
		ss.clear();
		int tot=0;
		for (int i = 0; i < st.size()-1; ++i) {
			int x = st[i];
			int y = st[i+1];
			int det = (x+k-y)/2;
			int cnt1=0;
			int cnt2=0;
			vector<int> ids;
			ids.clear();
			for (int j = 1; j <= n; ++j) {
				if (ss.find(j) != ss.end()) {
					cnt1++;
					if (cnt1 <= det) {
						ids.push_back(j);
						ss.erase(j);
					}
				} else {
					cnt2++;
					if (cnt2 <= k-det) {
						ids.push_back(j);
						ss.insert(j);
					}
				}
			}
			int res = query(ids);
			tot ^= res;
		}
		printf("! %d\n", tot);
	}
  return 0;
}
