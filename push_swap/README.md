# push_swap: Optimal sorting with two deque

### Mandatory

- ```a```, ```b``` 2개의 스택(덱)이 있다.
- n개의 중복되지 않는 integer를 인자로 받는다. 받은 인자들은 a에 넣어진다.
- 주어진 명령어들을 이용하여 결과적으로 '''a'''에 수들이 오름차순 정렬되도록 한다.
- 만점 기준 (n개의 interger를 정렬하는 최악의 경우 operation의 횟수)
	- n: 3일 때, opers: 3 이하
	- n: 5일 때, opers: 12 이하
	- n: 100일 때, opers: 700 이하
	- n: 500일 때, opers: 5500 이하

### Bonus: checker
- n개의 integer를 인자로 받는다.
- STDIN으로 명령어들을 순차적으로 받는다. EOF 시 ```a```에 수들이 오름차순 정렬되어있으면 OK, 아니라면 KO를 출력하고 종료한다.

### Operations
> - ```sa``` (swap a): Swap the first 2 elements at the top of stack a.  
> Do nothing if there is only one or no elements.  
> - ```sb``` (swap b): Swap the first 2 elements at the top of stack b.  
> Do nothing if there is only one or no elements.  
> - ```ss``` : sa and sb at the same time.  
> - ```pa``` (push a): Take the first element at the top of b and put it at the top of a.  
> Do nothing if b is empty.  
> - ```pb``` (push b): Take the first element at the top of a and put it at the top of b.  
> Do nothing if a is empty.  
> - ```ra``` (rotate a): Shift up all elements of stack a by 1.  
> The first element becomes the last one.  
> - ```rb``` (rotate b): Shift up all elements of stack b by 1.  
> The first element becomes the last one.  
> - ```rr``` : ra and rb at the same time.  
> - ```rra``` (reverse rotate a): Shift down all elements of stack a by 1.  
> The last element becomes the first one.  
> - ```rrb``` (reverse rotate b): Shift down all elements of stack b by 1.  
> The last element becomes the first one.  
> - ```rrr``` : rra and rrb at the same time.  

### How to use
- ```make``` to mandatory part  
  ```./push_swap [integers]```
- ```make bonus``` to bonus part (checker)  
```./checker [integers]```  
```STDIN: type operations```

### Examples

```bash
$ ./push_swap 0 1 2
$
```

```
$ ./push_swap 2 1 0
sa
rra
$
```

```
./push_swap 0 3 2 8
pb
ra
pb
ra
pa
pa
$
```

```
$ ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG
OK
$
```