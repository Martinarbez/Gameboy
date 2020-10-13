#include <stdlib.h>
#include <stdio.h>
#include <gb/gb.h>
#include <stdbool.h>
#include <stdint.h>
#include <rand.h>
#include <time.h>

#include <gb/font.h>


#include "GameCharacter.c"
#include "elle.c"
#include "back.c"

#include "backmap.c"
#include "fruta.c"
#include "windows.c"
#include "startwindows.c"

///Agregados para musica
#include "gbt_player.h"

extern const unsigned char * song_Data[];
///

const unsigned int blankmap[1]= {0x00};


bool puedomoverme (int i){
  bool result = (backmap[i-1] == blankmap[0]);
  return result;
  }

    /***********************************
     * Funciones de personaje y su movimiento
    ***********************************/
  struct GameCharacter elle;

  void movegamecharacter(uint8_t x, uint8_t y){
    move_sprite(elle.spritids[0], x, y);
    move_sprite(elle.spritids[1], x + 8, y);
    
  }

  void setupChar(){
    elle.x = 16;
    elle.y = 32;
    
    // load sprites for ship
    set_sprite_tile(0, 0);
    elle.spritids[0] = 0;
    set_sprite_tile(1, 2);
    elle.spritids[1] = 1;
       
    movegamecharacter(elle.x, elle.y);
    }
  
    
    /***********************************
     * i el personaje
     * Fruta 1: Uva posicion j
     * Fruta 2; Limon posicion s
    ***********************************/
    //randomFruta(posicion del personaje, numero de fruta a mover) 
   int randomFruta(int i, int f){
      int r = 0;
      int a = 0;
      int b = 0;
      while ( !puedomoverme(r) || !puedomoverme(r+21) || !puedomoverme(r+20) || !puedomoverme(r+1) || r==i || i==r +1 || i==r-1|| i==r-20|| i ==r-19 || i==r-21|| i ==r+19 || i==r+20 || i==r+21){
      a = (unsigned)rand()%18+1;
      b = (unsigned)rand()%16+1;
      r =((b-2)*20)+a;
      }
      move_sprite(f*2,a*8,b*8);
      move_sprite((f*2)+1,(a*8)+8,b*8);
      return r;
      }
 
    
    void contadorUvas(void){
    if(windows[3]==0x0B){
          windows[3]=0x02;
          windows[2]=windows[2]+0x01;
        }
        else if (windows[3]!=0x0B) {
        windows[3]=windows[3] + 0x01;
        }
        set_win_tiles(0,0,20,2,windows);
    }
         
    void contadorLimon(void){
     if(windows[23]==0x0B){
          windows[23]=0x02;
          windows[22]=windows[22]+0x01;
        }
        else if (windows[23]!=0x0B) {
        windows[23]=windows[23] + 0x01;
        }
        set_win_tiles(0,0,20,2,windows);
    }

    void contadorKiwi(void){
     if(windows[8]==0x0B){
          windows[8]=0x02;
          windows[7]=windows[7]+0x01;
        }
        else if (windows[8]!=0x0B) {
        windows[8]=windows[8] + 0x01;
        }
        set_win_tiles(0,0,20,2,windows);
    }

void contadorPera(void){
     if(windows[28]==0x0B){
          windows[28]=0x02;
          windows[27]=windows[27]+0x01;
        }
        else if (windows[28]!=0x0B) {
        windows[28]=windows[28] + 0x01;
        }
        set_win_tiles(0,0,20,2,windows);
    }

void contadorTiempo(void){
     if(windows[39]==0x0B){
          windows[39]=0x02;
          windows[38]=windows[38]+0x01;
        }
        else if (windows[39]!=0x0B) {
        windows[39]=windows[39] + 0x01;
        }
        set_win_tiles(0,0,20,2,windows);
    }

void main(void) {

    //Probamos agregando lo del vieja para la musica
    disable_interrupts();

    gbt_play(song_Data, 2, 7);
    gbt_loop(1);

    set_interrupts(VBL_IFLAG);
    enable_interrupts();
    ///

    // Cambio registros para activar sonido
    NR52_REG = 0x80; 
    NR50_REG = 0x77; 
    NR51_REG = 0xFF;
    
    //Personaje
    //puts("\n\n\n\n\nDale start perro!!!");

    //cargar fuente
    font_t min_font;
    font_init();
    min_font = font_load(font_min); // tile
    font_set(min_font);


    //Pantalla para de inicio
    set_win_tiles(0,0,20,18,startwindows);
    move_win(7,0);
    SHOW_WIN;
    DISPLAY_ON;
    delay(1000);


    //espera una tecla y incia random
    
    waitpad(0xFF);
    waitpadup();
    int l = DIV_REG;
    initarand(l);
    
    
    
    
    //cargar el primer nivel
    set_win_tiles(0,0,20,2,windows);
    move_win(8,128);
    
    SPRITES_8x16;
    
    set_sprite_data(0,48,Elle);
    setupChar();

    unsigned int i = 42;


    
    set_sprite_data(48,16,fruta);
    set_sprite_tile(2,48);
    set_sprite_tile(3,50);
    set_sprite_tile(4,52);
    set_sprite_tile(5,54);
    set_sprite_tile(6,56);
    set_sprite_tile(7,58);
    set_sprite_tile(8,60);
    set_sprite_tile(9,62);
    move_sprite(2,0,0);
    move_sprite(3,0,0);
    move_sprite(4,0,0);
    move_sprite(5,0,0);
    move_sprite(6,0,0);
    move_sprite(7,0,0);
    move_sprite(8,0,0);
    move_sprite(9,0,0);
    unsigned int j = randomFruta(i,1);    
    unsigned int s = randomFruta(i,2);
    unsigned int r = randomFruta(i,3);    
    unsigned int m = randomFruta(i,4);
    
    
    //mapa
    set_bkg_data(38,10,back);  //tile, cantidad de tildes,donde estan//
    set_bkg_tiles(0,0,20,18,backmap);

    SHOW_SPRITES;
    SHOW_BKG;
    DISPLAY_ON;

    
    time_t tiempo1 = time(NULL);
    time_t tiempo2;
    time_t diff;

    while (1)
    {
      //Linea para musica
      wait_vbl_done();
      //

      tiempo2 = time(NULL);
      diff = tiempo2-tiempo1;
      if (diff > 0.1)
      {
        contadorTiempo();
        tiempo1 = time(NULL);
      }

      switch (joypad())
      {
          
      case J_B:
       
      j = randomFruta(i,1);
      contadorUvas();
      //delay(300);

      s = randomFruta(i,2);
      contadorLimon();
      //delay(300);

      r = randomFruta(i,3);
      contadorKiwi();
      //delay(300);

      m = randomFruta(i,4);
      contadorPera();
      //delay(300);
      
      
      case J_A:  
      
      if(i+2==j || i-40==j || i-2==j || i+40==j) {
        j = randomFruta(i,1);
        contadorUvas();
        NR10_REG = 0x16;
        NR11_REG = 0x40;
        NR12_REG = 0x73;
        NR13_REG = 0x04;
        NR14_REG = 0xC7; 
        //delay(400);        
      }


      if(i+2==s || i-40==s || i-2==s || i+40==s) {
        s = randomFruta(i,2);
        contadorLimon();
        NR10_REG = 0x16;
        NR11_REG = 0x40;
        NR12_REG = 0x73;
        NR13_REG = 0x01;
        NR14_REG = 0xC6; 
        //delay(400);
        
      }
      if(i+2==r || i-40==r || i-2==r || i+40==r) {
        r = randomFruta(i,3);
        contadorKiwi();
        NR10_REG = 0x16;
        NR11_REG = 0x40;
        NR12_REG = 0x73;
        NR13_REG = 0x01;
        NR14_REG = 0xC6; 
        //delay(400);
        
      }

      if(i+2==m || i-40==m || i-2==m || i+40==m) {
        m = randomFruta(i,4);
        contadorPera();
        NR10_REG = 0x16;
        NR11_REG = 0x40;
        NR12_REG = 0x73;
        NR13_REG = 0x04;
        NR14_REG = 0xC7; 
        //delay(400);        
      }

      break;

      case J_RIGHT:
        
        set_sprite_tile(0,4);
        set_sprite_tile(1,6);
       
       
        if(puedomoverme(i+2) && puedomoverme(i+22) && ( (i+2)!=j && (i+22)!=j && (i-18)!=j)  && ( (i+2)!=s && (i+22)!=s && (i-18)!=s) && ( (i+2)!=r && (i+22)!=r && (i-18)!=r)&& ( (i+2)!=m && (i+22)!=m && (i-18)!=m)){
        set_sprite_tile(0,20);
        set_sprite_tile(1,22); 
        delay(60);
        scroll_sprite(0,2,0);  
        scroll_sprite(1,2,0);

        set_sprite_tile(0,4);
        set_sprite_tile(1,6);
        delay(60);
        scroll_sprite(0,2,0);  
        scroll_sprite(1,2,0);

        set_sprite_tile(0,36);
        set_sprite_tile(1,38); 
        delay(60); 
        scroll_sprite(0,2,0);  
        scroll_sprite(1,2,0);

        set_sprite_tile(0,4);
        set_sprite_tile(1,6);
        delay(60);
        scroll_sprite(0,2,0);  
        scroll_sprite(1,2,0);
        i = i +1;
        }             
      break;
      
      case J_UP:
        set_sprite_tile(0,12);
        set_sprite_tile(1,14);
        
        if(puedomoverme(i-20)&&puedomoverme(i-19) && (i-40!=j) && (i-41!=j) && (i-39!=j) && (i-40!=s) && (i-41!=s) && (i-39!=s)&& (i-40!=r) && (i-41!=r) && (i-39!=r)&& (i-40!=m) && (i-41!=m) && (i-39!=m)){
        set_sprite_tile(0,24);
        set_sprite_tile(1,26); 
        delay(60);
        scroll_sprite(0,0,-2);  
        scroll_sprite(1,0,-2);

        set_sprite_tile(0,12);
        set_sprite_tile(1,14);   
        delay(60);
        scroll_sprite(0,0,-2);  
        scroll_sprite(1,0,-2);

        set_sprite_tile(0,40);
        set_sprite_tile(1,42);   
        delay(60);
        scroll_sprite(0,0,-2);  
        scroll_sprite(1,0,-2);

        set_sprite_tile(0,12);
        set_sprite_tile(1,14);   
        delay(60);
        scroll_sprite(0,0,-2);  
        scroll_sprite(1,0,-2);
        i = i-20;
        }
      break;
      
      case J_LEFT:
        set_sprite_tile(0,8);
        set_sprite_tile(1,10);
        
        if(puedomoverme(i-1)&&puedomoverme(i+19) && (i-2!=j) && (i-22!=j) && (i+18!=j)&& (i-2!=s) && (i-22!=s) && (i+18!=s)&& (i-2!=r) && (i-22!=r) && (i+18!=r)&& (i-2!=m) && (i-22!=m) && (i+18!=m)){
        set_sprite_tile(0,28);
        set_sprite_tile(1,30); 
        delay(60);
        scroll_sprite(0,-2,0);  
        scroll_sprite(1,-2,0);

        set_sprite_tile(0,8);
        set_sprite_tile(1,10); 
        delay(60);
        scroll_sprite(0,-2,0);  
        scroll_sprite(1,-2,0);

        set_sprite_tile(0,44);
        set_sprite_tile(1,46); 
        delay(60); 
        scroll_sprite(0,-2,0);  
        scroll_sprite(1,-2,0);

        set_sprite_tile(0,8);
        set_sprite_tile(1,10); 
        delay(60);
        scroll_sprite(0,-2,0);  
        scroll_sprite(1,-2,0);
        i = i -1;
        }
      break;

      case J_DOWN:
        set_sprite_tile(0,0);
        set_sprite_tile(1,2);
        
        if(puedomoverme(i+40)&&puedomoverme(i+41) && (i+41!=j) && (i+40!=j) && (i+39!=j)&&(i+41!=s) && (i+40!=s) && (i+39!=s)&&(i+41!=r) && (i+40!=r) && (i+39!=r)&&(i+41!=m) && (i+40!=m) && (i+39!=m)){
        set_sprite_tile(0,16);
        set_sprite_tile(1,18);
        delay(60);
        scroll_sprite(0,0,2);  
        scroll_sprite(1,0,2);
        
        set_sprite_tile(0,0);
        set_sprite_tile(1,2);
        delay(60);  
        scroll_sprite(0,0,2);  
        scroll_sprite(1,0,2);

        set_sprite_tile(0,32);
        set_sprite_tile(1,34);
        delay(60);  
        scroll_sprite(0,0,2);  
        scroll_sprite(1,0,2);   

        set_sprite_tile(0,0);
        set_sprite_tile(1,2);
        delay(60); 
        scroll_sprite(0,0,2);  
        scroll_sprite(1,0,2);
        i = i + 20;
        
        }
      break;
      }
    //Linea para musica  
    gbt_update();
    //
    }
    

}

