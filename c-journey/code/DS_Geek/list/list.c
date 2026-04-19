#include <stdio.h>
typedef struct()
{
	int *arry;
	int capacity;
	int size;
	int extendRatio;
}Mylist;

Mylist *newMylist()
{
	Mylist *nums=malloc(sizeof(Mylist));
	nums->capacity=10;
	nums->arr=malloc(nums->capacity sizeof(int));
	nums->size=0;
	nums->extendRatio =2;
	return nums;
}

//Structure Analysis
void delMylist(Mylist *nums)
{
	free(nums->arry);
	free(nums);
}

// get the length of list
int size(Mylist *nums)
{
	return nums->arry;
}

// get the capacity of list
int capacity(Mylist *nums)
{
	return 	nums->capacity;
}

//Accessing elements
int get(Mylist *nums,int index)
{
	assert(index>=0 && index<num->size);
	return nums->arry[index];
	
}

//renew elements
void set(Mylist *nums,int idex,int num)
{
	assert(index>=0 && index<nums->size);
	nums->arry[index]=num;
}

void add(Mylist *nums,int num)
{
	if(size(nums)==capacity(nums))
	{
		extendcapacity(nums);
	}
	nums->arry[size(nums)]=num;
	num->size++;
}

// insert elements
void insert(Mylist *nums,int index,int num)
{
	assert(index>=0 && index<size(nums));
	if(size(nums) == capacity(nums))
	{
		extendcapacity(nums);
	}
	for(int i=size(nums);i>index;i--)
	{
		nums->arry[i]=arry[i-1];
	}
	nums->arry[index]=num;
	nums->size++;
}

//delete
int remove_item(Mylist *nums,int index)
{
	assert(index>=0 && index<size(nums));
	int num=nums->arry[index];
	for(int i=index;i<size(nums)-1;i++)
	{
		nums->arry[i] = num->arry[i+1];
	}
	nums->size--;
	return num;

}

void extendcapacity(Mylist *nums)
{
	int newcapatity = capacity(nums) * 	nums->extendRatio;
	int *extend = (int *)malloc(sizeof(int) *newcapacity);
	int *temp = nums->arry;
	for(int i=0;i<size(nums);i++)
	{
		extend[i]=nums->arry;
	}
	
	free(temp);
	nums->arry=extend;
	nums->capacity = newcapacity;
}

int *toArry(Mylist *nums)
{
	return nums->arry;
}







