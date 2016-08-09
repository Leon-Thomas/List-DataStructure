
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <stdbool.h>
#include "List.h"

static Lnode *getNode(List *list,Index i);

void listInit(List *list)
{
	if(list == NULL) return ;
	list->lt_len = 0; 
	list->head	 = NULL;
	list->rear	 = NULL;
}



/*插入一个数据到链表中*/
bool listInsert(List *list,Index i, Data d,size_t dsize)
{
	Index j = i;
	Lnode *pre,*tmp;

	if(list != NULL)
	{
		pre = getNode(list,i-1);
		tmp = (Lnode *)malloc(sizeof(Lnode));
		if(tmp == NULL) return false;
		tmp->data = (Data *)malloc(sizeof(dsize));
		if(tmp->data == NULL) 
		{
			free(tmp);
			return false;
		}
		memcpy(tmp->data,d,dsize);

		if(pre != NULL)
		{
			
			tmp->next = pre->next;
			pre->next = tmp;
			
		}
		else if(i==0)
		{
			tmp->next  = list->head;
			list->head = tmp;

		}
		else
		{
			free(tmp->data);
			free(tmp);
			
			return false;
		}

		if(pre == list->rear)
			list->rear = tmp;

		++list->lt_len;

		return true;
	}

	return false;
}

/*链尾追加一个元素*/
bool listAppend(List *list,Data d,size_t dsize)
{
	Lnode *p,*tmp;

	if(list != NULL)
	{
		p = list->rear;
		tmp = (Lnode *)malloc(sizeof(Lnode));
		if(tmp == NULL) return false;
		tmp->data = (Data)malloc(dsize);
		if(tmp->data == NULL)
		{
			free(tmp);
			return false;
		}
		memcpy(tmp->data,d,dsize);

		if(p != NULL)
		{
			tmp->next = p->next;
			p->next   = tmp;
			list->rear= tmp;
		}
		else
		{
			list->head = tmp;
			list->rear = list->head;
		}

		++list->lt_len;
	}

	return false;
}

/*删除值为d的结点，返回true , false*/
bool listDelByData(List *list,Data d,size_t dsize)
{
	Index i;
	Lnode *p,*tar;
	size_t num;

	if(list !=NULL)
	{
		num = list->lt_len;
		p = list->head;
		i = 0;
		if(list->head != NULL)
		{
			if(memcmp(p->data,d,dsize) == 0)
			{
				list->head = p->next;
				tar = p;
				if(tar == list->rear)
					list->rear = list->head;
			}
			else
			{
				++i;
				while(i < num)
				{
					if(memcmp(p->next->data,d,dsize) == 0)
						break;
					p = p->next;
					++i;
				}
				if(i < num)
				{
					tar		= p->next;
					p->next = tar->next;
					if(tar == list->rear)
						list->rear = p;
				}

			}
			if(i < num)
			{
				free(tar->data);
				free(tar);
				--list->lt_len;

				return true;
			}
		}
	}

	return false;
}

/*删除索引为i的结点，返回true , false*/
bool listDelByIndex(List *list,Index i)
{
	Lnode *pre,*tar;

	if(list != NULL)
	{
		pre = getNode(list,i-1);
		if(pre != NULL)
		{
			tar	= pre->next;
			pre->next = tar->next;
			if(tar == list->rear)
				list->rear = pre;
		}
		else if(list->lt_len != 0 && i == 0)
		{
			tar		   = list->head;
			list->head = tar->next;
			if(tar == list->rear)
				list->rear = list->head;
		}
		else return false;

		free(tar->data);
		free(tar);
		--list->lt_len;

		return true;

	}
	return false;
}

/*返回索引i的值，索引失败返回一个无效的(NULL)数据*/
Data listGet(List *list,Index i)
{
	Lnode *p;

	p = getNode(list,i);
	if(p != NULL)
	{
		return p->data;
	}

	return (Data)NULL;
}

/**/
bool listSet(List *list,Index i,Data d,size_t dsize)
{
	Lnode *p;

	p = getNode(list,i);
	if(p != NULL)
	{
		memcpy(p->data,d,dsize);
		return true;
	}

	return false;
}

/*原地将链表逆序*/
void listReverse(List *list)
{

}

/*回收链表的内存*/
void destroyList(List *list)
{
	Lnode *tar,*p;

	if(list != NULL)
	{
		p = list->head;
		while(p != NULL)
		{
			tar = p;
			p	= p->next;
			free(tar->data);
			free(tar);
		}
		list->lt_len = 0;
		list->head = list->rear = NULL;
	}
}


static Lnode *
getNode(List *list,Index i)
{
	Index j;
	Lnode *p = NULL;


	if(list != NULL)
	{
		p = list->head;
		j = 0;
		while(p != NULL && j < i)
		{
			p = p->next;
			++j;
		}
		if(p == NULL|| j > i) return NULL;
	}

	return p;
}



