/*
	结构体型参和返回值
*/
#include <stdio.h>
typedef struct pt
{
	int x,y;
}pt;
/*pt midpt(pt start,pt end)
{
	pt mid = {};
	mid.x = (start.x + end.x) / 2;
	mid.y = (start.y + end.y) / 2;
	return mid;
}*/
pt *midpt(const pt *p_start,const pt *p_end,pt *p_num)
{
	p_num->x = (p_start->x + p_end->x) / 2;
	p_num->y = (p_start->y + p_end->y) / 2;
	//return &max; 错误，因为生命周期的缘故
	return p_num;

}
int main()
{
	pt max = {},mai = {},min = {};
	printf("请输入一个点的位置:");
	scanf("%d %d",&max.x,&max.y);
	printf("请输入第二个点的位置:");
	scanf("%d %d",&mai.x,&mai.y);
	midpt(&max,&mai,&min);
	printf("中间点的位置是(%d,%d)\n",min.x,min.y);
	return 0;
}




