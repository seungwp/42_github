# 42 Cursus — seukim

42경산에서 진행한 과제 모음입니다. 자세한 내용은 각 디렉터리의 README를 참고하세요.

| 프로젝트 | 개요 |
| :--- | :--- |
| [LaPiscine](./LaPiscine) | 입학 과정(피신) 과제 모음. `c00`–`c08`(C 기초부터 포인터, 구조체, 정적 라이브러리까지), `shell00`(셸 기초), `final_exam`(시험 문제 풀이) |
| [libft](./libft) | 표준 C 라이브러리 함수와 연결 리스트 함수를 직접 구현한 나만의 정적 라이브러리 |
| [ft_printf](./ft_printf) | 가변 인자를 이용한 `printf` 재구현. `%c %s %p %d %i %u %x %X %%` 지원 |
| [get_next_line](./get_next_line) | 정적 변수로 버퍼를 유지하며 fd에서 한 줄씩 읽어오는 함수 |
| [Born2beroot](./Born2beroot) | VirtualBox 위에 CLI 전용 Debian 서버 구축. LVM/암호화, SSH, UFW, sudo 정책, 모니터링 스크립트 |
| [minitalk](./minitalk) | `SIGUSR1`/`SIGUSR2` 두 시그널만으로 문자열을 비트 단위 전송하는 클라이언트-서버 |
| [push_swap](./push_swap) | 두 스택과 제한된 연산으로 최소 횟수 정렬 (진행 중) |

모든 C 프로젝트는 42 Norm을 준수하며 `-Wall -Wextra -Werror`로 컴파일됩니다. 각 프로젝트 디렉터리에서 `make`로 빌드합니다.
