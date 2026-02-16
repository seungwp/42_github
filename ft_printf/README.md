*This project has been created as part of the 42 curriculum by seukim.*

## Description

**ft_printf** 프로젝트는 C 표준 라이브러리 함수인 `printf`를 직접 재구현하는 프로젝트입니다.

이 프로젝트의 주요 목표는 C언어의 **가변 인자(Variadic Functions)** 개념을 익히고, 서식 지정된 출력이 저수준에서 어떻게 처리되는지 깊이 있게 이해하는 것입니다.

본 함수는 실제 `printf`의 동작을 모방하며, 다음과 같은 서식 지정자를 지원합니다:

- `%c` : 단일 문자 출력
- `%s` : 문자열 출력
- `%p` : `void *` 포인터 인자를 16진수 형식으로 출력
- `%d` / `%i` : 부호 있는 10진 정수 출력
- `%u` : 부호 없는 10진 정수 출력
- `%x` : 16진수 소문자 형식으로 출력
- `%X` : 16진수 대문자 형식으로 출력
- `%%` : 퍼센트 기호 출력

이 프로젝트는 향후 다른 42 프로젝트에서 활용할 수 있도록 정적 라이브러리 형태(`libftprintf.a`)로 빌드됩니다.

## Compilation

Makefile을 사용하여 컴파일을 자동화하였습니다.

라이브러리를 생성하려면 터미널에서 프로젝트 루트 경로로 이동한 후 다음 명령어를 입력하세요:

```bash
make
```

정적 라이브러리 파일 `libftprintf.a`가 생성됩니다.

##  Resources
Variadic Functions: C 가변 인자 공식 문서 `cppreference.com` - va_start, va_arg, va_copy, va_end 매크로의 동작 원리.

Printf Manual: Standard printf documentation (man 3 printf) - 각 서식 지정자의 반환값 및 엣지 케이스 처리 기준.

## AI Usage Disclosure

본 프로젝트는 다음 작업에 AI(Gemini)를 활용했습니다.

- Makefile 의존성 최적화 가이드
- 본 README.md 문서의 작성 및 번역


