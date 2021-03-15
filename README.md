# Exam_rank02
 - union / inter 중 1문제
 - get_next_line / ft_pirntf 중 1문제
 - 총 2문제가 출제되며, 제한시간은 2시간

#  Kerberos 티켓 생성
 - kinit [intra_ID]
 - intra password 입력

# Examshell 진입
 - examshell 명령어 입력 -> yes
 - status 명령어 : 현재상태(점수, 문제, 남은시간 등을 볼수있다.)
 - grademe 명령어 : 원격저장소에 제출한 파일을 채점
 - finish 명령어 : 시험이 끝난 후 반드시 입력(중요!)

# Subject
 - 루트의 subject 폴더 (ko.subject가 없는 문제도 있음)

# 풀이
 - 루트의 rendu 폴더 안에 subject명으로 폴더 생성(mkdir) 후 해당폴더 내에 작성
 - ex) ./rendu/get_next_line/get_next_line.c
 - examshell에 이런식으로 제출하라고 쓰여있음

# 제출
 - rendu 폴더에 git init 과 git remote add 가 되어있는 상태(확인 : git remote -v)
 - rendu 폴더에서 git add-> commit-> push
