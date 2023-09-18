#define SET_BIT(n, b) (n = n | (1 << b))
#define CLR_BIT(n, b) (n = n & ~(1 << b))
#define TGL_BIT(n, b) (n = n ^ (1 << b))
#define GET_BIT(n, b) (n = (n >> b) & 1)
