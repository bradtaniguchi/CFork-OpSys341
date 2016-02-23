/* Bradley Taniguchi
 * 
 * CFork-OpSys341
 * Operating Systems 341
 * Dr. Bin Tang
 * 02/17/16
 */
struct thread_args {
    int len;
    int *arrPtr;
}; //structure to be passed to threadtype functions
void pidTest();
void getMin(int len, int* arrPtr);
void getMax(int len, int* arrPtr);
void getAvg(int len, int* arrPtr);
void printarray(int len, int* array);
void awesomePrompt();

void *getMinThread(void *StructPtr);
void *getMaxThread(void *StructPtr);
void *getAvgThread(void *StructPtr);
