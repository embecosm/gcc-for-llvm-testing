/* PR middle-end/31095, expand_builtin_memmove_args forgot to take into
   account that tree folding of builtins can add an extra NOP_EXPR.   */
/* { dg-require-effective-target builtin_bcopy } */

struct timeval
{
  int tv_sec;
  int tv_usec;
};
void
capture_next_packet (void)
{
  struct timeval past, now, then;
  __builtin_bcopy (&then, &past, sizeof (then));
}
