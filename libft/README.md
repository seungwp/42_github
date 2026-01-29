*This project has been created as part of the 42 curriculum by seukim.*

**Description**
이 프로젝트의 목표는 표준 C 라이브러리의 주요 함수들을 직접 구현하고, 향후 과제에서 사용할 다양한 함수들을 포함한 나만의 라이브러리를 만드는 것입니다.

1. 파트별 함수 구성

**[Part 1]**
메모리 제어: ft_memset, ft_bzero, ft_memcpy, ft_memmove, ft_memchr, ft_memcmp, ft_calloc

문자 확인: ft_isalpha, ft_isdigit, ft_isalnum, ft_isascii, ft_isprint

문자열 조작: ft_strlen, ft_strlcpy, ft_strlcat, ft_strchr, ft_strrchr, ft_strncmp, ft_strnstr, ft_strdup

변환 및 대소문자: ft_toupper, ft_tolower, ft_atoi

**[Part 2]**
문자열 가공: ft_substr (부분 문자열), ft_strjoin (결합), ft_strtrim (공백 제거), ft_split (문자열 분할)

문자 변환: ft_itoa (숫자를 문자열로), ft_strmapi, ft_striteri

출력 함수: ft_putchar_fd, ft_putstr_fd, ft_putendl_fd, ft_putnbr_fd

**[Bonus Part: Linked_List]**
ft_lstnew, ft_lstadd_front, ft_lstsize, ft_lstlast, ft_lstadd_back, ft_lstdelone, ft_lstclear, ft_lstiter, ft_lstmap

2. 빌드 및 컴파일 (Linux)

일반 빌드 : libft 에서 make 명령어를 입력하면 Part 1, Part 2를 포함한 라이브러리를 생성합니다.
보너스 포함 빌드 : make bonus 명령어를 입력 시 Part 3 연결 리스트 함수까지 포함하여 빌드합니다.
정리 : make clean 명령어 입력 시 오브젝트 파일(.o), make fclean은 생성된 라이브러리(libft.a)까지 모두 삭제합니다. make re 명령어 입력 시 모든 파일을 삭제 한 후 처음부터 다시 빌드합니다.