
//InitList(&L) ����ʼ���� 
//DestoryList(&L):���٣��ͷŴ洢�ռ�
//ListInsert(&L,i,e):����������ڱ�L�е�i��λ�ò���e
//ListDelete(&L,i,e):ɾ������ 
//LocateElem(L,e) :��ֵ���� 
//GetElem(L,i):��λ���� 
//Length(L):��� 
//PrintList(L):����� 
//Empty(L):�пղ������գ�true�� 
//&��ʾ��Ҫ���޸ĺ�ı�������ȥ
//sizeof(e):e�Ĵ�С 

#include<stdio.h>
#define MaxSize 10

//-------���Ա�ľ�̬����˳��洢�ṹ---- 
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

//-------���Ա�Ķ�̬����˳��洢�ṹ---- 
//typedef struct{
//	int *data;		//��ų�ʼλ�õ�ָ��
//	int length;		//��ǰ���� 
//	int listsize;	//��ǰ�洢���� 
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
////���Ӷ�̬���鳤��
//void IncreaseSize(SqList L,int len){
//	int *p=L.data;			//����һ��ָ��ָ������ʼλ��
//	L.data=(int *)malloc((L.listsize+len)*sizeof(int));		//��������ռ� 
//	//����ԭʼ���� 
//	int i;
//	for (i=0;i<L.length;i++){
//		L.data[i]=p[i];
//	}
//	L.listsize+=len;			//���ı�ĳ��� 
//	free(p);					//�ͷ�ԭ���Ŀռ� 
//} 

















int main(){
	SqList L;
	InitList_STATE(L);
//	InitList_dynamic(L);
//	IncreaseSize(L,5);


} 
