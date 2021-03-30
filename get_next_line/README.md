# get_next_len
 - 통과

# Subject Summary
 - int get_get_line(char **line);
 - 표준입력(fd = 0)으로 부터 한줄씩 읽어와서 *line에 저장해주는 함수
 - 성공적으로 읽어왔을 경우 return (1);
 - 마지막까지 읽어왔을 경우 return (0);
 - 에러 발생 시 return (-1);
 - buffer_size는 자유롭게 설정 가능
 - 메모리 누수가 발생하면 안된다.

# Check Result
 - main문 작성하여 결과 출력
 - 표준입력(fd = 0)일 경우 문자열 전달
~~~C
printf "test\nfor\nfd = 0" | ./a.out | cat-e
~~~
 - 메모리 누수 체크 컴파일 옵션
~~~C
gcc -g3 -fsanitize=address get_next_line.c
~~~
 - main문에서 무한루프 돌린 후 새로운 터미널창에서 leaks 확인
~~~C
leaks a.out // leaks 사용 시 컴파일은 gcc로만
~~~
