%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern FILE* yyin;
int yylex(void);
void yyerror(const char* s);

FILE *tac_fp, *asm_fp;

int temp_count = 1;
int label_count = 0;

char* new_temp() {
    char* buf = malloc(10);
    sprintf(buf, "t%d", temp_count++);
    return buf;
}

char* new_label() {
    char* buf = malloc(10);
    sprintf(buf, "L%d", label_count++);
    return buf;
}

#define MAX_REGS 20
char reg_names[MAX_REGS][4];
int reg_stack[MAX_REGS];
int reg_sp = -1;
int reg_next = 0;

void init_regs() {
    for (int i = 0; i < MAX_REGS; i++) {
        sprintf(reg_names[i], "R%d", i);
    }
}

char* alloc_reg() {
    if (reg_next >= MAX_REGS) {
        fprintf(stderr, "Out of registers!\n");
        exit(1);
    }
    int idx = reg_next++;
    reg_stack[++reg_sp] = idx;
    return reg_names[idx];
}

char* pop_reg() {
    if (reg_sp < 0) {
        fprintf(stderr, "Register stack underflow!\n");
        exit(1);
    }
    int idx = reg_stack[reg_sp--];
    return reg_names[idx];
}

void push_reg(const char* name) {
    int idx = atoi(name + 1);
    reg_stack[++reg_sp] = idx;
}

void reset_regs() {
    reg_sp = -1;
    reg_next = 0;
}

%}

%union {
    char cvar[20];
    struct {
        char code[20];
        char true_label[10];
        char false_label[10];
    } expr_attr;
    struct {
        char* first;
        char* second;
    } lbl_pair;
}

%token <cvar> VAR NUM
%token IF ELSE WHILE FOR
%token FUNC
%token EQ NE LE GE AND OR NOT
%token PEQ MEQ TEQ DEQ MODEQ

%type <cvar> expr primary
%type <cvar> assignment
%type <lbl_pair> if_head while_head for_head

%left OR
%left AND
%nonassoc EQ NE
%nonassoc '<' '>' LE GE
%left '+' '-'
%left '*' '/' '%'
%right UMINUS NOT

%nonassoc IFX
%nonassoc ELSE

%%

program:
    statement_list
    ;

statement_list:
    statement
    | statement_list statement
    ;

statement:
    assignment ';'
    | expr ';'             { reset_regs(); }
    | if_stmt
    | while_stmt
    | for_stmt
    | block
    ;

assignment:
    VAR '=' expr {
        fprintf(tac_fp, "%s = %s\n", $1, $3);
        char* result_reg = pop_reg();
        fprintf(asm_fp, "MOV %s, %s\n", $1, result_reg);
        reset_regs();
    }
    | VAR PEQ expr {
        char* t = new_temp();
        fprintf(tac_fp, "%s = %s + %s\n", t, $1, $3);
        fprintf(tac_fp, "%s = %s\n", $1, t);
        char* expr_reg = pop_reg();
        char* var_reg = alloc_reg();
        fprintf(asm_fp, "MOV %s, %s\n", var_reg, $1);
        fprintf(asm_fp, "ADD %s, %s\n", var_reg, expr_reg);
        fprintf(asm_fp, "MOV %s, %s\n", $1, var_reg);
        reset_regs();
        free(t);
    }
    | VAR MEQ expr {
        char* t = new_temp();
        fprintf(tac_fp, "%s = %s - %s\n", t, $1, $3);
        fprintf(tac_fp, "%s = %s\n", $1, t);
        char* expr_reg = pop_reg();
        char* var_reg = alloc_reg();
        fprintf(asm_fp, "MOV %s, %s\n", var_reg, $1);
        fprintf(asm_fp, "SUB %s, %s\n", var_reg, expr_reg);
        fprintf(asm_fp, "MOV %s, %s\n", $1, var_reg);
        reset_regs();
        free(t);
    }
    | VAR TEQ expr {
        char* t = new_temp();
        fprintf(tac_fp, "%s = %s * %s\n", t, $1, $3);
        fprintf(tac_fp, "%s = %s\n", $1, t);
        char* expr_reg = pop_reg();
        char* var_reg = alloc_reg();
        fprintf(asm_fp, "MOV %s, %s\n", var_reg, $1);
        fprintf(asm_fp, "MUL %s, %s\n", var_reg, expr_reg);
        fprintf(asm_fp, "MOV %s, %s\n", $1, var_reg);
        reset_regs();
        free(t);
    }
    | VAR DEQ expr {
        char* t = new_temp();
        fprintf(tac_fp, "%s = %s / %s\n", t, $1, $3);
        fprintf(tac_fp, "%s = %s\n", $1, t);
        char* expr_reg = pop_reg();
        char* var_reg = alloc_reg();
        fprintf(asm_fp, "MOV %s, %s\n", var_reg, $1);
        fprintf(asm_fp, "DIV %s, %s\n", var_reg, expr_reg);
        fprintf(asm_fp, "MOV %s, %s\n", $1, var_reg);
        reset_regs();
        free(t);
    }
    | VAR MODEQ expr {
        char* t = new_temp();
        fprintf(tac_fp, "%s = %s %% %s\n", t, $1, $3);
        fprintf(tac_fp, "%s = %s\n", $1, t);
        char* expr_reg = pop_reg();
        char* var_reg = alloc_reg();
        fprintf(asm_fp, "MOV %s, %s\n", var_reg, $1);
        fprintf(asm_fp, "MOD %s, %s\n", var_reg, expr_reg);
        fprintf(asm_fp, "MOV %s, %s\n", $1, var_reg);
        reset_regs();
        free(t);
    }
    ;

/* if statement */
if_stmt:
    if_head block %prec IFX {
        fprintf(tac_fp, "%s:\n", $1.second);
        fprintf(asm_fp, "%s:\n", $1.second);
        free($1.first);
        free($1.second);
        reset_regs();
    }
    | if_head block ELSE {
        fprintf(tac_fp, "goto %s\n", $1.second);
        fprintf(asm_fp, "JMP %s\n", $1.second);
        fprintf(tac_fp, "%s:\n", $1.first);
        fprintf(asm_fp, "%s:\n", $1.first);
        $<lbl_pair>$.first  = $1.first;
        $<lbl_pair>$.second = $1.second;
    } block {
        fprintf(tac_fp, "%s:\n", $<lbl_pair>5.second);
        fprintf(asm_fp, "%s:\n", $<lbl_pair>5.second);
        free($<lbl_pair>5.first);
        free($<lbl_pair>5.second);
        reset_regs();
    }
    ;

if_head:
    IF '(' expr ')' {
        char* else_lbl = new_label();
        char* end_lbl  = new_label();
        fprintf(tac_fp, "ifFalse %s goto %s\n", $3, else_lbl);
        char* cond_reg = pop_reg();
        fprintf(asm_fp, "CMP %s, #0\n", cond_reg);
        fprintf(asm_fp, "JE %s\n", else_lbl);
        $$.first  = else_lbl;
        $$.second = end_lbl;
    }
    ;

/* while loop */
while_stmt:
    while_head block {
        fprintf(tac_fp, "goto %s\n", $1.first);
        fprintf(asm_fp, "JMP %s\n", $1.first);
        fprintf(tac_fp, "%s:\n", $1.second);
        fprintf(asm_fp, "%s:\n", $1.second);
        free($1.first);
        free($1.second);
        reset_regs();
    }
    ;

while_head:
    WHILE {
        char* start_lbl = new_label();
        char* end_lbl   = new_label();
        fprintf(tac_fp, "%s:\n", start_lbl);
        fprintf(asm_fp, "%s:\n", start_lbl);
        $<lbl_pair>$.first  = start_lbl;
        $<lbl_pair>$.second = end_lbl;
    } '(' expr ')' {
        char* start_lbl = $<lbl_pair>2.first;
        char* end_lbl   = $<lbl_pair>2.second;
        fprintf(tac_fp, "ifFalse %s goto %s\n", $4, end_lbl);
        char* cond_reg = pop_reg();
        fprintf(asm_fp, "CMP %s, #0\n", cond_reg);
        fprintf(asm_fp, "JE %s\n", end_lbl);
        $$.first  = start_lbl;
        $$.second = end_lbl;
    }
    ;

/* for loop */
for_stmt:
    for_head block {
        fprintf(tac_fp, "goto %s\n", $1.first);
        fprintf(asm_fp, "JMP %s\n", $1.first);
        fprintf(tac_fp, "%s:\n", $1.second);
        fprintf(asm_fp, "%s:\n", $1.second);
        free($1.first);
        free($1.second);
        reset_regs();
    }
    ;

for_head:
    FOR '(' assignment ';' {
        char* start_lbl = new_label();
        char* end_lbl   = new_label();
        fprintf(tac_fp, "%s:\n", start_lbl);
        fprintf(asm_fp, "%s:\n", start_lbl);
        $<lbl_pair>$.first  = start_lbl;
        $<lbl_pair>$.second = end_lbl;
    } expr ';' {
        char* start_lbl = $<lbl_pair>5.first;
        char* end_lbl   = $<lbl_pair>5.second;
        fprintf(tac_fp, "ifFalse %s goto %s\n", $6, end_lbl);
        char* cond_reg = pop_reg();
        fprintf(asm_fp, "CMP %s, #0\n", cond_reg);
        fprintf(asm_fp, "JE %s\n", end_lbl);
        $<lbl_pair>$.first  = start_lbl;
        $<lbl_pair>$.second = end_lbl;
    } assignment ')' {
        $$.first  = $<lbl_pair>8.first;
        $$.second = $<lbl_pair>8.second;
    }
    ;

block:
    '{' statement_list '}'
    ;

expr:
    expr OR expr {
        char* t = new_temp();
        fprintf(tac_fp, "%s = %s || %s\n", t, $1, $3);
        char* right = pop_reg();
        char* left  = pop_reg();
        fprintf(asm_fp, "OR %s, %s\n", left, right);
        push_reg(left);
        strcpy($$, t);
        free(t);
    }
    | expr AND expr {
        char* t = new_temp();
        fprintf(tac_fp, "%s = %s && %s\n", t, $1, $3);
        char* right = pop_reg();
        char* left  = pop_reg();
        fprintf(asm_fp, "AND %s, %s\n", left, right);
        push_reg(left);
        strcpy($$, t);
        free(t);
    }
    | expr EQ expr {
        char* t = new_temp();
        fprintf(tac_fp, "%s = %s == %s\n", t, $1, $3);
        char* right = pop_reg();
        char* left  = pop_reg();
        fprintf(asm_fp, "CMPEQ %s, %s\n", left, right);
        push_reg(left);
        strcpy($$, t);
        free(t);
    }
    | expr NE expr {
        char* t = new_temp();
        fprintf(tac_fp, "%s = %s != %s\n", t, $1, $3);
        char* right = pop_reg();
        char* left  = pop_reg();
        fprintf(asm_fp, "CMPNE %s, %s\n", left, right);
        push_reg(left);
        strcpy($$, t);
        free(t);
    }
    | expr '<' expr {
        char* t = new_temp();
        fprintf(tac_fp, "%s = %s < %s\n", t, $1, $3);
        char* right = pop_reg();
        char* left  = pop_reg();
        fprintf(asm_fp, "CMPLT %s, %s\n", left, right);
        push_reg(left);
        strcpy($$, t);
        free(t);
    }
    | expr '>' expr {
        char* t = new_temp();
        fprintf(tac_fp, "%s = %s > %s\n", t, $1, $3);
        char* right = pop_reg();
        char* left  = pop_reg();
        fprintf(asm_fp, "CMPGT %s, %s\n", left, right);
        push_reg(left);
        strcpy($$, t);
        free(t);
    }
    | expr LE expr {
        char* t = new_temp();
        fprintf(tac_fp, "%s = %s <= %s\n", t, $1, $3);
        char* right = pop_reg();
        char* left  = pop_reg();
        fprintf(asm_fp, "CMPLE %s, %s\n", left, right);
        push_reg(left);
        strcpy($$, t);
        free(t);
    }
    | expr GE expr {
        char* t = new_temp();
        fprintf(tac_fp, "%s = %s >= %s\n", t, $1, $3);
        char* right = pop_reg();
        char* left  = pop_reg();
        fprintf(asm_fp, "CMPGE %s, %s\n", left, right);
        push_reg(left);
        strcpy($$, t);
        free(t);
    }
    | expr '+' expr {
        char* t = new_temp();
        fprintf(tac_fp, "%s = %s + %s\n", t, $1, $3);
        char* right = pop_reg();
        char* left  = pop_reg();
        fprintf(asm_fp, "ADD %s, %s\n", left, right);
        push_reg(left);
        strcpy($$, t);
        free(t);
    }
    | expr '-' expr {
        char* t = new_temp();
        fprintf(tac_fp, "%s = %s - %s\n", t, $1, $3);
        char* right = pop_reg();
        char* left  = pop_reg();
        fprintf(asm_fp, "SUB %s, %s\n", left, right);
        push_reg(left);
        strcpy($$, t);
        free(t);
    }
    | expr '*' expr {
        char* t = new_temp();
        fprintf(tac_fp, "%s = %s * %s\n", t, $1, $3);
        char* right = pop_reg();
        char* left  = pop_reg();
        fprintf(asm_fp, "MUL %s, %s\n", left, right);
        push_reg(left);
        strcpy($$, t);
        free(t);
    }
    | expr '/' expr {
        char* t = new_temp();
        fprintf(tac_fp, "%s = %s / %s\n", t, $1, $3);
        char* right = pop_reg();
        char* left  = pop_reg();
        fprintf(asm_fp, "DIV %s, %s\n", left, right);
        push_reg(left);
        strcpy($$, t);
        free(t);
    }
    | expr '%' expr {
        char* t = new_temp();
        fprintf(tac_fp, "%s = %s %% %s\n", t, $1, $3);
        char* right = pop_reg();
        char* left  = pop_reg();
        fprintf(asm_fp, "MOD %s, %s\n", left, right);
        push_reg(left);
        strcpy($$, t);
        free(t);
    }
    | NOT expr %prec NOT {
        char* t = new_temp();
        fprintf(tac_fp, "%s = !%s\n", t, $2);
        char* op = pop_reg();
        fprintf(asm_fp, "NOT %s\n", op);
        push_reg(op);
        strcpy($$, t);
        free(t);
    }
    | '-' expr %prec UMINUS {
        char* t = new_temp();
        fprintf(tac_fp, "%s = -%s\n", t, $2);
        char* op = pop_reg();
        fprintf(asm_fp, "NEG %s\n", op);
        push_reg(op);
        strcpy($$, t);
        free(t);
    }
    | '(' expr ')' {
        strcpy($$, $2);
    }
    | primary {
        strcpy($$, $1);
    }
    ;

primary:
    VAR {
        strcpy($$, $1);
        char* r = alloc_reg();
        fprintf(asm_fp, "MOV %s, %s\n", r, $1);
    }
    | NUM {
        strcpy($$, $1);
        /* Load immediate into a register first */
        char* r = alloc_reg();
        fprintf(asm_fp, "MOV %s, #%s\n", r, $1);
        /* The register is already on the stack (alloc_reg pushed it) */
    }
    | FUNC '(' argument_list ')' {
        char* t = new_temp();
        fprintf(tac_fp, "%s = %s()\n", t,
                ($<cvar>0[0]=='s'?"sqrt":
                 $<cvar>0[0]=='p'?"pow":
                 $<cvar>0[0]=='l'?"log":
                 $<cvar>0[0]=='e'?"exp":
                 $<cvar>0[0]=='i'?"sin":
                 $<cvar>0[0]=='c'?"cos":
                 $<cvar>0[0]=='t'?"tan":"abs"));
        if ($<cvar>0[0] == 'p') {
            char* arg2 = pop_reg();
            char* arg1 = pop_reg();
            char* res = alloc_reg();
            fprintf(asm_fp, "POW %s, %s, %s\n", res, arg1, arg2);
        } else {
            char* arg = pop_reg();
            char* res = alloc_reg();
            switch($<cvar>0[0]) {
                case 's': fprintf(asm_fp, "SQRT %s, %s\n", res, arg); break;
                case 'l': fprintf(asm_fp, "LOG %s, %s\n", res, arg); break;
                case 'e': fprintf(asm_fp, "EXP %s, %s\n", res, arg); break;
                case 'i': fprintf(asm_fp, "SIN %s, %s\n", res, arg); break;
                case 'c': fprintf(asm_fp, "COS %s, %s\n", res, arg); break;
                case 't': fprintf(asm_fp, "TAN %s, %s\n", res, arg); break;
                case 'a': fprintf(asm_fp, "ABS %s, %s\n", res, arg); break;
            }
        }
        strcpy($$, t);
        free(t);
    }
    ;

argument_list:
    expr
    | argument_list ',' expr
    ;

%%

void yyerror(const char* s) {
    fprintf(stderr, "Syntax error: %s\n", s);
}

int main() {
    init_regs();
    yyin = fopen("input.txt", "r");
    tac_fp = fopen("ThreeAdressCode.txt", "w");
    asm_fp = fopen("Assembly.txt", "w");
    if (!yyin || !tac_fp || !asm_fp) {
        perror("File open error");
        return 1;
    }
    yyparse();
    fclose(yyin);
    fclose(tac_fp);
    fclose(asm_fp);
    return 0;
}