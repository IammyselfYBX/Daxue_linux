#include <stdio.h>
#include <dirent.h>
int main()
{
	DIR *dir = opendir("../");
	struct dirent *ent = readdir(dir);
	while(ent/* != NULL*/)
	{
		printf("%s\n",ent->d_name);
		ent = readdir(dir);
	}
	return 0;
}
