/* { dg-options "-O2 -funit-at-a-time" } */
/* { dg-final { scan-assembler-not "big_function_2" } } */
/* { dg-additional-options "-Wno-ignored-optimization-argument" } */

int t(void);
static void
big_function_2(void);
void
big_function_1()
{
	while (t());
	while (t());
	while (t());
	while (t());
	while (t());
	while (t());
	while (t());
	while (t());
	while (t());
	while (t());
	while (t());
	while (t());
	while (t());
	while (t());
	while (t());
	while (t());
	while (t());
	big_function_2();
}
static void
big_function_2()
{
	while (t());
	while (t());
	while (t());
	while (t());
	while (t());
	while (t());
	while (t());
	while (t());
	while (t());
	while (t());
	while (t());
	while (t());
	while (t());
	while (t());
	while (t());
	while (t());
	while (t());
}
