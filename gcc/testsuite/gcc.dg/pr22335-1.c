/* { dg-do compile } */
/* { dg-options "-O1 -fdelete-null-pointer-checks"  } */
/* { dg-require-effective-target delete_null_pointer_checks } */
int t(int *a)
{
  int i;
  *a = 1;
  i = a == 0;
  return i;
}

