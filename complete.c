#include <stdio.h>
#include <malloc.h>

typedef int element;
typedef struct Node{
	element data;
	struct Node *next;
}Node;

void print_list(Node *plist);

int get_integer();
int arr[30];

int main(void){
	Node *plist;
	Node *curr=NULL, *prev=NULL;
	int i, a, num=0, ayy[30], x, h;
	plist = NULL;
	printf("==============================\n||        베르실 예약        ||\n==============================\n");
	printf("베르실 예약을 알고리즘과 자료구조를 활용해 C언어로 구현\n\t예약한 시간은 연결리스트를 이용해 저장되며\n\t사용자에게 선택 정렬을 이용해 정리해 화면에 띄웁니다.\n");
	printf("베르실 예약을 하겠습니까?\n(Y: 예약, N: 취소)\n: ");
    scanf("%C", &a);
	if(a==89){
		while(1){
			num+=1;
			if(num>=5) break;
			else{
				i=get_integer();
				curr=(Node*)malloc(sizeof(Node));
				curr->data=i;
				curr->next=NULL;
				if(prev==NULL) plist=curr; 
				else prev->next=curr;
				prev=curr;
			}
		}
	}
	print_list(plist);
	printf("차례대로 어느 방을 예약하시겠습니까?\n");
	for(int h=0; h<4; h++){
		scanf("%d", &x);
		printf("%d번 방은 %d시에 예약\n", x, arr[h]);
	}
	return 0;
}

void print_list(Node *plist){
	Node *p;
	int i, j, n=4, k, temp, m=0, list[30];
	p=plist;
	while(p){
		list[m]=p->data;
		arr[m]=p->data;
		p=p->next;
		m+=1;
	}
    for(i=0; i<n-1; i++){
        k=i;
        for(j=i+1; j<n; j++) if(list[j]<list[k]) k=j;
        temp=list[i];
        list[i]=list[k];
        list[k]=temp;
    }
    for(i=0; i<n; i++) printf("%02d ", list[i]);
	printf("시에 예약하겠습니다.\n\n");
}

int get_integer(){
	int num, a;
    printf("베르실을 몇시에 예약할까요?\n(1~9시, 한번 예약은 1시간 입니다.)\n: ");
	scanf("%d", &num);
	return num;
}

Node* insert_first(Node *head, element data){
    Node *node=(Node*)malloc(sizeof(Node));
    node->data=data;
    if(head==NULL){
        head=node;
        node->next=head;
    }
    else{
        node->next=head->next;
        head->next=node;
    }
    return head;
}

Node* insert_last(Node *head, element data){
    Node *node=(Node*)malloc(sizeof(Node));
    node->data=data;
    if(head==NULL){
        head=node;
        node->next=head;
    }
    else{
        node->next=head->next;
        head->next=node;
        head=node;
    }
    return head;
}