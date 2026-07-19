*This project has been created as part of the 42 curriculum by seukim.*

# Minitalk

## Description

Minitalk은 UNIX 시그널만을 이용해 클라이언트와 서버 사이에 데이터를 주고받는 프로그램이다. 데이터 채널로 쓸 수 있는 시그널은 `SIGUSR1`과 `SIGUSR2` 두 종류뿐이므로, 문자열을 그대로 전송할 수 없다. 따라서 각 문자(8비트)를 비트 단위로 쪼개어 시그널로 하나씩 전송하고, 수신 측에서 이를 다시 문자로 재조립하는 방식을 사용한다.

- **server**: 먼저 실행되며, 시작 시 자신의 PID를 출력하고 시그널을 기다린다. 받은 비트를 조립해 문자를 복원하고 출력한다. 여러 클라이언트의 메시지를 재시작 없이 연속으로 처리한다.
- **client**: 서버의 PID와 보낼 문자열을 인자로 받아, 문자열을 비트 단위로 쪼개 시그널로 전송한다.

두 프로그램은 안정적인 전송을 위해 **stop-and-wait 방식의 흐름 제어**를 사용한다. 클라이언트는 비트 하나를 보낼 때마다 서버가 보내는 확인 신호(ACK)를 받은 뒤에야 다음 비트를 전송한다. 이는 리눅스가 동일한 종류의 시그널이 대기(pending) 중일 때 추가로 들어온 시그널을 큐잉하지 않고 버리는 특성 때문에 발생하는 신호 유실을 방지하기 위한 것이다.

## Instructions

### 컴파일

```
make        # client와 server 모두 빌드
make clean  # 오브젝트 파일 삭제
make fclean # 오브젝트 파일 + 실행 파일 삭제
make re     # 전체 재빌드
```

### 실행

```
# 1. 서버 실행 (PID 출력됨)
./server
Server PID: 12345

# 2. 다른 터미널에서 클라이언트 실행
./client 12345 "Hello World"
```

서버 터미널에 전송한 문자열이 출력된다.

## 기술적 선택

- **sigaction 사용 (signal 대신)**: `signal()`은 플랫폼별로 동작이 달라 이식성이 떨어진다. 서버는 발신자 PID(`si_pid`)를 알아야 ACK를 보낼 수 있는데, 이를 위해 `SA_SIGINFO` 플래그와 3인자 핸들러가 필요하므로 `sigaction`을 사용했다.
- **비트 전송 순서 (MSB first)**: 클라이언트는 최상위 비트부터 전송하고(`(c >> i) & 1`), 서버는 왼쪽 시프트로 조립한다(`(c << 1) | bit`). 두 방식이 짝을 이뤄 원래 문자가 복원된다.
- **문자열 종료**: 문자열 끝의 `\0`까지 전송하여 서버가 메시지 끝을 인식하고 상태를 초기화하도록 했다.
- **전역변수**: 클라이언트의 `g_ack`은 ACK 수신 여부 플래그로, 비동기 시그널 핸들러와 메인 흐름이 공유해야 하는 유일한 상태이므로 전역변수로 두었다. 서버는 조립 중인 바이트와 비트 카운트를 핸들러 내부 `static` 변수로 처리하여 전역변수를 사용하지 않는다.
- **대기 방식 (usleep)**: ACK 대기 시 `pause()`는 조건 검사와 잠들기 사이에 신호가 도착하면 이를 놓치고 무한 대기에 빠지는 race condition이 있다. 완전한 해결책인 `sigsuspend`는 허용 함수가 아니므로, `usleep`으로 주기적으로 재검사하여 이 문제를 회피했다.
- **에러 처리**: 인자 개수, PID의 숫자 여부, int 오버플로, 서버 존재 여부(`kill(pid, 0)`)를 검증한다. 잘못된 입력에도 프로그램이 비정상 종료되지 않는다.

## Resources

- [man 2 sigaction](https://man7.org/linux/man-pages/man2/sigaction.2.html) — sigaction 함수, `struct sigaction`, `SA_SIGINFO`, `siginfo_t` 구조체
- [man 7 signal](https://man7.org/linux/man-pages/man7/signal.7.html) — 시그널 개념, 기본 동작, 목록
- [man 7 signal-safety](https://man7.org/linux/man-pages/man7/signal-safety.7.html) — 시그널 핸들러 내에서 안전하게 호출 가능한 함수(`write`가 되고 `printf`가 안 되는 이유)
- [GNU C Library — Signal Handling](https://www.gnu.org/software/libc/manual/html_node/Signal-Handling.html) — 시그널 처리 전반

### AI 활용

이 프로젝트에서 AI는 다음 용도로 활용했다.

- **개념 학습**: 시그널이 데이터를 담지 못하고 종류만 전달한다는 점, 리눅스가 pending 시그널을 큐잉하지 않아 유실이 발생한다는 점, 이로부터 비트 단위 직렬화와 ACK 기반 흐름 제어가 필요하다는 결론을 도출하는 과정을 AI와의 문답으로 학습했다.
- **문법 이해**: 비트 연산(`<<`, `>>`, `&`, `|`)으로 문자를 비트로 분해·조립하는 원리, 함수 포인터로 핸들러를 등록하는 방식, `struct sigaction`의 각 멤버 역할을 이해하는 데 활용했다.
- **디버깅**: `pause()` 사용 시 발생한 race condition의 원인을 분석하고 `usleep` 방식으로 전환하는 판단, 테스터가 요구하는 에러 출력 형식(stdout)과 PID 검증(오버플로, 존재하지 않는 서버) 보강에 활용했다.

AI가 생성한 내용은 그대로 복사하지 않고, 각 줄의 동작 원리를 이해한 뒤 직접 작성·수정하며 코드에 반영했다.