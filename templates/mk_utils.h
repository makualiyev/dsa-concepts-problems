#define STR(x) #x
#define PRINT_INT_VAL(x) printf("%s = %d\n", #x, x)
#define ARRAY_SIZE(x) (sizeof(x) / sizeof((x)[0]))
#define FIELD_SIZEOF(t, f) (sizeof(((t*)0)->f))