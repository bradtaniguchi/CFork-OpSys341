/* Bradley Taniguchi
 *
 * 02/22/16
 * Part two of CSC341 Programming project 2
 * using pthreads
 */
#include <stdio.h> //For printline
#include <pthread.h>
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
        test = pthread_create(&minthread, NULL, getMin(int len, int* myArray), NULL);

        //pthread_t thread1;
        // integer1 = pthread_create(&thread1, NULL, print_message_function, (void*) message1)
    }
    return 0;
}
