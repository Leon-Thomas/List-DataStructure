#include <stdio.h>
#include "List.h"

int main()
{
	List list,list2;
	float d;
	float *f=NULL;
	int i=0;

	listInit(&list);
	listInit(&list2);

	printf("请输入5个数据：\n");
	
	for(int i = 0;i < 5;++i)
	{
		scanf("%f",&d);
		listInsert(&list,i,(void *)&d,sizeof(d));
	}
	for(int i = 0;i < 5;++i)
		printf("%f ",(*(float*)listGet(&list,i)));
	putchar('\n');

	printf("Enter a data to Append:");
	scanf("%f",&d);
	printf("list append:\n");
	listAppend(&list,&d,sizeof(d));
	f=NULL;
	i=0;
	while((f=(float *)listGet(&list,i))!=NULL)
	{
		printf("%f ",*f);
		++i;
	}
	printf("\n-----------------------\n");

	printf("Enter a data and id to insert:");
	scanf("%f%d",&d,&i);
	listInsert(&list,i,&d,sizeof(d));
	printf("list inserted:\n");

	f=NULL;
	i=0;
	while((f=(float *)listGet(&list,i))!=NULL)
	{
		printf("%f ",*f);
		++i;
	}

	printf("\n-----------------------\n");

	printf("Enter a data to delete:");
	scanf("%f",&d);
	printf("After Delete...\n");

	listDelByData(&list,&d,sizeof(d));


	f=NULL;
	i=0;
	while((f=(float *)listGet(&list,i))!=NULL)
	{
		printf("%f ",*f);
		++i;
	}
	printf("\n-----------------------\n");
	printf("Enter a data and id to modify:");
	scanf("%f%d",&d,&i);
	listSet(&list,i,&d,sizeof(d));
	f=NULL;
	i=0;
	while((f=(float *)listGet(&list,i))!=NULL)
	{
		printf("%f ",*f);
		++i;
	}




	putchar('\n');

	destroyList(&list);

	return 0;
}

