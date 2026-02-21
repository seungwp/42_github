*This project has been created as part of the 42 curriculum by seukim.*

## Description

**Born2beRoot** 프로젝트는 가상 머신(VirtualBox)을 활용하여 자신만의 첫 번째 서버를 구축하는 시스템 관리 프로젝트입니다.

이 프로젝트의 주요 목표는 가상화 기술을 이해하고, 리눅스 운영체제를 설치하며, 엄격한 보안 규칙을 적용하는 것입니다. 그래픽 인터페이스 없이 오직 CLI 환경에서만 작동하는 서버를 구축하며, 다음과 같은 기술적 요소들을 구현합니다

- LVM 및 디스크 암호화: 보안을 위한 논리 볼륨 관리 및 파티션 암호화 설정.
- SSH 서비스: 4242 포트를 통한 안전한 원격 접속 설정 (root 접속 금지).
- UFW 방화벽: 특정 포트만 허용하는 네트워크 보안 설정.
- 비밀번호 정책: 복잡성 및 유효 기간을 포함한 강력한 계정 보안 정책.
- sudo 설정: 보안 로그 기록 및 TTY 모드를 포함한 권한 관리.
- Monitoring 스크립트: 시스템 상태를 10분마다 자동으로 출력하는 Bash 스크립트.


## Instructions

- VirtualBox를 실행하고 설정된 Debian 가상 머신을 선택하여 [시작] 버튼을 누릅니다.
- 터미널 환경(CLI)이 나타나면 사용자 ID(seukim)와 비밀번호로 로그인합니다.
- 호스트 PC의 터미널에서 다음 명령어를 통해 가상 머신에 접속 할 수 있습니다.
```bash
ssh seukim@<IP_ADDRESS> -p 4242
```
- 서버가 가동되면 monitoring.sh 스크립트가 10분마다 모든 터미널에 시스템 상태 정보를 출력합니다.
- 스크립트의 위치는 /usr/local/bin/monitoring.sh이며, cron을 통해 자동 실행됩니다.
- 가상 머신의 무결성을 확인하기 위해 다음 명령어로 .vdi 파일의 SHA1 해시값을 확인할 수 있습니다
```bash
sha1sum <파일명>.vdi
```
이 해시값은 제출된 signature.txt 파일의 내용과 일치해야 합니다.

##  Resources
- Debian Official Documentation: 시스템 설치 및 기본 패키지 관리
- Sudoers Manual (man 5 sudoers): visudo를 이용한 로그 설정 및 TTY 보안 정책 참조
- UFW (Uncomplicated Firewall) Guide: 포트 4242 개방 및 방화벽 활성화 방법
- LVM & LUKS Guide: 논리 볼륨 관리 및 디스크 암호화 설정

## AI Usage Disclosure

- README 문서 구조화: 과제 필수 항목인 비교 분석(Debian vs Rocky 등) 및 필수 섹션 구성에 대한 가이드를 얻었습니다.
- 리눅스 명령어에 대한 가이드를 얻었습니다.
- 스크립트 로직 검토: monitoring.sh 작성 시 시스템 자원(CPU, RAM, Disk) 정보를 추출하는 리눅스 명령어의 옵션을 검토했습니다.
- 본 README.md 문서의 작성 가이드를 얻었습니다.

## Additional information

Debian vs Rocky Linux
- 데비안은 커뮤니티가 주도하는 독립적인 배포판 - 자유도 높음
- 로키는 기업용 - 레드햇 엔터프라이즈 리눅스(RHEL)의 소스 코드를 그대로 사용하는 배포판으로, 기업 환경에 최적화된 안정성
- 데비안은 apt, aptitude 명령어 사용 / 로키는 dnf, yum 명령어 사용

AppArmor vs SELinux
- AppArmor는 파일의 절대 경로를 사용하여 보안 프로필을 생성하므로, 관리자가 설정 내용을 이해하고 수정하기가 훨씬 직관적임
- SELinux은 파일 시스템에 직접 보안 라벨을 입혀 보안성이 강력함

UFW vs firewalld
- Uncomplicated Firewall vs Dynamic Firewall Manager
- UFW는 명령어가 매우 직관적이고 설정이 간편함, 규칙이 변경되면 방화벽을 재시작해야 적용되는 경우가 많음
- firewalld는 Zone 개념을 이용하여 네트워크 환경별로 다른 규칙을 적용함, 서비스 중단 없이 실시간으로 규칙을 변경하고 적용하는데 최적화됨 

VirtualBox vs UTM
- VirtualBox은 오라클 UTM은 UTM 제작 팀에서 만듦
- VirtualBox은 윈도우, 리눅스, 맥(Intel)
- UTM은 맥, iOS
- VirtualBox은 호스트 OS 위에서 하드웨어 자원을 직접 가상화함.
- UTM은 애플의 가상화 프레임워크를 사용함

apt와 aptitude의 차이점?
- apt (Advanced Package Tool) 데비안의 표준 패키지 관리 도구로 가장 대중적으로 사용
- aptitude는 apt보다 높은 수준의 패키지 관리 도구로 패키지 설치에서 문제가 생기면 해결책을 제시해주고 안쓰는 파일도 지워주는 도구

## Command

- sudo ufw status
- sudo systemctl status ssh
- uname, hostnamectl, cat /etc/os-release

- id seukim
- id seukim, cat /etc/group
- sudo vi /etc/login.defs 
- sudo adduser test
- groupadd testgroup
- sudo usermod -aG <그룹명> <유저명>

- hostname, hostnamectl
- sudo hostnamectl set-hostname <새로운 이름>
- sudo reboot
- lsblk

- sudo usermod -aG sudo <유저명>
- sudo ls -l /var/log/sudo/
- sudo sudoreplay -l -d /var/log/sudo, sudo tree /var/log/sudo

- sudo ufw status verbose
- sudo ufw status
- sudo ufw allow 8080
- sudo ufw delete allow 8080
- sudo ufw status

- systemctl status ssh
- ss -tunlp, vim /etc/ssh/sshd_cofing

- sudo vim /usr/local/bin/moniterning.sh
- sudo crontab -l
- sudo crontab -e