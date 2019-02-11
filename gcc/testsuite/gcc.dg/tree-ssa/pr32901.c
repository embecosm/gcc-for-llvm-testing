/* { dg-do compile } */
/* { dg-options "-O -fdump-tree-gimple" } */
/* { dg-require-effective-target gcc_frontend } */

struct foo {
        unsigned a1: 1;
        unsigned a2: 3;
        unsigned : 4;
};

extern struct foo thefoo, theotherfoo;

void setup_foo(void)
{
        const struct foo init = {
                .a1 = 1,
                .a2 = 5,
        };
	volatile const struct foo volinit = {
		.a1 = 0,
		.a2 = 6
	};
        thefoo = init;
	theotherfoo = volinit;
}

/* { dg-final { scan-tree-dump-times "thefoo.* = {}" 1 "gimple"} } */
/* { dg-final { scan-tree-dump-times "thefoo.* = 1" 1 "gimple"} } */
/* { dg-final { scan-tree-dump-times "thefoo.* = 5" 1 "gimple"} } */
/* { dg-final { scan-tree-dump-times "theotherfoo = volinit" 1 "gimple"} } */
