/* { dg-require-effective-target indirect_jumps } */
/* { dg-require-effective-target nonlabel_goto } */

int jump () { goto * (int (*) ()) 0xbabebec0; }

