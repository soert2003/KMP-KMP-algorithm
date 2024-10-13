#include <iostream>
#include <cstdio>

using namespace std;

#define MAXSIZE 255

//串的顺序存储结构
typedef struct {
	char ch[MAXSIZE + 1];//存储串的一维数组
	int length;//数组长度
}SString;

//暴力查找子串
int index_BF(SString S, SString T) {
	int i = 1, j = 1;
	while (i <= S.length && j <= T.length) {
		if (S.ch[i] == T.ch[j]) {
			i++;
			j++;
		}
		else {
			i = i - j + 2;
			j = 1;
		}
	}
	if (j == T.length + 1) return i - T.length;
	return 0;
}

//求解next数组
void get_next(SString T, int next[])
{
	int i = 1, j = 0;
	next[0] = 0;
	next[1] = 0;
	while (i <= T.length) {
		if (j == 0 || T.ch[i] == T.ch[j]) {
			i++;
			j++;
			next[i] = j;
		}
		else {
			j = next[j];
		}
	}
}

//KMP算法查找子串
int index_KMP(SString S, SString T)
{
	int i = 1, j = 1;
	int size = T.length + 1;
	int* next = new int[size];
	get_next(T, next);
	while (i <= S.length && j <= T.length) {
		if (S.ch[i] == T.ch[j]) {
			i++;
			j++;
		}
		else {
			j = next[j];
		}
	}

}



