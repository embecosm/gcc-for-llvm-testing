/* { dg-require-effective-target indirect_jumps } */
/* { dg-require-effective-target nonlabel_goto } */

f(x){goto*(void *)x;}
