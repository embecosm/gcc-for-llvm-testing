/* { dg-do compile } */
/* { dg-options "-W -Wall -Werror" } */
/* { dg-require-effective-target gcc_frontend } */

static inline int unused_fn(int dummyarg)
{
	return dummyarg*dummyarg;
}

int main()
{
	return 0;
}
