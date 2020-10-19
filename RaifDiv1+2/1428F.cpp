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
#define N 500005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n;
string s;
int tree[N<<4];
int llen[N];
ll mlen[N];
void update(int id, int l, int r, int pos, int val) {
	int m=(l+r)/2;
	if (l==r) {
		tree[id]=val;
		return ;
	}
	if (pos<=m) {
		update(id*2, l, m, pos, val);
	} else {
		update(id*2+1, m+1, r, pos, val);
	}
	tree[id]=max(tree[id*2], tree[id*2+1]);
}
int query(int id, int l, int r, int len) {
	if (l==r) return l;
	int m=(l+r)/2;
	if (tree[id]<=len) return 0;
	if (tree[id*2+1]>len) {
		return query(id*2+1, m+1, r, len);
	} else {
		return query(id*2, l, m, len);
	}
}
int query2(int id, int l, int r, int len) {
	if (l==r) return r;
	if (tree[id]<len) return 0;
	int m=(l+r)/2;
	if (tree[id*2]>=len) {
		return query2(id*2, l, m, len);
	}
	return query2(id*2+1, m+1, r, len);
}
int main() {
	cin>>n>>s;
	//n=s.size();
	if (n==1) {
		if (s[0]=='1') cout<<1<<endl;
		else cout<<0<<endl;
		return 0;
	}
	memset(mlen, 0, sizeof(mlen));
	for (int i = 1; i <= n; ++i) {
		mlen[i]=mlen[i-1]+(ll)i*(ll)(i+1)/2;
	}
	vector<pair<int,int>> os;
	os.clear();
	int cnt=0;
	int id=-1;
	for (int i = 0; i < n; ++i) {
		if (s[i]=='1') {
			if (id<0) {
				id=i+1;
				cnt=1;
			} else {
				cnt++;
			}
		} else {
			if (cnt>0) {
				os.push_back(make_pair(id, cnt));
				llen[id]=cnt;
			}
			id=-1;
			cnt=0;
		}
	}
	if (cnt>0) {
		os.push_back(make_pair(id, cnt));
		llen[id]=cnt;
	}
	memset(tree,0, sizeof(tree));
	vector<ll> tot(os.size(), 0);
	ll ans=0LL;
	for (int i = 0; i < os.size(); ++i) {
		ll len=os[i].second;
		int id=os[i].first;
		if (len>2) {
			ans += mlen[len-2];
		}
		if (len>1) {
			for (int j = 1; j < len; ++j) {
				int id2=query(1, 1, n, j);
				int len2=llen[id2];
				int id3=id2+len2-j;
				if (id2<=0) {
					id3=1;
				}
				ans += (ll)j*(ll)(id-id3+1);
			}
		}
		int id2=query(1, 1, n, len);
		if (id2<=0) {
			tot[i] = id;
		} else {
			int len2=llen[id2];
			int id3=id2+len2-len;
			tot[i] = id-id3+1;
		}
	//	cout<<ans<<" "<<id2<<" "<<tot[i]<<endl;
		update(1, 1, n, id, len);
	}
	memset(tree, 0, sizeof(tree));
	for (int i = os.size()-1; i >= 0; --i) {
		ll len=os[i].second;
		int id=os[i].first;
		if (len>1) {
			for (int j =1; j < len; ++j) {
				int id2=query2(1, 1, n, j);
				int id3;
				if (id2<=0) {
					id3=n;
				} else {
					int len2=llen[id2];
					id3=id2+j-2;
				}
				ans += (ll)j*(ll)(id3-id-len+2);
			}
		}
		int id2=query2(1, 1, n, len);
		if (id2<=0) {
			ans += len*tot[i] * (ll)(n-id-len+2);
		} else {
			int id3=id2+len-2;
			ans += len*tot[i]*(ll)(id3-id-len+2);
		}
		update(1, 1, n, id, len);
	}
	cout<<ans<<endl;
	return 0;
}
