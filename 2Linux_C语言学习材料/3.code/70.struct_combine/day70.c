/*
	结构体联系
*/
#include <stdio.h>
#include <string.h>
int main()
{
	typedef struct iphone
	{
		char brand[20];
		char mode[20];
		int price;
	}iphone;
	iphone name = {"iphone","iphone 7",7000};
	printf("品牌是%s\n",name.brand);
	printf("型号是%s\n",name.mode);
	printf("价格是%d\n",name.price);
	return 0;
}
