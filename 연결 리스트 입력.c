#include <stdio.h>
#include <malloc.h>

typedef int element;
typedef struct NODE {
	element data;
	struct NODE *link;
}NODE;

void print_list(NODE *plist);

int get_integer();

int main(void) {
	NODE *plist;
	NODE *curr = NULL, *prev = NULL;
	int i;
	plist = NULL;
	while(1){
		i=get_integer();
		if(i < 0) break;
		curr=(NODE*)malloc(sizeof(NODE));
		curr->data=i;
		curr->link=NULL;
		if(prev==NULL)plist = curr; 
        else prev->link = curr;
		prev = curr;
	}
	print_list(plist);
	return 0;
}

void print_list(NODE *plist) {
	NODE *p;
	p = plist;
	while(p) {
		printf("%d->",p->data);
		p = p->link;
	}
	printf("NULL\n");
}

int get_integer() {
	int num;
	printf("양의 정수를 입력하세요(종료 -1): ");
	scanf("%d",&num);
	return num;
}