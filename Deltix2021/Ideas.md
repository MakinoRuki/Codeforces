B. n个数两两配对，假设i<j,(a[i],a[j])->(a[i]+a[j],a[j])->(a[i]+a[j],-a[i])->(a[j],-a[i]-a[j])->(-a[i],-a[i]-a[j])->(-a[i],-a[j])。

C. 用stack当前的答案序列，当数字a[i]!=a[stk.back()]+1的时候pop。

