/* 
 * Bradley Taniguchi
 *
 * CFork-OpSys341
 * Operating Systems 341
 * Dr. Bin Tang
 * 02/17/16
 */

#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h> //include wait
#include <stdlib.h>
#include <unistd.h>
#include "headers.h"

int main(int argc, char** argv) { //only takes integer char
    if (argc == 1) {
        printf("Not Enough Arguments!\n"
                "Give a list of integers as arguments to get data about them!\n");
        return 1; //exit Program
    }
    else {
        //remove ./main.o from arguments
        argc = argc - 1;
        argv = argv + 1;// think this works
        int i, len;
        int myArray[argc]; //create array to work on
        for(i=0; i < argc; i++) {
            //if (argv[i]) //check if integer, else dont add to new array
            myArray[i] = atoi(argv[i]);
            len++; //new array length after checking
        }
        pid_t pid = getpid();
        if (fork() != 0) { //in parent
            awesomePrompt();
            printarray(argc, myArray);
            wait(NULL); //wait for children 
        }
        else { //Start child
            if (fork() !=0) { //Still in child
                getMin(argc, myArray);
                wait(NULL);
            }
            else { //Start child-child
                if (fork() !=0) { //Still in child-child
                    getMax(argc, myArray);
                    wait(NULL); //wait for children
                }
                else { //Start child-child-child
                    getAvg(argc, myArray);
                }//end child-child-child
            }//end child-child
        }// end child
        if(pid == getpid()) { //we are THE parent
            printf("\n\n");
        }
    }
    return 0;
}
