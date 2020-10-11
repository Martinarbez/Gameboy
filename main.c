#include <stdlib.h>
#include <stdio.h>
#include <gb/gb.h>
#include <stdbool.h>
#include <stdint.h>
#include <rand.h>
//#include <time.h>

#include <gb/font.h>



#include "elle.c"

#include "back.c"

#include "backmap.c"
#include "fruta.c"
#include "windows.c"
#include "startwindows.c"

const unsigned int blankmap[1]= {0x00};


bool puedomoverme (int i){
  bool result = (backmap[i-1] == blankmap[0]);
  return result;
  }


  
    
    /***********************************
     * i el personaje
     * j la primer fruta 
     * s la segunda fruta
    ***********************************/
  
  int randomFruta(int i){
      int j = 0;
      int a = 0;
      int b = 0;
      while ( !puedomoverme(j) || !puedomoverme(j+21) || !puedomoverme(j+20) || !puedomoverme(j+1) || i==j || i==j +1 || i==j-1|| i==j-20|| i ==j-19 || i==j-21|| i ==j+19 || i==j+20 || i==j+21){
      a = (unsigned)rand()%18+1;
      b = (unsigned)rand()%16+1;
      j =((b-2)*20)+a;
      }
      move_sprite(2,a*8,b*8);
      move_sprite(3,(a*8)+8,b*8);
      return j;
      }

  int randomFruta2(int i){
      int s = 0;
      int a = 0;
      int b = 0;
      while ( !puedomoverme(s) || !puedomoverme(s+21) || !puedomoverme(s+20) || !puedomoverme(s+1) || i==s || i==s +1 || i==s-1|| i==s-20|| i ==s-19 || i==s-21|| i ==s+19 || i==s+20 || i==s+21){
      a = (unsigned)rand()%18+1;
      b = (unsigned)rand()%16+1;
      s =((b-2)*20)+a;
      }
     
      move_sprite(4,a*8,b*8);
      move_sprite(5,(a*8)+8,b*8);
      
      return s;
      }
    
         

void main(void) {
    //srand((unsigned) time(NULL));
    //Personaje
    //puts("\n\n\n\n\nDale start perro!!!");
    font_t min_font;
    font_init();
    min_font = font_load(font_min); // tile
    font_set(min_font);



    set_win_tiles(0,0,20,18,startwindows);
    move_win(7,0);
    SHOW_WIN;
    DISPLAY_ON;

    delay(2000);

    waitpad(0xFF);
    waitpadup();
    int l = DIV_REG;
    initarand(l);
    //
    //fuente
    
    
    
    set_win_tiles(0,0,20,2,windows);
    move_win(7,128);
    
    //
        
    SPRITES_8x16;
    set_sprite_data(0,48,Elle);
    set_sprite_tile(0,0);
    move_sprite(0,16,32);
    set_sprite_tile(1,2);
    move_sprite(1,24,32);
    unsigned int i = 42;


    SPRITES_8x16;
    set_sprite_data(48,56,fruta);
    set_sprite_tile(2,48);
    set_sprite_tile(3,50);
    set_sprite_tile(4,52);
    set_sprite_tile(5,54);
    move_sprite(2,0,0);
    move_sprite(3,0,0);
    move_sprite(4,0,0);
    move_sprite(5,0,0);
    unsigned int j = randomFruta(i);

      
    
    unsigned int s = randomFruta2(i);



    SHOW_SPRITES;
    
    
    //mapa
    set_bkg_data(38,6,back);  //tile, cantidad de tildes,donde estan//
    set_bkg_tiles(0,0,20,18,backmap);

    SHOW_BKG;
    DISPLAY_ON;

    
    
    while (1)
    {
        


      switch (joypad())
      {

      case J_B:
       
      j = randomFruta(i);
      delay(300);
      s = randomFruta2(i);
      delay(300);

      if(windows[8]==0x0B){
          windows[8]=0x02;
          windows[7]=windows[7]+0x01;
        }
        else if (windows[8]!=0x0B) {
        windows[8]=windows[8] + 0x01;
        }
        set_win_tiles(0,0,20,2,windows);

        if(windows[28]==0x0B){
          windows[28]=0x02;
          windows[27]=windows[27]+0x01;
        }
        else if (windows[28]!=0x0B) {
        windows[28]=windows[28] + 0x01;
        }
        set_win_tiles(0,0,20,2,windows);
      /*
      delay(400);
      mapita[3]=blankmap[0];
      set_bkg_tiles(0,0,20,18,mapita);
      delay(100);
      if (mapita[3]==blankmap[0]){
        mapita[3]=mapita[2];
        set_bkg_tiles(0,0,20,18,mapita);
      }*/

      
      case J_A:  
      
      if(i+2==j) {
        j = randomFruta(i);
        delay(400);
        if(windows[8]==0x0B){
          windows[8]=0x02;
          windows[7]=windows[7]+0x01;
        }
        else if (windows[8]!=0x0B) {
        windows[8]=windows[8] + 0x01;
        }
        set_win_tiles(0,0,20,2,windows);
        
        
        
      }
      if(i-40==j) {
        j = randomFruta(i);
        //printf("%d",j);   
        delay(400);

       if(windows[8]==0x0B){
          windows[8]=0x02;
          windows[7]=windows[7]+0x01;
        }
        else if (windows[8]!=0x0B) {
        windows[8]=windows[8] + 0x01;
        }
        set_win_tiles(0,0,20,2,windows);
      }
      if(i+-2==j){
        j = randomFruta(i);
       // printf("%d",j);   
        delay(400);

      if(windows[8]==0x0B){
          windows[8]=0x02;
          windows[7]=windows[7]+0x01;
        }
        else if (windows[8]!=0x0B) {
        windows[8]=windows[8] + 0x01;
        }
        set_win_tiles(0,0,20,2,windows);
        
      }
      if((i+40==j) ){
        j = randomFruta(i);
        //printf("%d",j);   
        delay(400);

        if(windows[8]==0x0B){
          windows[8]=0x02;
          windows[7]=windows[7]+0x01;
        }
        else if (windows[8]!=0x0B) {
        windows[8]=windows[8] + 0x01;
        }
        set_win_tiles(0,0,20,2,windows);
      }

      if(i+2==s) {
        s = randomFruta2(i);
        delay(400);

        if(windows[28]==0x0B){
          windows[28]=0x02;
          windows[27]=windows[27]+0x01;
        }
        else if (windows[28]!=0x0B) {
        windows[28]=windows[28] + 0x01;
        }
        set_win_tiles(0,0,20,2,windows);
        
      }
      if(i-40==s) {
        s = randomFruta2(i);
        //printf("%d",j);   
        delay(400);

      if(windows[28]==0x0B){
          windows[28]=0x02;
          windows[27]=windows[27]+0x01;
        }
        else if (windows[28]!=0x0B) {
        windows[28]=windows[28] + 0x01;
        }
        set_win_tiles(0,0,20,2,windows);
      }

      if(i+-2==s){
        s = randomFruta2(i);
       // printf("%d",j);   
        delay(400);

       if(windows[28]==0x0B){
          windows[28]=0x02;
          windows[27]=windows[27]+0x01;
        }
        else if (windows[28]!=0x0B) {
        windows[28]=windows[28] + 0x01;
        }
        set_win_tiles(0,0,20,2,windows);

      }
      if((i+40==s) ){
        s = randomFruta2(i);
        //printf("%d",j);   
        delay(400);

        if(windows[28]==0x0B){
          windows[28]=0x02;
          windows[27]=windows[27]+0x01;
        }
        else if (windows[28]!=0x0B) {
        windows[28]=windows[28] + 0x01;
        }
        set_win_tiles(0,0,20,2,windows);
      }
      break;

      case J_RIGHT:

        set_sprite_tile(0,4);
        set_sprite_tile(1,6);
       
        if(puedomoverme(i+2) && puedomoverme(i+22) && ( (i+2)!=j && (i+22)!=j && (i-18)!=j)  && ( (i+2)!=s && (i+22)!=s && (i-18)!=s) ){
        set_sprite_tile(0,20);
        set_sprite_tile(1,22); 
        delay(80);
        scroll_sprite(0,2,0);  
        scroll_sprite(1,2,0);

        set_sprite_tile(0,4);
        set_sprite_tile(1,6);
        delay(80);
        scroll_sprite(0,2,0);  
        scroll_sprite(1,2,0);

        set_sprite_tile(0,36);
        set_sprite_tile(1,38); 
        delay(80); 
        scroll_sprite(0,2,0);  
        scroll_sprite(1,2,0);

        set_sprite_tile(0,4);
        set_sprite_tile(1,6);
        delay(80);
        scroll_sprite(0,2,0);  
        scroll_sprite(1,2,0);
        i = i +1;
        }             
      break;
      
      case J_UP:
        set_sprite_tile(0,12);
        set_sprite_tile(1,14); 
        if(puedomoverme(i-20)&&puedomoverme(i-19) && (i-40!=j) && (i-41!=j) && (i-39!=j) && (i-40!=s) && (i-41!=s) && (i-39!=s)){
        set_sprite_tile(0,24);
        set_sprite_tile(1,26); 
        delay(80);
        scroll_sprite(0,0,-2);  
        scroll_sprite(1,0,-2);

        set_sprite_tile(0,12);
        set_sprite_tile(1,14);   
        delay(80);
        scroll_sprite(0,0,-2);  
        scroll_sprite(1,0,-2);

        set_sprite_tile(0,40);
        set_sprite_tile(1,42);   
        delay(80);
        scroll_sprite(0,0,-2);  
        scroll_sprite(1,0,-2);

        set_sprite_tile(0,12);
        set_sprite_tile(1,14);   
        delay(80);
        scroll_sprite(0,0,-2);  
        scroll_sprite(1,0,-2);
        i = i-20;
        }
      break;

      case J_LEFT:
        set_sprite_tile(0,8);
        set_sprite_tile(1,10);
        if(puedomoverme(i-1)&&puedomoverme(i+19) && (i-2!=j) && (i-22!=j) && (i+18!=j)&& (i-2!=s) && (i-22!=s) && (i+18!=s)){
        set_sprite_tile(0,28);
        set_sprite_tile(1,30); 
        delay(80); 
        scroll_sprite(0,-2,0);  
        scroll_sprite(1,-2,0);

        set_sprite_tile(0,8);
        set_sprite_tile(1,10); 
        delay(80); 
        scroll_sprite(0,-2,0);  
        scroll_sprite(1,-2,0);

        set_sprite_tile(0,44);
        set_sprite_tile(1,46); 
        delay(80); 
        scroll_sprite(0,-2,0);  
        scroll_sprite(1,-2,0);

        set_sprite_tile(0,8);
        set_sprite_tile(1,10); 
        delay(80); 
        scroll_sprite(0,-2,0);  
        scroll_sprite(1,-2,0);
        i = i -1;
        }
      break;

      case J_DOWN:
        set_sprite_tile(0,0);
        set_sprite_tile(1,2);
        if(puedomoverme(i+40)&&puedomoverme(i+41) && (i+41!=j) && (i+40!=j) && (i+39!=j)&&(i+41!=s) && (i+40!=s) && (i+39!=s)){
        set_sprite_tile(0,16);
        set_sprite_tile(1,18);
        delay(80);
        scroll_sprite(0,0,2);  
        scroll_sprite(1,0,2);
        
        set_sprite_tile(0,0);
        set_sprite_tile(1,2);
        delay(80);   
        scroll_sprite(0,0,2);  
        scroll_sprite(1,0,2);

        set_sprite_tile(0,32);
        set_sprite_tile(1,34);
        delay(80);   
        scroll_sprite(0,0,2);  
        scroll_sprite(1,0,2);   

        set_sprite_tile(0,0);
        set_sprite_tile(1,2);
        delay(40);   
        scroll_sprite(0,0,2);  
        scroll_sprite(1,0,2);
        i = i + 20;
        }
      break;
      }
      
      

    }
}

