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
#include <stdlib.h>

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
    for(i=1; len > i; i++) {
        //printf(">>> %d, %d",i, arrPtr[i]); 
        if (arrPtr[i] < min) {
            min = arrPtr[i];
        }
    }
    fflush(stdout);
    printf("Min value: %d\n", min); //print out min value
}
void getMax(int len, int* arrPtr) {
    int max = *arrPtr;
    int i;
    for(i=1; len >= i; i++) {
        if (arrPtr[i] < max) {
            max = arrPtr[i];
        }
    }
    fflush(stdout);
    printf("Max value: %d\n", max); 
}
void getAvg(int len, int* arrPtr) {
    fflush(stdout);
    printf("Avg value: 0\n");
}
void printarray(int len, int* array) {
    int i;
    printf("i   Integer\n");
    for (i=0; i < len; i++) {
        printf("%d = %d\n", i+1, array[i]);
    }
}
int main(int argc, char** argv) { //only takes integer char
    printf("---CFork-OpSys341---\n\n");
    if (argc == 1) {
        printf("Not Enough Arguments!\n"
                "Give Array of integers to get data about them!\n");
        return 1; //exit Program
    }
    else {
        //remove ./main.o from arguments
        argc = argc - 1;
        argv = argv + 1;// think this works
        int i;
        int myArray[argc]; //create array to work on
        for(i=0; i < argc; i++) {
            myArray[i] = atoi(argv[i]);
        }
        pid_t pid = getpid();
        printarray(argc, myArray);
        if (fork() != 0) { //in parent
          wait(NULL); //wait for children 
        }
        else { //in child
            if (fork() !=0) { // back in FIRST child
                getMin(argc, myArray);
            }
            else { //in child-child
                if (fork() !=0) { //child-child
                    getMax(argc, myArray);
                }
                else { //child-child-child
                    getAvg(argc, myArray);
                }//end child-child-child
            }//end child-child
        }// end child
        //printf("Waiting for Children\n");
        if(pid == getpid()) { //we are parent
            printf("\n---CFork-OpSys341---\n");
        }
    }
    return 0;
}
