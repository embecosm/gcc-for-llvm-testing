/* { dg-require-effective-target nested_func } */
f ()
{
  long long i;
  int j;
  long long k = i = j;

  int inner () {return j + i;}
  return k;
}
