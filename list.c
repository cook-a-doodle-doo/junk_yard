#include <stdlib.h>
#include <stdio.h>
#include "list.h"

//新しいノードを作成して、そのノードへのポインタを戻り値として返す。
//ミスったらNULL;
ListNode* CreateNewNode(void){
	ListNode* ln;
	ln = (ListNode*)malloc(sizeof(ListNode));
	if(ln == NULL)return NULL;
	ln->data = 0;
	ln->prev = NULL;
	ln->next = NULL;
	return ln;
}

//引数に渡したノードの値を戻り値として返す。
int GetValue(ListNode* ln){
	if(ln == NULL){
		puts("NULL Pointer [GetValue]");
		return -1;
	}
	return ln->data;
}

//指定したノードの値を設定する。
void SetValue(ListNode* ln,int val){
	if(ln == NULL){
		puts("NULL Pointer [SetValue]");
		return;
	}
	
	ln->data = val;
}

//指定したノードの次のノードのポインタを得る。
ListNode* NextNode(ListNode* ln){
	if(ln == NULL){
		puts("NULL Pointer [NextNode]");
		return NULL;
	}
	return ln->next;
}

//指定したノードの前のノードのポインタを得る。
ListNode* PrevNode(ListNode* ln){
	if(ln == NULL){
		puts("NULL Pointer [PrevNode]");
		return NULL;
	}
	return ln->prev;
}

//指定したリストのメモリを解放する。
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

//指定したノードの次に指定したノードを付け足す。
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

//指定したノードの前に指定したノードを挿入する。
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

//指定したリストの値を全て表示する．
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









