# CFork-OpSys341
Bradley Taniguchi
C Programming Project for Operating Systems 341.

####INSTRUCTIONS
1. compile with `make` or `gcc main.c -o main.o`
2. `./main.o <integers to sort>`
    for example: `./main.o 1 2 3 4 5`
    Will give the following output:
`/ ____|  ____|       | |   
| |    | |__ ___  _ __| | __
| |    |  __/ _ \| '__| |/ /
| |____| | | (_) | |  |   < 
 \_____|_|  \___/|_|  |_|\_\

o:::::::::::::::::
o:::Data given::::
o:::i = Integer:::
o:::1 = 1:::::::::
o:::2 = 2:::::::::
o:::3 = 3:::::::::
o:::4 = 4:::::::::
o:::5 = 5:::::::::
o:::::::::::::::::

Min value: 1
Max value: 5
Avg value: 3.000000
`
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
