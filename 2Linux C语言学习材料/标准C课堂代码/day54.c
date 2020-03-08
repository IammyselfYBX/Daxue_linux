/*
 *指针运算掩饰
 */
#include <stdio.h>
 int main()
 {
	 int num = 100,num1 = 200;
	 int *p_num = &num1;
	 int arr = 100,arr1 = 1000,*p_arr = &arr,*p_arr1 = &arr1;
	 *p_num = *p_num + num;
	 printf("*p_num是%d\n",*p_num);
	 *p_num = *p_num + num - 200;
	 printf("*p_num for two是%d\n",*p_num);
	 *p_arr = *p_arr1 - *p_arr;
	 printf("arr的值是%d\n",*p_arr);
	 return 0;
 }
