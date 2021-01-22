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
#define N 150
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n,k;
int t;
int s[N];
vector<int> ids[N];
int main() {
	cin>>n;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &s[i]);
		ids[s[i]].push_back(i-1);
	}
	int tot1=0;
	int tot2=0;
	for (int i = 1; i <= 100; ++i) {
		if (ids[i].size()==1) {
			tot1++;
		} else if (ids[i].size() > 2) {
			tot2++;
		}
	}
	if (tot1 % 2==0 || tot2>0) {
		string ans=string(n, ' ');
		int cnt1=0;
		int cnt2=0;
		int ub = tot1/2;
		if (tot1%2) {
			ub=(tot1+1)/2;
		}
	//	cout<<tot1<<" "<<tot2<<" "<<ub<<endl;
		for (int i = 1; i <= 100; ++i) {
			if (ids[i].size() == 1) {
				if (cnt1<ub) {
					ans[ids[i][0]] = 'A';
					cnt1++;
				} else {
					ans[ids[i][0]] = 'B';
					cnt2++;
				}
			}
		}
		for (int i = 1; i <= 100; ++i) {
			if (ids[i].size()>0) {
				if (ids[i].size()==2) {
					ans[ids[i][0]] = 'A';
					ans[ids[i][1]] = 'B';
				} else if (ids[i].size() > 2) {
					if (cnt1 < ub) {
						ans[ids[i][0]] = 'A';
						for (int j = 1; j < ids[i].size(); ++j) {
							ans[ids[i][j]] = 'B';
						}
						cnt1++;
					} else if (cnt2<ub) {
						ans[ids[i][0]] = 'B';
						for (int j = 1; j < ids[i].size(); ++j) {
							ans[ids[i][j]] = 'A';
						}
						cnt2++;
					} else {
						for (int j = 0; j < ids[i].size(); ++j) {
							ans[ids[i][j]] = 'A';
						}
					}
				}
			}
		}
		cout<<"YES"<<endl;
		cout<<ans<<endl;
	} else {
		cout<<"NO"<<endl;
	}
	return 0;
}
