/* { dg-require-effective-target indirect_jumps } */
/* { dg-require-effective-target nonlabel_goto } */

extern void*t[];x(i){goto*t[i];}
