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
#define N 200005
#define M 10005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int t;
int n;
int a[N];
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		cin>>n;
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
		}
		int i = n-1;
		while(i >= 1 && a[i] >= a[i+1]) {
			i--;
		}
		if (i==0) {
			cout<<0<<endl;
			continue;
		}
		while(i >= 1 && a[i] <= a[i+1]) {
			i--;
		}
		if (i == 0) {
			cout<<0<<endl;
			continue;
		}
		if (a[i] > a[i+1]) {
			cout<<i<<endl;
		}
	}
  return 0;
}
