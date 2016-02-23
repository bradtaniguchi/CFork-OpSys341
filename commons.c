/* Bradley Taniguchi
 * Common Code between the two main programs
 */
#include <stdio.h>
#include <unistd.h> 

struct thread_args { // to allow single argument pass to get functions
    int len;
    int *arrPtr;
};

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
        if (arrPtr[i] < min) {
            min = arrPtr[i];
        }
    }
    fflush(stdout);
    printf("Min value: %d\n", min); //print out min value
}
void getMax(int len, int* arrPtr) {
    int max = arrPtr[0];
    int i;
    for(i=1; len > i; i++) {
        if (arrPtr[i] > max) {
            max = arrPtr[i];
        }
    }
    fflush(stdout);
    printf("Max value: %d\n", max); 
}
void getAvg(int len, int* arrPtr) {
    float avg;
    int i, total = 0;
    for(i=0; len > i; i++) {
        total += arrPtr[i]; //add all values into total
    }
    avg = (total/len);

    fflush(stdout);
    printf("Avg value: %f\n", avg);
}
void printarray(int len, int* array) {
    int i;
    printf("o:::::::::::::::::\n");
    printf("o:::Data given::::\n");
    printf("o:::i = Integer:::\n");
    for (i=0; i < len; i++) {
        printf("o:::::::::::::::::\r");
        printf("o:::%d = %d\n", i+1, array[i]);
    }
    printf("o:::::::::::::::::\n\n");
}
void awesomePrompt() {
    printf("\n  _____ ______         _\n");    
    printf(" / ____|  ____|       | |   \n");
    printf("| |    | |__ ___  _ __| | __\n");
    printf("| |    |  __/ _ \\| '__| |/ /\n");
    printf("| |____| | | (_) | |  |   < \n");
    printf(" \\_____|_|  \\___/|_|  |_|\\_\\\n\n");
}
void *getMinThread(void *StructPtr) {
    /*Sadly threads are to dumb to use more than 1 argument. 
    * So I need to use the struct to pass more than 1 argument
    * This means I need 3 more NEW functions to wrap around the old ones
    * as C ALSO doesn't naturally allow function overloading :/
    */
    struct thread_args *args = StructPtr; 
    int mylen = args->len;
    int *myarrPtr = args->arrPtr;
    getMin(mylen, myarrPtr);
}
void *getMaxThread(void *StructPtr) {
    struct thread_args *args = StructPtr;
    int mylen = args->len;
    int *myarrPtr = args->arrPtr;
    getMax(mylen, myarrPtr);
}
void *getAvgThread(void *StructPtr) { 
    struct thread_args *args = StructPtr;
    int mylen = args->len;
    int *myarrPtr = args->arrPtr;
    getMax(mylen, myarrPtr);
}

