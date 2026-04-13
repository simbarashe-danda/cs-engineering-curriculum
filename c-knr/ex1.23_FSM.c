#include <stdio.h>

/* all possible states of the state machine */
enum { NORMAL = 1, SLASH_PENDING = 2, IN_BLOCK_COMMENT = 3,
    STAR_PENDING = 4, IN_LINE_COMMENT = 5,  IN_STRING = 6,
    STRING_ESCAPE = 7, IN_CHARACTER = 8, CHARACTER_ESCAPE = 9 };

/* Finite state machine(FSM) approach */
int main(void)
{
    int state = NORMAL; // initial state

    int c;  // char input
    while ((c = getchar()) != EOF) 
        switch (state) { // previous state
        case NORMAL:
            if (c == '/') {state = SLASH_PENDING; break;} // delay slash
            if (c == '"') state = IN_STRING;
            else if (c == '\'') state = IN_CHARACTER;
            putchar(c);
            break;
        case SLASH_PENDING:
            if (c == '*') {state = IN_BLOCK_COMMENT; break; }
            if (c == '/') {state = IN_LINE_COMMENT; break; }
            if (c == '\'') state = IN_CHARACTER; // eg 100 / 'A';
            else if (c == '"') state = IN_STRING;
            else state = NORMAL;
            putchar('/'); putchar(c); // output the delayed slash
            break;
        case IN_LINE_COMMENT:
            if (c == '\n') {state = NORMAL;
                putchar('\n'); }
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
            putchar(c);
            break;
        case STRING_ESCAPE:
            state = IN_STRING; putchar(c);
            break;
        case IN_CHARACTER:
            if (c == '\\') state = CHARACTER_ESCAPE;
            else if(c == '\'') state = NORMAL;
            putchar(c);
            break;
        case CHARACTER_ESCAPE:
            state = IN_CHARACTER; putchar(c);
            break;
        }
}