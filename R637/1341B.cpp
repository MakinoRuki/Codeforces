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
#include <queue>
#define N 200005
using namespace std;
typedef long long ll;
int t, n, k;
int a[N];
bool pk[N];
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		cin>>n>>k;
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
		}
		int maxv = 0;
		int li = 1;
		for (int i =1 ; i <= n; ++i) {
			pk[i] = false;
		}
		int cnt=0;
		for (int i = 2; i < k; ++i) {
			if (a[i]>a[i-1] && a[i]>a[i+1]) {
				pk[i] = true;
				cnt++;
			}
		}
		maxv = cnt;
		for (int i = k+1; i <= n; ++i) {
			if (pk[i-k+1]) {
				cnt--;
			}
			if (a[i-1]>a[i-2] && a[i-1]>a[i]) {
				pk[i-1] = true;
				cnt++;
			}
			if (cnt>maxv) {
				maxv = cnt;
				li = i-k+1;
			}
		}
		cout<<maxv+1<<" "<<li<<endl;
	}
	return 0;
}
