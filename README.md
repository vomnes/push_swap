# Push_Swap
This project will make you sort data on a stack, with a limited set of instructions, using the lowest possible number of actions.
Available : 2 stacks and a set ofinstructions to manipulate both stacks.

Checker:
The program checker takes integer arguments and reads instructions on the standard output. Once read, checker executes them and displays OK if integers are sorted. Otherwise, it will display KO.

Push_swap:
This program calculates and displays on the standard output the smallest progam using Push_swap instruction language that sorts integer arguments received.

```
./push_swap [list_of_numbers] | ./checker [list_of_numbers] 
```
# Generate random numbers
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
![alt text](https://github.com/vomnes/push_swap/blob/master/map_screenshot/push_swap.png "Push_swap")

### Shell
![alt text](https://github.com/vomnes/push_swap/blob/master/map_screenshot/shell.png "Shell")

### Visual
![alt text](https://github.com/vomnes/push_swap/blob/master/map_screenshot/.png "Visual")