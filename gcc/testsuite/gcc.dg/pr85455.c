/* { dg-do compile } */
/* { dg-options "-O1 -fthread-jumps -fno-tree-dominator-opts -fno-tree-reassoc -fno-tree-sink -fno-tree-slsr" } */
/* { dg-require-effective-target gcc_frontend } */

void
ty (void);

void
um (void);

void
au (int qj)
{
  if (qj < 1)
    {
vq:
      ty ();
    }

  um ();

  goto vq;
}
