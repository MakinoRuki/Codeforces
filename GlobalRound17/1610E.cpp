#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#define M 1000005
#define N 200005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
string s;
int t;
int n;
vector<int> a;
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d", &n);
		a.clear();
		for (int i = 1; i <= n; ++i) {
			int x;
			scanf("%d", &x);
			a.push_back(x);
		}
		int ans = 0;
		int cnt=0;
		for (int i = 1; i <= n; ++i) {
		//	cout<<"i="<<i<<endl;
			if (i == 1) {
				cnt++;
				ans = max(ans, cnt);
			} else {
				if (a[i-1] == a[i-2]) {
					cnt++;
					ans = max(ans, cnt);
				} else {
					int num = 1;
					int cur = i, pre = i-1;
					while(true) {
						int id = lower_bound(a.begin()+cur, a.end(), 2*a[cur-1] - a[pre-1]) - a.begin();
					//	cout<<"id="<<pre<<" "<<cur<<" "<<2*a[cur-1]-a[pre-1]<<" "<<id<<endl;
						if (id >= a.size()) {
							break;
						}
						num++;
						cur = id+1;
					}
					ans = max(ans, cnt + num);
					cnt = 1;
				}
			}
		//	cout<<"i2="<<i<<endl;
		}
		printf("%d\n", n-ans);
	}
  return 0;
}

