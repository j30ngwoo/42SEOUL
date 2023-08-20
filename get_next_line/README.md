# get_next_line
```c
char *get_next_line(int fd)
```
### Mandatory
> 함수가 호출될 때마다, fd로부터 개행을 기준으로 한 줄씩 읽어 반환한다.  
더 이상 읽을 줄이 없거나, 오류가 발생할 경우 ```NULL pointer```를 반환한다.

### Bonus
> 여러 fd(파일)를 동시에 사용 가능하다. 

### Example
#### Code
```c
#include "get_next_line/get_next_line_bonus.h"
#include <stdio.h>
#include <fcntl.h>
int main()
{
	int fd = open("test", O_RDONLY);
	for (int i = 0; i < 4; i++)
		printf("%s\n", get_next_line(fd));
}
```

#### "test" file
```
Hello
World!
I'm jeongwoo
```

#### Result
```
Hello
World!
I'm jeongwoo
(NULL)
```