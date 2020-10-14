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
#define N 100
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t,n,k;
string s;
int a[N];
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d%d", &n, &k);
		cin>>s;
		int tot=0;
		int cnt=0;
		int id=-1;
		vector<pair<int,int>> ls;
		ls.clear();
		vector<pair<int,int>> ts;
		ts.clear();
		for (int i = 0; i < n; ++i) {
			if (s[i]=='W') {
				if (i-1<0 || s[i-1] != 'W') {
					cnt++;
					if (id>=0) {
						ls.push_back(make_pair(i-id-1,id+1));
					}
				}
				if (id<0 && i>0) {
					ts.push_back(make_pair(i,0));
				}
				id=i;
			}
		}
		if (id<n-1) {
			ts.push_back(make_pair(n-1-id,id+1));
		}
		// cout<<ls.size()<<" "<<ts.size()<<endl;
		// cout<<ls[0].first<<" "<<ls[0].second<<endl;
		//cout<<ts[0].first<<" "<<ts[0].second<<endl;
		sort(ls.begin(), ls.end());
		for (int i = 0; i < ls.size(); ++i) {
			int l = ls[i].first;
			if (k>=l) {
				for (int j = 0; j < ls[i].first; ++j) {
					s[ls[i].second+j]='W';
				}
				k-=l;
			} else {
				for (int j = 0; j < k; ++j) {
					s[ls[i].second+j]='W';
				}
				k -= k;
				break;
			}
		}
	//	cout<<"k="<<k<<" "<<s<<endl;
		if (k) {
			int i;
			for (i=0; i < n; ++i) {
				if (s[i] == 'W') break;
			}
			i--;
			while(k && i>=0) {
				s[i] = 'W';
				k--;
				i--;
			}
			i=n-1;
			for (i=n-1; i >= 0; --i) {
				if (s[i] == 'W') break;
			}
			i++;
			while(k && i < n) {
				s[i] = 'W';
				k--;
				i++;
			}
		}
		tot=0;
	//	cout<<"k2="<<s<<endl;
		for (int i = 0; i < n; ++i) {
			if (s[i]=='W') {
				if (i-1>=0 && s[i-1]=='W') {
					tot += 2;
				} else {
					tot++;
				}
			}
		}
		printf("%d\n", tot);
	}
	return 0;
}
