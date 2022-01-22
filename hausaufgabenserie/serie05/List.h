#ifndef OK0579_LIST_H
#define OK0579_LIST_H

#include "stdlib.h"
typedef enum {False, True} Bool;

typedef int Value;
typedef void (*VProc) (Value);

typedef struct _list {
    Value val;
    struct _list *next;
}Elem, *List;

List init(void);
Bool empty(List);
List insert(Value, List);
Value head(List);
List tail(List);
Value nth(List, unsigned int);
Bool isin(Value, List);
void iterate(List, VProc);
List append(List, List);
Value last(List);
unsigned int length(List);

Bool check_equal(List, List);
void deleteAll(Value, List*);
void insertBefore(Value, Value, List*);
void insertAfter(Value, Value, List*);
#endif //OK0579_LIST_H