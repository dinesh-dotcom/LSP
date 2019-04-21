#include<stdio.h>
#include<sys/time.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>

int main()
{
	int fd1,fd2,retfd;
	char buf[4096];
	int val;

	fd1=open("/dev/input/event17",O_RDONLY);//mouse
	if(fd1<0){
		perror("Open Fails");
		return -1;
	}
	fd2=open("/dev/input/event3",O_RDONLY); // power button
	if(fd2<0) {
		perror("Open Fails");
		return -1;
	}
	retfd=read(fd1,buf,4096);
	printf("Read return value - fd1 - Mouse :%d\n",retfd);
	if(retfd<0){
		printf("read is failed\n");
		return -1;
		}

	retfd=read(fd2,buf,4096);
	printf("Read return value of fd2 - powerbutton:%d\n",retfd);
	if(retfd<0){
		printf("read is failed\n");
		return -1;
		}
	return 0;
}

