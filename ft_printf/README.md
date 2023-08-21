# ft_printf: Implementation of printf

### Prototype
```c
int ft_printf(const char *, ...);
```

### 🎯Keyword
> Variadic Arguments

#### 1. ```make``` to use several format specifier
- ```%c``` character
- ```%s``` string (char *)
- ```%p``` pointer
- ```%d, %i``` int
- ```%u``` unsigned int
- ```%x, %X``` unsigned hex
- ```%%:``` print '%' sign
#### 2. ```make bonus``` to use format tags ```%[flag][width][.precision]```
- ```%-``` 왼쪽 정렬 (Default == 오른쪽 정렬)
- ```%0``` 오른쪽 정렬 시 공백을 0으로 변환
- ```%.[precision]``` d/x와 사용시 출력될 숫자의 최소값. s와 사용시 출력할 최대 바이트. 
- ```%#``` x, X format specifier와 함께 사용할 경우 맨 앞에 '0x', '0X' 출력
- ```%(공백)``` 출력값이 양수일 때 맨 앞에 공백 기호 출력
- ```%+``` 출력값이 양수일 때 맨 앞에 '+' 기호 출력
- ```%[width]``` 출력값의 최소 폭 지정. 출력값이 최소 폭보다 작을 경우 공백(or 0) 삽입

### How to use
1. ```make``` or ```make bonus``` to build ```libftprintf.a```
2. include ```ft_printf.h``` or ```ft_printf_bonus.h``` in your C file
3. ```gcc [your C files] -L [location of libftprintf.a] -l ftprintf```

### Example

#### Code
```c
#include "bonus_srcs/ft_printf_bonus.h"
int main()
{
	int i = 42;
	char str[] = "hello";
	ft_printf("test\n%-5d\n%05d\n%#X\n%+d\n%.3s\n", i, i, i, i, str);
}
```
#### Result
```
% gcc test.c -L . -l ftprintf
% ./a.out | cat -e           
test$
42   $
00042$
0X2A$
+42$
hel$
```