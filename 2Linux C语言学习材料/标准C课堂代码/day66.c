/*
 *宏操作符演示
  */
#include <stdio.h>
#define STR(n) #n
#define LOCAL(n) l_##n
  int main()
  {
	  printf("STR(abc)是%s\n",STR(abc));
	  int LOCAL(num) = 0;
	  printf("%d\n",LOCAL(num));
	  return 0;
  }
