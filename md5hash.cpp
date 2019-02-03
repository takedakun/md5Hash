#include <iostream>

using namespace std;

//auxiliary function. input: three 32-bit word, output: 32-bit word
int f_func(int x, int y, int z) {
  return (x & y) | (~x & z);
}

int g_func(int x, int y, int z) {
  return (x & y) | (y & ~z);
}

int h_func(int x, int y, int z) {
  return x ^ y ^ z;
}

int i_func(int x, int y, int z) {
  return y ^ (x | ~z);
}

//bitwise rotation shift
int bit_shift_rotation(int num, int cnt) {
  return (num << cnt) | (num >> (32-cnt));
}

//16bit add function
int two_byte_add(int x, int y) {
  int output = x + y;
  return (output & 0xFFFF);
}

//md5 operation
int md5_operation(int a, int b, int c, int d, int x_k, int s, int t_i, int func_type) {
  switch (func_type) {
    case 1:
      //call f_func
      return two_byte_add(b, bit_shift_rotation(two_byte_add(a, two_byte_add(x_k, two_byte_add(t_i, f_func(b, c, d)))), s));
    case 2:
      //call g_func
      return two_byte_add(b, bit_shift_rotation(two_byte_add(a, two_byte_add(x_k, two_byte_add(t_i, g_func(b, c, d)))), s));
    case 3:
      //call h_func
      return two_byte_add(b, bit_shift_rotation(two_byte_add(a, two_byte_add(x_k, two_byte_add(t_i, h_func(b, c, d)))), s));
    case 4:
      //call i_func
      return two_byte_add(b, bit_shift_rotation(two_byte_add(a, two_byte_add(x_k, two_byte_add(t_i, i_func(b, c, d)))), s));
    default:
      cout << "input correct type of func_type" << endl;
      return 0;
  }
}

//operatons using f_func
int operatons_f(int& buff_A, int& buff_B, int& buff_C, int& buff_D, int *X, int *T) {
  int func_type = 1;
  //update buff_A, buff_B, buff_C, buff_D
  buff_A = md5_operation(buff_A, buff_B, buff_C, buff_D, X[0], 7, -680876936, func_type);
  buff_D = md5_operation(buff_D, buff_A, buff_B, buff_C, X[1], 12, -389564586, func_type);
  buff_C = md5_operation(buff_C, buff_D, buff_A, buff_B, X[2], 17, 606105819, func_type);
  buff_B = md5_operation(buff_B, buff_C, buff_D, buff_A, X[3], 22, -1044525330, func_type);

  buff_A = md5_operation(buff_A, buff_B, buff_C, buff_D, X[4], 7, -176418897, func_type);
  buff_D = md5_operation(buff_D, buff_A, buff_B, buff_C, X[5], 12, 1200080426, func_type);
  buff_C = md5_operation(buff_C, buff_D, buff_A, buff_B, X[6], 17, -1473231341, func_type);
  buff_B = md5_operation(buff_B, buff_C, buff_D, buff_A, X[7], 22, -45705983, func_type);

  buff_A = md5_operation(buff_A, buff_B, buff_C, buff_D, X[8], 7, 1770035416, func_type);
  buff_D = md5_operation(buff_D, buff_A, buff_B, buff_C, X[9], 12, -1958414417, func_type);
  buff_C = md5_operation(buff_C, buff_D, buff_A, buff_B, X[10], 17, -42063, func_type);
  buff_B = md5_operation(buff_B, buff_C, buff_D, buff_A, X[11], 12, -1990404162, func_type);

  buff_A = md5_operation(buff_A, buff_B, buff_C, buff_D, X[12], 7, 1804603682, func_type);
  buff_D = md5_operation(buff_D, buff_A, buff_B, buff_C, X[13], 12, -40341101, func_type);
  buff_C = md5_operation(buff_C, buff_D, buff_A, buff_B, X[14], 17, -1502002290, func_type);
  buff_B = md5_operation(buff_B, buff_C, buff_D, buff_A, X[15], 22, 1236535329, func_type);
  return 0;
}

//operatons using g_func
int operatons_g(int& buff_A, int& buff_B, int& buff_C, int& buff_D, int *X, int *T) {
  int func_type = 2;
  //update buff_A, buff_B, buff_C, buff_D
  buff_A = md5_operation(buff_A, buff_B, buff_C, buff_D, X[1], 5, -165796510, func_type);
  buff_D = md5_operation(buff_D, buff_A, buff_B, buff_C, X[6], 9, -1069501632, func_type);
  buff_C = md5_operation(buff_C, buff_D, buff_A, buff_B, X[11], 14, 643717713, func_type);
  buff_B = md5_operation(buff_B, buff_C, buff_D, buff_A, X[0], 20, -373897302, func_type);

  buff_A = md5_operation(buff_A, buff_B, buff_C, buff_D, X[5], 5, -701558691, func_type);
  buff_D = md5_operation(buff_D, buff_A, buff_B, buff_C, X[10], 9, 38016083, func_type);
  buff_C = md5_operation(buff_C, buff_D, buff_A, buff_B, X[15], 14, -660478335, func_type);
  buff_B = md5_operation(buff_B, buff_C, buff_D, buff_A, X[4], 20, -405537848, func_type);

  buff_A = md5_operation(buff_A, buff_B, buff_C, buff_D, X[9], 5, 568446438, func_type);
  buff_D = md5_operation(buff_D, buff_A, buff_B, buff_C, X[14], 9, -1019803690, func_type);
  buff_C = md5_operation(buff_C, buff_D, buff_A, buff_B, X[3], 14, -187363961, func_type);
  buff_B = md5_operation(buff_B, buff_C, buff_D, buff_A, X[8], 20, 1163531501, func_type);

  buff_A = md5_operation(buff_A, buff_B, buff_C, buff_D, X[13], 5, -1444681467, func_type);
  buff_D = md5_operation(buff_D, buff_A, buff_B, buff_C, X[2], 9, -51403784, func_type);
  buff_C = md5_operation(buff_C, buff_D, buff_A, buff_B, X[7], 14, 1735328473, func_type);
  buff_B = md5_operation(buff_B, buff_C, buff_D, buff_A, X[12], 20, -1926607734, func_type);
  return 0;
}

//operatons using h_func
int operatons_h(int& buff_A, int& buff_B, int& buff_C, int& buff_D, int *X, int *T) {
  int func_type = 3;
  //update buff_A, buff_B, buff_C, buff_D
  buff_A = md5_operation(buff_A, buff_B, buff_C, buff_D, X[5], 4, -378558, func_type);
  buff_D = md5_operation(buff_D, buff_A, buff_B, buff_C, X[8], 11, -2022574463, func_type);
  buff_C = md5_operation(buff_C, buff_D, buff_A, buff_B, X[11], 16, 1839030562, func_type);
  buff_B = md5_operation(buff_B, buff_C, buff_D, buff_A, X[14], 23, -35309556, func_type);

  buff_A = md5_operation(buff_A, buff_B, buff_C, buff_D, X[1], 4, -1530992060, func_type);
  buff_D = md5_operation(buff_D, buff_A, buff_B, buff_C, X[4], 11, 1272893353, func_type);
  buff_C = md5_operation(buff_C, buff_D, buff_A, buff_B, X[7], 16, -155497632, func_type);
  buff_B = md5_operation(buff_B, buff_C, buff_D, buff_A, X[10], 23, -1094730640, func_type);

  buff_A = md5_operation(buff_A, buff_B, buff_C, buff_D, X[13], 4, 681279174, func_type);
  buff_D = md5_operation(buff_D, buff_A, buff_B, buff_C, X[0], 11, -358537222, func_type);
  buff_C = md5_operation(buff_C, buff_D, buff_A, buff_B, X[3], 16, -722521979, func_type);
  buff_B = md5_operation(buff_B, buff_C, buff_D, buff_A, X[6], 23, 76029189, func_type);

  buff_A = md5_operation(buff_A, buff_B, buff_C, buff_D, X[9], 4, -640364487, func_type);
  buff_D = md5_operation(buff_D, buff_A, buff_B, buff_C, X[12], 11, -421815835, func_type);
  buff_C = md5_operation(buff_C, buff_D, buff_A, buff_B, X[15], 16, 530742520, func_type);
  buff_B = md5_operation(buff_B, buff_C, buff_D, buff_A, X[2], 23, -995338651, func_type);
  return 0;
}

//operatons using i_func
int operatons_i(int& buff_A, int& buff_B, int& buff_C, int& buff_D, int *X, int *T) {
  int func_type = 4;
  //update buff_A, buff_B, buff_C, buff_D
  buff_A = md5_operation(buff_A, buff_B, buff_C, buff_D, X[0], 6, -198630844, func_type);
  buff_D = md5_operation(buff_D, buff_A, buff_B, buff_C, X[7], 10, 1126891415, func_type);
  buff_C = md5_operation(buff_C, buff_D, buff_A, buff_B, X[14], 15, -1416354905, func_type);
  buff_B = md5_operation(buff_B, buff_C, buff_D, buff_A, X[5], 21, -57434055, func_type);

  buff_A = md5_operation(buff_A, buff_B, buff_C, buff_D, X[12], 6, 1700485571, func_type);
  buff_D = md5_operation(buff_D, buff_A, buff_B, buff_C, X[3], 10, -1894986606, func_type);
  buff_C = md5_operation(buff_C, buff_D, buff_A, buff_B, X[10], 15, -1051523, func_type);
  buff_B = md5_operation(buff_B, buff_C, buff_D, buff_A, X[1], 21, -2054922799, func_type);

  buff_A = md5_operation(buff_A, buff_B, buff_C, buff_D, X[8], 6, 1873313359, func_type);
  buff_D = md5_operation(buff_D, buff_A, buff_B, buff_C, X[15], 10, -30611744, func_type);
  buff_C = md5_operation(buff_C, buff_D, buff_A, buff_B, X[6], 15, -1560198380, func_type);
  buff_B = md5_operation(buff_B, buff_C, buff_D, buff_A, X[13], 21, 1309151649, func_type);

  buff_A = md5_operation(buff_A, buff_B, buff_C, buff_D, X[4], 6, -145523070, func_type);
  buff_D = md5_operation(buff_D, buff_A, buff_B, buff_C, X[11], 10, -1120210379, func_type);
  buff_C = md5_operation(buff_C, buff_D, buff_A, buff_B, X[2], 15, 718787259, func_type);
  buff_B = md5_operation(buff_B, buff_C, buff_D, buff_A, X[9], 21, -343485551, func_type);
  return 0;
}



int main(int argc, char *argv[]) {
  char *message = "takeryo";

  //use four 32bit buffer.
  int buff_A, buff_B, buff_C, buff_D;
  buff_A = 1732584193; // hexadecimal 67452301
  buff_B = -271733879; // hexadecimal efcdab89
  buff_C = -1732584194; //hexadecimal 98badcfe
  buff_D = 271733878; //hexadecimal 10325476

  for () {

  }
  cout << << endl;
  return 0;
}
