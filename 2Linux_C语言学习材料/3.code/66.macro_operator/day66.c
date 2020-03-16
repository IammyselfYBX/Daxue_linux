/*
 *宏操作符演示
  */
#include <stdio.h>
#define STR(n) #n
#define LOCAL(n) l_##n
  int main()
  {
	  printf("STR(abc)是%s\n",STR(abc));
	  int LOCAL(num) = 111;
	  printf("%d\n",LOCAL(num));
	  return 0;
  }
// gcc -E 
// int main()
//   {
//    printf("STR(abc)是%s\n","abc");
//    int l_num = 111;
//    printf("%d\n",l_num);
//    return 0;
//   }