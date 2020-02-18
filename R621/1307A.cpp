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
int t,n,d;
int a[102];
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		cin>>n>>d;
		for (int i = 1; i <= n; ++i) {
			cin>>a[i];
		}
		int tot=a[1];
		for (int i = 2; i <= n; ++i) {
			if (d == 0) break;
			int num = d/(i-1);
			num = min(num, a[i]);
			tot += num;
			d -= (i-1)*num;
		}
		cout<<tot<<endl;
	}
	return 0;
}
