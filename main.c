/* 
 * Bradley Taniguchi
 *
 * CFork-OpSys341
 * Operating Systems 341
 * Dr. Bin Tang
 * 02/17/16
 */

#include <stdio.h>
#include <unistd.h> 
#include <sys/types.h>
#include <sys/wait.h> //include wait

void pidTest() { 
    // Show the pid, getpid and getppid
    printf("================\n");
    printf("getppid: %d\n", getppid());
    printf("getpid: %d\n", getpid());
    printf("================\n");
}
int getMin(int len, int* arrPtr) {
    return -1;    
}
int getMax(int len, int* arrPtr) {
    return -1;
}
int getAvg(int len, int* arrPtr) {
    return -1;
}
int main(int argc, int* argv) { //only takes integer char
    printf("---InMain---\n\n");
    if (argc == 1) {
        printf("Not Enough Arguments!\n");
        return 0; //exit Program
    }
    else {
        if (fork() != 0) { //in parent
            printf("PARENT\n");
            pidTest();
        }
        else { //in child
            if (fork() !=0) { // back in FIRST child
                printf("CHILD1\n");
                pidTest();
            }
            else { //in child-child
                if (fork() !=0) { //child-child
                    printf("CHILD2\n");
                    pidTest();
                }
                else { //child-child-child
                    printf("CHILD3\n");
                    pidTest();
                }
            }//end child-child
        }// end child
        printf("Waiting for Children\n");
        return 0;//end parent
    }
}
