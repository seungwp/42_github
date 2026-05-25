*This project has been created as part of the 42 curriculum by seukim.*

# Get Next Line (GNL)

## Description (설명)
이 프로젝트는 파일 디스크립터(file descriptor)로부터 읽어들인 한 줄을 반환하는 함수를 프로그래밍하는 것입니다[cite: 4]. `get_next_line()` 함수를 반복적으로 호출(예: 루프 사용)하면 파일 디스크립터가 가리키는 텍스트 파일에서 한 번에 한 줄씩 읽을 수 있습니다. 이 함수는 외부 파일을 읽을 때와 표준 입력(standard input)을 읽을 때 모두 정상적으로 작동합니다. 반환되는 줄에는 항상 `\n` 문자가 포함되어야 합니다. 단, 파일의 끝(EOF)에 도달했고 파일이 `\n` 문자로 끝나지 않는 경우는 제외됩니다.

## Algorithm Explanation & Justification (알고리즘 설명 및 근거)
이 구현의 핵심은 `static` 변수인 `leftover`를 사용하여 여러 함수 호출 간에 파싱되지 않고 남은 문자열 데이터를 보존하는 데 있습니다. 

성능을 최적화하고 잦은 메모리 재할당으로 인한 오버헤드를 최소화하기 위해, 본 알고리즘은 **동적 용량 2배 증가 전략(dynamic capacity-doubling strategy)**을 사용합니다:
1. **동적 버퍼 증가 (`ft_grow`):** 긴 줄을 읽을 때 $O(N^2)$ 의 시간 복잡도 오버헤드를 발생시키는 표준 문자열 연결(`ft_strjoin`)을 사용하는 대신, `(*len + br + 1) * 2` 공식을 통해 새로운 용량을 계산하여 메모리를 동적으로 확장합니다. 이는 필요할 때만 버퍼 크기를 기하급수적으로 늘려주어 `malloc` 및 `free` 연산 횟수를 대폭 줄여줍니다.
2. **청크 단위 읽기 (`fill_res`):** 개행 문자 `\n` 또는 EOF를 만날 때까지 파일 디스크립터에서 `BUFFER_SIZE` 단위로 청크를 읽어 들입니다. 읽어들인 데이터는 동적으로 증가한 버퍼에 추가됩니다.
3. **줄 추출 (`extract_line`):** 개행 문자나 EOF가 발견되면, 개행 문자를 포함한 부분까지의 문자열을 분리하여 최종 줄(line)로 반환합니다.
4. **상태 관리 (`update_leftover`):** 개행 문자 이후에 남은 문자들은 분리되어 다시 정적 변수 `leftover`에 저장되며, 다음 `get_next_line()` 호출 시 처리될 수 있도록 상태를 유지합니다.

## Instructions (사용 방법)
이 프로젝트는 컴파일러 호출 시 `-D BUFFER_SIZE=n` 옵션을 추가하여 `read()`에 사용될 버퍼 크기를 지정해야 합니다. 코드는 일반적인 플래그와 더불어 `-D BUFFER_SIZE` 플래그가 있든 없든 성공적으로 컴파일되도록 설계되었습니다.

**컴파일 예시:**
```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c