# include <stdio.h>
# include "trie.h"
# include <string.h>
# include <stdlib.h>
# define FROMASCIITOZERO 97
# define WORD 100
/*
    ASCII:
A = 65 ... Z = 90
a = 97 ... z = 122
*/


/*
the method recived a word and node* to the head of the trie and insert the word to the trie.
*/
void addWord(char* word, node* trie){
    int i;
    node* n=trie;
    for(i=0; i<strlen(word); i++){
        n= addLetter(word[i], n);
    }
    // the counter of the word in the node thet represent the last letter in the word so add 1 to count.
    ++(n->count);
}
/*
the method recived a letter and node* and insert this letter to children if not exist 
and return node* to the new chidren. else return node* to the exist children.
*/ 
node* addLetter(char letter, node* n){
    //if the letter not exist yet.
    if(n->children[letter-FROMASCIITOZERO]==NULL){
        //make a new node.
        node* add=(node*)malloc(sizeof(node));
        //insert to the new node.
        add->letter=letter;
        add->count=0;
        add->parent=n;
        for(int i=0; i<NUM_LETTERS; i++)
           (add->children[i])=NULL;
        //insert the new node to the parent
        (n->children[letter-FROMASCIITOZERO])= add;
        return add;
    }
    else { 
        return (n->children[letter-FROMASCIITOZERO]);
    }

}

int isALeaf(node* n){
    if(n==NULL)
        return FALSE;
    for(int i=0; i<NUM_LETTERS; i++){
        if((n->children[i])!=NULL)
            return FALSE;
    }
    return TRUE;
}
void printUp(node* trie, char* word){
    int index=0;
    node* head=trie;
    printUpHelper(head, word,index );
}
void printUpHelper(node* child, char* word, int index ){
    if(isALeaf(child)){
        //its the head after print all
        if(child->parent==NULL){
            return;
        }
        //thats mean word
        ifWord(child, word);
        --index;
        word[index]=0;
        printUpHelper(freeUP(child),word, index );
    }
    else{
        int j=0;
        while(child->children[j]==NULL ){
            j++;
        }
        ifWord(child, word);
        //add the letter to the word
        word[index]= child->children[j]->letter;
        //the index of the next letter of the word
        ++index;
        printUpHelper(child->children[j],word, index );
     }   
}

node* freeUP(node* n){
    node* temp=NULL;
    char letter=(n->letter);
    temp=n->parent;
    free(n);
    (temp->children[letter-FROMASCIITOZERO])=NULL;
    return temp;       
}
void ifWord(node* n, char* word){
    if(n->count!=0){
        //print the word
        printf("%s  %ld\n", word, n->count );
        //if the program return to this word, so dont print the word again.
        n->count=0;
    }
}
void printDown(node* trie, char* word){
    node* head=trie;
    int index=0;
    printDownHelper(head, word, index);    
}
void printDownHelper(node* child, char* word, int index ){
    if (isALeaf(child))
    {
        freeNodesAndPrint(child, word, index);
        return;
        
    }
    for(int i=NUM_LETTERS-1; i>=0; i--){
        if((child->children[i])!=NULL)
        {
            word[index]= child->children[i]->letter;
            ++index;
            printDownHelper(child->children[i],word, index );
        }
    }
}
void freeNodesAndPrint(node* n, char* word, int index){
    node* temp=NULL;
    if(isALeaf(n)){
        if(n->parent==NULL)
            return;
        word[index]=0;
        --index;
        if((n->count)!=0){
            printf("%s  %ld\n", word, n->count );
        }
        char letter=(n->letter);
        temp=n->parent;
        free(n);
        (temp->children[letter-FROMASCIITOZERO])=NULL;
        freeNodesAndPrint(temp,word, index);
    }
    else 
        printDownHelper(n,word,index);

}