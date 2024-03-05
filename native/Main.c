#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "Main.h"
#include <util.h>

JNIEXPORT jint JNICALL Java_org_wonjoo_ios_jpty_Main_createPty(JNIEnv *env, jclass clazz) {
    int master, slave;
    char *slavename;
    char *shellname = getenv("SHELL");

    if (openpty(&master, &slave, NULL, NULL, NULL) == -1) {
        perror("openpty");
        exit(EXIT_FAILURE);
    }

    slavename = ttyname(slave);
    printf("master : %d\n", master);
    printf("slave : %d\n", slave);
    printf("slavename : %s\n", slavename);
    printf("SHEEL : %s\n", shellname);


    pid_t pid = fork();
    if(pid == -1){
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if(pid == 0){ // child
        close(master);

        execlp(shellname, shellname, "-i", NULL); // -i 옵션으로 인터렉티브 쉘 실행

        perror("execlp");

        exit(EXIT_FAILURE);
    } else {
        close(slave);

        waitpid(pid, NULL, 0);
    }

    return 0;
}
