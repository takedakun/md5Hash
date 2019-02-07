#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <stdint.h>

using namespace std;

//auxiliary function. input: three 32-bit word, output: 32-bit word
int f_func(int x, int y, int z) {
  return (x & y) | (~x & z);
}

int g_func(int x, int y, int z) {
  return (x & z) | (y & ~z);
}

int h_func(int x, int y, int z) {
  return x ^ y ^ z;
}

int i_func(int x, int y, int z) {
  return y ^ (x | ~z);
}

//bitwise rotation shift
int bit_shift_rotation(uint32_t num, int cnt) {
  return (num << cnt) | (num >> (32-cnt));
}

//add function
int bit_32_add(int x, int y) {
  int output = x + y;
  return (output & 0xFFFFFFFF);
}

//md5 operation
int md5_operation(int a, int b, int c, int d, int x_k, int s, int t_i, int func_type) {
  switch (func_type) {
    case 1:
      //call f_func
      return bit_32_add(b, bit_shift_rotation(bit_32_add(a, bit_32_add(x_k, bit_32_add(t_i, f_func(b, c, d)))), s));
    case 2:
      //call g_func
      return bit_32_add(b, bit_shift_rotation(bit_32_add(a, bit_32_add(x_k, bit_32_add(t_i, g_func(b, c, d)))), s));
    case 3:
      //call h_func
      return bit_32_add(b, bit_shift_rotation(bit_32_add(a, bit_32_add(x_k, bit_32_add(t_i, h_func(b, c, d)))), s));
    case 4:
      //call i_func
      return bit_32_add(b, bit_shift_rotation(bit_32_add(a, bit_32_add(x_k, bit_32_add(t_i, i_func(b, c, d)))), s));
    default:
      cout << "input correct type of func_type" << endl;
      return 0;
  }
}

//operatons using f_func
int operatons_f(int& buff_A, int& buff_B, int& buff_C, int& buff_D, int *X, int i) {
  int func_type = 1;
  //update buff_A, buff_B, buff_C, buff_D
  buff_A = md5_operation(buff_A, buff_B, buff_C, buff_D, X[i+0], 7, -680876936, func_type);
  buff_D = md5_operation(buff_D, buff_A, buff_B, buff_C, X[i+1], 12, -389564586, func_type);
  buff_C = md5_operation(buff_C, buff_D, buff_A, buff_B, X[i+2], 17, 606105819, func_type);
  buff_B = md5_operation(buff_B, buff_C, buff_D, buff_A, X[i+3], 22, -1044525330, func_type);

  buff_A = md5_operation(buff_A, buff_B, buff_C, buff_D, X[i+4], 7, -176418897, func_type);
  buff_D = md5_operation(buff_D, buff_A, buff_B, buff_C, X[i+5], 12, 1200080426, func_type);
  buff_C = md5_operation(buff_C, buff_D, buff_A, buff_B, X[i+6], 17, -1473231341, func_type);
  buff_B = md5_operation(buff_B, buff_C, buff_D, buff_A, X[i+7], 22, -45705983, func_type);

  buff_A = md5_operation(buff_A, buff_B, buff_C, buff_D, X[i+8], 7, 1770035416, func_type);
  buff_D = md5_operation(buff_D, buff_A, buff_B, buff_C, X[i+9], 12, -1958414417, func_type);
  buff_C = md5_operation(buff_C, buff_D, buff_A, buff_B, X[i+10], 17, -42063, func_type);
  buff_B = md5_operation(buff_B, buff_C, buff_D, buff_A, X[i+11], 22, -1990404162, func_type);

  buff_A = md5_operation(buff_A, buff_B, buff_C, buff_D, X[i+12], 7, 1804603682, func_type);
  buff_D = md5_operation(buff_D, buff_A, buff_B, buff_C, X[i+13], 12, -40341101, func_type);
  buff_C = md5_operation(buff_C, buff_D, buff_A, buff_B, X[i+14], 17, -1502002290, func_type);
  buff_B = md5_operation(buff_B, buff_C, buff_D, buff_A, X[i+15], 22, 1236535329, func_type);

  return 0;
}

//operatons using g_func
int operatons_g(int& buff_A, int& buff_B, int& buff_C, int& buff_D, int *X, int i) {
  int func_type = 2;
  //update buff_A, buff_B, buff_C, buff_D
  buff_A = md5_operation(buff_A, buff_B, buff_C, buff_D, X[i+1], 5, -165796510, func_type);
  buff_D = md5_operation(buff_D, buff_A, buff_B, buff_C, X[i+6], 9, -1069501632, func_type);
  buff_C = md5_operation(buff_C, buff_D, buff_A, buff_B, X[i+11], 14, 643717713, func_type);
  buff_B = md5_operation(buff_B, buff_C, buff_D, buff_A, X[i+0], 20, -373897302, func_type);

  buff_A = md5_operation(buff_A, buff_B, buff_C, buff_D, X[i+5], 5, -701558691, func_type);
  buff_D = md5_operation(buff_D, buff_A, buff_B, buff_C, X[i+10], 9, 38016083, func_type);
  buff_C = md5_operation(buff_C, buff_D, buff_A, buff_B, X[i+15], 14, -660478335, func_type);
  buff_B = md5_operation(buff_B, buff_C, buff_D, buff_A, X[i+4], 20, -405537848, func_type);

  buff_A = md5_operation(buff_A, buff_B, buff_C, buff_D, X[i+9], 5, 568446438, func_type);
  buff_D = md5_operation(buff_D, buff_A, buff_B, buff_C, X[i+14], 9, -1019803690, func_type);
  buff_C = md5_operation(buff_C, buff_D, buff_A, buff_B, X[i+3], 14, -187363961, func_type);
  buff_B = md5_operation(buff_B, buff_C, buff_D, buff_A, X[i+8], 20, 1163531501, func_type);

  buff_A = md5_operation(buff_A, buff_B, buff_C, buff_D, X[i+13], 5, -1444681467, func_type);
  buff_D = md5_operation(buff_D, buff_A, buff_B, buff_C, X[i+2], 9, -51403784, func_type);
  buff_C = md5_operation(buff_C, buff_D, buff_A, buff_B, X[i+7], 14, 1735328473, func_type);
  buff_B = md5_operation(buff_B, buff_C, buff_D, buff_A, X[i+12], 20, -1926607734, func_type);
  return 0;
}

//operatons using h_func
int operatons_h(int& buff_A, int& buff_B, int& buff_C, int& buff_D, int *X, int i) {
  int func_type = 3;
  //update buff_A, buff_B, buff_C, buff_D
  buff_A = md5_operation(buff_A, buff_B, buff_C, buff_D, X[i+5], 4, -378558, func_type);
  buff_D = md5_operation(buff_D, buff_A, buff_B, buff_C, X[i+8], 11, -2022574463, func_type);
  buff_C = md5_operation(buff_C, buff_D, buff_A, buff_B, X[i+11], 16, 1839030562, func_type);
  buff_B = md5_operation(buff_B, buff_C, buff_D, buff_A, X[i+14], 23, -35309556, func_type);

  buff_A = md5_operation(buff_A, buff_B, buff_C, buff_D, X[i+1], 4, -1530992060, func_type);
  buff_D = md5_operation(buff_D, buff_A, buff_B, buff_C, X[i+4], 11, 1272893353, func_type);
  buff_C = md5_operation(buff_C, buff_D, buff_A, buff_B, X[i+7], 16, -155497632, func_type);
  buff_B = md5_operation(buff_B, buff_C, buff_D, buff_A, X[i+10], 23, -1094730640, func_type);

  buff_A = md5_operation(buff_A, buff_B, buff_C, buff_D, X[i+13], 4, 681279174, func_type);
  buff_D = md5_operation(buff_D, buff_A, buff_B, buff_C, X[i+0], 11, -358537222, func_type);
  buff_C = md5_operation(buff_C, buff_D, buff_A, buff_B, X[i+3], 16, -722521979, func_type);
  buff_B = md5_operation(buff_B, buff_C, buff_D, buff_A, X[i+6], 23, 76029189, func_type);

  buff_A = md5_operation(buff_A, buff_B, buff_C, buff_D, X[i+9], 4, -640364487, func_type);
  buff_D = md5_operation(buff_D, buff_A, buff_B, buff_C, X[i+12], 11, -421815835, func_type);
  buff_C = md5_operation(buff_C, buff_D, buff_A, buff_B, X[i+15], 16, 530742520, func_type);
  buff_B = md5_operation(buff_B, buff_C, buff_D, buff_A, X[i+2], 23, -995338651, func_type);
  return 0;
}

//operatons using i_func
int operatons_i(int& buff_A, int& buff_B, int& buff_C, int& buff_D, int *X, int i) {
  int func_type = 4;
  //update buff_A, buff_B, buff_C, buff_D
  buff_A = md5_operation(buff_A, buff_B, buff_C, buff_D, X[i+0], 6, -198630844, func_type);
  buff_D = md5_operation(buff_D, buff_A, buff_B, buff_C, X[i+7], 10, 1126891415, func_type);
  buff_C = md5_operation(buff_C, buff_D, buff_A, buff_B, X[i+14], 15, -1416354905, func_type);
  buff_B = md5_operation(buff_B, buff_C, buff_D, buff_A, X[i+5], 21, -57434055, func_type);

  buff_A = md5_operation(buff_A, buff_B, buff_C, buff_D, X[i+12], 6, 1700485571, func_type);
  buff_D = md5_operation(buff_D, buff_A, buff_B, buff_C, X[i+3], 10, -1894986606, func_type);
  buff_C = md5_operation(buff_C, buff_D, buff_A, buff_B, X[i+10], 15, -1051523, func_type);
  buff_B = md5_operation(buff_B, buff_C, buff_D, buff_A, X[i+1], 21, -2054922799, func_type);

  buff_A = md5_operation(buff_A, buff_B, buff_C, buff_D, X[i+8], 6, 1873313359, func_type);
  buff_D = md5_operation(buff_D, buff_A, buff_B, buff_C, X[i+15], 10, -30611744, func_type);
  buff_C = md5_operation(buff_C, buff_D, buff_A, buff_B, X[i+6], 15, -1560198380, func_type);
  buff_B = md5_operation(buff_B, buff_C, buff_D, buff_A, X[i+13], 21, 1309151649, func_type);

  buff_A = md5_operation(buff_A, buff_B, buff_C, buff_D, X[i+4], 6, -145523070, func_type);
  buff_D = md5_operation(buff_D, buff_A, buff_B, buff_C, X[i+11], 10, -1120210379, func_type);
  buff_C = md5_operation(buff_C, buff_D, buff_A, buff_B, X[i+2], 15, 718787259, func_type);
  buff_B = md5_operation(buff_B, buff_C, buff_D, buff_A, X[i+9], 21, -343485551, func_type);
  return 0;
}

//change char to int
int char2int(char c){
  return (c & 0xFF);
}

//change message to binary and append padding
int* message2binary_array(char* message) {
  int message_length = strlen(message);
  int words_num = message_length >> 2;
  int array_length = (words_num/14 + 1)*16;
  static int *output_array = new int[array_length];

  for(int i=0; i<words_num; i+=1) {
    for(int j=0; j<4; j++) {
      output_array[i] += (char2int(message[4*i+j]) << j*8);
    }
  }
  //append padding
  if(message_length%4 == 0) {
    output_array[words_num] = (1 << 7);
  } else {
    for(int i=0; i < message_length%4; i++){
      output_array[words_num] += (char2int(message[words_num*4+i]) << i*8);
    }
    output_array[words_num] += (1 << (8*(message_length%4 + 1)-1));
  }
  //add length of message to end of output_array
  output_array[array_length-2] = message_length * 8;
  return output_array;
}

//change int to hexadecimal
char int_buff2hex_char(int buff_A, int buff_B, int buff_C, int buff_D) {
  return 0;
}

int main(int argc, char *argv[]) {
  char message[] = "takeryo";
  int *encoded_message = message2binary_array(message);
  int encoded_message_length = ((strlen(message) >> 2)/14 + 1)*16;

  //use four 32bit buffer.
  int buff_A, buff_B, buff_C, buff_D, buff_AA, buff_BB, buff_CC, buff_DD;
  buff_A = 0x67452301; // hexadecimal 67452301 decimal 173258419
  buff_B = 0xefcdab89; // hexadecimal efcdab89 decimal -271733879
  buff_C = 0x98badcfe; //hexadecimal 98badcfe decimal -1732584194
  buff_D = 0x10325476; //hexadecimal 10325476 decimal 271733878

  for (int i=0; i < encoded_message_length; i+=16) {
    buff_AA = buff_A;
    buff_BB = buff_B;
    buff_CC = buff_C;
    buff_DD = buff_D;
    operatons_f(buff_A, buff_B, buff_C, buff_D, encoded_message, i);
    operatons_g(buff_A, buff_B, buff_C, buff_D, encoded_message, i);
    operatons_h(buff_A, buff_B, buff_C, buff_D, encoded_message, i);
    operatons_i(buff_A, buff_B, buff_C, buff_D, encoded_message, i);
    buff_A = bit_32_add(buff_A, buff_AA);
    buff_B = bit_32_add(buff_B, buff_BB);
    buff_C = bit_32_add(buff_C, buff_CC);
    buff_D = bit_32_add(buff_D, buff_DD);
  }

  uint32_t digest_A, digest_B, digest_C, digest_D;
  digest_A = buff_A;
  digest_B = buff_B;
  digest_C = buff_C;
  digest_D = buff_D;
  for(int i=0; i<4; i++) {
    cout << hex << ((digest_A & (0xFF << (i*8))) >> (8*i) );
  }
  for(int i=0; i<4; i++) {
    cout << hex << ((digest_B & (0xFF << (i*8))) >> (8*i) );
  }
  for(int i=0; i<4; i++) {
    cout << hex << ((digest_C & (0xFF << (i*8))) >> (8*i) );
  }
  for(int i=0; i<4; i++) {
    cout << hex << ((digest_D & (0xFF << (i*8))) >> (8*i) );
  }
  cout << endl;
  return 0;
}
