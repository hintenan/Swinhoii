#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#ifndef PROMPT
#define PROMPT "//>"
#endif

#ifndef VARIABLE_LEN
#define VARIABLE_LEN 64
#endif

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 256
#endif

// Basic node
struct Node {
    int data;
    struct Node* next;
};
struct DNode {
    int data;
    struct DNode* prev;
    struct DNode* next;
};
struct Node_Variable {
    char variable[VARIABLE_LEN];
    char dtype[20];
    struct Node_Int* data;
    struct Node_Variable* next;
};
struct DNode_Variable {
    char variable[VARIABLE_LEN];
    char dtype[20];
    struct Node_Int* data;
    struct Node_Char* prev;
    struct Node_Char* next;
};
struct Segment {
    char var_seg[VARIABLE_LEN];
    int dtype;
};

// Declaration
// Print method
void Print_tmp(char *text); 

// Add Node
void add_Node(int data, struct Node** head_ptoptr);



void add_Node_Variable(char* x, struct Node_Variable** head_ptoptr);
struct Node_Variable* add_end_of_Node_Variable(char* x, struct Node_Variable** head_ptoptr, struct Node_Variable* end_ptr);

//Delete Node

//Top Node
int top_Node(struct Node** head_ptoptr);
char* top_Node_Variable(struct Node_Variable** head_ptoptr);

// Reverse Node methods
void reverse_Node_Varialbe(struct Node_Variable** head_ptoptr);

// Empty Node
void empty_Node(struct Node** head_ptoptr);
void empty_Node_Variable(struct Node_Variable** head_ptoptr);

// Print Node Methods
void print_Node(struct Node** head_ptoptr);
void print_Node_Variable(struct Node_Variable** head_ptoptr);
void print_Object(struct Segment* ptr);

// syntax check
int close_bracket_check(char text, struct Node** head_ptoptr);

// infix, prefix and postfix
int syntax_check(int index, char* text);
int alpha_check(int index, char* text);
void identify_punct();
void in_to_postfix(struct Node_Variable** head_ptoptr);
void evaluate_postfix(struct Node_Variable** head_ptoptr);

