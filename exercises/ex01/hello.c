int main()
{
	int x = 5;
	int y = x + 1;
	printf(y);
}
/*
11) This is the line repsonible for setting x = 5: movl	$5, -4(%rbp)
12) With the -O2 optimization added, there are far fewer lines of machine code to do the same thing. Also
there was a warning about printf that wasn't there before.
13) The optimization no longer uses "puts" and instead uses jmp to go to where the printf function begins.
The non optimized version isn't very different from the version before.
14) The non-optimized version acts normally by assigning both x and y the numbers associated with them, but
the optimized version just abstracts out x because it has no relevance after y is declared, and seems to just
declare y to be 6 instead of going through process of adding 1 to x.
*/
