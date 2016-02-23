# CFork-OpSys341
Bradley Taniguchi
C Programming Project for Operating Systems 341.

####INSTRUCTIONS
1. compile with `make` or `gcc cfork.c -o cfork.o && gcc cthread.c -o cthread.o`
2. `./main.o <integers to sort>`
    for example: `./main.o 1 2 3 4 5`
    Will give the following output:  

Min value: 1
Max value: 5
Avg value: 3.000000

####Screenshot
![Screenshot of Output] (/screenshots/screenshot3.png?raw=true)

####Prompt

 C program that calculates various statistical values for a list of numbers. This program will be passed a 
series of numbers on the command and will then create three separate processes. One process will 
determine the average of the numbers, the second will determine the maximum value, and the third
will determine the minimum value. For example, suppose your program is passed the integers

90 81 78 95 79 72 85

The program will report

The average value is 82

The minimum value is 72

The maximum value is 95

#####PART 2: 
Do the same as above, but using pthread
