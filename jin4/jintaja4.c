#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>
#define BUFSIZE 512 /* 읽혀질 덩어리의 크기 */ 

char taja[BUFSIZE] = "Hello world!! maple story";

int main(){
    time_t start_time, end_time;
    char a[20];
    char buffer[BUFSIZE]; // 타자수 확인 버퍼
    char buf1[BUFSIZE]; // 파일 입력 버퍼

    int wrong_count=0;
    int n;
    int filedes;
    int fd;
    int sum = 0;
    double total = 0;

    //초기화
    printf("타자 연습 프로그램입니다. 시작(Enter)\n");
    printf("엔터를 눌러 시작");
    gets(a);
    start_time = time(NULL);

    // 주어진 문자 입력 
    fprintf(stderr, "%s\n", taja);
    gets(buf1);

 
    end_time = time(NULL);


    // 타이핑까지 걸린 시간
    total = difftime(end_time, start_time);

    // 입력한 타이핑 전체 글자수
    sum = strlen(buf1);
    sum /= total/60; 

    // 잘못 입력한거 체크
    for(int i = 0; i < strlen(taja); i++) if(buf1[i] != taja[i]) wrong_count++;
 

    printf("잘못 타이핑한 횟수: %d\n",wrong_count); 
    printf("평균 분당 타자수: %ld\n", sum);
    printf("총 걸린시간: %f\n", total);

    exit(0);

    return 0;
}
