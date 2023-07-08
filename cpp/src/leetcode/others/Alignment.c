#define ALIGNMENT 8 // must be a power of 2
#define ALIGN(size) (((size) + (ALIGNMENT-1)) & ~(ALIGNMENT-1))

/*
for (i=1; i<=32; i+=2) {
	printf("ALIGN(%d) = %d\n",i, ALIGN(i));
}

Result:

ALIGN(1) = 8
ALIGN(3) = 8
ALIGN(5) = 8
ALIGN(7) = 8
ALIGN(9) = 16
ALIGN(11) = 16
ALIGN(13) = 16
ALIGN(15) = 16
ALIGN(17) = 24
ALIGN(19) = 24
ALIGN(21) = 24
ALIGN(23) = 24
ALIGN(25) = 32
ALIGN(27) = 32
ALIGN(29) = 32
ALIGN(31) = 32
*/