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
- ```%.[precision]``` 소수점 자릿수 결정
- ```%#``` x, X format specifier와 함께 사용할 경우 맨 앞에 '0x', '0X' 출력
- ```%(공백)``` 출력값이 양수일 때 맨 앞에 공백 기호 출력
- ```%+``` 출력값이 양수일 때 맨 앞에 '+' 기호 출력
- ```%[width]``` 출력값의 최소 폭 지정. 출력값이 최소 폭보다 작을 경우 공백(or 0) 삽입
