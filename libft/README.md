*This project has been created as part of the 42 curriculum by seukim.*

## Description
이 프로젝트의 목표는 표준 C 라이브러리의 주요 함수들을 직접 구현하고, 향후 과제에서 사용할 다양한 함수들을 포함한 나만의 라이브러리를 만드는 것입니다.

## Detailed Description
이 라이브러리는 다음과 같은 파트로 구성되어 있습니다.

### Part 1: Libc Functions
표준 C 라이브러리(libc)의 함수들을 재구현한 파트입니다.

| 분류 | 함수 목록 |
| :--- | :--- |
| **메모리 제어** | `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`, `ft_memchr`, `ft_memcmp`, `ft_calloc` |
| **문자 확인** | `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint` |
| **문자열 조작** | `ft_strlen`, `ft_strlcpy`, `ft_strlcat`, `ft_strchr`, `ft_strrchr`, `ft_strncmp`, `ft_strnstr`, `ft_strdup` |
| **변환 및 대소문자** | `ft_toupper`, `ft_tolower`, `ft_atoi` |

### Part 2: Additional Functions
문자열 가공 및 출력을 위해 추가적으로 구현한 유틸리티 함수들입니다.

| 분류 | 함수 목록 |
| :--- | :--- |
| **문자열 가공** | `ft_substr` (부분 문자열), `ft_strjoin` (결합), `ft_strtrim` (공백 제거), `ft_split` (문자열 분할) |
| **문자 변환** | `ft_itoa` (숫자를 문자열로), `ft_strmapi`, `ft_striteri` |
| **출력 함수** | `ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd` |

### Part 3: Linked List
연결 리스트(Linked List)를 다루기 위한 함수들입니다.

- **기본 조작**: `ft_lstnew`, `ft_lstadd_front`, `ft_lstsize`, `ft_lstlast`, `ft_lstadd_back`
- **삭제 및 순회**: `ft_lstdelone`, `ft_lstclear`, `ft_lstiter`, `ft_lstmap`

## Instructions
이 프로젝트는 `Makefile`을 통해 빌드됩니다. 터미널에서 다음 명령어들을 사용할 수 있습니다.

### 빌드 및 컴파일 (Linux)

# Part 1, 2, 3 함수 컴파일 및 libft.a 생성
make

# 생성된 object 파일(.o) 삭제
make clean

# 모든 빌드 결과물 삭제
make fclean

# 재빌드 (fclean 후 make)
make re

# Resources
Documentation: Linux Manual Pages (man) - 표준 함수들의 공식 사양 참고

AI Usage:

README 작성: 프로젝트 설명 및 마크다운 구조 최적화를 위해 AI를 사용하였습니다.

코드 로직 검토: ft_split 및 ft_strnstr과 같은 복잡한 함수의 예외 처리 케이스를 검토하는 용도로 활용되었습니다.

Makefile 작성 시 발생한 규칙 충돌 문제를 해결하기 위한 가이드로 사용되었습니다.