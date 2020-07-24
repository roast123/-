//ListInsert(&L,i,e):����������ڱ�L�е�i��λ�ò���e
//ListDelete(&L,i,e):ɾ������ 

#include<stdio.h>
#define MaxSize 10

//-------���Ա�ľ�̬����˳��洢�ṹ---- 
typedef  struct{
	int data[MaxSize];
	int length;
}SqList;

void InitList_STATE(SqList *L){						//ע�����ָ��L���ڴ浥Ԫ 
	L->length=0;
}
//ƽ��ʱ�临�Ӷ�O(n) 
int InsertList(SqList *L,int i,int e){
	if(i<1 || i>L->length+1) return 0;
	int j;
	//�Ѳ���λ���Ժ��Ԫ�غ���һλ 
	for(j=L->length;j>=i;j--)
		L->data[j]=L->data[j-1];
	L->data[i-1]=e;
	L->length++;
} 
//ƽ��ʱ�临�Ӷ�O(n)
int DelectList(SqList *L,int i,int *e){
	if(i<1 || i>L->length+1) return 0;
	int *p=&(L->data[i-1]); 
	*e=*p;
	int j;
	//��ɾ��λ���Ժ��Ԫ��ǰ��һλ 
	for(j=i-1;j<=L->length;j++)
		L->data[j]=L->data[j+1];
	//���һλ���� 
	L->data[L->length-1]=0;
	L->length--;
	return 1;
}

int main(){
	SqList L;
	InitList_STATE(&L);					//ע������&����ʾȡL�ĵ�ַ 
	int i;
	//��ʼ�����Ա� 
	for(i=0;i<5;i++){
		L.data[L.length]=i;
		L.length++;
	}
	printf("���Ա�Ϊ��");
	for(i=0;i<L.length;i++){
		printf("%d ",L.data[i]);
	}
	printf("\n");
	//����һ��Ԫ�� 
	int e;
	printf("���룺\n");
	scanf("%d%d",&i,&e); 
	InsertList(&L,i,e);
	printf("���Ա�Ϊ��");
	for(i=0;i<L.length;i++){
		printf("%d ",L.data[i]);
	}
	
	printf("���Ա���Ϊ��%d\n",L.length);
	
	//ɾ��һ��Ԫ�� 
	
	scanf("%d",&i); 	 
	DelectList(&L,i,&e);
	printf("ɾ��Ԫ��Ϊ��%d\n",e);
	printf("���Ա�Ϊ��\n");
	for(i=0;i<L.length;i++){
		printf("%d ",L.data[i]);
	}
	printf("���Ա���Ϊ��%d",L.length);
	
	return 0;
} 
