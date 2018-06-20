/* { dg-do compile } */
/* { dg-require-effective-target gcc_frontend } */
/* { dg-options "-fno-tree-ccp -fno-tree-vrp -O2 -Wuninitialized -Werror=uninitialized -Wno-error=maybe-uninitialized" } */
void blah();
void bar (int);
int gflag;

void foo()
{
   int v;
   if (gflag)
     v = 10;

   blah(); /* *gflag may be killed, but compiler won't know */

   if (gflag)
    bar(v);   /* { dg-warning "uninitialized" "should not be promoted to error" } */
}
