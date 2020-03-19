#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if(3 != argc){
        printf("USE: ./main <src> <target>\n");
        return -1;
    }
    //OPEN src
    int src = open(argv[1], O_RDONLY);
    if(-1 == src){
        perror("OPEN src ERROR");
        return -1;
    }

    //READ
    printf("READING ...\n");
	char buf[1024];
	size_t read_size = sizeof(buf);
	ssize_t readed = read(src,buf,read_size);
	if(readed == -1)
	{
		perror("READ ERROR");
		return -1;
	}

    //OPEN tar  O_CREAT | O_APPEND | O_RDWR
    int tar = open(argv[2], O_WRONLY | O_CREAT | O_EXCL, 0666);
    printf("--------------------------------\n");
    
    if(-1 == tar){
        //如果argv[2]存在
        if(errno != EEXIST){
            perror("OPEN Target ERROR");
            return -1;
        }
        printf("文件%s 已存在，是否覆盖？（y/n) ",argv[2]);
        char y_n = getchar();
        if(y_n != 'Y' && y_n != 'y' ){
            printf("FINISH!\n");
            return 0;
        }
        printf("WRITing ...\n");
        if(readed > 0){
            //O_WRONLY | O_CREAT | O_TRUNC
        	int fd = open(argv[2],O_WRONLY | O_CREAT | O_TRUNC,0666);
            printf("要写入内容：%s\n",buf);
            size_t  towrite = strlen(buf) * sizeof(buf[0]);	//求字符串长度
            ssize_t writed = write(fd, buf, towrite);
            printf("希望写入的字节数：%d，实际写入字节数：%d\n",towrite,writed);
            if(-1 ==writed ){
                perror("WRITE ERROR");
                return -1;
        }
        close(src);
        close(tar);
    }
    printf("--------------------------------\n");
    
    if(tar != -1){
        //WRITE
        //如果argv[2]不存在
        printf("WRITing ...\n");
        if(readed > 0){
            printf("要写入内容：%s\n",buf);
            size_t  towrite = strlen(buf) * sizeof(buf[0]);	//求字符串长度
            ssize_t writed = write(tar, buf, towrite);
            printf("希望写入的字节数：%d，实际写入字节数：%d\n",towrite,writed);
            if(-1 ==writed ){
                perror("WRITE ERROR");
                return -1;
            }
        }
        
        close(src);
        close(tar); 
    }    
    
    return 0;
}