int main() {
    char x[10] = {00,11,22,33,44,55,66,77,88,99};
    x[12345678] = 'a';
    //x is only an array of size 10
    return x[0];
}
