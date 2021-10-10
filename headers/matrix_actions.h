
enum Errors {MRX_OK, MRX_MALLOC_ERR, MRX_INPUT_ERR};

int matrix_init(float*** matrix, int m, int n);
int matrix_input(float** matrix, int m, int n);
void matrix_print(float** matrix, int m, int n);

int string_is_zero(float* a, int len);
int string_sum(float* a, const float* b, float k, int len);
int string_mul(float* a, float k, int len);
int string_trade(float* a, float* b, int len);