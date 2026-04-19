#include <stdio.h>
int sentinel_search(int arry[] , int len , int x)
{
	int i = 0;
	int last = arry[len-1];
	arry[len-1] = x;
	while(arry[i]!=x)
	{
		i++;
    }
    if( (i<len-1) || (arry[len-1]==x))
        return i;
    else return -1;
}



int main(void)
{
	int arry[] = {10, 20, 180, 30, 60, 50, 110, 100, 70};
	int len = sizeof(arry)/sizeof(arry[0]);
	if (len==0)
	{
	    printf("the arry is null");
	    return 0;		
	}
	int flag = sentinel_search(arry,len,110);
	if (flag==-1) printf("the key number is not exist");
	else printf("the index of the key number is:%d",flag);
	
}
