#pragma once

#define MAXSIZE 1000			//����˳�����󳤶�
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
