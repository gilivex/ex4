# ifndef TIMES
# define TIMES

# define NUM_LETTERS 26

typedef enum {FALSE = 0, TRUE = 1} boolean;

typedef struct node{
    char letter;
    long unsigned int count;
    struct node* parent;
    struct node* children[NUM_LETTERS];
} node;

void addWord(char*, node*);

node* addLetter(char, node*);

void printUp(node*, char*);

int isALeaf(node* n);

void printUpHelper(node* child, char* word, int index );

node* freeUP(node* n);

void ifWord(node* n, char* word);

void printDownHelper(node* child, char* word, int index );

void freeNodesAndPrint(node* n, char* word, int index);

void printDown(node*, char*);

# endif
