/* { dg-do compile } */
/* { dg-options "-O -fdump-tree-fre1-details" } */
/* { dg-require-effective-target gcc_frontend } */

typedef union
{
  int* data;
} SA;

typedef struct
{
  int reserved;
  char* array;
}SB;

typedef struct
{
  int status;
}SC;

void foo(SA* pResult, SB* method, SC* self)
{
  if (method->array[0] == 'L' && !self->status && pResult->data != 0)
    pResult->data = pResult->data;
}

/* { dg-final { scan-tree-dump "Deleted redundant store" "fre1" } } */
