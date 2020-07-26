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
#define M 20010
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int t, n, m;
int a[N];
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		cin>>n;
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
		}
		bool ok = true;
		for (int i = n-1; i>= 1; --i) {
			if (a[i]==1) {
				if (ok) ok = false;
				else ok = true;
			} else {
				ok = true;
			}
		}
		if (ok) cout<<"First"<<endl;
		else cout<<"Second"<<endl;
	}
  return 0;
}
