#include <stdlib.h>
#include <stdio.h>
#include "list.h"

//�V�����m�[�h���쐬���āA���̃m�[�h�ւ̃|�C���^��߂�l�Ƃ��ĕԂ��B
//�~�X������NULL;
ListNode* CreateNewNode(void){
	ListNode* ln;
	ln = (ListNode*)malloc(sizeof(ListNode));
	if(ln == NULL)return NULL;
	ln->data = 0;
	ln->prev = NULL;
	ln->next = NULL;
	return ln;
}

//�����ɓn�����m�[�h�̒l��߂�l�Ƃ��ĕԂ��B
int GetValue(ListNode* ln){
	if(ln == NULL){
		puts("NULL Pointer [GetValue]");
		return -1;
	}
	return ln->data;
}

//�w�肵���m�[�h�̒l��ݒ肷��B
void SetValue(ListNode* ln,int val){
	if(ln == NULL){
		puts("NULL Pointer [SetValue]");
		return;
	}
	
	ln->data = val;
}

//�w�肵���m�[�h�̎��̃m�[�h�̃|�C���^�𓾂�B
ListNode* NextNode(ListNode* ln){
	if(ln == NULL){
		puts("NULL Pointer [NextNode]");
		return NULL;
	}
	return ln->next;
}

//�w�肵���m�[�h�̑O�̃m�[�h�̃|�C���^�𓾂�B
ListNode* PrevNode(ListNode* ln){
	if(ln == NULL){
		puts("NULL Pointer [PrevNode]");
		return NULL;
	}
	return ln->prev;
}

//�w�肵�����X�g�̃��������������B
void RemoveList(ListNode** ln){
	ListNode *now = *ln;
	ListNode *next;
	
	if(*ln == NULL){
		puts("NULL Pointer[RemoveList]");
		return;
	}
	*ln = NULL;
	for(;;){
		if(now->prev == NULL)break;
		now = now->prev;
	}
	for(;;){
		if((next = now->next) == NULL){
			now->prev = NULL;
			free(now);
			break;
		}
		free(now);
		now->prev = NULL;
		now->next = NULL;
		now = next;
	}
	ln = NULL;
}

//�w�肵���m�[�h�̎��Ɏw�肵���m�[�h��t�������B
void AppendNode(ListNode* ln, ListNode* lnNext){
	if(ln == NULL){
		puts("NULL Pointer [AppendNode]");
		return;
	}
	if(lnNext->prev != NULL)(lnNext->prev)->next = lnNext->next;
	if(lnNext->next != NULL)(lnNext->next)->prev = lnNext->prev;
	lnNext->prev = ln;
	lnNext->next = ln->next;
	if(ln->next != NULL)(ln->next)->prev = lnNext;
	ln->next = lnNext;
}

//�w�肵���m�[�h�̑O�Ɏw�肵���m�[�h��}������B
void InsertNode(ListNode* ln, ListNode* lnPrev){
	if(ln == NULL){
		puts("NULL Pointer [InsertNode]");
		return;
	}
	if(lnPrev->prev != NULL)(lnPrev->prev)->next = lnPrev->next;
	if(lnPrev->next != NULL)(lnPrev->next)->prev = lnPrev->prev;
	lnPrev->prev = ln->prev;
	lnPrev->next = ln;
	if(ln->prev != NULL){
		(ln->prev)->next = lnPrev;
	}
	ln->prev = lnPrev;
}

//�w�肵�����X�g�̒l��S�ĕ\������D
void PutList(ListNode* ln){
	ListNode *now = ln;
	
	if(ln == NULL){
		puts("NULL Pointer [PutList]");
		return;
	}
	for(;;){
		if(now->prev == NULL)break;
		now = now->prev;
	}
	
	for(int i=1;;i++){
		printf("\nData%10d:%10d",i,now->data);
		if((now = NextNode(now)) == NULL)break;
	}
	printf("\n");
}

//do InsertSort
void InsertSort(ListNode *ln){
	ListNode *fn;
	
	if(ln == NULL){
		puts("NULL Pointer [InsertSort]");
		return;
	}
	//looking for firstnode.
	for(fn = ln;fn->prev != NULL;fn = fn->prev);
	
	for(ln = fn;ln->next != NULL;){
	
		if(ln->data > (ln->next)->data){
			ListNode *tmp;
			for(tmp = ln;tmp->prev != NULL;tmp = tmp->prev){
				if(!((tmp->prev)->data > (ln->next)->data))break;
			}
			InsertNode(tmp,ln->next);
		}else{
			ln = ln->next;
		}
	}
}









