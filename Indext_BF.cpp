#include <iostream>
#include <cstdio>

using namespace std;

#define MAXSIZE 255
#define OK 1
#define ERROR 0

typedef int Status;

typedef struct {
	char ch[MAXSIZE + 1];
	int length;
}SString;

Status InitString(SString& str)
{
	str.length = 0;
	for (int cnt = 0; cnt < MAXSIZE + 1; cnt++) {
		cin >> str.ch[cnt];
		if (str.ch[cnt] == 'z') break;
		str.length++;
	}
	return OK;
}

int index_BF(SString S, SString T)
{
	//定义两个指针
	int i = 1, j = 1;
	while (i < S.length && j < T.length) {
		if (S.ch[i] == T.ch[j]) {
			i++;
			j++;
		}
		else {
			i = i - j + 2;
			j = 1;
		}
	}

	if (j == T.length) return i - T.length + 1;
	return 0;
}

int main(void)
{
	SString S, T;
	InitString(S);
	InitString(T);
	cout << index_BF(S, T) << endl;
	cin.get();
	return 0;
}
