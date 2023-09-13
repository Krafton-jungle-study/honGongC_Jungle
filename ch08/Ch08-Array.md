# [DAY7] 08장. 배열

# 08-1. 배열의 선언과 사용

## 배열 선언

## 배열 초기화

- {} 중괄호 사용해서 초기화.
- 처음 선언할 때 초기화 하는 게 아니면 다시 중괄호로 초기화 할 수 없다.

```c
int arr[5]={1,2,3,4,5}
```

---

```c
int arr[5]={1,2,3} // 1,2,3,0,0
```

```c
int arr[1000]={1} // 1,0,0,0, ...
```

![Untitled](%5BDAY7%5D%2008%E1%84%8C%E1%85%A1%E1%86%BC%20%E1%84%87%E1%85%A2%E1%84%8B%E1%85%A7%E1%86%AF%203a5879c74e674c21a358f55b52a5fadd/Untitled.png)

---

```c
int arr[]={1,2,3}
```

---

```c
double arr[5]={1.0,2.1,3.2,4.3,5.4};
char arr[5]={'a','b','c','d','e'};
```

## 배열 반복문

```c
for(int i=0 ; i<count ; i++){
	scanf("%d",&arr[i]);
}
```

## sizeof 연산자로 count 변수 만들기

- `sizeof(배열명)/sizeof(배열요소)`

```c
int arr[10];

int count = sizeof(arr)/sizeof(arr[0]);
```

# 08-2. 문자를 저장하는 char형 배열

```c
char str[4]="yes"; // yes\0

char str2[4];

str2[0]='y';
str2[1]='e';
str2[2]='s';
str2[3]='\0';
```

## 선언과 초기화

### 널 문자

- 끝에 널 문자를 꼭 포함시켜야 함. (scanf, get, strcpy함수 사용 시에는 내장된 기능)
    - 널 문자는 문자열의 끝을 표시한다.

### 초기화

- `char str[4]="yes"` 같은 경우 끝에 널 문자가 자동으로 추가됨.
- 배열 하나씩 초기화하는 경우 끝에 널 문자 반드시 포함해야 하는 것에 주의.

### char형 배열 선언 시 주의할 점

- 문자열의 길이보다 최소한 하나 이상 크게 배열을 선언한다.
- 문자열의 길이가 일정하지 않을 경우, 배열의 크기는 최대한 넉넉하게 선언한다.

```c
char str[100];

scanf("%s",str);

```

### 함수 사용 시 주의할 점

- scanf, get, strcpy 함수 등에서 입력할 배열의 크기를 검사하지 않는다. 배열의 크기보다 긴 문자열을 입력하면 배열을 벗어난 메모리 영역을 침범할 가능성이 있다. 따라서 항상 배열의 크기를 고려해야 한다. 컴파일러에 따라 시스템 안전성 문제로 컴파일을 제한하기도 한다.

## 문자열 대입 함수: strcpy

- `strcpy(복사받을 공간 ... 배열, 복사될 문자열 ... 문자열 상수 또는 배열)`

## 문자열 전용 입출력 함수: gets, puts

- gets: 띄어쓰기가 있어도 한 줄까지 문자열로 입력된다.
- puts: gets와 짝이다.

# 도전 예제 문제

## 대문자를 찾아 소문자로 바꾸는 프로그램 작성하기

- 참고한 블로그

[[C언어/C++] 문자열 대소문자 변환 (toupper, tolower) 함수 사용법 & 예제](https://coding-factory.tistory.com/679)

### 함수 사용한 풀이

- `isupper`: 주어진 문자가 대문자면 1 반환 / 아니면 0 반환
- `islower`: 주어진 문자가 소문자면 1 반환 / 아니면 0 반환

---

- `toupper`: 주어진 문자가 소문자면 대문자로 변환
- `tolower`: 주어진 문자가 대문자면 소문자로 변환

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <ctype.h>

int main(void) {
	
	char str[80] = "";
	int i = 0, count = 0;

	printf("문장 입력: ");
	gets(str);
	printf("바뀐 문장: ");

	while (str[i]) {
		if (isupper(str[i])) {
			count++;
		}
		printf("%c", tolower(str[i]));
		i++;
	}

	printf("\n바뀐 글자 수: ");
	printf("%d", count);

	return 0;
}
```

- `while(str[i])`
    - 널 문자(’\0’)의 아스키 코드 값은 0이다.

### 아스키 코드 값을 사용한 풀이

- 대문자와 소문자 간 아스키 코드 값은 32 차이가 난다.

![출처: [https://stepbystep1.tistory.com/10](https://stepbystep1.tistory.com/10)](%5BDAY7%5D%2008%E1%84%8C%E1%85%A1%E1%86%BC%20%E1%84%87%E1%85%A2%E1%84%8B%E1%85%A7%E1%86%AF%203a5879c74e674c21a358f55b52a5fadd/Untitled%201.png)

출처: [https://stepbystep1.tistory.com/10](https://stepbystep1.tistory.com/10)

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <ctype.h>

int main(void) {

	char str[80] = "";
	int i = 0, count = 0;

	printf("문장 입력: ");
	gets(str);
	printf("바뀐 문장: ");

	while (str[i]) {
		if (str[i]>=65 && str[i]<=90) {
			count++;
		}
		printf("%c", str[i]+32);
		i++;
	}

	printf("\n바뀐 글자 수: ");
	printf("%d", count);

	return 0;
}
```