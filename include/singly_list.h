#ifndef _INC_SINGLY_LIST
#define _INC_SINGLY_LIST

typedef struct SinglyNode {
    void *data;
    struct SinglyNode *next;
} SinglyNode;

typedef struct {
    SinglyNode *head;
    SinglyNode *tail;
    int count;
} SinglyList;

SinglyList *create_list();
SinglyNode *insert_node(int index, void *data, SinglyList *list);
SinglyNode *get_node(int index, SinglyList *list);
SinglyNode *push_head(void *data, SinglyList *list);
SinglyNode *push_tail(void *data, SinglyList *list);
void remove_node(int index, SinglyList *list);
void pop_head(SinglyList *list);
void pop_tail(SinglyList *list);
void clear_list(SinglyList *list);
void free_list(SinglyList *list);
void reverse_list(SinglyList *list);

#endif
