# Push_Swap
This project will make you sort data on a stack, with a limited set of instructions, using the lowest possible number of actions.
Available : 2 stacks and a set of instructions to manipulate both stacks.

Checker:
The program checker takes integer arguments and reads instructions on the standard output. Once read, checker executes them and displays OK if integers are sorted. Otherwise, it will display KO.

Push_swap:
This program calculates and displays on the standard output the smallest progam using Push_swap instruction language that sorts integer arguments received.

## Operations list

sa    : Swap a - swap the first 2 elements at the top of stack a.
        Do nothing if there is only one or no elements).
sb    : Swap b - swap the first 2 elements at the top of stack b.
        Do nothing if there is only one or no elements).
ss    : sa and sb at the same time.

pa    : Push a - take the first element at the top of b and put it
        at the top of a. Do nothing if b is empty.
pb    : Push b - take the first element at the top of a and put it
        at the top of b. Do nothing if a is empty.

ra    : Rotate a - shift up all elements of stack a by 1. The first
        element becomes the last one.
rb    : Rotate b - shift up all elements of stack b by 1. The first
        element becomes the last one.
rr    : ra and rb at the same time.

rra   : Reverse rotate a - shift down all elements of stacka by 1.
        The last element becomes the first one.
rrb   : Reverse rotate b - shift down all elements of stackb by 1.
        The last element becomes the first one.
rrr   : rra and rrb at the same time.

```
./push_swap [list_of_numbers] | ./checker [list_of_numbers] 
```
## Generate random numbers
```
`ruby -e "puts (1..50).to_a.shuffle.join(' ')"`
```

## Options
Visual with -visual
```
./push_swap -visual [list_of_numbers]
```
Print stack a and b with -print
```
./push_swap -print [list_of_numbers]
```
Try operations in a shell with -shell
```
./checker -shell [list_of_numbers]
```

### Push_swap
![alt text](https://github.com/vomnes/push_swap/blob/master/screenshot/push_swap.png "Push_swap")

### Shell
![alt text](https://github.com/vomnes/push_swap/blob/master/screenshot/shell.png "Shell")

### Visual
![alt text](https://github.com/vomnes/push_swap/blob/master/screenshot/visual.png "Visual")