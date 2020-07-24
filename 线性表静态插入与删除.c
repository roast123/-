//ListInsert(&L,i,e):插入操作。在表L中第i个位置插入e
//ListDelete(&L,i,e):删除操作 

#include<stdio.h>
#define MaxSize 10

//-------线性表的静态分配顺序存储结构---- 
typedef  struct{
	int data[MaxSize];
	int length;
}SqList;

void InitList_STATE(SqList *L){						//注意必须指向L的内存单元 
	L->length=0;
}
//平均时间复杂度O(n) 
int InsertList(SqList *L,int i,int e){
	if(i<1 || i>L->length+1) return 0;
	int j;
	//把插入位置以后的元素后移一位 
	for(j=L->length;j>=i;j--)
		L->data[j]=L->data[j-1];
	L->data[i-1]=e;
	L->length++;
} 
//平均时间复杂度O(n)
int DelectList(SqList *L,int i,int *e){
	if(i<1 || i>L->length+1) return 0;
	int *p=&(L->data[i-1]); 
	*e=*p;
	int j;
	//把删除位置以后的元素前移一位 
	for(j=i-1;j<=L->length;j++)
		L->data[j]=L->data[j+1];
	//最后一位清零 
	L->data[L->length-1]=0;
	L->length--;
	return 1;
}

int main(){
	SqList L;
	InitList_STATE(&L);					//注意必须加&，表示取L的地址 
	int i;
	//初始化线性表 
	for(i=0;i<5;i++){
		L.data[L.length]=i;
		L.length++;
	}
	printf("线性表为：");
	for(i=0;i<L.length;i++){
		printf("%d ",L.data[i]);
	}
	printf("\n");
	//插入一个元素 
	int e;
	printf("插入：\n");
	scanf("%d%d",&i,&e); 
	InsertList(&L,i,e);
	printf("线性表为：");
	for(i=0;i<L.length;i++){
		printf("%d ",L.data[i]);
	}
	
	printf("线性表长度为：%d\n",L.length);
	
	//删除一个元素 
	
	scanf("%d",&i); 	 
	DelectList(&L,i,&e);
	printf("删除元素为：%d\n",e);
	printf("线性表为：\n");
	for(i=0;i<L.length;i++){
		printf("%d ",L.data[i]);
	}
	printf("线性表长度为：%d",L.length);
	
	return 0;
} 
