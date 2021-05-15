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
#define N 505
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t,n,l,r,s;
int b[N];
int main() {
	cin>>t;
	for (int cas=1;  cas<=t; ++cas) {
		scanf("%d%d%d%d", &n, &l, &r, &s);
		int m = r-l+1;
		int sum=0;
		for (int i = l; i <= r; ++i) {
			b[i] = i-l+1;
			sum += (i-l+1);
		}
		if (sum > s) {
			puts("-1");
			continue;
		}
		for (int i = r; i >= l; --i) {
		//	cout<<"i="<<i<<endl;
			if (sum == s) {
				break;
			}
			int ub = n-(r-i);
			while(b[i] < ub && sum < s) {
				b[i]++;
				sum++;
			}
			//cout<<"x="<<b[i]<<endl;
		}
	//	cout<<"??"<<endl;
		if (sum < s) {
			puts("-1");
			continue;
		}
		set<int> ss;
		ss.clear();
		for (int i = 1; i <= n; ++i) {
			ss.insert(i);
		}
		for (int i = l; i <= r; ++i) {
			ss.erase(b[i]);
		}
	//	cout<<"sz="<<ss.size()<<endl;
		for (int i =1 ; i < l; ++i) {
			b[i] = (*ss.begin());
			ss.erase(ss.begin());
		}
		for (int i = r+1; i <= n; ++i) {
			b[i] = (*ss.begin());
			ss.erase(ss.begin());
		}
		for (int i = 1; i <= n; ++i) {
			printf("%d", b[i]);
			if (i < n) cout<<" ";
			else cout<<endl;
		}
	}
  return 0;
}
