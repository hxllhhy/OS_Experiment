/*************************************************************************
	> File Name: 1.c
	> Author: 
	> Mail: 
	> Created Time: 2018年03月19日 星期一 23时59分48秒
 ************************************************************************/

#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main()
{
    int status;
    puts("start");

    pid_t pid = fork();
    if(pid == -1) {
        perror("创建子进程失败");
        return 1;
    }
    if(pid == -1) {
        puts("I'm child");

        puts("sleep 5s ...");
        sleep(5);
        puts("sleep end");

        printf("子进程pid是%d\n",getpid());
        printf("父进程pid是%d\n",getppid());

        return 0;
    }
    else {
        puts("I'm parent");

        printf("子进程pid是%d\n",pid);
        printf("父进程pid是%d\n",getpid());
    }

    wait(&status);
    printf("%d\n",status);
    puts("main end");
    return 0;
}
