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
    fflush(stdout);
    printf("================\n");
    printf("getppid: %d\n", getppid());
    printf("getpid: %d\n", getpid());
    printf("================\n");
}
void getMin(int len, int* arrPtr) {
    int min = arrPtr[0];  //what ever is at the first spot
    int i;
    for(i=1; len >= i; i++) {
        if (arrPtr[i] < min) {
            min = arrPtr[i];
        }
    }
    printf("Min value: %d\n", min); //print out min value
}
void getMax(int len, int* arrPtr) {
    int max = *arrPtr;
    printf("%d\n\n", max);
    int i;
    for(i=1; len >= i; i++) {
        if (arrPtr[i] < max) {
            max = arrPtr[i];
        }
    }
    printf("Max value: %d\n", max); 
}
void getAvg(int len, int* arrPtr) {
    printf("Avg value: \n");
}
int main(int argc, int* argv) { //only takes integer char
    printf("---InMain---\n\n");
    if (argc == 1) {
        printf("Not Enough Arguments!\n"
                "Give Array of integers to get data about them!\n");
        return 1; //exit Program
    }
    else {
        if (fork() != 0) { //in parent
          wait(NULL); //wait for children 
        }
        else { //in child
            if (fork() !=0) { // back in FIRST child
                //printf("CHILD1\n");
                //pidTest();
                getMin(argc, argv);
            }
            else { //in child-child
                if (fork() !=0) { //child-child
                    //printf("CHILD2\n");
                    //pidTest();
                    getMax(argc, argv);
                }
                else { //child-child-child
                    //printf("CHILD3\n");
                    //pidTest();
                    getAvg(argc, argv);
                }//end child-child-child
            }//end child-child
        }// end child
        printf("Waiting for Children\n");
    }
    return 0;
}
