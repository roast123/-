
//InitList(&L) ：初始化表 
//DestoryList(&L):销毁，释放存储空间
//ListInsert(&L,i,e):插入操作。在表L中第i个位置插入e
//ListDelete(&L,i,e):删除操作 
//LocateElem(L,e) :按值查找 
//GetElem(L,i):按位查找 
//Length(L):求表长 
//PrintList(L):输出表 
//Empty(L):判空操作。空：true。 
//&表示需要把修改后的变量带回去
//sizeof(e):e的大小 

#include<stdio.h>
#define MaxSize 10

//-------线性表的静态分配顺序存储结构---- 
typedef  struct{
	int data[MaxSize];
	int length;
}SqList;

void InitList_STATE(SqList L){
	int i;
	for(i=0;i<MaxSize;i++)
		L.data[i]=0;
	L.length=0;
}

//-------线性表的动态分配顺序存储结构---- 
//typedef struct{
//	int *data;		//存放初始位置的指针
//	int length;		//当前长度 
//	int listsize;	//当前存储容量 
//	 
//}SqList; 
//
//void InitList_dynamic(SqList L){
//	L.data=(int *)malloc(MaxSize*sizeof(int));
//	if(!L.data) return 0;
//	L.length=0;
//	L.listsize=MaxSize; 
//}
//
////增加动态数组长度
//void IncreaseSize(SqList L,int len){
//	int *p=L.data;			//定义一个指针指向表的起始位置
//	L.data=(int *)malloc((L.listsize+len)*sizeof(int));		//重新申请空间 
//	//复制原始数据 
//	int i;
//	for (i=0;i<L.length;i++){
//		L.data[i]=p[i];
//	}
//	L.listsize+=len;			//更改表的长度 
//	free(p);					//释放原来的空间 
//} 

















int main(){
	SqList L;
	InitList_STATE(L);
//	InitList_dynamic(L);
//	IncreaseSize(L,5);


} 
