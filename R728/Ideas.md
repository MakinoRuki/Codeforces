B. a[i]*a[j]=i+j。因为i+j一定不会很大因此枚举，然后sqrt分解枚举a[i]和a[j]。

C. 最优解应该是先按照d排序然后相邻两点之间加边边权是delta。然后两两之间加上绝对值为它们最短路的负值反边。
