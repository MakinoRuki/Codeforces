B. 最值只会在前缀和的mx和mn处取得，因此需要维护前缀和的mx和mn。然后当前值可能是a[i]-s,a[i],a[i]+s，用它更新前缀和之后只可能是a[i],a[i]+s,a[i]+2s。所以新的mn=min(a[i],a[i]+2L),mx=max(a[i],a[i]+2R)。

***C. 二分这个代价cost，那么对于每一个i<=cost,最多有cnt[i]<=cost/i，sum{i\*cnt[i]}>=n。找到这个cost之后从大到小枚举i，得到cnt[i]，然后给a[i]暴力填上。***
