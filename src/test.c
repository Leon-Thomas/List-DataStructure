/*
**文件：test.c
**时间：2016.09.07 17:39:31
**作者：Unknown
**功能：
*/

#include "List.h"
#include <stdio.h>

void test()
{
    int d,t = 5,ret;
    List list;
    listInit(&list);

    scanf("%d",&d);
    listAppend(&list,(Data)&d,sizeof(int));
    listDelByData(&list,(Data)&d,sizeof(int));

    scanf("%d",&d);
    listAppend(&list,(Data)&d,sizeof(int));
    listDelByData(&list,(Data)&d,sizeof(int));

    scanf("%d",&d);
    listAppend(&list,(Data)&d,sizeof(int));
    ret = listDelByData(&list,(Data)&t,sizeof(int));
    printf("ret=%d\n",ret);

}
int main()
{ 
    test();
    return 0;
}
