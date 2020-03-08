/*
 *文件位置指针演示
 */
#include <stdio.h>
 int main()
 {
	 FILE *p_file = fopen("a.txt","rb");
	 if(p_file)
	 {
		 fseek(p_file,2,SEEK_SET);
		 printf("位置指针在%ld\n",ftell(p_file));
		 fseek(p_file,1,SEEK_CUR);
		 printf("现在位置指针在%ld\n",ftell(p_file));
		 fseek(p_file,1,SEEK_END);
		 printf("再次移动后的文件位置指针是%ld\n",ftell(p_file));
		 fclose(p_file);
		 p_file = NULL;
	 }

	 return 0;
 }

