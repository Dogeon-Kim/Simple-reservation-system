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
	int i, a, num=0;
	char x, y, z, l;
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
	printf("어느 방을 예약하시겠습니까?\n");
	scanf("%C %C %C %C", &x, &y, &z, &l);
	for(i=0; i<4; i++){
		if(i==0) printf("%d시에 %C방 입니다.\n", arr[i], x);
		else if(i==1) printf("%d시에 %C방 입니다.\n", arr[i], y);
		else if(i==2) printf("%d시에 %C방 입니다.\n", arr[i], z);
		else if(i==3) printf("%d시에 %C방 입니다.\n", arr[i], l);
	}
	return 0;
}

void print_list(Node *plist){
	Node *p;
	int i, j, n=4, k, temp, m=0, list[30];
	p=plist;
	while(p){
		list[m]=p->data;
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