A. 把2都乘到去掉2之后最大的奇数上。

B. 每次只看修改位置前后5个位置的"abc"串改变即可。

C. 按照i%e分类，然后每个i找到右边第一个素数位置为l，以及这个素数右边第一个大于1的位置为r，那么l<=i+e*k<r。

D. 并查集。找到合并后最大集合。如果有剩余操作可以按照size排序后合并集合。
