# Link Cut Centroids

## 题面翻译

#### 题意

给定一棵节点数为 $n$ 的树 ， 删一条边然后加上一条边 ， 使得该树的重心唯一 。（删掉的边和加上的边可以是同一条）

### 输入格式

第 $1$ 行一个正整数 $T$ ， 表示有 $T$ 组测试数据 ， 其中 $1\le T\le10^4$

对于每组测试数据  。

第 $1$ 行一个正整数 $n$ ， 表示该树有 $n$ 个节点 ， 其中 $3\le n\le 10^5$ 。

第 $2$ 行到第 $n$ 行每行两个正整数 $x,y$ ， 表示 $x$ 到 $y$ 有无一条无向边 ， 其中 $1\le x,y\le n$ 。

### 输出格式

对于每一组测试数据 。

第 $1$ 行两个正整数 $x_1,y_1$ ， 表示删的边的端点为 $x_1,y1$ 。

第 $2$ 行两个正整数 $x_2,y_2$ ， 表示连的边的端点为 $x_2,y_2$ 。

### 限制与约定

对于每个测试点，保证 $\sum{n}\le10^5$。

## 题目描述

Fishing Prince loves trees, and he especially loves trees with only one centroid. The tree is a connected graph without cycles.

A vertex is a centroid of a tree only when you cut this vertex (remove it and remove all edges from this vertex), the size of the largest connected component of the remaining graph is the smallest possible.

For example, the centroid of the following tree is $ 2 $ , because when you cut it, the size of the largest connected component of the remaining graph is $ 2 $ and it can't be smaller.

 ![](https://cdn.luogu.com.cn/upload/vjudge_pic/CF1406C/9a64e191e7d5e53307a96e2436ecb584246a151e.png)However, in some trees, there might be more than one centroid, for example:

 ![](https://cdn.luogu.com.cn/upload/vjudge_pic/CF1406C/c4ed03cd30d398d003584be1653b746383e227d0.png)Both vertex $ 1 $ and vertex $ 2 $ are centroids because the size of the largest connected component is $ 3 $ after cutting each of them.

Now Fishing Prince has a tree. He should cut one edge of the tree (it means to remove the edge). After that, he should add one edge. The resulting graph after these two operations should be a tree. He can add the edge that he cut.

He wants the centroid of the resulting tree to be unique. Help him and find any possible way to make the operations. It can be proved, that at least one such way always exists.

## 输入格式

The input consists of multiple test cases. The first line contains an integer $ t $ ( $ 1\leq t\leq 10^4 $ ) — the number of test cases. The description of the test cases follows.

The first line of each test case contains an integer $ n $ ( $ 3\leq n\leq 10^5 $ ) — the number of vertices.

Each of the next $ n-1 $ lines contains two integers $ x, y $ ( $ 1\leq x,y\leq n $ ). It means, that there exists an edge connecting vertices $ x $ and $ y $ .

It's guaranteed that the given graph is a tree.

It's guaranteed that the sum of $ n $ for all test cases does not exceed $ 10^5 $ .

## 输出格式

For each test case, print two lines.

In the first line print two integers $ x_1, y_1 $ ( $ 1 \leq x_1, y_1 \leq n $ ), which means you cut the edge between vertices $ x_1 $ and $ y_1 $ . There should exist edge connecting vertices $ x_1 $ and $ y_1 $ .

In the second line print two integers $ x_2, y_2 $ ( $ 1 \leq x_2, y_2 \leq n $ ), which means you add the edge between vertices $ x_2 $ and $ y_2 $ .

The graph after these two operations should be a tree.

If there are multiple solutions you can print any.

## 样例 #1

### 样例输入 #1

```
2
5
1 2
1 3
2 4
2 5
6
1 2
1 3
1 4
2 5
2 6
```

### 样例输出 #1

```
1 2
1 2
1 3
2 3
```

## 提示

Note that you can add the same edge that you cut.

In the first test case, after cutting and adding the same edge, the vertex $ 2 $ is still the only centroid.

In the second test case, the vertex $ 2 $ becomes the only centroid after cutting the edge between vertices $ 1 $ and $ 3 $ and adding the edge between vertices $ 2 $ and $ 3 $ .