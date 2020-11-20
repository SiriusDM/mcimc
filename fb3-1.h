/*
    Declaration for a calculator fb3-1
*/

/* interface to the lexer */
extern int yylineno; /*from lexer*/
void yyerror(char *s, ...);

/* node in the abstract syntax tree */
struct ast {
    int nodetype;
    struct ast *l;
    struct ast *r;
};

struct numcal
{
    int nodetype; /* type k for constant */
    double number;
};

/* build an AST */
struct ast *newast(int nodetype, struct ast *l, struct ast *r);
struct ast *newnum(double d);

/* evaluate an AST */
double eval(struct ast *);

/*delete and free an AST */
void treefree(struct ast *);

