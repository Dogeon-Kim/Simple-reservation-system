#include <stdio.h>
#include <time.h>

void main(void){
	//초 단위
	time_t now;
	//시간 구조체
	struct tm t;

	//초 계산
	time(&now);

	//현재 날짜/시간 계산
	t = *localtime(&now);

	//현재 날짜에 100일 더함
    t.tm_min -= 10;

	//날짜 재 계산 : 100일 더함 계산
	mktime(&t);

	//변경된 날짜 출력
	printf("%d:%d\n", t.tm_hour+9, t.tm_min);
}