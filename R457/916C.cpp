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
#define eps 1e-7
#define M 20005
#define N 500005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n,m;
bool pr[N];
int main() {
	memset(pr, true, sizeof(pr));
	for (int i = 2; i*i <= 200000; ++i) {
		if (pr[i]) {
			for (int j = i*i; j <= 200000; j+=i) {
				pr[j]=false;
			}
		}
	}
	cin>>n>>m;
	if (n==2) {
		cout<<2<<" "<<2<<endl;
		cout<<1<<" "<<2<<" "<<2<<endl;
		return 0;
	}
	if (pr[n-1]) {
		cout<<n-1<<" "<<n-1<<endl;
		vector<pair<pair<int,int>,int>> es;
		es.clear();
		for (int i = 1; i < n; ++i) {
			es.push_back(make_pair(make_pair(i,i+1), 1));
		}
		int det=m-(n-1);
		for (int i = 1; i < n; ++i) {
			for (int j = i+2; j <= n; ++j) {
				if (det==0) break;
				es.push_back(make_pair(make_pair(i,j),inf));
				det--;
			}
			if (!det) break;
		}
		for (int i= 0; i < es.size(); ++i) {
			printf("%d %d %d\n", es[i].first.first, es[i].first.second, es[i].second);
		}
	} else {
		int w;
		for (w=n; w <= 200000; ++w) {
			if (pr[w]) break;
		}
		int det=w-(n-1);
		cout<<w<<" "<<w<<endl;
		vector<pair<pair<int,int>,int>> es;
		es.clear();
		for (int i = 1; i < n-1; ++i) {
			es.push_back(make_pair(make_pair(i,i+1),1));
		}
		es.push_back(make_pair(make_pair(n-1,n),det+1));
		det=m-(n-1);
		for (int i = 1; i < n; ++i) {
			for (int j=i+2; j <= n; ++j) {
				if (det==0) break;
				es.push_back(make_pair(make_pair(i,j),inf));
				det--;
			}
			if (!det) break;
		}
		for (int i = 0; i < es.size(); ++i) {
			printf("%d %d %d\n", es[i].first.first, es[i].first.second, es[i].second);
		}
	}
	return 0;
}
