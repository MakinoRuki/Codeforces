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
#define N 100005
#define M 1000005
#define inf 1000000000
#define pii pair<int,int>
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int t, n;
int a[N];
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		cin>>n;
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
		}
		int res=0;
		for (int i = 30; i >= 0; --i) {
			int cnt=0;
			for (int j = 1; j <= n; ++j) {
				if ((1<<i)&a[j]) {
					cnt++;
				}
			}
			if (cnt%2==0) continue;
			int x = (cnt-1)/2;
			int y = 0;
			if (x%2==0) {
				y = 1;
				res = 1;
				break;
			}
			if ((n-cnt)%2) {
				res=1;
			} else {
				res = -1;
			}
			break;
		}
		if (res>0) cout<<"WIN"<<endl;
		else if (res==0) cout<<"DRAW"<<endl;
		else cout<<"LOSE"<<endl;
	}
  return 0;
}
