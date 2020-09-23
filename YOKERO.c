#include <drawlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

 void start(void);

 int main(void) {
   int ran1 = rand() % 3 - 0, ran2 = rand() % 3 - 0, i1 = 0;
   int move = 10;
   int kya1x = DL_WIDTH / 2, kya1y = DL_HEIGHT / 2, br = 25;
   int t, k, x, y;
   int start_time, end_time, total_time = 0;;
   int tx = DL_HEIGHT / 2 , ty = DL_WIDTH / 2 - 150;
   int b = 590, by = 0, c = 640, cy = DL_WIDTH/2, d = 490, dy = DL_HEIGHT, e = 540, ey = DL_WIDTH/2 - 80;
   int bc = 0, de = 0, sp1 = 0, sp2 = 0;
   int bvb = 4.0, bvc = 4.0, bvd = 6.0, bve = 6.0;
   char z[] = " ";
  
   dl_initialize(1.0);
  
  /* スタート画面を表示 */
   start();
  
  /* タイマースタート */
   start_time = time(NULL);
  
  /* バーの移動速度をランダムで設定 */
   bvb = 4.0 + ran1;
   bvc = 4.0 + ran1;
   bvd = 5.5 + ran2;
   bve = 5.5 + ran2;
  
   while (1) {
   
  /* 操作手順 */
     while(dl_get_event(&t, &k, &x, &y)){
      
       if (k == DL_KEY_UP) {
         kya1y -= move;
     } else if (k == DL_KEY_DOWN) {
         kya1y += move; 
       }
     }
     
  /* バーの移動 */   
     b -= bvb;
     c -= bvc;    
     d -= bvd;
     e -= bve;
     
  /* 球がy軸上の画面外をはみ出ないように設定 */      
     if (kya1y <= 0) {
       kya1y = br + 1;
   } else if (kya1y + br >= DL_HEIGHT) {
       kya1y = DL_HEIGHT - br - 1;
   }
   
  /* 壁に到達したら、反対向きに移動。さらにスピード加速 */
     if ((b <= 0) || (c >= DL_WIDTH)) {       
       bvb = (bvb + sp1) * (-1) ;
       bvc = (bvc + sp1) * (-1) ;
       bc++;
    }
  
     if ((d <= 0) || (e >= DL_WIDTH)) {
       bvd = (bvd + sp2) * (-1);
       bve = (bve + sp2) * (-1);
       de++;
    }
    
  /* 三回壁に当たったら、スピードが（0.1　＋　0.1)づつ加速できるよう設定
　　十回まで上がり続ける */
     if (bc >= 3 && bc <= 10) {
       sp1 = sp1 + 0.1;
    }

     if (de >= 3 && de <= 10) {
       sp2 = sp2 - 0.1;
    }
    
   /* 当たり判定 */
     if (((b <= kya1x - br / 2 ) && ((c - b) + b >= kya1x - br / 2)) && ((0 < kya1y - br / 2) && (cy >  kya1y + br / 2))) {
 
       break;
    }
     if (((d <= kya1x - br / 2 ) && ((e - d) + d >= kya1x - br / 2)) && ((dy > kya1y - br / 2) && (ey <  kya1y + br / 2))) {

       break;
    }
    
   /* 描写設定 */
     dl_stop();
     dl_clear(DL_C("white"));  
     
     dl_circle(kya1x, kya1y, br, DL_C("white"), 1, 1); 
     dl_circle(kya1x, kya1y, br, DL_C("blue"), 1, 1);
    
     dl_rectangle(b, by, c, cy, DL_C("green"), 1, 1);  
     dl_rectangle(d, dy, e, ey, DL_C("green"), 1, 1);
    
     dl_resume();
     
     dl_wait(0.05);
           
 } /* 計測時間を計算 */
     end_time = time(NULL);     
     total_time = end_time - start_time;
     sprintf(z,"%d", total_time);
   
   /* 終了画面 */
     dl_rectangle(DL_WIDTH / 6, DL_HEIGHT / 4, 640 - DL_WIDTH / 6, 480 - DL_HEIGHT / 4, DL_C("yellow"), 1, 1);
       
     dl_text(z, DL_WIDTH / 2 - 40, ty + 150,  4, DL_C("red"), 3);
       
     dl_text("time", tx - 20, ty + 50, 3, DL_C("black"), 3);
       
     while(1){
     
   /* どこかのキーを押せば終了 */
       if(dl_get_event(&t, &k, &x, &y) && t == DL_EVENT_KEY){

         break;
       }
     }
     return 0;
} 
  void start(void){
  
    int t, k, x, y;

   /* スタート画面描写 */
      dl_text("[YOKERO!!]", DL_WIDTH / 4 - 50, DL_HEIGHT / 5 + 80, 2.5, DL_C("black"),4.5);
      dl_rectangle(250, 300, 400, 350, DL_C("red"), 2, 2);
      dl_text("START", 280, 335, 1, DL_C("white"),2);
      dl_rectangle(560, 0, 650, 480, DL_C("green"), 1, 1);
      dl_circle(40, 440, 80, DL_C("blue"), 1, 1);
    
      while(1)
     {
        if(dl_get_event(&t, &k, &x, &y))
       {
          if(t == DL_EVENT_L_DOWN)
         { 
         
    /* この範囲内でクリックしたらループを抜ける */
            if(250 < x && x < 400 && 300 < y && y < 350)
           {
              dl_clear(DL_C("white"));
              break;      
    
            }
      
          }
      
       }
     
     }
  
  }
   
