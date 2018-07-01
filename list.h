/* リストの要素 (ノード) を表す構造体 */
typedef struct tagListNode{
  struct tagListNode *prev;     /* 前の要素へのポインタ */
  struct tagListNode *next;     /* 次の要素へのポインタ */
  int data;           /* この要素が持つデータ */
} ListNode;

ListNode* CreateNewNode(void);        	//新しいノードを作成して、そのノードへのポインタを戻り値として返す。
int	GetValue	(ListNode *ln);    		//引数に渡したノードの値を戻り値として返す。
void	SetValue	(ListNode *ln, int val);  	//指定したノードの値を設定する。
ListNode* NextNode	(ListNode *ln); 	//指定したノードの次のノードのポインタを得る。
ListNode* PrevNode	(ListNode *ln);		//指定したノードの前のノードのポインタを得る。
void	RemoveList	(ListNode **ln);  	//ポインタのポインタで指定したリストのメモリを解放する。
void	AppendNode	(ListNode *ln, ListNode *lnNext);//指定したノードの次に指定したノードを付け足す。
void	InsertNode	(ListNode *ln, ListNode *lnPrev);//指定したノードの前に指定したノードを挿入する。
void	PutList		(ListNode *ln);		//指定したノードのリストの値を全て表示する．
void 	InsertSort	(ListNode *ln);		//指定したノードの属すリストをソートする
