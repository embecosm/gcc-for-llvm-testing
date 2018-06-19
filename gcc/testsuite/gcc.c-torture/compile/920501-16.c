/* { dg-require-effective-target vla_in_struct } */
f(n){struct z{int a,b[n],c[n];};}
