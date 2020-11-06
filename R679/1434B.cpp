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
#define N 100005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n;
int a[2*N];
int b[2*N];
int BIT[2*N];
vector<int> ids;
int lowbit(int x) {
	return x&(-x);
}
int query(int pos) {
	int res=0;
	while(pos) {
		res += BIT[pos];
		pos -= lowbit(pos);
	}
	return res;
}
void update(int pos) {
	while(pos<=n) {
		BIT[pos] += 1;
		pos += lowbit(pos);
	}
}
int getid(int ub) {
	int res=query(ub);
	if (res==ub) return 0;
	int l = 1, r = ub;
	while(l<r) {
		int mid=(l+r)/2;
		if (res-query(mid)>=ub-mid) {
			r=mid;
		} else {
			l=mid+1;
		}
	}
	return r;
}
int main() {
	cin>>n;
	ids.clear();
//	memset(sum, 0, sizeof(sum));
	for (int i = 1; i <= 2*n; ++i) {
		string s;
		cin>>s;
		if (s=="+") {
			ids.push_back(i);
		} else {
			int v;
			scanf("%d", &v);
			a[i]=-v;
			b[v] = ids.size();
		}
	}
	memset(BIT, 0, sizeof(BIT));
	bool ok=true;
	for (int i = 1; i <= n; ++i) {
		int id=getid(b[i]);
		if (id<=0) {
			ok=false;
			break;
		}
		a[ids[id-1]]=i;
		update(id);
	}
	set<int> ss;
	ss.clear();
	for (int i = 1; i <= 2*n; ++i) {
		if (a[i]>0) {
			ss.insert(a[i]);
		} else {
			if (ss.empty() || ((*ss.begin()) != -a[i])) {
				ok=false;
				break;
			}
			ss.erase(-a[i]);
		}
	}
	if (!ok) cout<<"NO"<<endl;
	else {
		cout<<"YES"<<endl;
		int cnt=0;
		for (int i = 1; i <= 2*n ;++i) {
			if (a[i]>0) {
				printf("%d", a[i]);
				cnt++;
				if (cnt==n) cout<<endl;
				else cout<<" ";
			}
		}
	}
	return 0;
}
