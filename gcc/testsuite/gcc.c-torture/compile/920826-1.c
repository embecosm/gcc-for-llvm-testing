/* { dg-require-effective-target indirect_jumps } */
/* { dg-require-effective-target nonlabel_goto } */

f(int*x){goto*(void*)(__INTPTR_TYPE__)(char)*x;}
