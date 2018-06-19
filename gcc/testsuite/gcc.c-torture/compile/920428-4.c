/* { dg-skip-if "requires alloca" { ! alloca } { "-O0" } { "" } } */
/* { dg-require-effective-target vla_in_struct } */
x(a){struct{int p[a],i;}l;l.i;}
