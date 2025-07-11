#ifndef _INC_SINGLY_LIST
#define _INC_SINGLY_LIST

typedef struct SinglyNode {
    void *data;
    struct SinglyNode *next;
} SinglyNode;

SinglyNode *add_node(void *data, SinglyNode **head);
SinglyNode *get_node(int index, SinglyNode *head);
SinglyNode *get_last_node(SinglyNode *head);
SinglyNode *insert_node(int index, void *data, SinglyNode **head);
SinglyNode *append_node(void *data, SinglyNode **head);
void remove_node(int index, SinglyNode **head);
void free_list(SinglyNode *head);

#endif
