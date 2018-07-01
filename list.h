/* ���X�g�̗v�f (�m�[�h) ��\���\���� */
typedef struct tagListNode{
  struct tagListNode *prev;     /* �O�̗v�f�ւ̃|�C���^ */
  struct tagListNode *next;     /* ���̗v�f�ւ̃|�C���^ */
  int data;           /* ���̗v�f�����f�[�^ */
} ListNode;

ListNode* CreateNewNode(void);        	//�V�����m�[�h���쐬���āA���̃m�[�h�ւ̃|�C���^��߂�l�Ƃ��ĕԂ��B
int	GetValue	(ListNode *ln);    		//�����ɓn�����m�[�h�̒l��߂�l�Ƃ��ĕԂ��B
void	SetValue	(ListNode *ln, int val);  	//�w�肵���m�[�h�̒l��ݒ肷��B
ListNode* NextNode	(ListNode *ln); 	//�w�肵���m�[�h�̎��̃m�[�h�̃|�C���^�𓾂�B
ListNode* PrevNode	(ListNode *ln);		//�w�肵���m�[�h�̑O�̃m�[�h�̃|�C���^�𓾂�B
void	RemoveList	(ListNode **ln);  	//�|�C���^�̃|�C���^�Ŏw�肵�����X�g�̃��������������B
void	AppendNode	(ListNode *ln, ListNode *lnNext);//�w�肵���m�[�h�̎��Ɏw�肵���m�[�h��t�������B
void	InsertNode	(ListNode *ln, ListNode *lnPrev);//�w�肵���m�[�h�̑O�Ɏw�肵���m�[�h��}������B
void	PutList		(ListNode *ln);		//�w�肵���m�[�h�̃��X�g�̒l��S�ĕ\������D
void 	InsertSort	(ListNode *ln);		//�w�肵���m�[�h�̑������X�g���\�[�g����
