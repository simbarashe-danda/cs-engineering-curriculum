/* Exercise 1-24. Write a program to check a C program for rudimentary syntax errors like 
unmatched parentheses, brackets and braces.
Don't forget about quotes, both single and  double, escape sequences, and comments. */

/* Finite State Machine(FSM) and fixed stack approach */
#include <stdio.h>

/* all possible states of the lexer state machine */
enum { NORMAL = 1, SLASH_PENDING = 2, IN_BLOCK_COMMENT = 3,
    STAR_PENDING = 4, IN_LINE_COMMENT = 5,  IN_STRING = 6,
    STRING_ESCAPE = 7, IN_CHARACTER = 8, CHARACTER_ESCAPE = 9, 
    /* Braces */
    BRACE1_OPEN = '{', BRACE1_CLOSE = '}',
    BRACE2_OPEN = '[', BRACE2_CLOSE = ']',
    BRACE3_OPEN = '(', BRACE3_CLOSE = ')', 
    MAXDEPTH = 21   };

/* invariant 1: top == 0 at eof is braces are balanced.
   invarinat 2: fsm state is NORMAL if comments, quotes are balanced*/
int main(void)
{
    int state = NORMAL; // initial state
    int top = 0;    // works as stack top ptr
    char stack[MAXDEPTH] = "";  // stack of maxdepth 20

    int c;  // char input
    while ((c = getchar()) != EOF) {
        switch (state) { // previous state
        case NORMAL:
            if (c == '/') state = SLASH_PENDING;
            else if (c == '"') state = IN_STRING;
            else if (c == '\'') state = IN_CHARACTER;

            /* stack pushing */
            else if (c == BRACE1_OPEN || c == BRACE2_OPEN || c == BRACE3_OPEN) {
                if (top < MAXDEPTH) stack[top++] = c; // push brace to stack and update stack top
                else{ printf("max brace depth reached"); return 1; }
            }
            else if (c == BRACE1_CLOSE || c == BRACE2_CLOSE || c == BRACE3_CLOSE) {
                if (top-1 < 0) { printf("Syntax error!, Missing opening brace\n"); // underflow
                    return 1; }
                /* stack LIFO popping */
                switch (c) {
                    /* same as popping last in brace if it matches current brace input. eg {}*/
                    case BRACE1_CLOSE:
                        if (stack[top-1] == BRACE1_OPEN) --top; 
                        else {printf("Syntax error!, braces of different type\n");
                            return 1; }
                        break;
                    case BRACE2_CLOSE:
                        if (stack[top-1] == BRACE2_OPEN) --top;
                        else {printf("Syntax error!, braces of different type\n");
                            return 1;}
                        break;
                    case BRACE3_CLOSE:
                        if (stack[top-1] == BRACE3_OPEN) --top;
                        else {printf("Syntax error!, braces of different type\n");
                            return 1; }
                        break;
                    default: // else we have a closing brace but not same type as last in, in stack
                        printf("Syntax error!, Non matching braces\n");
                        return 1;
                }
            }
            break;
        case SLASH_PENDING:
            if (c == '*') state = IN_BLOCK_COMMENT;
            else if (c == '/') state = IN_LINE_COMMENT;
            else if (c == '\'') state = IN_CHARACTER; // eg 100 / 'A';
            else {state = NORMAL; ungetc(c, stdin);}// push back char to input stream 
            break;
        case IN_LINE_COMMENT:
            if (c == '\n') state = NORMAL; 
            break;  
        case IN_BLOCK_COMMENT:
            if (c == '*') state = STAR_PENDING;
            break;
        case STAR_PENDING:
            if (c == '/') state = NORMAL;
            else if (c == '*') break; // multiple stars in a comment
            else state = IN_BLOCK_COMMENT;
            break;
        case IN_STRING:
            if (c == '\\') state = STRING_ESCAPE;
            else if (c == '"') state = NORMAL;
            break;
        case STRING_ESCAPE:
            state = IN_STRING;
            break;
        case IN_CHARACTER:
            if (c == '\\') state = CHARACTER_ESCAPE;
            else if(c == '\'') state = NORMAL;
            break;
        case CHARACTER_ESCAPE:
            state = IN_CHARACTER;
            break;
        }
    }

    /* invariant violation */
    if (top != 0) { printf("Syntax error!, Non matching braces\n");
        return 1; }
    if (state != NORMAL){ printf("Synatx error! Non matching quotes or comments\n");
        return 1; }
    return 0;
}