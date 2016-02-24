/* Bradley Taniguchi
 *
 * 02/22/16
 * Part two of CSC341 Programming project 2
 * using pthreads
 */
#include <stdio.h> //For printline
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include "headers.h" //for original functions

int main(int argc, char** argv)  {
    if (argc == 1) {
        printf("Not Enough Arguments!\n"
                "Give a list of integers as arguments to get data about them!\n");
        return -1;
    }
    else {
        argc = argc - 1; 
        argv = argv + 1;
        int i, len, test;
        int myArray[argc];
        for(i=0; i < argc; i++) {
            myArray[i] = atoi(argv[i]);
            len++; //new array length after checking
        }
        pthread_t minthread, maxthread, avgthread; //declare threads
        pthread_attr_t attr;
        struct thread_args *args = malloc(sizeof(args));
        args->len = argc;
        args->arrPtr = myArray;
        pthread_attr_init(&attr);
        awesomePrompt();
        printarray(argc, myArray);

        pthread_create(&minthread, &attr, getMinThread, args);
        pthread_join(minthread, NULL);
        
        pthread_create(&maxthread, &attr, getMaxThread, args);
        pthread_join(maxthread, NULL);

        pthread_create(&avgthread, &attr, getAvgThread, args);
        pthread_join(avgthread, NULL);
    }
    return 0;
}
