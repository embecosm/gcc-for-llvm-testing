/* { dg-require-effective-target untyped_assembly } */
/* { dg-require-effective-target builtin_apply } */

g (a, b) {}

f (xx)
     void* xx;
{
  __builtin_apply ((void*)g, xx, 200);
}
