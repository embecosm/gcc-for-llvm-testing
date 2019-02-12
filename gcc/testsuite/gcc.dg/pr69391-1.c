/* { dg-do run } */
/* { dg-additional-options "-ftrack-macro-expansion=0" } */
#define STR_I(X) #X
#define STR(X) STR_I(X)
#define LINE STR(__LINE__) STR(__LINE__)
int main()
{
  const char *s = LINE;
  if (s[0] != '9' || s[1] != '9')
    __builtin_abort ();
  return 0;
}
