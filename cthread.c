/* Bradley Taniguchi
 *
 * 02/22/16
 * Part two of CSC341 Programming project 2
 * using pthreads
 */
#include <stdio.h>
#include "headers.h" //for original functions

int main(int argc, char** argv)  {
    if (argc == 1) {
        printf("Not Enough Arguments!\n"
                "Give a list of integers as arguments to get data about them!\n");
        return -1;
    }
    else {
        pidTest();
    }
    return 0;
}
