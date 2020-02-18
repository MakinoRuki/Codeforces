#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#define N 100005
using namespace std;
typedef long long ll;
int t,n,x;
int a[N];
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		cin>>n>>x;
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
		}
		sort(a+1, a+n+1);
		ll cnt=x/a[n];
		if (x%a[n]) cnt++;
		if (cnt == 1) {
			int i;
			for (i = 1; i <=n; ++i) {
				if (a[i] == x) break;
			}
			if (i <= n) {
				cout<<cnt<<endl;
			} else {
				cout<<cnt+1<<endl;
			}
		} else {
			cout<<cnt<<endl;
		}
	}
	return 0;
}
