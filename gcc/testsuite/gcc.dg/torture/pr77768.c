/* { dg-do run } */
/* { dg-require-effective-target builtin_exit } */

static const int a;
int b;
int *c, *d;
int main()
{
  c = (int *)&a;
  c == d ?: __builtin_exit(0); 
  for (; b; b++ >= (*d = a))
    ;
  return 0;
}
