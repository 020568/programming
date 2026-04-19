#define MAXSIZE    10000
typedef struct 
{
	char no[20];
	char name[50];
	float price;
	
}Book;
typedef struct
{
	Book *elem;
	int length;
	
}SqList;


Sqlist L;



Status InitList(Sqlist,&L)
{
	L.elem=new ElemType[MAXSIZE];
	if (L.elem) exit (OVERFLOW);
	L.length=0;
	return OK;
}

Status Getelem(Sqlist L,int i ,ElemType &e)
{
	if (i<1||i>L.length) return ERROR;
	e=L.elem[i-1];
	return OK;
}

int LocateElem(Sqlist,L,ElemType e)
{
	for (i=0;i<L.length;i++)
		if (L.elem[i]==e) return i+1;
	
	return 0;
	
}






















