/* { dg-do compile } */
/* { dg-options "-O1 -fdump-tree-dse1-details" } */
/* { dg-require-effective-target builtin_malloc } */
/* { dg-require-effective-target gcc_frontend } */

char*g;
char* f(){
  char*p=__builtin_malloc(42);
  __builtin_memset(p,3,33);
  __builtin_memset(p,7,10);
  return p;
}
void h(){
  char*p=__builtin_malloc(42);
  g=__builtin_memset(p,3,10);
}

/* { dg-final { scan-tree-dump-not "Deleted dead" "dse1" } } */
