# Stripe

## 题面翻译

给定一整数n，下面有n个数a[i]，求将该数列分割成两个非空数列且两个数列内数字的和相等的方案数
1<=n<=10^5
a[i]的绝对值不大于10000

Translated by 稀神探女

## 题目描述

Once Bob took a paper stripe of $ n $ squares (the height of the stripe is 1 square). In each square he wrote an integer number, possibly negative. He became interested in how many ways exist to cut this stripe into two pieces so that the sum of numbers from one piece is equal to the sum of numbers from the other piece, and each piece contains positive integer amount of squares. Would you help Bob solve this problem?

## 输入格式

The first input line contains integer $ n $ ( $ 1<=n<=10^{5} $ ) — amount of squares in the stripe. The second line contains $ n $ space-separated numbers — they are the numbers written in the squares of the stripe. These numbers are integer and do not exceed 10000 in absolute value.

## 输出格式

Output the amount of ways to cut the stripe into two non-empty pieces so that the sum of numbers from one piece is equal to the sum of numbers from the other piece. Don't forget that it's allowed to cut the stripe along the squares' borders only.

## 样例 #1

### 样例输入 #1

```
9
1 5 -6 7 9 -16 0 -2 2
```

### 样例输出 #1

```
3
```

## 样例 #2

### 样例输入 #2

```
3
1 1 1
```

### 样例输出 #2

```
0
```

## 样例 #3

### 样例输入 #3

```
2
0 0
```

### 样例输出 #3

```
1
```