#include <stdio.h>
#include <malloc.h>

typedef int element;
typedef struct Node{
	element data;
	struct Node *next;
}Node;

void print_list(Node *plist);

int get_integer();

int main(void){
	Node *plist;
	Node *curr=NULL, *prev=NULL;
	int i, a, num=0;
	plist = NULL;
	printf("베르실을 예약하시겠습니까?: \n");
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
	return 0;
}



void print_list(Node *plist){
	Node *p;
	p=plist;
	while(p){
		printf("%d->", p->data);
		p=p->next;
	}
}

int get_integer(){
	int num, a;
    printf("예약할 베르실의 번호를 입력하세요(종료 -1): \n");
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