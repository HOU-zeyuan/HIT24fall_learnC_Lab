typedef struct Node{
    char *data;
    struct Node *next;
}Node, *LinkedList;

void add(LinkedList head);
void delete(LinkedList head);
void search(LinkedList head);
void update(LinkedList head);
void exchange(LinkedList head);
void empty(LinkedList head);
void print(LinkedList head);