/* { dg-do compile } */
/* { dg-options "-O2 -fdump-tree-profile_estimate" } */
/* { dg-require-effective-target gcc_frontend } */

int main(int argc, char **argv)
{
  if (argc == 123)
    goto exit;
  else
    {
      return 0;
    }

exit:
  return 1;
}

/* { dg-final { scan-tree-dump "goto heuristics of edge" "profile_estimate"} } */
