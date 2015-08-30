#pragma once

#define MAXSIZE 1000			//待排顺序表最大长度
typedef int KeyType;
typedef char InforType;
typedef struct {
	KeyType key;
	InforType otherInfo;
}RecType;

typedef struct {
	RecType r[MAXSIZE + 1];
	int length;
}SqList;
