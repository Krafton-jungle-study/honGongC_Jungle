# CH17 사용자 정의 자료형

## 구조체 (struct)

## 용도

- 형태가 서로 다른 변수들을 묶음
- 이후 변수처럼 변수, 배열, 포인터로 활용 가능

## 크기

- 바이트 얼라인먼트 - 데이터를 읽고 쓰는 시간을 아낄 수 있다?
    - 패딩 바이트
        - `#pragma pack(1)` 으로 바이트 얼라인먼트를 1로 설정 할 수 있다.
    - 배열이나 구조체가 멤버일 때는, 패딩 바이트가 훨씬 커질까?
- 멤버의 순서에 따라 구조체의 크기가 달라질 수 있다!

## 특징

### 멤버

- 이미 설정된 다른 타입, 배열, 포인터
- 다른 구조체도 사용 가능 (먼저 선언된 구조체만 쓸 수 있다.)

### 초기화

- 밖에서 하면 전역변수이므로, 따로 초기화 안하면 전체 0이다.

### 함수 전달

- 매개변수 전달과 반환시 , 구조체의 모든 멤버들이 복사되어 전달됨
- 함수에 묶어서 넣은 다음 반환 받으면, 안쪽의 값끼리 교환도 가능
- 구조체를 포인터로 넘겨줄 수도 있다.

### 자기참조 구조체 (미쳤다!)

- 연결리스트 - 구조체 변수를 포인터로 연결한 것
    
    ```c
    //연결 리스트끼리 연결해준다.
    //head가 연결리스트의 처음을 가리킨다.
    //current가 요소를 따라가게 하는게 좋다.
    
    //끝을 검사하는 문법
    ```
    

## 문법

### 기본 - 선언, 초기화, 접근, 복사

```c
//선언
struct strt1{
	char ch[10];
	char *str;
	struct strt2 ostrt; //다른 구조체도 멤버로 가능
};

//초기화
struct strt1 s1={"홍","길",{"동"}};  //strt2 에 다른 테이터형이 있는 경우 대입 가능

//선언과 동시에 초기화
struct strt3{
	char ch[10];
}s2 = {"초기화"};

//접근
s1.str = "string";

//복사
struct strt s3;
s3 = s1;
```

### 구조체 포인터

- `.` 연산자는 우선순위가 높음에 유의

```c
struct strt{ char ch[20] }s = {"문자열"};
struct strt *ps = &s;  // strt 구조체를 가리키는 포인터

printf("%s",(*ps).ch); //주소로 접근한 후 멤버 접근
printf("%s",ps->ch); //포인터로 멤버 접근
```

- `->` : 간접 멤버 접근 연산자
- `ps->mem` = `(*ps).mem` (ps 가 구조체 포인터일 때)

### 구조체 배열

```c
struct strt{char ch[10];};

//초기화
struct strt list[5] = {
	{""},{""},{""},{""},{""}
},

//접근
printf("%s",list[i].ch);
```

### 자기참조 구조체

```c

```

## 공용체 (union)

## 필요성

- 한 변수로 다양한 데이터형을 다룸.  (union; 연합, 단체)
- 메모리가 절약됨
- +동적 할당이 어떤 크기가 올지 모를 때 쓰는거라면, 공용체는 어떤 데이터타입이 올지 모를 때 활용

## 특징

- 모든 멤버가 하나의 저장공간을 사용
    - 다른 멤버에 의해 값 바뀔 수 있음 유의
- 공용체 변수의 크기는 멤버 중에서 가장 크기가 큰 멤버의 크기
- 첫번째 멤버는 `.` 없이 초기화 가능
    - 나머지는 멤버명을 정해서 초기화 해야 함
- + 공용체는 0으로 자동 초기화되지 않는다.

## 문법

```c
union student
{
	int num;
	double grade;
}

union student s1={1} // 초기화시 멤버 명시 안하면 첫번째 멤버로 들어감.
union student s2={.grade=2.0} //두번째 멤버는 . 으로 명시해줘야 함

//불가한 문법
s1 = {1} //선언이 아닐 때 {} 로 초기화
	//배열 처럼 멤버 하나하나에 접근해서 입력해줘야 한다.
printf("%d",s1} // 이상한 값이 나온다. 구조체 이름은 구조체 전체를 가리킨다.
s1 = 1; // 구조체 이름으느 구조체 전체를 가리킨다.
```

## 활용 예

- 유니코드 문자열을 다양한 인코딩으로 변환(*GPT*)
    
    ```c
    #include <stdio.h>
    #include <stdlib.h>
    #include <wchar.h>
    #include <locale.h>
    
    union Encoding {
        char utf8[64];
        char utf16[32];
        char utf32[16];
    };
    
    void convertToUTF8(wchar_t *input, union Encoding *output) {
        wcstombs(output->utf8, input, sizeof(output->utf8));
    }
    
    void convertToUTF16(wchar_t *input, union Encoding *output) {
        swprintf((wchar_t *)output->utf16, sizeof(output->utf16) / sizeof(wchar_t), L"%ls", input);
    }
    
    void convertToUTF32(wchar_t *input, union Encoding *output) {
        swprintf((wchar_t *)output->utf32, sizeof(output->utf32) / sizeof(wchar_t), L"%ls", input);
    }
    
    int main() {
        setlocale(LC_ALL, "");
    
        wchar_t unicodeStr[] = L"안녕하세요"; // 유니코드 문자열
    
        union Encoding utf8Data, utf16Data, utf32Data;
    
        convertToUTF8(unicodeStr, &utf8Data);
        convertToUTF16(unicodeStr, &utf16Data);
        convertToUTF32(unicodeStr, &utf32Data);
    
        printf("UTF-8: %s\n", utf8Data.utf8);
        printf("UTF-16: %ls\n", (wchar_t *)utf16Data.utf16);
        printf("UTF-32: %ls\n", (wchar_t *)utf32Data.utf32);
    
        return 0;
    }
    ```
    

## 열거형 (enum)

- 변수에 저장할 수 있는 **정수값**을 기호로 정의하여 나열 (Enumerate;순서대로 나열하다)

## 활용

- 연관 있는 자료들을 그룹화 함
- 코드를 더 읽기 쉽게 함
- 유지보수가 쉬움

## 문법

```c
enum season {SPRING, SUMMER, FALL, WINTER}; //자동으로 0,1,2,3 로 초기화
enum season ss;
ss = SPRING;

enum season {SPRING=5,SUMMER,FALL=10,WINTER} //초기화 변경 가능(5,6,10,11로 초기화)
```

## typedef

- 형 재정의 (type definition)
- 자료형을 짧고 쉬운 이름으로 사용할 수 있음
- +반복되는 복잡한 자료형을 type화 할 수 있을 듯! → 구조체로 먼저 만들고 typedef하면 됨.

## 필요성

- struct, union의 활용시 키워드 생략 가능
- 기본 자료형도 의미를 갖게 재정의 할 수 있음

## 문법

```c
struct strt
{  //구조체 선언
	
};
typedef struct strt Strt;  //구조체 데이터타입을 Strt 형으로 재정의
Strt s1 = {};  //struct 키워드 없이 선언 가능;

//구조체 선언과 동시에 재정의
typedef struct
{

} Strt;    

//공용체 enum도 같음
typedef union 
{

} Uni;

typedef enum
{

} ENUM;
```

- 구조체 이름을 굳이 쓸 이유가 없다면 선언과 동시에 재정의해도 된다.
- +포인터와 배열의 typedef

```c
typedef char* String;  //포인터는 *를 형 뒤에 서줘야 한다.
typedef char Str[10];  //배열의 크기를 정해서 typedef 할 수 있다.
```

## 궁금한 것

- 왜 구조체 등은 초기화 해주면서, 일반 지역변수,구조체는 자동초기화를 안 해줄까?

## 문제

### 도전 실전 예제