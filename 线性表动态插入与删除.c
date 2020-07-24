
#include <stdio.h>

#include <stdlib.h>

 

#define LIST_INIT_SIZE    5    //���Ա��ʼ����

#define LISTINCREMENT    5    //���Ա�ÿ�����䳤��

 

#define OK                1

#define ERROR            0

 

//���Ա�ṹ��

typedef struct {    
    int *elem;				//Ԫ���׵�ַ 
    int len;				//���� 
    int size;				//��С 

}SqList;

 

//��ʼ�����Ա�

int InitList_Sq(SqList *L){

    //ʹ��malloc����������һ�������Ĵ洢�ռ�

    L->elem = (int *)malloc(LIST_INIT_SIZE * sizeof(int));

    if(!L->elem)exit(0);

    L->len=0;

    L->size = LIST_INIT_SIZE;

    return OK;

}

 

//�����Ա��в�������

int ListInsert_Sq( SqList *L,int i,int e){

    if(i<1||i>L->len+1) return ERROR;

    if(L->len>=L->size){

        //ʹ��realloc��������ԭ���Ļ���ַ���������Ĵ洢�ռ�

        int *newbase = (int *)realloc(L->elem,(LIST_INIT_SIZE + LISTINCREMENT) * sizeof(int));

        //�������ռ�ʧ�����������

        if(!newbase)exit(0);

        L->size += LISTINCREMENT;

    }

    int *q = &(L->elem[i-1]);

    int *p;

    for(p=&L->elem[L->len-1];p>=q;--p)

        *(p+1)=*p;

    *q=e;

    ++L->len;

    return OK;

}

 

//ɾ�����Ա��е�����

int ListDelete_Sq(SqList *L,int i,int *e){

    if(i<1||i>L->len) return ERROR;

    int *p=&(L->elem[i-1]);

    *e=*p;

    int j;
	//��ɾ��λ���Ժ��Ԫ��ǰ��һλ 
	for(j=i-1;j<=L->len;j++)
		L->elem[j]=L->elem[j+1];
	//���һλ���� 
	L->elem[L->len-1]=0;
	L->len--;

    return OK;

}

 

//������Ա��е�����

int ListShow_Sq(SqList *L,char* s){

    printf("%s",s);

    int i;

    for(i=0;i<L->len;i++){

        printf("%d ",L->elem[i]);

    }

    putchar('\n');

}

 

void main(){

    int i;

    SqList L;

    

    //��ʼ�����Ա�

    InitList_Sq(&L);

    

    //��������

    int n;

    printf("Ԥ�������ԭʼ���ݸ����ǣ�");

    scanf("%d",&n);

    printf("�����Ա���%d��ԭʼ���ݣ�",n);

    for(i=0;i<n;i++){

        int t;

        scanf("%d",&t);

        ListInsert_Sq(&L,L.len+1,t);

    }

    ListShow_Sq(&L,"ԭʼ���ݣ�");

    

    //�������/ɾ������ʱλ�ú���ֵ����

    int s,v;

    

    //�������

    printf("���������ݲ����λ��s ����ֵv ��");

    scanf("%d%d",&s,&v);

    printf("%s",ListInsert_Sq(&L,s,v)?"����ɹ�.\n":"����ʧ��.\n");

    ListShow_Sq(&L,"�����");

    

    //ɾ������

    printf("����������ɾ����λ��s ��");

    scanf("%d",&s);

    if(ListDelete_Sq(&L,s,&v))

        printf("ɾ���ɹ�.ɾ���������ǣ�%d\n",v);

    else

        printf("ɾ��ʧ��.λ������.");

    ListShow_Sq(&L,"ɾ����");

 

    system("pause");

}

