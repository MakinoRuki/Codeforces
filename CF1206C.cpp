#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
int n;
int main() {
	cin>>n;
	if (n % 2 == 0) cout<<"NO"<<endl;
	else {
		vector<int> ans(2 * n, 0);
		for (int i = 0; i < n; ++i) {
			if (i & 1) {
				ans[i] = 2 * i + 2;
				ans[i+n] = 2 * i + 1;
			} else {
				ans[i] = 2 * i + 1;
				ans[i + n] = 2 * i + 2;
			}
		}
		cout<<"YES"<<endl;
		for (int i = 0; i < 2 * n; ++i) {
			cout<<ans[i];
			if ( i < 2 * n - 1) cout<< " ";
			else cout<<endl;
		}
	}
	return 0;
}
