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
#define N 400005
//#define M 10005
#define inf 1000000000
#define pii pair<int, int>
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int t, n;
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d",&n);
		int n2 = 0, n3 = 0;
		int m=n;
		while(m%2==0) {
			n2++;
			m/=2;
		}
		while(m%3==0) {
			n3++;
			m/=3;
		}
		if (m>1) {
			cout<<-1<<endl;
			continue;
		}
		if (n2>0 && n3==0) {
			cout<<-1<<endl;
			continue;
		}
		if (n3 > 0 && n2 > n3) {
			cout<<-1<<endl;
			continue;
		}
		int res = n3-n2+n3;
		cout<<res<<endl;
	}
	return 0;
}
