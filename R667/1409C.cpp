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
//#define M 10005
#define inf 1000000000
#define pii pair<int, int>
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int t;
int n,x,y;
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d%d%d",&n,&x,&y);
		int det=y-x;
		int i;
		for (i = 1; i <= det; ++i) {
			if (det%i==0 && det/i+1<=n) {
				break;
			}
		}
		int n1=det/i+1;
		int n2=min(n-n1, (x-1)/i);
		int a=x-n2*i;
		for (int j = 1; j <= n; ++j) {
			printf("%d", a+(j-1)*i);
			if (j<n) cout<<" ";
			else cout<<endl;
		}
	}
	return 0;
}
