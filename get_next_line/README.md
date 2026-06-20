*This project has been created as part of the 42 curriculum by seukim.*

# Get Next Line

## Description

`get_next_line`은 파일 디스크립터(fd)로부터 텍스트를 한 줄씩 읽어오는 함수입니다.

이 프로젝트의 목표는 버퍼링, 동적 메모리 관리, 그리고 함수 호출 간 상태 유지를 직접 구현하여 안정적으로 한 줄씩 읽어오는 기능을 만드는 것입니다. 이를 통해 정적 변수(Static Variable)와 메모리 관리에 대한 이해를 높일 수 있었습니다.

---

## Algorithm

본 구현은 다음과 같은 정적 변수를 사용합니다.

```c
static char *storage;
```

`storage`는 이전 호출에서 읽고 남은 데이터를 보관하여 다음 호출에서도 이어서 읽을 수 있도록 합니다.

알고리즘은 다음 세 단계로 구성됩니다.

1. **read_to_storage**

   * `read()`를 사용하여 데이터를 읽습니다.
   * 읽어온 데이터를 `storage`에 누적합니다.
   * 개행 문자(`\n`)를 만나거나 EOF에 도달할 때까지 반복합니다.

2. **split_line**

   * `storage`에서 한 줄을 추출하여 반환합니다.
   * 과제 명세에 따라 개행 문자도 함께 포함합니다.

3. **trim_storage**

   * 반환한 줄을 제외한 나머지 데이터를 새로운 `storage`에 저장합니다.
   * 다음 호출 시 이어서 읽을 수 있도록 합니다.

이 방식을 선택한 이유는 `read()`가 줄 단위가 아닌 고정 크기 버퍼 단위로 데이터를 읽기 때문입니다. 정적 변수를 사용하면 한 번에 읽고 남은 데이터를 보관할 수 있어 여러 번 호출하더라도 올바른 위치에서 계속 읽을 수 있습니다.

### Memory Management

메모리 누수를 방지하기 위해 다음 사항을 고려했습니다.

* 더 이상 필요하지 않은 메모리는 즉시 해제
* `read()` 에러 발생 시 할당된 메모리 정리
* EOF 도달 후 남은 데이터가 없으면 `storage` 해제

---

## Instructions

사용하려는 파일에서 헤더를 포함한 뒤 소스 파일과 함께 컴파일하면 됩니다.

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 \
	main.c get_next_line.c get_next_line_utils.c
```

`BUFFER_SIZE`를 지정하지 않으면 헤더 파일에 정의된 기본값을 사용합니다.

---

## Resources

### Classic References

* `man 2 read`
* `man 3 malloc`
* `man 3 free`
* C 언어의 Static Variable 관련 문서

### AI Usage Description

* 메모리 관리 로직 검토
* 메모리 누수 가능성 확인
* 엣지 케이스 테스트 아이디어 검토
* README 구조 및 문장 교정
