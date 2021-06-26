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
#define N 300005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n;
int k;
string s;
int q;
int p, c;
int idx[N];
int cnt[N];
void dfs(int id) {
	if (id>=(1<<(k))) {
		return;
	}
	if (id >= (1<<(k-1)) && id<(1<<(k))) {
		if (s[id-1] == '?') cnt[id] = 2;
		else cnt[id] = 1;
		return ;
	}
	dfs(id*2);
	dfs(id*2+1);
	if (s[id-1] == '?') {
		cnt[id] = cnt[id*2] + cnt[id*2+1];
	} else if (s[id-1] == '0') {
		cnt[id] = cnt[id*2];
	} else {
		cnt[id] = cnt[id*2+1];
	}
	
}
int main() {
	scanf("%d", &k);
	cin>>s;
	vector<pair<string, pair<int,int>>> v;
	v.clear();
	int cur = 0;
	int det = (1<<(k-1));
	while(cur < (1<<k)-1) {
		string t = s.substr(cur, det);
	//	cout<<cur<<" "<<det<<" "<<t<<endl;
		v.push_back(make_pair(t, make_pair(cur, cur+det-1)));
		cur += det;
		det /= 2;
	}
	s = "";
	for (int i = v.size()-1; i >= 0; --i) {
		int det = v[i].second.second;
		int cur=v[i].second.first;
		int s1=(int)s.size();
		s += v[i].first;
		int s2 = (int)s.size();
		for (int j = s1; j < s2; ++j) {
			idx[cur+j-s1] = j;
		}
	}
//	cout<<s<<endl;
	memset(cnt, 0, sizeof(cnt));
	dfs(1);
	int tot=cnt[1];
	// for (int i = 0; i < (1<<k); ++i) {
	// 	int sum = 0, det = 0;
	// 	det = (1<<(k-1));
	// 	bool ok = true;
	// 	for (int j = 0; j < k; ++j) {
	// 		int id = i/(1<<(j+1));
	// 	//	idx[sum+id][2]++;
	// 		int cnt = (1<<(j+1));
	// 		int l = i/cnt*cnt;
	// 		int r = i/cnt*(cnt+1);
	// 		int res = 1;
	// 		if (i >= l && i < r) {
	// 			res = 0;
	// 		}
	// 		idx[sum+id][res]++;
	// 		if (s[sum+id] != '?' && s[sum+id] - '0' != res) {
	// 			ok=false;
	// 		}
	// 		sum += det;
	// 		det /= 2;
	// 	}
	// 	if (ok) tot++;
	// }
//	cout<<cnt[1]<<endl;
	cin>>q;
	while(q-->0) {
		scanf("%d", &p);
		p--;
		string c;
		cin>>c;
		int id = idx[p]+1;
	//	cout<<id<<endl;
		s[idx[p]] = c[0];
		while(id) {
			if (id >= (1<<(k-1)) && id < (1<<(k))) {
				if (s[id-1] == '?') {
					cnt[id] = 2;
				} else {
					cnt[id] = 1;
				}
				id /= 2;
				continue;
			}
			if (s[id-1] == '?') {
				cnt[id] = cnt[id*2] + cnt[2*id+1];
			} else if (s[id-1] == '0') {
				cnt[id] = cnt[id*2];
			} else {
				cnt[id] = cnt[id*2+1];
			}
	//		cout<<"id="<<id<<" "<<cnt[id]<<endl;
			id /= 2;
		}
//		if (p==0) cout<<"x="<<cnt[3]<<endl;
		printf("%d\n", cnt[1]);
	}
  return 0;
}
