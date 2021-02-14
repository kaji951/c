/*　ジャンケンゲームができるプログラムを作成する。

ソースプログラム： */

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void hantei(int, int);
char *c_to_str(int);

int main(void){
  int m, key;
  char b[3] = {'0', '1', '2'};
  printf("【ジャンケンゲームシミュレータ】\n");
  printf("【0（グー）、1（チョキ）、2（パー）を出そう【'Q'または'q'で終了】\n");
  printf("じゃんーけんーぼん\n");
  while( (key = getchar() ) != EOF ){
    if(key == 'Q' || key== 'q') {
      printf("ゲーム終了！お疲れ\n");
      return(0);
    }
    srand(time(NULL));
    m = rand() % 3;
    hantei( b[m], key);
  }
  return(0);
}
void hantei(int m, int key){
  if(m == key){
    printf("アイコ！\n");
    return;
  }
  switch (key) {
  case '0':
    if(m=='2'){
      printf("負け！ (自分%s 相手%s)\n", c_to_str(key), c_to_str(m));
    }
    if(m=='1'){
      printf("勝ち！ (自分%s 相手%s)\n", c_to_str(key), c_to_str(m));
    }
    break;
  case '1':
    if(m=='0'){
      printf("負け！ (自分%s 相手%s)\n", c_to_str(key), c_to_str(m));
    }
    if(m=='2'){
      printf("勝ち！ (自分%s 相手%s)\n", c_to_str(key), c_to_str(m));
    }
    break;
  case '2':
    if(m=='1'){
      printf("負け！ (自分%s 相手%s)\n", c_to_str(key), c_to_str(m));
    }
    if(m=='0'){
      printf("勝ち！ (自分%s 相手%s)\n", c_to_str(key), c_to_str(m));
    }
    break;
  }
}
char *c_to_str(int c){
  if(c == '0'){
    return("グー");
  }
  if(c == '1'){
    return("チョキ");
  }
  if(c == '2'){
    return("パー");
  }
  return 0;
}