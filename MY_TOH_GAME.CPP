#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<dos.h>
#include<graphics.h>
#include<io.h>
#define true 1
#define false 0


void loadingpage();
void greetings();
void discselection();
int calldisc3();
int calldisc4();
int calldisc5();
int calldisc6();
int calldisc7();
int calldisc8();
int calldisc9();
int calldisc10();
void gameinfo();
void exitpage();
void howtoplay();
void readmust();
void contactme();
void aboutme();
void tohhistory();
void color(int a,int b,int c,int d,int e);
int erase(int f,int g,int h,int i,int j);
void linedraw(int ,int ,int ,int ,int);
void popup(int r, int e, int m, int o);
int mode();



/*
////left button pressed////



 int left_pressed(){
 union REGS r;
 r.x.ax=3;
 int86(0x33,&r,&r);
 return (r.x.bx & 2);
 }

*/



///shown mouse///




void showmouse()
{
union REGS in ,out;
in.x.ax=1;
int86(0x33,&in,&out);
}





//////////////////////*HIDE MOUSE*/////////////////////////////////////////




void hidemouse()
{
union REGS in ,out;
in.x.ax=2;
int86(0x33,&in,&out);
}





/////////////////////////*MOUSE INFORMATION*///////////////////////////////




void mouseInfo(int*button,int*Xpos,int*Ypos)
{
union REGS in ,out;
in.x.ax=3;
int86(0x33,&in,&out);
*Xpos=out.x.cx;
*Ypos=out.x.dx;
*button=out.x.bx;
}
int Xpos,Ypos,button,I,p=1,z;






////// graphics drivers function/////////


int graphicsdriver(){
 int gd=DETECT,gm,check,graphok=0;
 initgraph(&gd,&gm,"c://tc//BGI");
 check=graphresult();
 if(check != graphok){
 printf("Graphics Error %s",grapherrormsg(check));
 exit(1);
 }
 return 0;
}




////// Exit page//////




void exitpage(){
graphicsdriver();
setbkcolor(0);
outtextxy(getmaxx()/2-40,200,"LEAVING......");
sound(500);
delay(2000);
nosound();
 clrscr();
 cleardevice();
 closegraph();

}




//////perfect win//////



void perfectwin(int count){
  clrscr();
  cleardevice();
  closegraph();
  graphicsdriver();
  sound(1000);
  setbkcolor(2);
  setcolor(4);
  settextstyle(1,0,5);
  printf("\n\n\n\n\n\n\n                                %d WRONG ATTEMPTS :) ",count);
  settextstyle(10,0,5);
  outtextxy(200,150,"PERFECT");
  settextstyle(1,0,1);
  setcolor(1);
  outtextxy(0,260,"You WON the game with the least number of moves possible,");
  setcolor(15);
  settextstyle(0,0,2);
  outtextxy(250,290,"WELL DONE!!!!");
  settextstyle(0,0,2);
  setcolor(4);
  outtextxy(200,400,"Press ANY key");
//  outtextxy(200,360,"Pess BACKSPACE to go Back");
   nosound();
  getch();
 // nosound();
 cleardevice();
 discselection();


 //return 0;
}






/////WON//////


void win(int count){
clrscr();
cleardevice();
closegraph();
graphicsdriver();
sound(1000);
 setbkcolor(2);
 setcolor(15);
 printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n                         %d WRONG ATTEMPTS",count);
 printf("\n\n\n\n\n\n                  PRESS ANY KEY FOR NEW GAME");
 settextstyle(0,0,5);
 outtextxy(200,100,"HURRAH!!!");
 settextstyle(0,0,3);
 outtextxy(50,200,"YOU'VE WON THE GAME");
 nosound();
 getch();
 clrscr();
 cleardevice();
 discselection();

// return true;
}





/////LOST//////




void lost(int count){
clrscr();
cleardevice();
closegraph();
graphicsdriver();
sound(1000);
 setbkcolor(1);
 setcolor(4);
 printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n                         %d WRONG ATTEMPTS",count);
 printf("\n\n\n\n\n\n                  PRESS ANY KEY FOR NEW GAME");
 settextstyle(0,0,5);
 outtextxy(200,100,"SORRY!!!");
 settextstyle(0,0,3);
 outtextxy(50,200,"YOU'VE LOST THE GAME");
 nosound();
 getch();
 clrscr();
 cleardevice();
 discselection();

// return true;
}



// #include "MY.H"



//// main function////




void main(){

 graphicsdriver();
 loadingpage();
 cleardevice();
 graphicsdriver();
 greetings();
 cleardevice();
 graphicsdriver();
 gameinfo();
 cleardevice();
 graphicsdriver();
 discselection();
 cleardevice();
  closegraph();
 //return 0;
}
  void loadingpage(){
  short int x=200,y=220,x1=210,y1=220;
  setcolor(4);
  settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
  outtextxy(200,200,"please wait...");
  setcolor(14);
  settextstyle(10,0,4);
  outtextxy(200,70,"D ");
  delay(250);
  outtextxy(250,70,"O ");
  delay(250);
  outtextxy(300,70,"S ");
  delay(400);
  settextstyle(10,0,2);
  setcolor(15);
  outtextxy(100,140,"OpenGL Programming");
  setcolor(14);
  settextstyle(SANS_SERIF_FONT,HORIZ_DIR,5);
  outtextxy(getmaxx()-303,getmaxy()-103,"LOADING.....");
  setcolor(15);
  outtextxy(getmaxx()-301,getmaxy()-100,"LOADING.....");
  setcolor(0);
  outtextxy(getmaxx()-300,getmaxy()-101,"LOADING.....");
  while(x1<=420){
  sound(x1*5);
  setcolor(15);
   delay(32);
   line(x,y+5,x1,y1+5);
   line(x,y+7,x1,y1+7);
   x+=3,x1+=3;
  }
  delay(200);
  nosound();
  cleardevice();
//  closegraph();
 }




 ///// greetings//////


 void greetings(){
 setbkcolor(1);
  short int x=200,y=300,x1=210,y1=300;
 setcolor(12);
 settextstyle(SANS_SERIF_FONT,HORIZ_DIR,5);
  outtextxy(0,100,"WELCOME TO TOWER OF HANOI");
  outtextxy(100,140,"(puzzle) GAME");
   settextstyle(3,HORIZ_DIR,4);
   setcolor(15);
   outtextxy(getmaxx()/3,getmaxy()/2,"LOADING.....");
  while(x1<=420){
  setcolor(12);
  sound(x1);
   delay(25);
   line(x,y,x1,y1);
   line(x,y+1,x1,y1+1);
   line(x,y+2,x1,y1+2);
   x+=2,x1+=3;
   }
   nosound();
   cleardevice();
  // closegraph();
 }







 ////// GAME information and how to play!!//////





 void gameinfo(){
 setbkcolor(4);
 setcolor(15);
 settextstyle(3,HORIZ_DIR,3);
  outtextxy(150,5,"Select options below:");
  setcolor(1);
  settextstyle(3,HORIZ_DIR,3);
  setcolor(1);
  bar3d(0,40,200,100,5,1);
  outtextxy(10,42,"HOW TO PLAY?");
  bar3d(0,120,200,180,5,1);
  outtextxy(10,122,"Read me(must)");
  bar3d(0,200,200,260,4,1);
  outtextxy(10,202,"History of this");
  outtextxy(10,220,"puzzle");
  bar3d(0,280,200,340,4,1);
  outtextxy(10,292,"ABOUT");
 // outtextxy(10,302,"Developer");
  bar3d(0,360,200,420,5,1);
  outtextxy(10,372,"CONTACT");
  //outtextxy(10,390,"(MOBASSIR)");
  bar3d(300,40,520,100,5,1);
  outtextxy(310,42,"continue to GAME");
  outtextxy(getmaxx()/2,getmaxy()-140,"Press ANY key TWICE");
  char c;
 c= getch();
  showmouse();

   setcolor(13);
 //  outtextxy(getmaxx()/2,getmaxy()-140,"press ANY key");

   //char c;
  // c=getch();
      outtextxy(getmaxx()/2,getmaxy()-100,"press ESC TWICE to exit");
  c=getch();
  while(c!=27){
  if(kbhit()){
  c=getch();
  }

  setcolor(2);
 outtextxy(getmaxx()/2-50,getmaxy()-300,"Now USE your mouse to select");
 outtextxy(getmaxx()/2-10,getmaxy()-280,"Options");
 mouseInfo(&button, &Xpos, &Ypos);
 if((Xpos>0 && Xpos<200)&& (Ypos>40 && Ypos<100))if(1==(button&1)){
 cleardevice();
 howtoplay();
 break;
 }


  if((Xpos>0 && Xpos<200)&& (Ypos>120 && Ypos<180))if(1==(button&1)){
 cleardevice();
 readmust();
 break;
 }


  if((Xpos>0 && Xpos<200)&& (Ypos>200 && Ypos<260))if(1==(button&1)){
 cleardevice();
 tohhistory();
 break;
 }

  if((Xpos>0 && Xpos<200)&& (Ypos>280 && Ypos<340))if(1==(button&1)){
 cleardevice();
 aboutme();
 break;
 }

  if((Xpos>0 && Xpos<200)&& (Ypos>360 && Ypos<420))if(1==(button&1)){
 cleardevice();
 contactme();
 break;
 }
  if((Xpos>300 && Xpos<520)&& (Ypos>40 && Ypos<100))if(1==(button&1)){
 cleardevice();
 discselection();
// continuegame();
 break;
 }

 }

  if(kbhit());
  char  ch=getch();
   if(ch==27){
   exitpage();
    }
   getch();
   hidemouse();
   cleardevice();
   closegraph();
  // return 0;
  }








 ///Select disc to play///




 void discselection(){
 clrscr();
 cleardevice();
 closegraph();
 graphicsdriver();
 setbkcolor(1);
 setcolor(14);
 settextstyle(3,HORIZ_DIR,2);
  outtextxy(150,10,"Select Number of DISC below:");
  setcolor(4);
  settextstyle(3,HORIZ_DIR,3);
  setcolor(4);
  bar3d(0,40,200,100,5,1);
  outtextxy(10,42,"3 DISC PUZZLE");
  bar3d(0,120,200,180,5,1);
  outtextxy(10,122,"4 DISC PUZZLE");
  bar3d(0,200,200,260,5,1);
  outtextxy(10,202,"5 DISC PUZZLE");
  bar3d(0,280,200,340,5,1);
  outtextxy(10,282,"6 DISC PUZZLE");
  setcolor(2);
  outtextxy(15,310,"(Not Available)");
  setcolor(4);
  bar3d(0,360,200,420,5,1);
  outtextxy(10,362,"7 DISC PUZZLE");
  setcolor(2);
  outtextxy(15,390,"(Not Available)");
  setcolor(4);
  bar3d(300,40,520,100,5,1);
  outtextxy(310,42,"8 DISC PUZZLE");
  setcolor(2);
  outtextxy(315,70,"(Not Available)");
  setcolor(4);
  bar3d(300,120,520,180,5,1);
  outtextxy(310,122,"9 DISC PUZZLE");
  setcolor(2);
  outtextxy(315,150,"(Not Available)");
  setcolor(4);
  bar3d(300,200,520,260,5,1);
  outtextxy(310,202,"10 DISC PUZZLE");
  setcolor(2);
  outtextxy(315,230,"(Not Available)");
  setcolor(4);
  outtextxy(getmaxx()/2,getmaxy()-130,"Press ANY key Twice");
  getch();
   showmouse();
   setcolor(13);
   char c;
   c=getch();
   outtextxy(getmaxx()/2,getmaxy()-100,"press ESC to exit");
  while(c!=27 || c!=8){
  if(kbhit()){
  c=getch();
  if(c==8){
   clrscr();
   cleardevice();
   closegraph();
   graphicsdriver();
   gameinfo();
  }if(c==27)exitpage();
  }
 mouseInfo(&button, &Xpos, &Ypos);
  setcolor(14);
 outtextxy(getmaxx()/2-50,getmaxy()-200,"Now USE your mouse to select");
 outtextxy(getmaxx()/2-10,getmaxy()-180,"options");

 if((Xpos>0 && Xpos<200)&& (Ypos>40 && Ypos<100))if(1==(button&1)){
 cleardevice();
 calldisc3();
 break;
 }


  if((Xpos>0 && Xpos<200)&& (Ypos>120 && Ypos<180))if(1==(button&1)){
 cleardevice();
 calldisc4();
 break;
 }


  if((Xpos>0 && Xpos<200)&& (Ypos>200 && Ypos<260))if(1==(button&1)){
 cleardevice();
 calldisc5();
 break;
 }

  if((Xpos>0 && Xpos<200)&& (Ypos>280 && Ypos<340))if(1==(button&1)){
 cleardevice();
 calldisc6();
 break;
 }

  if((Xpos>0 && Xpos<200)&& (Ypos>360 && Ypos<420))if(1==(button&1)){
 cleardevice();
 calldisc7();
 break;
 }

  if((Xpos>300 && Xpos<520)&& (Ypos>40 && Ypos<100))if(1==(button&1)){
 cleardevice();
 calldisc8();
 break;
 }

  if((Xpos>300 && Xpos<520)&& (Ypos>120 && Ypos<180)) if(1==(button&1)){
 cleardevice();
 calldisc9();
 break;
 }

  if((Xpos>300 && Xpos<520)&& (Ypos>200 && Ypos<260))if(1==(button&1)){
 cleardevice();
 calldisc10();
 break;
 }
 }

  if(kbhit());
  char  ch=getch();
   if(ch==27){
   exitpage();
    }
   getch();
   hidemouse();
   cleardevice();
   closegraph();
  // return 0;
  }

 ////page for 3 disc////

int calldisc3(){
 short int mod;
mod=mode();
clrscr();
cleardevice();
graphicsdriver();
showmouse();
   settextstyle(SANS_SERIF_FONT,HORIZ_DIR,3);
   setcolor(15);
   outtextxy(190,0,"Draw 3 disc PUZZLE");
   setcolor(13);
   outtextxy(191,1,"Draw 3 disc PUZZLE");
   setcolor(4);
   if(mod=='h' || mod=='H')outtextxy(190,50,"*****HARD MODE*****");
   else if(mod=='E' || mod=='e')outtextxy(190,50,"*****EASY MODE*****");
   if(mod=='m' || mod=='M')outtextxy(190,50,"*****Medium MODE*****");
   settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
  line(70,70,70,200);
  setbkcolor(2);
  fillellipse(0,201,201,1);
  setcolor(1);
  outtextxy(30,210,"SOURCE");
  setcolor(4);
	 rectangle(10,190,130,200);
   short  int x=11,y=191,x1=130,y1=191;///x1 will be constant
  while(y1!=200){
   line(x,y,x1,y1);
   y++,y1++;
   }
   setcolor(15);
	 rectangle(20,180,125,190);
  x=21,y=181,x1=125,y1=181;
  while(y1!=190){
  line(x,y,x1,y1);
  y++,y1++;
  }
	 setcolor(1);
	 rectangle(30,170,115,180);
  x=31,y=171,x1=115,y1=171;
  while(y1!=180){
  line(x,y,x1,y1);
  y++,y1++;
  }
  line(540,70,540,200);
  fillellipse(600,201,201,1);
  setcolor(14);
  outtextxy(550,212,"TEMPORARY");
  line(getmaxx()/2-20,250,getmaxx()/2-20,400);
  fillellipse(300,400,200,1);
  setcolor(15);
  outtextxy(getmaxx()/2,410,"DESTINATION");

  int count=0;
 printf("WRONG ATTEMPTS = %d",count);

//////  1st move...////////



  x=getmaxx()/2-62,x1=getmaxx()/2-20+42,y=390,y1=400;
while(true){
    mouseInfo(&button, &Xpos, &Ypos);
    outtextxy(180,200,"Select Top DISC");
 if((Xpos>30 && Xpos<115)&& (Ypos>170 && Ypos<180))if(1==(button&1)){
 popup(180,195,450,210);
 setcolor(WHITE);
 outtextxy(180,200,"Now click on the moveable place");
  break;
 }
  }

  while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     if((Xpos>x && Xpos<x1)&&(Ypos>y && Ypos<y1))if(1==(button&1)){
	  rectangle(x,y,x1,y1);
	  hidemouse();
	 // sound(1);
	  color(x,y,x1,y1,1);
	  x=30,y=170,x1=115,y1=180;
	  erase(x,y,x1,y1,2);
	  erase(240,140,370,160,2);
	  linedraw(70,70,70,200,13);

	  break;
	 }

	   ////wrong attempt around temp

	 if((Xpos>getmaxx()-200 && Xpos<getmaxx())&&(Ypos>10 && Ypos<230))if(1==(button&1)){
	     delay(200);
	     setcolor(4);
	     sound(200);
	     outtextxy(250,150,"Wrong Attempt!!");
	     count++;
	     gotoxy(18,1);
	     printf("%d",count);
	     nosound();
	     if(mod=='h' || mod=='H')if(count>1)lost(count);
	      if(mod=='m' || mod=='M')if(count>2)lost(count);
	     if(mod=='e' || mod=='E')if(count>4)lost(count);
	 // break;
	 }
  }
  rectangle(180,195,450,210);
  popup(180,195,450,210);
  showmouse();


///////2nd move...../////////



   setcolor(WHITE);
  outtextxy(180,200,"Try next MOVE");
  showmouse();

   x=540-52,x1=540+52,y=190,y1=200;
while(true){
    mouseInfo(&button, &Xpos, &Ypos);
 if((Xpos>20 && Xpos<125)&& (Ypos>180 && Ypos<190))if(1==(button&1)){
 popup(180,195,450,210);
 setcolor(WHITE);
 outtextxy(180,200,"Now click on the moveable place");
  break;
 }
  }
  while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     if((Xpos>x && Xpos<x1)&&(Ypos>y && Ypos<y1))if(1==(button&1)){
	  rectangle(x,y,x1,y1);
	  hidemouse();
	 // sound(1);
	  color(x,y,x1,y1,15);
	  x=20,y=180,x1=125,y1=190;
	  erase(x,y,x1,y1,2);
	  erase(240,140,370,160,2);
	  linedraw(540,70,540,200,13);
	  linedraw(70,70,70,200,13);

	  break;
	 }


	 ///wrong attempt around destination

	  if((Xpos>getmaxx()/2-82 && Xpos<getmaxx()/2-20+62)&&(Ypos>300 && Ypos<400))if(1==(button&1)){
	      delay(200);
	     setcolor(4);
	     sound(200);
	     outtextxy(250,150,"Wrong Attempt!!");
	     count++;
	     gotoxy(18,1);
	     printf("%d",count);
	     nosound();
	      if(mod=='h' || mod=='H')if(count>1)lost(count);
		if(mod=='m' || mod=='M')if(count>2)lost(count);
		  if(mod=='e' || mod=='E')if(count>4)lost(count);
	  }
  }
  rectangle(180,195,450,210);
  popup(180,195,450,210);
  showmouse();


/////// 3rd move//////


   setcolor(WHITE);
  outtextxy(180,200,"Try next MOVE");
  showmouse();
  // x=540-52,x1=540+52,y=190,y1=200;
     x=getmaxx()/2-62,x1=getmaxx()/2-20+42,y=390,y1=400;  ///1st click
while(true){
    mouseInfo(&button, &Xpos, &Ypos);
 if((Xpos>x && Xpos<x1)&& (Ypos>y && Ypos<y1))if(1==(button&1)){
 popup(180,195,450,210);
 setcolor(WHITE);
 outtextxy(180,200,"Now click on the moveable place");
 x=540-42,x1=540+42,y=180,y1=190; ///2nd click
  break;
 }
  }
  while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     if((Xpos>x && Xpos<x1)&&(Ypos>y && Ypos<y1))if(1==(button&1)){
	  rectangle(x,y,x1,y1);
	  hidemouse();
	 // sound(1);
	  color(x,y,x1,y1,1);
	  x=getmaxx()/2-62,x1=getmaxx()/2-20+42,y=390,y1=400; ///remove moved 1
	  erase(x,y,x1,y1,2);
	   erase(240,140,370,160,2);
	  linedraw(540,70,540,200,13);
	  linedraw(70,70,70,200,13);
	  linedraw(getmaxx()/2-20,250,getmaxx()/2-20,400,13);
	  break;
	 }



	 ///Wrong attempt around Source

	 if((Xpos>10 && Xpos<150)&&(Ypos>10 && Ypos<220))if(1==(button&1)){
	    delay(200);
	   setcolor(4);
	     sound(200);
	     outtextxy(250,150,"Wrong Attempt!!");
	     count++;
	     gotoxy(18,1);
	     printf("%d",count);
	     nosound();
	      if(mod=='h' || mod=='H')if(count>1)lost(count);
	       if(mod=='m' || mod=='M')if(count>2)lost(count);
		 if(mod=='e' || mod=='E')if(count>4)lost(count);
	 }
  }
  rectangle(180,195,450,210);
  popup(180,195,450,210);
  showmouse();


//////// 4th move....//////////


  x=10,x1=130,y=190,y1=200;
while(true){
    mouseInfo(&button, &Xpos, &Ypos);
    setcolor(WHITE);
    outtextxy(180,200,"Select BOTTOM DISC");
 if((Xpos>x && Xpos<x1)&& (Ypos>y && Ypos<y1))if(1==(button&1)){
 popup(180,195,450,210);
 setcolor(WHITE);
 outtextxy(180,200,"Now click on the moveable place");
  x=getmaxx()/2-82,x1=getmaxx()/2-20+62,y=390,y1=400;
  break;
 }
  }
  while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     if((Xpos>x && Xpos<x1)&&(Ypos>y && Ypos<y1))if(1==(button&1)){
	  rectangle(x,y,x1,y1);
	  hidemouse();
	 // sound(1);
	  color(x,y,x1,y1,4);
	  x=10,y=130,x1=190,y1=200;
	  erase(x,y,x1,y1,2);
	   erase(240,140,370,160,2);
	  linedraw(540,70,540,200,13);
	  linedraw(70,70,70,200,13);
	  linedraw(getmaxx()/2-20,250,getmaxx()/2-20,400,13);

	  break;
	 }


	  ////wrong attempt around temp

 if((Xpos>getmaxx()-200 && Xpos<getmaxx())&&(Ypos>10 && Ypos<230))if(1==(button&1)){
	      delay(200);
	     setcolor(4);
	     sound(200);
	     outtextxy(250,150,"Wrong Attempt!!");
	     count++;
	      gotoxy(18,1);
	     printf("%d",count);
	     nosound();
	      if(mod=='h' || mod=='H')if(count>1)lost(count);
	       if(mod=='m' || mod=='M')if(count>2)lost(count);
		 if(mod=='e' || mod=='E')if(count>4)lost(count);
	 // break;
	 }
  }
  rectangle(180,195,450,210);
  popup(180,195,450,210);
  showmouse();


//////// 5th move....//////////



x=540-42,x1=540+42,y=180,y1=190;
while(true){
    mouseInfo(&button, &Xpos, &Ypos);
    setcolor(WHITE);
    outtextxy(180,200,"Try Next MOVE");
 if((Xpos>x && Xpos<x1)&& (Ypos>y && Ypos<y1))if(1==(button&1)){
 popup(180,195,450,210);
 setcolor(WHITE);
 outtextxy(180,200,"Now click on the moveable place");
   x=30,x1=115,y=190,y1=200;
  break;
 }
  }
  while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     if((Xpos>x && Xpos<x1)&&(Ypos>y && Ypos<y1))if(1==(button&1)){
	  rectangle(x,y,x1,y1);
	  hidemouse();
	 // sound(1);
	  color(x,y,x1,y1,1);
	 x=540-42,x1=540+42,y=180,y1=190;
	  erase(x,y,x1,y1,2);
	   erase(240,140,370,160,2);
	  linedraw(540,70,540,200,13);
	  linedraw(70,70,70,200,13);
	  linedraw(getmaxx()/2-20,250,getmaxx()/2-20,400,13);

	  break;
	 }

 ///wrong attempt around destination

	  if((Xpos>getmaxx()/2-82 && Xpos<getmaxx()/2-20+62)&&(Ypos>300 && Ypos<400))if(1==(button&1)){
	      delay(200);
	     setcolor(4);
	     sound(200);
	     outtextxy(250,150,"Wrong Attempt!!");
	     count++;
	      gotoxy(18,1);
	     printf("%d",count);
	     nosound();
	      if(mod=='h' || mod=='H')if(count>1)lost(count);
	      if(mod=='m' || mod=='M')if(count>2)lost(count);
		if(mod=='e' || mod=='E')if(count>4)lost(count);
	  }

  }
  rectangle(180,195,450,210);
  popup(180,195,450,210);
  showmouse();



  //////// 6th move....//////////


  x=540-52,x1=540+52,y=190,y1=200;
while(true){
    mouseInfo(&button, &Xpos, &Ypos);
    setcolor(WHITE);
    outtextxy(180,200,"Try Next MOVE");
 if((Xpos>x && Xpos<x1)&& (Ypos>y && Ypos<y1))if(1==(button&1)){
 popup(180,195,450,210);
 setcolor(WHITE);
 outtextxy(180,200,"Now click on the moveable place");
   x=getmaxx()/2-72,x1=getmaxx()/2-20+52,y=380,y1=390;
  break;
 }
  }
  while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     if((Xpos>x && Xpos<x1)&&(Ypos>y && Ypos<y1))if(1==(button&1)){
	  rectangle(x,y,x1,y1);
	  hidemouse();
	 // sound(1);
	  color(x,y,x1,y1,15);
	  x=540-52,x1=540+52,y=190,y1=200;
	  erase(x,y,x1,y1,2);
	   erase(240,140,370,160,2);
	  linedraw(540,70,540,200,13);
	  linedraw(70,70,70,200,13);
	  linedraw(getmaxx()/2-20,250,getmaxx()/2-20,400,13);

	  break;
	 }
    ///Wrong attempt around Source

	 if((Xpos>10 && Xpos<150)&&(Ypos>10 && Ypos<220))if(1==(button&1)){
	    delay(200);
	   setcolor(4);
	     sound(200);
	     outtextxy(250,150,"Wrong Attempt!!");
	     count++;
	      gotoxy(18,1);
	     printf("%d",count);
	     nosound();
	      if(mod=='h' || mod=='H')if(count>1)lost(count);
	       if(mod=='m' || mod=='M')if(count>2)lost(count);
		 if(mod=='e' || mod=='E')if(count>4)lost(count);
	 }




  }
  rectangle(180,195,450,210);
  popup(180,195,450,210);
  showmouse();




//////// 7th/FINAL  move....//////////


  x=30,x1=115,y=190,y1=200;
while(true){
    mouseInfo(&button, &Xpos, &Ypos);
    setcolor(WHITE);
    outtextxy(180,200,"Try Next MOVE");
 if((Xpos>x && Xpos<x1)&& (Ypos>y && Ypos<y1))if(1==(button&1)){
 popup(180,195,450,210);
 setcolor(WHITE);
 outtextxy(180,200,"Now click on the moveable place");
  x=getmaxx()/2-62,x1=getmaxx()/2-20+42,y=370,y1=380;
  break;
 }
  }
  while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     if((Xpos>x && Xpos<x1)&&(Ypos>y && Ypos<y1))if(1==(button&1)){
	  rectangle(x,y,x1,y1);
	  hidemouse();
	 // sound(1);
	  color(x,y,x1,y1,1);
	  x=30,x1=115,y=190,y1=200;
	  erase(x,y,x1,y1,2);
	   erase(240,140,370,160,2);
	  linedraw(540,70,540,200,13);
	  linedraw(70,70,70,200,13);
	  linedraw(getmaxx()/2-20,250,getmaxx()/2-20,400,13);

	  break;
	 }

	  ////wrong attempt around temp

 if((Xpos>getmaxx()-200 && Xpos<getmaxx())&&(Ypos>10 && Ypos<230))if(1==(button&1)){
	      delay(200);
	     setcolor(4);
	     sound(200);
	     outtextxy(250,150,"Wrong Attempt!!");

	     count++;
	      gotoxy(18,1);
	     printf("%d",count);
	     nosound();
	 // break;
	  if(mod=='h' || mod=='H')if(count>1)lost(count);
	   if(mod=='m' || mod=='M')if(count>2)lost(count);
	     if(mod=='e' || mod=='E')if(count>4)lost(count);
	 }
  }
  rectangle(180,195,450,210);
  popup(180,195,450,210);
  setcolor(15);
  outtextxy(180,200,"congratulations!!!");
  outtextxy(180,210,"YOU WIN!!");
  if(count==0)perfectwin(count);
  if(count==1)win(count);
  if(mod=='m' || mod=='M')if(count==2)win(count);
  if(mod=='e' || mod=='E')if(count<=4)win(count);
//   cleardevice();
  // graphicsdriver();
   if(kbhit());
  char ch=getch();
  if(ch==27)exitpage();
  if(ch==8){
   cleardevice();
   graphicsdriver();
   discselection();
  }
 getch();
 cleardevice();
 closegraph();
 return 0;
}





///wrong attemps code rough/////


/*
 ///Wrong attempt around Source

	 if((Xpos>10 && Xpos<150)&&(Ypos>10 && Ypos<220))if(1==(button&1)){
	   setcolor(4);
	     sound(200);
	     outtextxy(250,150,"Wrong Attempt!!");
	     count++;
	     nosound();
	 }



	  ////wrong attempt around temp

 if((Xpos>getmaxx()-200 && Xpos<getmaxx())&&(Ypos>10 && Ypos<230))if(1==(button&1)){
	     setcolor(4);
	     sound(200);
	     outtextxy(250,150,"Wrong Attempt!!");
	     count++;
	     nosound();
	 // break;
	 }



 ///wrong attempt around destination

	  if((Xpos>getmaxx()/2-82 && Xpos<getmaxx()/2-20+62)&&(Ypos>300 && Ypos<400))if(1==(button&1)){
	     setcolor(4);
	     sound(200);
	     outtextxy(250,150,"Wrong Attempt!!");
	     count++;
	     nosound();

	  }



	   erase(240,140,370,160,2);

*/

///page for 4 disc////


int calldisc4(){
int mod;
mod=mode();
clrscr();
cleardevice();
graphicsdriver();
//showmouse();
 settextstyle(SANS_SERIF_FONT,HORIZ_DIR,3);
 setcolor(15);
 outtextxy(190,0,"Draw 4 disc PUZZLE");
 setcolor(13);
 outtextxy(191,1,"Draw 4 disc PUZZLE");
   setcolor(4);
   if(mod=='h' || mod=='H')outtextxy(190,50,"*****HARD MODE*****");
   else if(mod=='E' || mod=='e')outtextxy(190,50,"*****EASY MODE*****");
   if(mod=='m' || mod=='M')outtextxy(190,50,"*****Medium MODE*****");
 settextstyle(DEFAULT_FONT,HORIZ_DIR,1);

  line(70,70,70,200);
  setbkcolor(2);
  fillellipse(0,201,201,1);
  setcolor(1);
  outtextxy(30,210,"SOURCE");
  setcolor(4);
	 rectangle(10,190,130,200);
  int x=11,y=191,x1=130,y1=191,count=0;///x1 will be
  printf("WRONG ATTEMPTS = %d ",count);
  while(y1!=200){
   line(x,y,x1,y1);
   y++,y1++;
   }
   setcolor(15);
	  rectangle(20,180,125,190);
  x=21,y=181,x1=125,y1=181;
  while(y1!=190){
  line(x,y,x1,y1);
  y++,y1++;
  }
  setcolor(1);
	  rectangle(30,170,115,180);
  x=31,y=171,x1=115,y1=171;
  while(y1!=180){
  line(x,y,x1,y1);
  y++,y1++;
  }
  setcolor(14);
	 rectangle(40,160,105,170);
  x=41,y=161,x1=105,y1=161;
  while(y1!=170){
  line(x,y,x1,y1);
  y++,y1++;
  }
  line(540,70,540,200);
  fillellipse(600,201,201,1);
  setcolor(14);
  outtextxy(550,212,"TEMPORARY");
  line(getmaxx()/2-20,250,getmaxx()/2-20,400);
  fillellipse(300,400,200,1);
  setcolor(15);
  outtextxy(getmaxx()/2,410,"DESTINATION");


//////  1st move...////////


  showmouse();
  x=40,y=160,x1=105,y1=170;
while(true){
setcolor(WHITE);
    mouseInfo(&button, &Xpos, &Ypos);
    outtextxy(180,200,"Select Top DISC");
 if((Xpos>x && Xpos<x1)&& (Ypos>y && Ypos<y1))if(1==(button&1)){
 popup(180,195,450,210);
 setcolor(WHITE);
 outtextxy(180,200,"Now click on the moveable place");
  x=540-32,x1=540+32,y=190,y1=200;
  break;
 }
  }
  while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     if((Xpos>x && Xpos<x1)&&(Ypos>y && Ypos<y1))if(1==(button&1)){
	  rectangle(x,y,x1,y1);
	  hidemouse();
	 // sound(1);

	  color(x,y,x1,y1,14);
	   x=40,y=160,x1=105,y1=170;
	  erase(x,y,x1,y1,2);
	   erase(240,140,370,160,2);
	  linedraw(70,70,70,200,13);

	  break;
	 }

	 ///wrong attempt around destination

	  if((Xpos>getmaxx()/2-82 && Xpos<getmaxx()/2-20+62)&&(Ypos>300 && Ypos<400))if(1==(button&1)){
	      delay(200);
	     setcolor(4);
	     sound(200);
	     outtextxy(250,150,"Wrong Attempt!!");
	     count++;
	      gotoxy(18,1);
	      printf("%d",count);
	     nosound();
	     if(mod=='h' || mod=='H')if(count>3)lost(count);
	      if(mod=='m' || mod=='M')if(count>5)lost(count);
	     if(mod=='e' || mod=='E')if(count>8)lost(count);


	  }
  }
  rectangle(180,195,450,210);
  popup(180,195,450,210);
  showmouse();



//////  2nd move...////////


  x=getmaxx()/2-62,x1=getmaxx()/2-20+42,y=390,y1=400;
while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     setcolor(WHITE);
    outtextxy(180,200,"Try Next MOVE");
 if((Xpos>30 && Xpos<115)&& (Ypos>170 && Ypos<180))if(1==(button&1)){
 popup(180,195,450,210);
 setcolor(WHITE);
 outtextxy(180,200,"Now click on the moveable place");
  break;
 }
  }
  while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     if((Xpos>x && Xpos<x1)&&(Ypos>y && Ypos<y1))if(1==(button&1)){
	  rectangle(x,y,x1,y1);
	  hidemouse();
	 // sound(1);
	  color(x,y,x1,y1,1);
	  x=30,y=170,x1=115,y1=180;
	  erase(x,y,x1,y1,2);
	   erase(240,140,370,160,2);
	  linedraw(70,70,70,200,13);

	  break;
	 }


	  ////wrong attempt around temp

 if((Xpos>getmaxx()-200 && Xpos<getmaxx())&&(Ypos>10 && Ypos<230))if(1==(button&1)){
	     delay(200);
	     setcolor(4);
	     sound(200);
	     outtextxy(250,150,"Wrong Attempt!!");
	       count++;
		gotoxy(18,1);
	      printf("%d",count);
	     nosound();
	     if(mod=='h' || mod=='H')if(count>3)lost(count);
	      if(mod=='m' || mod=='M')if(count>5)lost(count);
	     if(mod=='e' || mod=='E')if(count>8)lost(count);
	 // break;
	 }

  }
  rectangle(180,195,450,210);
  popup(180,195,450,210);
  showmouse();


//////  3rd move...////////


  x=540-42,x1=540+42,y=190,y1=200;
  showmouse();
while(true){
setcolor(WHITE);
    mouseInfo(&button, &Xpos, &Ypos);
    outtextxy(180,200,"Try next MOVE");
 if((Xpos>x && Xpos<x1)&& (Ypos>y && Ypos<y1))if(1==(button&1)){
 popup(180,195,450,210);
 setcolor(WHITE);
 outtextxy(180,200,"Now click on the moveable place");
  x=getmaxx()/2-52,x1=getmaxx()/2-20+32,y=380,y1=390;
  break;
 }
  }
  while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     if((Xpos>x && Xpos<x1)&&(Ypos>y && Ypos<y1))if(1==(button&1)){
	  rectangle(x,y,x1,y1);
	  hidemouse();
	 // sound(1);

	  color(x,y,x1,y1,14);
	  x=540-42,x1=540+42,y=190,y1=200;
	  erase(x,y,x1,y1,2);
	   erase(240,140,370,160,2);
	  linedraw(70,70,70,200,13);
	  linedraw(540,70,540,200,13);
	  linedraw(getmaxx()/2-20,250,getmaxx()/2-20,400,13);

	  break;
	 }

	 ///Wrong attempt around Source

	 if((Xpos>10 && Xpos<150)&&(Ypos>10 && Ypos<220))if(1==(button&1)){
	    delay(200);
	   setcolor(4);
	     sound(200);
	     outtextxy(250,150,"Wrong Attempt!!");
	     count++;
	      gotoxy(18,1);
	     printf("%d",count);
	     nosound();
	     if(mod=='h' || mod=='H')if(count>3)lost(count);
	      if(mod=='m' || mod=='M')if(count>5)lost(count);
	     if(mod=='e' || mod=='E')if(count>8)lost(count);
	 }

  }
  rectangle(180,195,450,210);
  popup(180,195,450,210);
  showmouse();



 //////  4th move...////////


   x=540-52,x1=540+52,y=190,y1=200;
while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     setcolor(WHITE);
    outtextxy(180,200,"Try Next MOVE");
 if((Xpos>20 && Xpos<125)&& (Ypos>180 && Ypos<190))if(1==(button&1)){
 popup(180,195,450,210);
 setcolor(WHITE);
 outtextxy(180,200,"Now click on the moveable place");
  break;
 }
  }
  while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     if((Xpos>x && Xpos<x1)&&(Ypos>y && Ypos<y1))if(1==(button&1)){
	  rectangle(x,y,x1,y1);
	  hidemouse();
	 // sound(1);
	  color(x,y,x1,y1,15);
	  x=20,y=180,x1=125,y1=190;
	  erase(x,y,x1,y1,2);
	   erase(240,140,370,160,2);
	   linedraw(70,70,70,200,13);
	  linedraw(540,70,540,200,13);
	  linedraw(getmaxx()/2-20,250,getmaxx()/2-20,400,13);

	  break;
	 }

	 ///wrong attempt around destination

	  if((Xpos>getmaxx()/2-82 && Xpos<getmaxx()/2-20+62)&&(Ypos>300 && Ypos<400))if(1==(button&1)){
	     delay(200);
	     setcolor(4);
	     sound(200);
	     outtextxy(250,150,"Wrong Attempt!!");
	     count++;
	      gotoxy(18,1);
	     printf("%d",count);
	     nosound();
	     if(mod=='h' || mod=='H')if(count>3)lost(count);
	      if(mod=='m' || mod=='M')if(count>5)lost(count);
	     if(mod=='e' || mod=='E')if(count>8)lost(count);

	  }
  }
  rectangle(180,195,450,210);
  popup(180,195,450,210);
  showmouse();


//////  5th move...////////


   x=getmaxx()/2-52,x1=getmaxx()/2-20+32,y=380,y1=390;
while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     setcolor(WHITE);
    outtextxy(180,200,"Try Next MOVE");
 if((Xpos>x && Xpos<x1)&& (Ypos>y && Ypos<y1))if(1==(button&1)){
 popup(180,195,450,210);
 setcolor(WHITE);
 outtextxy(180,200,"Now click on the moveable place");
 x=40,y=180,x1=100,y1=190;
  break;
 }
  }
  while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     if((Xpos>x && Xpos<x1)&&(Ypos>y && Ypos<y1))if(1==(button&1)){
	  rectangle(x,y,x1,y1);
	  hidemouse();
	 // sound(1);
	  color(x,y,x1,y1,14);
	   x=getmaxx()/2-52,x1=getmaxx()/2-20+32,y=380,y1=390;
	  erase(x,y,x1,y1,2);
	   erase(240,140,370,160,2);
	   linedraw(70,70,70,200,13);
	  linedraw(540,70,540,200,13);
	  linedraw(getmaxx()/2-20,250,getmaxx()/2-20,400,13);

	  break;
	 }


	  ////wrong attempt around temp

 if((Xpos>getmaxx()-200 && Xpos<getmaxx())&&(Ypos>10 && Ypos<230))if(1==(button&1)){
	     delay(200);
	     setcolor(4);
	     sound(200);
	     outtextxy(250,150,"Wrong Attempt!!");
	     count++;
	      gotoxy(18,1);
	   printf("%d",count);
	     nosound();
	     if(mod=='h' || mod=='H')if(count>3)lost(count);
	      if(mod=='m' || mod=='M')if(count>5)lost(count);
	     if(mod=='e' || mod=='E')if(count>8)lost(count);
	 }

  }
  rectangle(180,195,450,210);
  popup(180,195,450,210);
  showmouse();




//////  6th move...////////


  x=getmaxx()/2-62,x1=getmaxx()/2-20+42,y=390,y1=400;
while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     setcolor(WHITE);
    outtextxy(180,200,"Try Next MOVE");
 if((Xpos>x && Xpos<x1)&& (Ypos>y && Ypos<y1))if(1==(button&1)){
 popup(180,195,450,210);
 setcolor(WHITE);
 outtextxy(180,200,"Now click on the moveable place");
  x=540-42,x1=540+42,y=180,y1=190;
  break;
 }
  }
  while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     if((Xpos>x && Xpos<x1)&&(Ypos>y && Ypos<y1))if(1==(button&1)){
	  rectangle(x,y,x1,y1);
	  hidemouse();
	 // sound(1);
	  color(x,y,x1,y1,1);
	   x=getmaxx()/2-62,x1=getmaxx()/2-20+42,y=390,y1=400;
	  erase(x,y,x1,y1,2);
	   erase(240,140,370,160,2);
	   linedraw(70,70,70,200,13);
	  linedraw(540,70,540,200,13);
	  linedraw(getmaxx()/2-20,250,getmaxx()/2-20,400,13);

	  break;
	 }

	 ///Wrong attempt around Source

	 if((Xpos>10 && Xpos<150)&&(Ypos>10 && Ypos<220))if(1==(button&1)){
	   delay(200);
	   setcolor(4);
	     sound(200);
	     outtextxy(250,150,"Wrong Attempt!!");
	     count++;
	      gotoxy(18,1);
	     printf("%d",count);
	     nosound();
	     if(mod=='h' || mod=='H')if(count>3)lost(count);
	      if(mod=='m' || mod=='M')if(count>5)lost(count);
	     if(mod=='e' || mod=='E')if(count>8)lost(count);
	 }

  }
  rectangle(180,195,450,210);
  popup(180,195,450,210);
  showmouse();



//////  7th move...////////


    x=40,y=180,x1=100,y1=190;
while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     setcolor(WHITE);
    outtextxy(180,200,"Try Next MOVE");
 if((Xpos>x && Xpos<x1)&& (Ypos>y && Ypos<y1))if(1==(button&1)){
 popup(180,195,450,210);
 setcolor(WHITE);
 outtextxy(180,200,"Now click on the moveable place");
   x=540-32,x1=540+32,y=170,y1=180;
  break;
 }
  }
  while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     if((Xpos>x && Xpos<x1)&&(Ypos>y && Ypos<y1))if(1==(button&1)){
	  rectangle(x,y,x1,y1);
	  hidemouse();
	 // sound(1);
	  color(x,y,x1,y1,14);
	    x=40,y=180,x1=100,y1=190;
	  erase(x,y,x1,y1,2);
	   erase(240,140,370,160,2);
	   linedraw(70,70,70,200,13);
	  linedraw(540,70,540,200,13);
	  linedraw(getmaxx()/2-20,250,getmaxx()/2-20,400,13);

	  break;
	 }

	 ///wrong attempt around destination

	  if((Xpos>getmaxx()/2-82 && Xpos<getmaxx()/2-20+62)&&(Ypos>300 && Ypos<400))if(1==(button&1)){
	     delay(200);
	     setcolor(4);
	     sound(200);
	     outtextxy(250,150,"Wrong Attempt!!");
	     count++;
	      gotoxy(18,1);
	    printf("%d",count);
	     nosound();
	     if(mod=='h' || mod=='H')if(count>3)lost(count);
	      if(mod=='m' || mod=='M')if(count>5)lost(count);
	     if(mod=='e' || mod=='E')if(count>8)lost(count);

	  }
  }
  rectangle(180,195,450,210);
  popup(180,195,450,210);
  showmouse();



//////  8th move...////////


    x=5,y=190,x1=135,y1=200;
while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     setcolor(WHITE);
    outtextxy(180,200,"Try Next MOVE");
 if((Xpos>x && Xpos<x1)&& (Ypos>y && Ypos<y1))if(1==(button&1)){
 popup(180,195,450,210);
 setcolor(WHITE);
 outtextxy(180,200,"Now click on the moveable place");
    x=getmaxx()/2-82,x1=getmaxx()/2-20+62,y=390,y1=400;
  break;
 }
  }
  while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     if((Xpos>x && Xpos<x1)&&(Ypos>y && Ypos<y1))if(1==(button&1)){
	  rectangle(x,y,x1,y1);
	  hidemouse();
	 // sound(1);
	  color(x,y,x1,y1,4);
	     x=5,y=190,x1=135,y1=200;
	  erase(x,y,x1,y1,2);
	   erase(240,140,370,160,2);
	   linedraw(70,70,70,200,13);
	  linedraw(540,70,540,200,13);
	  linedraw(getmaxx()/2-20,250,getmaxx()/2-20,400,13);

	  break;
	 }


	  ////wrong attempt around temp

 if((Xpos>getmaxx()-200 && Xpos<getmaxx())&&(Ypos>10 && Ypos<230))if(1==(button&1)){
	     delay(200);
	     setcolor(4);
	     sound(200);
	     outtextxy(250,150,"Wrong Attempt!!");
	     count++;
	      gotoxy(18,1);
	    printf("%d",count);
	     nosound();
	     if(mod=='h' || mod=='H')if(count>3)lost(count);
	      if(mod=='m' || mod=='M')if(count>5)lost(count);
	     if(mod=='e' || mod=='E')if(count>8)lost(count);
	 }

  }
  rectangle(180,195,450,210);
  popup(180,195,450,210);
  showmouse();



  //////  9th move...////////


 x=540-32,x1=540+32,y=170,y1=180;
while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     setcolor(WHITE);
    outtextxy(180,200,"Try Next MOVE");
 if((Xpos>x && Xpos<x1)&& (Ypos>y && Ypos<y1))if(1==(button&1)){
 popup(180,195,450,210);
 setcolor(WHITE);
 outtextxy(180,200,"Now click on the moveable place");
    x=getmaxx()/2-42,x1=getmaxx()/2-20+22,y=380,y1=390;
  break;
 }
  }
  while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     if((Xpos>x && Xpos<x1)&&(Ypos>y && Ypos<y1))if(1==(button&1)){
	  rectangle(x,y,x1,y1);
	  hidemouse();
	 // sound(1);
	  color(x,y,x1,y1,14);
	      x=540-32,x1=540+32,y=170,y1=180;
	  erase(x,y,x1,y1,2);
	   erase(240,140,370,160,2);
	   linedraw(70,70,70,200,13);
	  linedraw(540,70,540,200,13);
	  linedraw(getmaxx()/2-20,250,getmaxx()/2-20,400,13);

	  break;
	 }

	 ///Wrong attempt around Source

	 if((Xpos>10 && Xpos<150)&&(Ypos>10 && Ypos<220))if(1==(button&1)){
	   delay(200);
	   setcolor(4);
	     sound(200);
	     outtextxy(250,150,"Wrong Attempt!!");
	     count++;
	      gotoxy(18,1);
	   printf("%d",count);
	     nosound();
	     if(mod=='h' || mod=='H')if(count>3)lost(count);
	      if(mod=='m' || mod=='M')if(count>5)lost(count);
	     if(mod=='e' || mod=='E')if(count>8)lost(count);
	 }

  }
  rectangle(180,195,450,210);
  popup(180,195,450,210);
  showmouse();




//////  10th move...////////


  x=540-42,x1=540+42,y=180,y1=190;
while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     setcolor(WHITE);
    outtextxy(180,200,"Try Next MOVE");
 if((Xpos>x && Xpos<x1)&& (Ypos>y && Ypos<y1))if(1==(button&1)){
 popup(180,195,450,210);
 setcolor(WHITE);
 outtextxy(180,200,"Now click on the moveable place");
  x=30,y=190,x1=115,y1=200;
  break;
 }
  }
  while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     if((Xpos>x && Xpos<x1)&&(Ypos>y && Ypos<y1))if(1==(button&1)){
	  rectangle(x,y,x1,y1);
	  hidemouse();
	 // sound(1);
	  color(x,y,x1,y1,1);
	    x=540-42,x1=540+42,y=180,y1=190;
	  erase(x,y,x1,y1,2);
	   erase(240,140,370,160,2);
	   linedraw(70,70,70,200,13);
	  linedraw(540,70,540,200,13);
	  linedraw(getmaxx()/2-20,250,getmaxx()/2-20,400,13);

	  break;
	 }

	 ///wrong attempt around destination

	  if((Xpos>getmaxx()/2-82 && Xpos<getmaxx()/2-20+62)&&(Ypos>300 && Ypos<400))if(1==(button&1)){
	     delay(200);
	     setcolor(4);
	     sound(200);
	     outtextxy(250,150,"Wrong Attempt!!");
	     count++;
	      gotoxy(18,1);
	     printf("%d",count);
	     nosound();
	     if(mod=='h' || mod=='H')if(count>3)lost(count);
	      if(mod=='m' || mod=='M')if(count>5)lost(count);
	     if(mod=='e' || mod=='E')if(count>8)lost(count);

	  }
  }
  rectangle(180,195,450,210);
  popup(180,195,450,210);
  showmouse();


 //////  11th move...////////


  x=getmaxx()/2-42,x1=getmaxx()/2-20+22,y=380,y1=390;
while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     setcolor(WHITE);
    outtextxy(180,200,"Try Next MOVE");
 if((Xpos>x && Xpos<x1)&& (Ypos>y && Ypos<y1))if(1==(button&1)){
 popup(180,195,450,210);
 setcolor(WHITE);
 outtextxy(180,200,"Now click on the moveable place");
  x=50,y=180,x1=95,y1=190;
  break;
 }
  }
  while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     if((Xpos>x && Xpos<x1)&&(Ypos>y && Ypos<y1))if(1==(button&1)){
	  rectangle(x,y,x1,y1);
	  hidemouse();
	 // sound(1);
	  color(x,y,x1,y1,14);
	       x=getmaxx()/2-42,x1=getmaxx()/2-20+22,y=380,y1=390;
	  erase(x,y,x1,y1,2);
	   erase(240,140,370,160,2);
	   linedraw(70,70,70,200,13);
	  linedraw(540,70,540,200,13);
	  linedraw(getmaxx()/2-20,250,getmaxx()/2-20,400,13);

	  break;
	 }


	  ////wrong attempt around temp

 if((Xpos>getmaxx()-200 && Xpos<getmaxx())&&(Ypos>10 && Ypos<230))if(1==(button&1)){
	     delay(200);
	     setcolor(4);
	     sound(200);
	     outtextxy(250,150,"Wrong Attempt!!");
	     count++;
	      gotoxy(18,1);
	     printf("%d",count);
	     nosound();
	     if(mod=='h' || mod=='H')if(count>3)lost(count);
	      if(mod=='m' || mod=='M')if(count>5)lost(count);
	     if(mod=='e' || mod=='E')if(count>8)lost(count);
	 }

  }
  rectangle(180,195,450,210);
  popup(180,195,450,210);
  showmouse();



//////  12th move...////////


  x=540-52,x1=540+52,y=190,y1=200;
while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     setcolor(WHITE);
    outtextxy(180,200,"Try Next MOVE");
 if((Xpos>x && Xpos<x1)&& (Ypos>y && Ypos<y1))if(1==(button&1)){
 popup(180,195,450,210);
 setcolor(WHITE);
 outtextxy(180,200,"Now click on the moveable place");
    x=getmaxx()/2-62,x1=getmaxx()/2-20+42,y=380,y1=390;
  break;
 }
  }
  while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     if((Xpos>x && Xpos<x1)&&(Ypos>y && Ypos<y1))if(1==(button&1)){
	  rectangle(x,y,x1,y1);
	  hidemouse();
	 // sound(1);
	  color(x,y,x1,y1,15);
	       x=540-52,x1=540+52,y=190,y1=200;
	  erase(x,y,x1,y1,2);
	   erase(240,140,370,160,2);
	   linedraw(70,70,70,200,13);
	  linedraw(540,70,540,200,13);
	  linedraw(getmaxx()/2-20,250,getmaxx()/2-20,400,13);

	  break;
	 }

	 ///Wrong attempt around Source

	 if((Xpos>10 && Xpos<150)&&(Ypos>10 && Ypos<220))if(1==(button&1)){
	   delay(200);
	   setcolor(4);
	     sound(200);
	     outtextxy(250,150,"Wrong Attempt!!");
	     count++;
	      gotoxy(18,1);
	      printf("%d",count);
	     nosound();
	     if(mod=='h' || mod=='H')if(count>3)lost(count);
	      if(mod=='m' || mod=='M')if(count>5)lost(count);
	     if(mod=='e' || mod=='E')if(count>8)lost(count);
	 }

  }
  rectangle(180,195,450,210);
  popup(180,195,450,210);
  showmouse();



 //////  13th move...////////


   x=50,y=180,x1=95,y1=190;
while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     setcolor(WHITE);
    outtextxy(180,200,"Try Next MOVE");
 if((Xpos>x && Xpos<x1)&& (Ypos>y && Ypos<y1))if(1==(button&1)){
 popup(180,195,450,210);
 setcolor(WHITE);
 outtextxy(180,200,"Now click on the moveable place");
    x=540-32,x1=540+32,y=190,y1=200;
  break;
 }
  }
  while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     if((Xpos>x && Xpos<x1)&&(Ypos>y && Ypos<y1))if(1==(button&1)){
	  rectangle(x,y,x1,y1);
	  hidemouse();
	 // sound(1);
	  color(x,y,x1,y1,14);
	   x=50,y=180,x1=95,y1=190;
	  erase(x,y,x1,y1,2);
	   erase(240,140,370,160,2);
	   linedraw(70,70,70,200,13);
	  linedraw(540,70,540,200,13);
	  linedraw(getmaxx()/2-20,250,getmaxx()/2-20,400,13);

	  break;
	 }

	 ///wrong attempt around destination

	  if((Xpos>getmaxx()/2-82 && Xpos<getmaxx()/2-20+62)&&(Ypos>300 && Ypos<400))if(1==(button&1)){
	     delay(200);
	     setcolor(4);
	     sound(200);
	     outtextxy(250,150,"Wrong Attempt!!");
	     count++;
	      gotoxy(18,1);
	     printf("%d",count);
	     nosound();
	     if(mod=='h' || mod=='H')if(count>3)lost(count);
	      if(mod=='m' || mod=='M')if(count>5)lost(count);
	     if(mod=='e' || mod=='E')if(count>8)lost(count);
	  }
  }
  rectangle(180,195,450,210);
  popup(180,195,450,210);
  showmouse();



//////  14th move...////////



    x=30,y=190,x1=115,y1=200;
while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     setcolor(WHITE);
    outtextxy(180,200,"Try Next MOVE");
 if((Xpos>x && Xpos<x1)&& (Ypos>y && Ypos<y1))if(1==(button&1)){
 popup(180,195,450,210);
 setcolor(WHITE);
 outtextxy(180,200,"Now click on the moveable place");
  x=getmaxx()/2-55,x1=getmaxx()/2-20+35,y=370,y1=380;
  break;
 }
  }
  while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     if((Xpos>x && Xpos<x1)&&(Ypos>y && Ypos<y1))if(1==(button&1)){
	  rectangle(x,y,x1,y1);
	  hidemouse();
	 // sound(1);
	  color(x,y,x1,y1,1);
	    x=30,y=190,x1=115,y1=200;
	  erase(x,y,x1,y1,2);
	   erase(240,140,370,160,2);
	   linedraw(70,70,70,200,13);
	  linedraw(540,70,540,200,13);
	  linedraw(getmaxx()/2-20,250,getmaxx()/2-20,400,13);

	  break;
	 }

	  ////wrong attempt around temp

 if((Xpos>getmaxx()-200 && Xpos<getmaxx())&&(Ypos>10 && Ypos<230))if(1==(button&1)){
	     delay(200);
	     setcolor(4);
	     sound(200);
	     outtextxy(250,150,"Wrong Attempt!!");
	     count++;
	      gotoxy(18,1);
	     printf("%d",count);
	     nosound();
	     if(mod=='h' || mod=='H')if(count>3)lost(count);
	      if(mod=='m' || mod=='M')if(count>5)lost(count);
	     if(mod=='e' || mod=='E')if(count>8)lost(count);
	 }

  }
  rectangle(180,195,450,210);
  popup(180,195,450,210);
  showmouse();



 //////  15th/FINAL move...////////



  x=540-32,x1=540+32,y=190,y1=200;
while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     setcolor(WHITE);
    outtextxy(180,200,"Try Next MOVE");
 if((Xpos>x && Xpos<x1)&& (Ypos>y && Ypos<y1))if(1==(button&1)){
 popup(180,195,450,210);
 setcolor(WHITE);
 outtextxy(180,200,"Now click on the moveable place");
  x=getmaxx()/2-40,x1=getmaxx()/2-20+20,y=360,y1=370;
  break;
 }
  }
  while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     if((Xpos>x && Xpos<x1)&&(Ypos>y && Ypos<y1))if(1==(button&1)){
	  rectangle(x,y,x1,y1);
	  hidemouse();
	 // sound(1);
	  color(x,y,x1,y1,14);
	     x=540-32,x1=540+32,y=190,y1=200;
	  erase(x,y,x1,y1,2);
	   erase(240,140,370,160,2);
	   linedraw(70,70,70,200,13);
	  linedraw(540,70,540,200,13);
	  linedraw(getmaxx()/2-20,250,getmaxx()/2-20,400,13);

	  break;
	 }

	 ///Wrong attempt around Source

	 if((Xpos>10 && Xpos<150)&&(Ypos>10 && Ypos<220))if(1==(button&1)){
	   delay(200);
	   setcolor(4);
	     sound(200);
	     outtextxy(250,150,"Wrong Attempt!!");
	     count++;
	      gotoxy(18,1);
	     printf("%d",count);
	     nosound();
	     if(mod=='h' || mod=='H')if(count>3)lost(count);
	      if(mod=='m' || mod=='M')if(count>5)lost(count);
	     if(mod=='e' || mod=='E')if(count>8)lost(count);
	 }

  }
  rectangle(180,195,450,210);
  popup(180,195,450,210);
  setcolor(15);
  outtextxy(180,200,"congratulations!!!");
  outtextxy(180,210,"YOU WIN!!");

  if(count==0)perfectwin(count);
  if(count==1)win(count);
 if(mod=='h'|| mod=='H') if(count<=3)win(count);
  if(mod=='m'|| mod=='M') if(count<=5)win(count);
   if(mod=='e'|| mod=='E') if(count<=8)win(count);

   if(kbhit());
  char ch=getch();
  if(ch==27)exitpage();
  if(ch==8){
   cleardevice();
   graphicsdriver();
   discselection();
  }
 getch();
 cleardevice();
 closegraph();
 return 0;
}






///wrong attemps code rough/////


/*
 ///Wrong attempt around Source

	 if((Xpos>10 && Xpos<150)&&(Ypos>10 && Ypos<220))if(1==(button&1)){
	   setcolor(4);
	     sound(200);
	     outtextxy(250,150,"Wrong Attempt!!");
	     count++;
	     nosound();
	 }



	  ////wrong attempt around temp

 if((Xpos>getmaxx()-200 && Xpos<getmaxx())&&(Ypos>10 && Ypos<230))if(1==(button&1)){
	     setcolor(4);
	     sound(200);
	     outtextxy(250,150,"Wrong Attempt!!");
	     count++;
	     nosound();
	 // break;
	 }



 ///wrong attempt around destination

	  if((Xpos>getmaxx()/2-82 && Xpos<getmaxx()/2-20+62)&&(Ypos>300 && Ypos<400))if(1==(button&1)){
	     setcolor(4);
	     sound(200);
	     outtextxy(250,150,"Wrong Attempt!!");
	     count++;
	     nosound();

	  }



	   erase(240,140,370,160,2);

*/


 ////page for 5 disc////


 int calldisc5(){
 int mod;
mod=mode();
 clrscr();
 cleardevice();
graphicsdriver();
showmouse();
 settextstyle(SANS_SERIF_FONT,HORIZ_DIR,3);
 setcolor(15);
 outtextxy(190,0,"Draw 5 disc PUZZLE");
 setcolor(13);
 outtextxy(191,1,"Draw 5 disc PUZZLE");
 setcolor(4);
   if(mod=='h' || mod=='H')outtextxy(190,50,"*****HARD MODE*****");
   else if(mod=='E' || mod=='e')outtextxy(190,50,"*****EASY MODE*****");
   if(mod=='m' || mod=='M')outtextxy(190,50,"*****Medium MODE*****");
 settextstyle(DEFAULT_FONT,HORIZ_DIR,1);

  line(70,70,70,200);
  setbkcolor(2);
  fillellipse(0,201,201,1);
  setcolor(1);
  outtextxy(30,210,"SOURCE");
  setcolor(4);
	  rectangle(10,190,130,200);
  int x=11,y=191,x1=130,y1=191,count=0;///x1 will be constant
   printf("WRONG ATTEMPTS = %d ",count);
  while(y1!=200){
   line(x,y,x1,y1);
   y++,y1++;
   }
   setcolor(15);
	 rectangle(20,180,125,190);
  x=21,y=181,x1=125,y1=181;
  while(y1!=190){
  line(x,y,x1,y1);
  y++,y1++;
  }
  setcolor(1);
	 rectangle(30,170,115,180);
  x=31,y=171,x1=115,y1=171;
  while(y1!=180){
  line(x,y,x1,y1);
  y++,y1++;
  }
  setcolor(14);
	 rectangle(40,160,105,170);
  x=41,y=161,x1=105,y1=161;
  while(y1!=170){
  line(x,y,x1,y1);
  y++,y1++;
  }
  setcolor(8);
	 rectangle(50,150,95,160);
  x=51,y=151,x1=95,y1=151;
  while(y1!=160){
  line(x,y,x1,y1);
  y++,y1++;
  }

  line(540,70,540,200);
  fillellipse(600,201,201,1);
  setcolor(14);
  outtextxy(550,212,"TEMPORARY");
  line(getmaxx()/2-20,250,getmaxx()/2-20,400);
  fillellipse(300,400,200,1);
  setcolor(15);
  outtextxy(getmaxx()/2,410,"DESTINATION");


//////  1st move...////////



    x=50,y=150,x1=95,y1=160;
while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     setcolor(WHITE);
    outtextxy(180,200,"Select top DISC");
 if((Xpos>x && Xpos<x1)&& (Ypos>y && Ypos<y1))if(1==(button&1)){
 popup(180,195,450,210);
 setcolor(WHITE);
 outtextxy(180,200,"Now click on the moveable place");
  x=getmaxx()/2-20-25,x1=getmaxx()/2-20+25,y=390,y1=400;
  break;
 }
  }
  while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     if((Xpos>x && Xpos<x1)&&(Ypos>y && Ypos<y1))if(1==(button&1)){
	  rectangle(x,y,x1,y1);
	  hidemouse();
	 // sound(1);
	  color(x,y,x1,y1,8);
	    x=50,y=150,x1=95,y1=160;
	  erase(x,y,x1,y1,2);
	   erase(240,140,370,160,2);
	   linedraw(70,70,70,200,13);
	  linedraw(540,70,540,200,13);
	  linedraw(getmaxx()/2-20,250,getmaxx()/2-20,400,13);

	  break;
	 }


	  ////wrong attempt around temp

 if((Xpos>getmaxx()-200 && Xpos<getmaxx())&&(Ypos>10 && Ypos<230))if(1==(button&1)){
	     delay(200);
	     setcolor(4);
	     sound(200);
	     outtextxy(250,150,"Wrong Attempt!!");
	     count++;
	      gotoxy(18,1);
	     printf("%d",count);
	     nosound();
	     if(mod=='h' || mod=='H')if(count>5)lost(count);
	      if(mod=='m' || mod=='M')if(count>8)lost(count);
	     if(mod=='e' || mod=='E')if(count>11)lost(count);
	 // break;
	 }


  }
  rectangle(180,195,450,210);
  popup(180,195,450,210);
  showmouse();


//////  2nd move...////////



  x=40,y=160,x1=105,y1=170;
while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     setcolor(WHITE);
    outtextxy(180,200,"TRY next MOVE");
 if((Xpos>x && Xpos<x1)&& (Ypos>y && Ypos<y1))if(1==(button&1)){
 popup(180,195,450,210);
 setcolor(WHITE);
 outtextxy(180,200,"Now click on the moveable place");
   x=540-32,x1=540+32,y=190,y1=200;
  break;
 }
  }
  while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     if((Xpos>x && Xpos<x1)&&(Ypos>y && Ypos<y1))if(1==(button&1)){
	  rectangle(x,y,x1,y1);
	  hidemouse();
	 // sound(1);
	  color(x,y,x1,y1,14);
	   x=40,y=160,x1=105,y1=170;
	  erase(x,y,x1,y1,2);
	   erase(240,140,370,160,2);
	   linedraw(70,70,70,200,13);
	  linedraw(540,70,540,200,13);
	  linedraw(getmaxx()/2-20,250,getmaxx()/2-20,400,13);

	  break;
	 }


 ///wrong attempt around destination

	  if((Xpos>getmaxx()/2-82 && Xpos<getmaxx()/2-20+62)&&(Ypos>300 && Ypos<400))if(1==(button&1)){
	     delay(200);
	     setcolor(4);
	     sound(200);
	     outtextxy(250,150,"Wrong Attempt!!");
	     count++;
	      gotoxy(18,1);
	     printf("%d",count);
	     nosound();
	     if(mod=='h' || mod=='H')if(count>5)lost(count);
	      if(mod=='m' || mod=='M')if(count>8)lost(count);
	     if(mod=='e' || mod=='E')if(count>11)lost(count);

	  }


  }
  rectangle(180,195,450,210);
  popup(180,195,450,210);
  showmouse();



 //////  3rd move...////////



     x=getmaxx()/2-20-25,x1=getmaxx()/2-20+25,y=390,y1=400;
while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     setcolor(WHITE);
    outtextxy(180,200,"TRY next MOVE");
 if((Xpos>x && Xpos<x1)&& (Ypos>y && Ypos<y1))if(1==(button&1)){
 popup(180,195,450,210);
 setcolor(WHITE);
 outtextxy(180,200,"Now click on the moveable place");
   x=540-22,x1=540+22,y=180,y1=190;
  break;
 }
  }
  while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     if((Xpos>x && Xpos<x1)&&(Ypos>y && Ypos<y1))if(1==(button&1)){
	  rectangle(x,y,x1,y1);
	  hidemouse();
	 // sound(1);
	  color(x,y,x1,y1,8);
	      x=getmaxx()/2-20-25,x1=getmaxx()/2-20+25,y=390,y1=400;
	  erase(x,y,x1,y1,2);
	   erase(240,140,370,160,2);
	   linedraw(70,70,70,200,13);
	  linedraw(540,70,540,200,13);
	  linedraw(getmaxx()/2-20,250,getmaxx()/2-20,400,13);

	  break;
	 }

	  ///Wrong attempt around Source

	 if((Xpos>10 && Xpos<150)&&(Ypos>10 && Ypos<220))if(1==(button&1)){
	   delay(200);
	   setcolor(4);
	     sound(200);
	     outtextxy(250,150,"Wrong Attempt!!");
	     count++;
		 gotoxy(18,1);
	     printf("%d",count);
	     nosound();
	     if(mod=='h' || mod=='H')if(count>5)lost(count);
	      if(mod=='m' || mod=='M')if(count>8)lost(count);
	     if(mod=='e' || mod=='E')if(count>11)lost(count);
	 }

  }
  rectangle(180,195,450,210);
  popup(180,195,450,210);
  showmouse();



 //////  4th move...////////



   x=30,x1=170,y=115,y1=180;
while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     setcolor(WHITE);
    outtextxy(180,200,"TRY next MOVE");
 if((Xpos>x && Xpos<x1)&& (Ypos>y && Ypos<y1))if(1==(button&1)){
 popup(180,195,450,210);
 setcolor(WHITE);
 outtextxy(180,200,"Now click on the moveable place");
   x=getmaxx()/2-20-45,x1=getmaxx()/2-20+45,y=390,y1=400;
  break;
 }
  }
  while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     if((Xpos>x && Xpos<x1)&&(Ypos>y && Ypos<y1))if(1==(button&1)){
	  rectangle(x,y,x1,y1);
	  hidemouse();
	 // sound(1);
	  color(x,y,x1,y1,1);
	  x=30,x1=170,y=115,y1=180;
	  erase(x,y,x1,y1,2);
	   erase(240,140,370,160,2);
	   linedraw(70,70,70,200,13);
	  linedraw(540,70,540,200,13);
	  linedraw(getmaxx()/2-20,250,getmaxx()/2-20,400,13);

	  break;
	 }


	  ////wrong attempt around temp

 if((Xpos>getmaxx()-200 && Xpos<getmaxx())&&(Ypos>10 && Ypos<230))if(1==(button&1)){
	     delay(200);
	     setcolor(4);
	     sound(200);
	     outtextxy(250,150,"Wrong Attempt!!");
	     count++;
	      gotoxy(18,1);
	   printf("%d",count);
	     nosound();
	     if(mod=='h' || mod=='H')if(count>5)lost(count);
	      if(mod=='m' || mod=='M')if(count>8)lost(count);
	     if(mod=='e' || mod=='E')if(count>11)lost(count);
	 }


  }
  rectangle(180,195,450,210);
  popup(180,195,450,210);
  showmouse();



 //////  5th move...////////



      x=540-22,x1=540+22,y=180,y1=190;
while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     setcolor(WHITE);
    outtextxy(180,200,"TRY next MOVE");
 if((Xpos>x && Xpos<x1)&& (Ypos>y && Ypos<y1))if(1==(button&1)){
 popup(180,195,450,210);
 setcolor(WHITE);
 outtextxy(180,200,"Now click on the moveable place");
  x=50,x1=95,y=170,y1=180;
  break;
 }
  }
  while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     if((Xpos>x && Xpos<x1)&&(Ypos>y && Ypos<y1))if(1==(button&1)){
	  rectangle(x,y,x1,y1);
	  hidemouse();
	 // sound(1);
	  color(x,y,x1,y1,8);
	       x=540-22,x1=540+22,y=180,y1=190;
	  erase(x,y,x1,y1,2);
	   erase(240,140,370,160,2);
	   linedraw(70,70,70,200,13);
	  linedraw(540,70,540,200,13);
	  linedraw(getmaxx()/2-20,250,getmaxx()/2-20,400,13);

	  break;
	 }


 ///wrong attempt around destination

	  if((Xpos>getmaxx()/2-82 && Xpos<getmaxx()/2-20+62)&&(Ypos>300 && Ypos<400))if(1==(button&1)){
	     delay(200);
	     setcolor(4);
	     sound(200);
	     outtextxy(250,150,"Wrong Attempt!!");
	     count++;
	      gotoxy(18,1);
	   printf("%d",count);
	     nosound();
	     if(mod=='h' || mod=='H')if(count>5)lost(count);
	      if(mod=='m' || mod=='M')if(count>8)lost(count);
	     if(mod=='e' || mod=='E')if(count>11)lost(count);

	  }


  }
  rectangle(180,195,450,210);
  popup(180,195,450,210);
  showmouse();



 //////  6th move...////////



       x=540-32,x1=540+32,y=190,y1=200;
while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     setcolor(WHITE);
    outtextxy(180,200,"TRY next MOVE");
 if((Xpos>x && Xpos<x1)&& (Ypos>y && Ypos<y1))if(1==(button&1)){
 popup(180,195,450,210);
 setcolor(WHITE);
 outtextxy(180,200,"Now click on the moveable place");
    x=getmaxx()/2-20-35,x1=getmaxx()/2-20+35,y=380,y1=390;
  break;
 }
  }
  while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     if((Xpos>x && Xpos<x1)&&(Ypos>y && Ypos<y1))if(1==(button&1)){
	  rectangle(x,y,x1,y1);
	  hidemouse();
	 // sound(1);
	  color(x,y,x1,y1,14);
		x=540-32,x1=540+32,y=190,y1=200;
	  erase(x,y,x1,y1,2);
	   erase(240,140,370,160,2);
	   linedraw(70,70,70,200,13);
	  linedraw(540,70,540,200,13);
	  linedraw(getmaxx()/2-20,250,getmaxx()/2-20,400,13);

	  break;
	 }

	  ///Wrong attempt around Source

	 if((Xpos>10 && Xpos<150)&&(Ypos>10 && Ypos<220))if(1==(button&1)){
	   delay(200);
	   setcolor(4);
	     sound(200);
	     outtextxy(250,150,"Wrong Attempt!!");
	     count++;
	      gotoxy(18,1);
	    printf("%d",count);
	     nosound();
	     if(mod=='h' || mod=='H')if(count>5)lost(count);
	      if(mod=='m' || mod=='M')if(count>8)lost(count);
	     if(mod=='e' || mod=='E')if(count>11)lost(count);
	 }

  }
  rectangle(180,195,450,210);
  popup(180,195,450,210);
  showmouse();




//////  7th move...////////



 x=50,x1=95,y=170,y1=180;
while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     setcolor(WHITE);
    outtextxy(180,200,"TRY next MOVE");
 if((Xpos>x && Xpos<x1)&& (Ypos>y && Ypos<y1))if(1==(button&1)){
 popup(180,195,450,210);
 setcolor(WHITE);
 outtextxy(180,200,"Now click on the moveable place");
  x=getmaxx()/2-20-25,x1=getmaxx()/2-20+25,y=370,y1=380;
  break;
 }
  }
  while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     if((Xpos>x && Xpos<x1)&&(Ypos>y && Ypos<y1))if(1==(button&1)){
	  rectangle(x,y,x1,y1);
	  hidemouse();
	 // sound(1);
	  color(x,y,x1,y1,8);
	   x=50,x1=95,y=170,y1=180;
	  erase(x,y,x1,y1,2);
	   erase(240,140,370,160,2);
	   linedraw(70,70,70,200,13);
	  linedraw(540,70,540,200,13);
	  linedraw(getmaxx()/2-20,250,getmaxx()/2-20,400,13);

	  break;
	 }


	  ////wrong attempt around temp

 if((Xpos>getmaxx()-200 && Xpos<getmaxx())&&(Ypos>10 && Ypos<230))if(1==(button&1)){
	     delay(200);
	     setcolor(4);
	     sound(200);
	     outtextxy(250,150,"Wrong Attempt!!");
	     count++;
	      gotoxy(18,1);
	    printf("%d",count);
	     nosound();
	     if(mod=='h' || mod=='H')if(count>5)lost(count);
	      if(mod=='m' || mod=='M')if(count>8)lost(count);
	     if(mod=='e' || mod=='E')if(count>11)lost(count);
	 }


  }
  rectangle(180,195,450,210);
  popup(180,195,450,210);
  showmouse();




//////  8th move...////////



  x=20,x1=125,y=180,y1=190;
while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     setcolor(WHITE);
    outtextxy(180,200,"TRY next MOVE");
 if((Xpos>x && Xpos<x1)&& (Ypos>y && Ypos<y1))if(1==(button&1)){
 popup(180,195,450,210);
 setcolor(WHITE);
 outtextxy(180,200,"Now click on the moveable place");
  x=540-55,x1=540+55,y=190,y1=200;
  break;
 }
  }
  while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     if((Xpos>x && Xpos<x1)&&(Ypos>y && Ypos<y1))if(1==(button&1)){
	  rectangle(x,y,x1,y1);
	  hidemouse();
	 // sound(1);
	  color(x,y,x1,y1,15);
	   x=20,x1=125,y=180,y1=190;
	  erase(x,y,x1,y1,2);
	   erase(240,140,370,160,2);
	   linedraw(70,70,70,200,13);
	  linedraw(540,70,540,200,13);
	  linedraw(getmaxx()/2-20,250,getmaxx()/2-20,400,13);

	  break;
	 }


 ///wrong attempt around destination

	  if((Xpos>getmaxx()/2-82 && Xpos<getmaxx()/2-20+62)&&(Ypos>300 && Ypos<400))if(1==(button&1)){
	     delay(200);
	     setcolor(4);
	     sound(200);
	     outtextxy(250,150,"Wrong Attempt!!");
	     count++;
	      gotoxy(18,1);
	   printf("%d",count);
	     nosound();
	     if(mod=='h' || mod=='H')if(count>5)lost(count);
	      if(mod=='m' || mod=='M')if(count>8)lost(count);
	     if(mod=='e' || mod=='E')if(count>11)lost(count);

	  }


  }
  rectangle(180,195,450,210);
  popup(180,195,450,210);
  showmouse();




//////  9th move...////////



   x=getmaxx()/2-20-25,x1=getmaxx()/2-20+25,y=370,y1=380;
while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     setcolor(WHITE);
    outtextxy(180,200,"TRY next MOVE");
 if((Xpos>x && Xpos<x1)&& (Ypos>y && Ypos<y1))if(1==(button&1)){
 popup(180,195,450,210);
 setcolor(WHITE);
 outtextxy(180,200,"Now click on the moveable place");
  x=540-25,x1=540+25,y=180,y1=190;
  break;
 }
  }
  while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     if((Xpos>x && Xpos<x1)&&(Ypos>y && Ypos<y1))if(1==(button&1)){
	  rectangle(x,y,x1,y1);
	  hidemouse();
	 // sound(1);
	  color(x,y,x1,y1,8);
	   x=getmaxx()/2-20-25,x1=getmaxx()/2-20+25,y=370,y1=380;
	  erase(x,y,x1,y1,2);
	   erase(240,140,370,160,2);
	   linedraw(70,70,70,200,13);
	  linedraw(540,70,540,200,13);
	  linedraw(getmaxx()/2-20,250,getmaxx()/2-20,400,13);

	  break;
	 }

	  ///Wrong attempt around Source

	 if((Xpos>10 && Xpos<150)&&(Ypos>10 && Ypos<220))if(1==(button&1)){
	   delay(200);
	   setcolor(4);
	     sound(200);
	     outtextxy(250,150,"Wrong Attempt!!");
	     count++;
	      gotoxy(18,1);
	   printf("%d",count);
	     nosound();
	     if(mod=='h' || mod=='H')if(count>5)lost(count);
	      if(mod=='m' || mod=='M')if(count>8)lost(count);
	     if(mod=='e' || mod=='E')if(count>11)lost(count);
	 }

  }
  rectangle(180,195,450,210);
  popup(180,195,450,210);
  showmouse();




//////  10th move...////////



       x=getmaxx()/2-20-35,x1=getmaxx()/2-20+35,y=380,y1=390;
while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     setcolor(WHITE);
    outtextxy(180,200,"TRY next MOVE");
 if((Xpos>x && Xpos<x1)&& (Ypos>y && Ypos<y1))if(1==(button&1)){
 popup(180,195,450,210);
 setcolor(WHITE);
 outtextxy(180,200,"Now click on the moveable place");
  x=40,x1=105,y=180,y1=190;
  break;
 }
  }
  while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     if((Xpos>x && Xpos<x1)&&(Ypos>y && Ypos<y1))if(1==(button&1)){
	  rectangle(x,y,x1,y1);
	  hidemouse();
	 // sound(1);
	  color(x,y,x1,y1,14);
	    x=getmaxx()/2-20-35,x1=getmaxx()/2-20+35,y=380,y1=390;
	  erase(x,y,x1,y1,2);
	   erase(240,140,370,160,2);
	   linedraw(70,70,70,200,13);
	  linedraw(540,70,540,200,13);
	  linedraw(getmaxx()/2-20,250,getmaxx()/2-20,400,13);

	  break;
	 }


	  ////wrong attempt around temp

 if((Xpos>getmaxx()-200 && Xpos<getmaxx())&&(Ypos>10 && Ypos<230))if(1==(button&1)){
	     delay(200);
	     setcolor(4);
	     sound(200);
	     outtextxy(250,150,"Wrong Attempt!!");
	     count++;
	      gotoxy(18,1);
	   printf("%d",count);
	     nosound();
	     if(mod=='h' || mod=='H')if(count>5)lost(count);
	      if(mod=='m' || mod=='M')if(count>8)lost(count);
	     if(mod=='e' || mod=='E')if(count>11)lost(count);
	 }


  }
  rectangle(180,195,450,210);
  popup(180,195,450,210);
  showmouse();









//////  11th move...////////



     x=540-25,x1=540+25,y=180,y1=190;
while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     setcolor(WHITE);
    outtextxy(180,200,"TRY next MOVE");
 if((Xpos>x && Xpos<x1)&& (Ypos>y && Ypos<y1))if(1==(button&1)){
 popup(180,195,450,210);
 setcolor(WHITE);
 outtextxy(180,200,"Now click on the moveable place");
  x=50,x1=95,y=170,y1=180;
  break;
 }
  }
  while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     if((Xpos>x && Xpos<x1)&&(Ypos>y && Ypos<y1))if(1==(button&1)){
	  rectangle(x,y,x1,y1);
	  hidemouse();
	 // sound(1);
	  color(x,y,x1,y1,8);
	     x=540-25,x1=540+25,y=180,y1=190;
	  erase(x,y,x1,y1,2);
	   erase(240,140,370,160,2);
	   linedraw(70,70,70,200,13);
	  linedraw(540,70,540,200,13);
	  linedraw(getmaxx()/2-20,250,getmaxx()/2-20,400,13);

	  break;
	 }


 ///wrong attempt around destination

	  if((Xpos>getmaxx()/2-82 && Xpos<getmaxx()/2-20+62)&&(Ypos>300 && Ypos<400))if(1==(button&1)){
	     delay(200);
	     setcolor(4);
	     sound(200);
	     outtextxy(250,150,"Wrong Attempt!!");
	     count++;
	      gotoxy(18,1);
	  printf("%d",count);
	     nosound();
	     if(mod=='h' || mod=='H')if(count>5)lost(count);
	      if(mod=='m' || mod=='M')if(count>8)lost(count);
	     if(mod=='e' || mod=='E')if(count>11)lost(count);

	  }


  }
  rectangle(180,195,450,210);
  popup(180,195,450,210);
  showmouse();










//////  12th move...////////



     x=getmaxx()/2-20-45,x1=getmaxx()/2-20+45,y=390,y1=400;
while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     setcolor(WHITE);
    outtextxy(180,200,"TRY next MOVE");
 if((Xpos>x && Xpos<x1)&& (Ypos>y && Ypos<y1))if(1==(button&1)){
 popup(180,195,450,210);
 setcolor(WHITE);
 outtextxy(180,200,"Now click on the moveable place");
 x=540-40,x1=540+40,y=180,y1=190;
  break;
 }
  }
  while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     if((Xpos>x && Xpos<x1)&&(Ypos>y && Ypos<y1))if(1==(button&1)){
	  rectangle(x,y,x1,y1);
	  hidemouse();
	 // sound(1);
	  color(x,y,x1,y1,1);

	      x=getmaxx()/2-20-45,x1=getmaxx()/2-20+45,y=390,y1=400;
	  erase(x,y,x1,y1,2);
	   erase(240,140,370,160,2);
	   linedraw(70,70,70,200,13);
	  linedraw(540,70,540,200,13);
	  linedraw(getmaxx()/2-20,250,getmaxx()/2-20,400,13);

	  break;
	 }

	  ///Wrong attempt around Source

	 if((Xpos>10 && Xpos<150)&&(Ypos>10 && Ypos<220))if(1==(button&1)){
	   delay(200);
	   setcolor(4);
	     sound(200);
	     outtextxy(250,150,"Wrong Attempt!!");
	     count++;
	      gotoxy(18,1);
	    printf("%d",count);
	     nosound();
	     if(mod=='h' || mod=='H')if(count>5)lost(count);
	      if(mod=='m' || mod=='M')if(count>8)lost(count);
	     if(mod=='e' || mod=='E')if(count>11)lost(count);
	 }

  }
  rectangle(180,195,450,210);
  popup(180,195,450,210);
  showmouse();






//////  13th move...////////



       x=50,x1=95,y=170,y1=180;
while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     setcolor(WHITE);
    outtextxy(180,200,"TRY next MOVE");
 if((Xpos>x && Xpos<x1)&& (Ypos>y && Ypos<y1))if(1==(button&1)){
 popup(180,195,450,210);
 setcolor(WHITE);
 outtextxy(180,200,"Now click on the moveable place");
  x=getmaxx()/2-20-22,x1=getmaxx()/2-20+22,y=390,y1=400;
  break;
 }
  }
  while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     if((Xpos>x && Xpos<x1)&&(Ypos>y && Ypos<y1))if(1==(button&1)){
	  rectangle(x,y,x1,y1);
	  hidemouse();
	 // sound(1);
	  color(x,y,x1,y1,8);

	       x=50,x1=95,y=170,y1=180;
	  erase(x,y,x1,y1,2);
	   erase(240,140,370,160,2);
	   linedraw(70,70,70,200,13);
	  linedraw(540,70,540,200,13);
	  linedraw(getmaxx()/2-20,250,getmaxx()/2-20,400,13);

	  break;
	 }


	  ////wrong attempt around temp

 if((Xpos>getmaxx()-200 && Xpos<getmaxx())&&(Ypos>10 && Ypos<230))if(1==(button&1)){
	     delay(200);
	     setcolor(4);
	     sound(200);
	     outtextxy(250,150,"Wrong Attempt!!");
	     count++;
	      gotoxy(18,1);
	    printf("%d",count);
	     nosound();
	     if(mod=='h' || mod=='H')if(count>5)lost(count);
	      if(mod=='m' || mod=='M')if(count>8)lost(count);
	     if(mod=='e' || mod=='E')if(count>11)lost(count);
	 }


  }
  rectangle(180,195,450,210);
  popup(180,195,450,210);
  showmouse();





//////  14th move...////////



	x=40,x1=105,y=180,y1=190;
while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     setcolor(WHITE);
    outtextxy(180,200,"TRY next MOVE");
 if((Xpos>x && Xpos<x1)&& (Ypos>y && Ypos<y1))if(1==(button&1)){
 popup(180,195,450,210);
 setcolor(WHITE);
 outtextxy(180,200,"Now click on the moveable place");
   x=540-35,x1=540+35,y=170,y1=180;
  break;
 }
  }
  while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     if((Xpos>x && Xpos<x1)&&(Ypos>y && Ypos<y1))if(1==(button&1)){
	  rectangle(x,y,x1,y1);
	  hidemouse();
	 // sound(1);
	  color(x,y,x1,y1,14);

	  x=40,x1=105,y=180,y1=190;
	  erase(x,y,x1,y1,2);
	   erase(240,140,370,160,2);
	   linedraw(70,70,70,200,13);
	  linedraw(540,70,540,200,13);
	  linedraw(getmaxx()/2-20,250,getmaxx()/2-20,400,13);

	  break;
	 }


 ///wrong attempt around destination

	  if((Xpos>getmaxx()/2-82 && Xpos<getmaxx()/2-20+62)&&(Ypos>300 && Ypos<400))if(1==(button&1)){
	     delay(200);
	     setcolor(4);
	     sound(200);
	     outtextxy(250,150,"Wrong Attempt!!");
	     count++;
	      gotoxy(18,1);
	    printf("%d",count);
	     nosound();
	     if(mod=='h' || mod=='H')if(count>5)lost(count);
	      if(mod=='m' || mod=='M')if(count>8)lost(count);
	     if(mod=='e' || mod=='E')if(count>11)lost(count);

	  }


  }
  rectangle(180,195,450,210);
  popup(180,195,450,210);
  showmouse();







//////  15th move...////////



	 x=getmaxx()/2-20-22,x1=getmaxx()/2-20+22,y=390,y1=400;
while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     setcolor(WHITE);
    outtextxy(180,200,"TRY next MOVE");
 if((Xpos>x && Xpos<x1)&& (Ypos>y && Ypos<y1))if(1==(button&1)){
 popup(180,195,450,210);
 setcolor(WHITE);
 outtextxy(180,200,"Now click on the moveable place");
   x=540-22,x1=540+22,y=160,y1=170;
  break;
 }
  }
  while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     if((Xpos>x && Xpos<x1)&&(Ypos>y && Ypos<y1))if(1==(button&1)){
	  rectangle(x,y,x1,y1);
	  hidemouse();
	 // sound(1);
	  color(x,y,x1,y1,8);

	   x=getmaxx()/2-20-22,x1=getmaxx()/2-20+22,y=390,y1=400;
	  erase(x,y,x1,y1,2);
	   erase(240,140,370,160,2);
	   linedraw(70,70,70,200,13);
	  linedraw(540,70,540,200,13);
	  linedraw(getmaxx()/2-20,250,getmaxx()/2-20,400,13);

	  break;
	 }

	  ///Wrong attempt around Source

	 if((Xpos>10 && Xpos<150)&&(Ypos>10 && Ypos<220))if(1==(button&1)){
	    delay(200);
	   setcolor(4);
	     sound(200);
	     outtextxy(250,150,"Wrong Attempt!!");
	     count++;
	      gotoxy(18,1);
	   printf("%d",count);
	     nosound();
	     if(mod=='h' || mod=='H')if(count>5)lost(count);
	      if(mod=='m' || mod=='M')if(count>8)lost(count);
	     if(mod=='e' || mod=='E')if(count>11)lost(count);
	 }

  }
  rectangle(180,195,450,210);
  popup(180,195,450,210);
  showmouse();





//////  16th move...////////



	 x=10,x1=130,y=190,y1=200;
while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     setcolor(WHITE);
    outtextxy(180,200,"TRY next MOVE");
 if((Xpos>x && Xpos<x1)&& (Ypos>y && Ypos<y1))if(1==(button&1)){
 popup(180,195,450,210);
 setcolor(WHITE);
 outtextxy(180,200,"Now click on the moveable place");
    x=getmaxx()/2-20-62,x1=getmaxx()/2-20+62,y=390,y1=400;
  break;
 }
  }
  while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     if((Xpos>x && Xpos<x1)&&(Ypos>y && Ypos<y1))if(1==(button&1)){
	  rectangle(x,y,x1,y1);
	  hidemouse();
	 // sound(1);
	  color(x,y,x1,y1,4);

	    x=10,x1=130,y=190,y1=200;
	  erase(x,y,x1,y1,2);
	   erase(240,140,370,160,2);
	   linedraw(70,70,70,200,13);
	  linedraw(540,70,540,200,13);
	  linedraw(getmaxx()/2-20,250,getmaxx()/2-20,400,13);

	  break;
	 }


	  ////wrong attempt around temp

 if((Xpos>getmaxx()-200 && Xpos<getmaxx())&&(Ypos>10 && Ypos<230))if(1==(button&1)){
	     delay(200);
	     setcolor(4);
	     sound(200);
	     outtextxy(250,150,"Wrong Attempt!!");
	     count++;
	      gotoxy(18,1);
	 printf("%d",count);
	     nosound();
	     if(mod=='h' || mod=='H')if(count>5)lost(count);
	      if(mod=='m' || mod=='M')if(count>8)lost(count);
	     if(mod=='e' || mod=='E')if(count>11)lost(count);
	 }


  }
  rectangle(180,195,450,210);
  popup(180,195,450,210);
  showmouse();






//////  17th move...////////



   x=540-22,x1=540+22,y=160,y1=170;
while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     setcolor(WHITE);
    outtextxy(180,200,"TRY next MOVE");
 if((Xpos>x && Xpos<x1)&& (Ypos>y && Ypos<y1))if(1==(button&1)){
 popup(180,195,450,210);
 setcolor(WHITE);
 outtextxy(180,200,"Now click on the moveable place");
     x=50,x1=95,y=190,y1=200;
  break;
 }
  }
  while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     if((Xpos>x && Xpos<x1)&&(Ypos>y && Ypos<y1))if(1==(button&1)){
	  rectangle(x,y,x1,y1);
	  hidemouse();
	 // sound(1);
	  color(x,y,x1,y1,8);

	     x=540-22,x1=540+22,y=160,y1=170;
	  erase(x,y,x1,y1,2);
	   erase(240,140,370,160,2);
	   linedraw(70,70,70,200,13);
	  linedraw(540,70,540,200,13);
	  linedraw(getmaxx()/2-20,250,getmaxx()/2-20,400,13);

	  break;
	 }


 ///wrong attempt around destination

	  if((Xpos>getmaxx()/2-82 && Xpos<getmaxx()/2-20+62)&&(Ypos>300 && Ypos<400))if(1==(button&1)){
	     delay(200);
	     setcolor(4);
	     sound(200);
	     outtextxy(250,150,"Wrong Attempt!!");
	     count++;
	      gotoxy(18,1);
	    printf("%d",count);
	     nosound();
	     if(mod=='h' || mod=='H')if(count>5)lost(count);
	      if(mod=='m' || mod=='M')if(count>8)lost(count);
	     if(mod=='e' || mod=='E')if(count>11)lost(count);
	  }


  }
  rectangle(180,195,450,210);
  popup(180,195,450,210);
  showmouse();



//////  18th move...////////



   x=540-35,x1=540+35,y=170,y1=180;
while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     setcolor(WHITE);
    outtextxy(180,200,"TRY next MOVE");
 if((Xpos>x && Xpos<x1)&& (Ypos>y && Ypos<y1))if(1==(button&1)){
 popup(180,195,450,210);
 setcolor(WHITE);
 outtextxy(180,200,"Now click on the moveable place");
      x=getmaxx()/2-20-32,x1=getmaxx()/2-20+32,y=380,y1=390;
  break;
 }
  }
  while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     if((Xpos>x && Xpos<x1)&&(Ypos>y && Ypos<y1))if(1==(button&1)){
	  rectangle(x,y,x1,y1);
	  hidemouse();
	 // sound(1);
	  color(x,y,x1,y1,14);

	   x=540-35,x1=540+35,y=170,y1=180;
	  erase(x,y,x1,y1,2);
	   erase(240,140,370,160,2);
	   linedraw(70,70,70,200,13);
	  linedraw(540,70,540,200,13);
	  linedraw(getmaxx()/2-20,250,getmaxx()/2-20,400,13);

	  break;
	 }

	  ///Wrong attempt around Source

	 if((Xpos>10 && Xpos<150)&&(Ypos>10 && Ypos<220))if(1==(button&1)){
	   delay(200);
	   setcolor(4);
	     sound(200);
	     outtextxy(250,150,"Wrong Attempt!!");
	     count++;
	      gotoxy(18,1);
	    printf("%d",count);
	     nosound();
	     if(mod=='h' || mod=='H')if(count>5)lost(count);
	      if(mod=='m' || mod=='M')if(count>8)lost(count);
	     if(mod=='e' || mod=='E')if(count>11)lost(count);
	 }

  }
  rectangle(180,195,450,210);
  popup(180,195,450,210);
  showmouse();





//////  19th move...////////



   x=50,x1=95,y=190,y1=200;
while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     setcolor(WHITE);
    outtextxy(180,200,"TRY next MOVE");
 if((Xpos>x && Xpos<x1)&& (Ypos>y && Ypos<y1))if(1==(button&1)){
 popup(180,195,450,210);
 setcolor(WHITE);
 outtextxy(180,200,"Now click on the moveable place");
   x=getmaxx()/2-20-22,x1=getmaxx()/2-20+22,y=370,y1=380;
  break;
 }
  }
  while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     if((Xpos>x && Xpos<x1)&&(Ypos>y && Ypos<y1))if(1==(button&1)){
	  rectangle(x,y,x1,y1);
	  hidemouse();
	 // sound(1);
	  color(x,y,x1,y1,8);

	      x=50,x1=95,y=190,y1=200;
	  erase(x,y,x1,y1,2);
	   erase(240,140,370,160,2);
	   linedraw(70,70,70,200,13);
	  linedraw(540,70,540,200,13);
	  linedraw(getmaxx()/2-20,250,getmaxx()/2-20,400,13);

	  break;
	 }


	  ////wrong attempt around temp

 if((Xpos>getmaxx()-200 && Xpos<getmaxx())&&(Ypos>10 && Ypos<230))if(1==(button&1)){
	     delay(200);
	     setcolor(4);
	     sound(200);
	     outtextxy(250,150,"Wrong Attempt!!");
	     count++;
	      gotoxy(18,1);
	   printf("%d",count);
	     nosound();
	     if(mod=='h' || mod=='H')if(count>5)lost(count);
	      if(mod=='m' || mod=='M')if(count>8)lost(count);
	     if(mod=='e' || mod=='E')if(count>11)lost(count);
	 }


  }
  rectangle(180,195,450,210);
  popup(180,195,450,210);
  showmouse();





//////  20th move...////////



   x=540-45,x1=540+45,y=180,y1=190;
while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     setcolor(WHITE);
    outtextxy(180,200,"TRY next MOVE");
 if((Xpos>x && Xpos<x1)&& (Ypos>y && Ypos<y1))if(1==(button&1)){
 popup(180,195,450,210);
 setcolor(WHITE);
 outtextxy(180,200,"Now click on the moveable place");
    x=30,x1=115,y=190,y1=200;
  break;
 }
  }
  while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     if((Xpos>x && Xpos<x1)&&(Ypos>y && Ypos<y1))if(1==(button&1)){
	  rectangle(x,y,x1,y1);
	  hidemouse();
	 // sound(1);
	  color(x,y,x1,y1,1);

	      x=540-45,x1=540+45,y=180,y1=190;
	  erase(x,y,x1,y1,2);
	   erase(240,140,370,160,2);
	   linedraw(70,70,70,200,13);
	  linedraw(540,70,540,200,13);
	  linedraw(getmaxx()/2-20,250,getmaxx()/2-20,400,13);

	  break;
	 }


 ///wrong attempt around destination

	  if((Xpos>getmaxx()/2-82 && Xpos<getmaxx()/2-20+62)&&(Ypos>300 && Ypos<400))if(1==(button&1)){
	     delay(200);
	     setcolor(4);
	     sound(200);
	     outtextxy(250,150,"Wrong Attempt!!");
	     count++;
	      gotoxy(18,1);
	   printf("%d",count);
	     nosound();
	     if(mod=='h' || mod=='H')if(count>5)lost(count);
	      if(mod=='m' || mod=='M')if(count>8)lost(count);
	     if(mod=='e' || mod=='E')if(count>11)lost(count);

	  }


  }
  rectangle(180,195,450,210);
  popup(180,195,450,210);
  showmouse();








//////  21st move...////////



    x=getmaxx()/2-20-22,x1=getmaxx()/2-20+22,y=370,y1=380;
while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     setcolor(WHITE);
    outtextxy(180,200,"TRY next MOVE");
 if((Xpos>x && Xpos<x1)&& (Ypos>y && Ypos<y1))if(1==(button&1)){
 popup(180,195,450,210);
 setcolor(WHITE);
 outtextxy(180,200,"Now click on the moveable place");
    x=540-22,x1=540+22,y=180,y1=190;
  break;
 }
  }
  while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     if((Xpos>x && Xpos<x1)&&(Ypos>y && Ypos<y1))if(1==(button&1)){
	  rectangle(x,y,x1,y1);
	  hidemouse();
	 // sound(1);
	  color(x,y,x1,y1,8);

	       x=getmaxx()/2-20-22,x1=getmaxx()/2-20+22,y=370,y1=380;
	  erase(x,y,x1,y1,2);
	   erase(240,140,370,160,2);
	   linedraw(70,70,70,200,13);
	  linedraw(540,70,540,200,13);
	  linedraw(getmaxx()/2-20,250,getmaxx()/2-20,400,13);

	  break;
	 }

	  ///Wrong attempt around Source

	 if((Xpos>10 && Xpos<150)&&(Ypos>10 && Ypos<220))if(1==(button&1)){
	    delay(200);
	   setcolor(4);
	     sound(200);
	     outtextxy(250,150,"Wrong Attempt!!");
	     count++;
	      gotoxy(18,1);
	   printf("%d",count);
	     nosound();
	     if(mod=='h' || mod=='H')if(count>5)lost(count);
	      if(mod=='m' || mod=='M')if(count>8)lost(count);
	     if(mod=='e' || mod=='E')if(count>11)lost(count);
	 }

  }
  rectangle(180,195,450,210);
  popup(180,195,450,210);
  showmouse();





//////  22nd move...////////



    x=getmaxx()/2-20-35,x1=getmaxx()/2-20+35,y=380,y1=390;
while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     setcolor(WHITE);
    outtextxy(180,200,"TRY next MOVE");
 if((Xpos>x && Xpos<x1)&& (Ypos>y && Ypos<y1))if(1==(button&1)){
 popup(180,195,450,210);
 setcolor(WHITE);
 outtextxy(180,200,"Now click on the moveable place");
    x=40,x1=105,y=180,y1=190;
  break;
 }
  }
  while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     if((Xpos>x && Xpos<x1)&&(Ypos>y && Ypos<y1))if(1==(button&1)){
	  rectangle(x,y,x1,y1);
	  hidemouse();
	 // sound(1);
	  color(x,y,x1,y1,14);

	       x=getmaxx()/2-20-35,x1=getmaxx()/2-20+35,y=380,y1=390;
	  erase(x,y,x1,y1,2);
	   erase(240,140,370,160,2);
	   linedraw(70,70,70,200,13);
	  linedraw(540,70,540,200,13);
	  linedraw(getmaxx()/2-20,250,getmaxx()/2-20,400,13);

	  break;
	 }


	  ////wrong attempt around temp

 if((Xpos>getmaxx()-200 && Xpos<getmaxx())&&(Ypos>10 && Ypos<230))if(1==(button&1)){
	     delay(200);
	     setcolor(4);
	     sound(200);
	     outtextxy(250,150,"Wrong Attempt!!");
	     count++;
	      gotoxy(18,1);
	    printf("%d",count);
	     nosound();
	     if(mod=='h' || mod=='H')if(count>5)lost(count);
	      if(mod=='m' || mod=='M')if(count>8)lost(count);
	     if(mod=='e' || mod=='E')if(count>11)lost(count);
	 }


  }
  rectangle(180,195,450,210);
  popup(180,195,450,210);
  showmouse();






//////  23rd move...////////



    x=540-22,x1=540+22,y=180,y1=190;
while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     setcolor(WHITE);
    outtextxy(180,200,"TRY next MOVE");
 if((Xpos>x && Xpos<x1)&& (Ypos>y && Ypos<y1))if(1==(button&1)){
 popup(180,195,450,210);
 setcolor(WHITE);
 outtextxy(180,200,"Now click on the moveable place");
    x=50,x1=95,y=170,y1=180;
  break;
 }
  }
  while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     if((Xpos>x && Xpos<x1)&&(Ypos>y && Ypos<y1))if(1==(button&1)){
	  rectangle(x,y,x1,y1);
	  hidemouse();
	 // sound(1);
	  color(x,y,x1,y1,8);

		x=540-22,x1=540+22,y=180,y1=190;
	  erase(x,y,x1,y1,2);
	   erase(240,140,370,160,2);
	   linedraw(70,70,70,200,13);
	  linedraw(540,70,540,200,13);
	  linedraw(getmaxx()/2-20,250,getmaxx()/2-20,400,13);

	  break;
	 }


 ///wrong attempt around destination

	  if((Xpos>getmaxx()/2-82 && Xpos<getmaxx()/2-20+62)&&(Ypos>300 && Ypos<400))if(1==(button&1)){
	     delay(200);
	     setcolor(4);
	     sound(200);
	     outtextxy(250,150,"Wrong Attempt!!");
	     count++;
	      gotoxy(18,1);
	   printf("%d",count);
	     nosound();
	     if(mod=='h' || mod=='H')if(count>5)lost(count);
	      if(mod=='m' || mod=='M')if(count>8)lost(count);
	     if(mod=='e' || mod=='E')if(count>11)lost(count);

	  }


  }
  rectangle(180,195,450,210);
  popup(180,195,450,210);
  showmouse();






//////  24th move...////////



    x=540-60,x1=540+60,y=190,y1=200;
while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     setcolor(WHITE);
    outtextxy(180,200,"TRY next MOVE");
 if((Xpos>x && Xpos<x1)&& (Ypos>y && Ypos<y1))if(1==(button&1)){
 popup(180,195,450,210);
 setcolor(WHITE);
 outtextxy(180,200,"Now click on the moveable place");
  x=getmaxx()/2-20-55,x1=getmaxx()/2-20+55,y=380,y1=390;
  break;
 }
  }
  while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     if((Xpos>x && Xpos<x1)&&(Ypos>y && Ypos<y1))if(1==(button&1)){
	  rectangle(x,y,x1,y1);
	  hidemouse();
	 // sound(1);
	  color(x,y,x1,y1,15);

		 x=540-60,x1=540+60,y=190,y1=200;
	  erase(x,y,x1,y1,2);
	   erase(240,140,370,160,2);
	   linedraw(70,70,70,200,13);
	  linedraw(540,70,540,200,13);
	  linedraw(getmaxx()/2-20,250,getmaxx()/2-20,400,13);

	  break;
	 }

	  ///Wrong attempt around Source

	 if((Xpos>10 && Xpos<150)&&(Ypos>10 && Ypos<220))if(1==(button&1)){
	   delay(200);
	   setcolor(4);
	     sound(200);
	     outtextxy(250,150,"Wrong Attempt!!");
	     count++;
	      gotoxy(18,1);
	    printf("%d",count);
	     nosound();
	     if(mod=='h' || mod=='H')if(count>5)lost(count);
	      if(mod=='m' || mod=='M')if(count>8)lost(count);
	     if(mod=='e' || mod=='E')if(count>11)lost(count);
	 }

  }
  rectangle(180,195,450,210);
  popup(180,195,450,210);
  showmouse();






//////  25th move...////////



     x=50,x1=95,y=170,y1=180;
while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     setcolor(WHITE);
    outtextxy(180,200,"TRY next MOVE");
 if((Xpos>x && Xpos<x1)&& (Ypos>y && Ypos<y1))if(1==(button&1)){
 popup(180,195,450,210);
 setcolor(WHITE);
 outtextxy(180,200,"Now click on the moveable place");
  x=getmaxx()/2-20-25,x1=getmaxx()/2-20+25,y=370,y1=380;
  break;
 }
  }
  while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     if((Xpos>x && Xpos<x1)&&(Ypos>y && Ypos<y1))if(1==(button&1)){
	  rectangle(x,y,x1,y1);
	  hidemouse();
	 // sound(1);
	  color(x,y,x1,y1,8);

	   x=50,x1=95,y=170,y1=180;
	  erase(x,y,x1,y1,2);
	   erase(240,140,370,160,2);
	   linedraw(70,70,70,200,13);
	  linedraw(540,70,540,200,13);
	  linedraw(getmaxx()/2-20,250,getmaxx()/2-20,400,13);

	  break;
	 }


	  ////wrong attempt around temp

 if((Xpos>getmaxx()-200 && Xpos<getmaxx())&&(Ypos>10 && Ypos<230))if(1==(button&1)){
	     delay(200);
	     setcolor(4);
	     sound(200);
	     outtextxy(250,150,"Wrong Attempt!!");
	     count++;
	      gotoxy(18,1);
	    printf("%d",count);
	     nosound();
	     if(mod=='h' || mod=='H')if(count>5)lost(count);
	      if(mod=='m' || mod=='M')if(count>8)lost(count);
	     if(mod=='e' || mod=='E')if(count>11)lost(count);
	 }


  }
  rectangle(180,195,450,210);
  popup(180,195,450,210);
  showmouse();




//////  26th move...////////



      x=40,x1=105,y=180,y1=190;
while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     setcolor(WHITE);
    outtextxy(180,200,"TRY next MOVE");
 if((Xpos>x && Xpos<x1)&& (Ypos>y && Ypos<y1))if(1==(button&1)){
 popup(180,195,450,210);
 setcolor(WHITE);
 outtextxy(180,200,"Now click on the moveable place");
   x=540-35,x1=540+35,y=190,y1=200;
  break;
 }
  }
  while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     if((Xpos>x && Xpos<x1)&&(Ypos>y && Ypos<y1))if(1==(button&1)){
	  rectangle(x,y,x1,y1);
	  hidemouse();
	 // sound(1);
	  color(x,y,x1,y1,14);

	    x=40,x1=105,y=180,y1=190;
	  erase(x,y,x1,y1,2);
	   erase(240,140,370,160,2);
	   linedraw(70,70,70,200,13);
	  linedraw(540,70,540,200,13);
	  linedraw(getmaxx()/2-20,250,getmaxx()/2-20,400,13);

	  break;
	 }


 ///wrong attempt around destination

	  if((Xpos>getmaxx()/2-82 && Xpos<getmaxx()/2-20+62)&&(Ypos>300 && Ypos<400))if(1==(button&1)){
	     delay(200);
	     setcolor(4);
	     sound(200);
	     outtextxy(250,150,"Wrong Attempt!!");
	     count++;
	      gotoxy(18,1);
	    printf("%d",count);
	     nosound();
	     if(mod=='h' || mod=='H')if(count>5)lost(count);
	      if(mod=='m' || mod=='M')if(count>8)lost(count);
	     if(mod=='e' || mod=='E')if(count>11)lost(count);

	  }


  }
  rectangle(180,195,450,210);
  popup(180,195,450,210);
  showmouse();




//////  27th move...////////



      x=getmaxx()/2-20-25,x1=getmaxx()/2-20+25,y=370,y1=380;
while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     setcolor(WHITE);
    outtextxy(180,200,"TRY next MOVE");
 if((Xpos>x && Xpos<x1)&& (Ypos>y && Ypos<y1))if(1==(button&1)){
 popup(180,195,450,210);
 setcolor(WHITE);
 outtextxy(180,200,"Now click on the moveable place");
   x=540-22,x1=540+22,y=180,y1=190;
  break;
 }
  }
  while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     if((Xpos>x && Xpos<x1)&&(Ypos>y && Ypos<y1))if(1==(button&1)){
	  rectangle(x,y,x1,y1);
	  hidemouse();
	 // sound(1);
	  color(x,y,x1,y1,8);

	    x=getmaxx()/2-20-25,x1=getmaxx()/2-20+25,y=370,y1=380;
	  erase(x,y,x1,y1,2);
	   erase(240,140,370,160,2);
	   linedraw(70,70,70,200,13);
	  linedraw(540,70,540,200,13);
	  linedraw(getmaxx()/2-20,250,getmaxx()/2-20,400,13);

	  break;
	 }

	  ///Wrong attempt around Source

	 if((Xpos>10 && Xpos<150)&&(Ypos>10 && Ypos<220))if(1==(button&1)){
	     delay(200);
	   setcolor(4);
	     sound(200);
	     outtextxy(250,150,"Wrong Attempt!!");
	     count++;
	      gotoxy(18,1);
	    printf("%d",count);
	     nosound();
	     if(mod=='h' || mod=='H')if(count>5)lost(count);
	      if(mod=='m' || mod=='M')if(count>8)lost(count);
	     if(mod=='e' || mod=='E')if(count>11)lost(count);
	 }

  }
  rectangle(180,195,450,210);
  popup(180,195,450,210);
  showmouse();






//////  28th move...////////



      x=30,x1=115,y=190,y1=200;
while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     setcolor(WHITE);
    outtextxy(180,200,"TRY next MOVE");
 if((Xpos>x && Xpos<x1)&& (Ypos>y && Ypos<y1))if(1==(button&1)){
 popup(180,195,450,210);
 setcolor(WHITE);
 outtextxy(180,200,"Now click on the moveable place");
    x=getmaxx()/2-20-45,x1=getmaxx()/2-20+45,y=370,y1=380;
  break;
 }
  }
  while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     if((Xpos>x && Xpos<x1)&&(Ypos>y && Ypos<y1))if(1==(button&1)){
	  rectangle(x,y,x1,y1);
	  hidemouse();
	 // sound(1);
	  color(x,y,x1,y1,1);
	     x=30,x1=115,y=190,y1=200;
	  erase(x,y,x1,y1,2);
	   erase(240,140,370,160,2);
	   linedraw(70,70,70,200,13);
	  linedraw(540,70,540,200,13);
	  linedraw(getmaxx()/2-20,250,getmaxx()/2-20,400,13);

	  break;
	 }


	  ////wrong attempt around temp

 if((Xpos>getmaxx()-200 && Xpos<getmaxx())&&(Ypos>10 && Ypos<230))if(1==(button&1)){
	     delay(200);
	     setcolor(4);
	     sound(200);
	     outtextxy(250,150,"Wrong Attempt!!");
	     count++;
	      gotoxy(18,1);
	  printf("%d",count);
	     nosound();
	     if(mod=='h' || mod=='H')if(count>5)lost(count);
	      if(mod=='m' || mod=='M')if(count>8)lost(count);
	     if(mod=='e' || mod=='E')if(count>11)lost(count);
	 }


  }
  rectangle(180,195,450,210);
  popup(180,195,450,210);
  showmouse();








//////  29th move...////////




       x=540-22,x1=540+22,y=180,y1=190;
while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     setcolor(WHITE);
    outtextxy(180,200,"TRY next MOVE");
 if((Xpos>x && Xpos<x1)&& (Ypos>y && Ypos<y1))if(1==(button&1)){
 popup(180,195,450,210);
 setcolor(WHITE);
 outtextxy(180,200,"Now click on the moveable place");
    x=50,x1=95,y=190,y1=200;
  break;
 }
  }
  while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     if((Xpos>x && Xpos<x1)&&(Ypos>y && Ypos<y1))if(1==(button&1)){
	  rectangle(x,y,x1,y1);
	  hidemouse();
	 // sound(1);
	  color(x,y,x1,y1,8);

	     x=540-22,x1=540+22,y=180,y1=190;
	  erase(x,y,x1,y1,2);
	   erase(240,140,370,160,2);
	   linedraw(70,70,70,200,13);
	  linedraw(540,70,540,200,13);
	  linedraw(getmaxx()/2-20,250,getmaxx()/2-20,400,13);

	  break;
	 }


 ///wrong attempt around destination

	  if((Xpos>getmaxx()/2-82 && Xpos<getmaxx()/2-20+62)&&(Ypos>300 && Ypos<400))if(1==(button&1)){
	     delay(200);
	     setcolor(4);
	     sound(200);
	     outtextxy(250,150,"Wrong Attempt!!");
	     count++;
	      gotoxy(18,1);
	 printf("%d",count);
	     nosound();
	     if(mod=='h' || mod=='H')if(count>5)lost(count);
	      if(mod=='m' || mod=='M')if(count>8)lost(count);
	     if(mod=='e' || mod=='E')if(count>11)lost(count);

	  }


  }
  rectangle(180,195,450,210);
  popup(180,195,450,210);
  showmouse();




//////  30th move...////////




       x=540-35,x1=540+35,y=190,y1=200;
while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     setcolor(WHITE);
    outtextxy(180,200,"TRY next MOVE");
 if((Xpos>x && Xpos<x1)&& (Ypos>y && Ypos<y1))if(1==(button&1)){
 popup(180,195,450,210);
 setcolor(WHITE);
 outtextxy(180,200,"Now click on the moveable place");
     x=getmaxx()/2-20-35,x1=getmaxx()/2-20+35,y=360,y1=370;
  break;
 }
  }
  while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     if((Xpos>x && Xpos<x1)&&(Ypos>y && Ypos<y1))if(1==(button&1)){
	  rectangle(x,y,x1,y1);
	  hidemouse();
	 // sound(1);
	  color(x,y,x1,y1,14);

	      x=540-35,x1=540+35,y=190,y1=200;
	  erase(x,y,x1,y1,2);
	   erase(240,140,370,160,2);
	   linedraw(70,70,70,200,13);
	  linedraw(540,70,540,200,13);
	  linedraw(getmaxx()/2-20,250,getmaxx()/2-20,400,13);

	  break;
	 }

	  ///Wrong attempt around Source

	 if((Xpos>10 && Xpos<150)&&(Ypos>10 && Ypos<220))if(1==(button&1)){
	   delay(200);
	   setcolor(4);
	     sound(200);
	     outtextxy(250,150,"Wrong Attempt!!");
	     count++;
	      gotoxy(18,1);
	   printf("%d",count);
	     nosound();
	     if(mod=='h' || mod=='H')if(count>5)lost(count);
	      if(mod=='m' || mod=='M')if(count>8)lost(count);
	     if(mod=='e' || mod=='E')if(count>11)lost(count);
	 }

  }
  rectangle(180,195,450,210);
  popup(180,195,450,210);
  showmouse();








//////  31st/FINAL move...////////




       x=50,x1=95,y=190,y1=200;
while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     setcolor(WHITE);
    outtextxy(180,200,"TRY next MOVE");
 if((Xpos>x && Xpos<x1)&& (Ypos>y && Ypos<y1))if(1==(button&1)){
 popup(180,195,450,210);
 setcolor(WHITE);
 outtextxy(180,200,"Now click on the moveable place");
  x=getmaxx()/2-20-25,x1=getmaxx()/2-20+25,y=350,y1=360;
  break;
 }
  }
  while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     if((Xpos>x && Xpos<x1)&&(Ypos>y && Ypos<y1))if(1==(button&1)){
	  rectangle(x,y,x1,y1);
	  hidemouse();
	 // sound(1);
	  color(x,y,x1,y1,8);

	      x=50,x1=95,y=190,y1=200;
	  erase(x,y,x1,y1,2);
	   erase(240,140,370,160,2);
	   linedraw(70,70,70,200,13);
	  linedraw(540,70,540,200,13);
	  linedraw(getmaxx()/2-20,250,getmaxx()/2-20,400,13);

	  break;
	 }


	  ////wrong attempt around temp

 if((Xpos>getmaxx()-200 && Xpos<getmaxx())&&(Ypos>10 && Ypos<230))if(1==(button&1)){
	     delay(200);
	     setcolor(4);
	     sound(200);
	     outtextxy(250,150,"Wrong Attempt!!");
	     count++;
	      gotoxy(18,1);
	  printf("%d",count);
	     nosound();
	     if(mod=='h' || mod=='H')if(count>5)lost(count);
	      if(mod=='m' || mod=='M')if(count>8)lost(count);
	     if(mod=='e' || mod=='E')if(count>11)lost(count);
	 }


  }

  rectangle(180,195,450,210);
  popup(180,195,450,210);
  setcolor(15);
  outtextxy(180,200,"congratulations!!!");
  outtextxy(180,210,"YOU WIN!!");

  if(count==0)perfectwin(count);
  if(count<=5)win(count);
  if(mod=='m' || mod=='M')if(count<=8)win(count);
  if(mod=='e' || mod=='E')if(count<=11)win(count);

   if(kbhit());
  char ch=getch();
  if(ch==27)exitpage();
  if(ch==8){
   cleardevice();
   graphicsdriver();
   discselection();
  }
 getch();
 cleardevice();
// closegraph();
 return 0;
}







///wrong attemps code rough/////


/*
 ///Wrong attempt around Source

	 if((Xpos>10 && Xpos<150)&&(Ypos>10 && Ypos<220))if(1==(button&1)){
	   setcolor(4);
	     sound(200);
	     outtextxy(250,150,"Wrong Attempt!!");
	     count++;
	     nosound();
	 }



	  ////wrong attempt around temp

 if((Xpos>getmaxx()-200 && Xpos<getmaxx())&&(Ypos>10 && Ypos<230))if(1==(button&1)){
	     setcolor(4);
	     sound(200);
	     outtextxy(250,150,"Wrong Attempt!!");
	     count++;
	     nosound();
	 // break;
	 }



 ///wrong attempt around destination

	  if((Xpos>getmaxx()/2-82 && Xpos<getmaxx()/2-20+62)&&(Ypos>300 && Ypos<400))if(1==(button&1)){
	     setcolor(4);
	     sound(200);
	     outtextxy(250,150,"Wrong Attempt!!");
	     count++;
	     nosound();

	  }



	   erase(240,140,370,160,2);

*/







 ////page for 6 disc////


 int calldisc6(){
 clrscr();
 cleardevice();
graphicsdriver();
showmouse();
 settextstyle(SANS_SERIF_FONT,HORIZ_DIR,3);
 setcolor(15);
 outtextxy(190,0,"Draw 6 disc PUZZLE");
 setcolor(13);
 outtextxy(191,1,"Draw 6 disc PUZZLE");
 setcolor(1);
 outtextxy(190,50,"Not Available Now");
 outtextxy(190,100,"Press any Key");
 settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
  line(70,70,70,200);
  setbkcolor(2);
  fillellipse(0,201,201,1);
  setcolor(1);
  outtextxy(30,210,"SOURCE");
  setcolor(4);
	  rectangle(10,190,130,200);
  int x=11,y=191,x1=130,y1=191;///x1 will be constant
  while(y1!=200){
   line(x,y,x1,y1);
   y++,y1++;
   }
   setcolor(15);
	  rectangle(20,180,125,190);
  x=21,y=181,x1=125,y1=181;
  while(y1!=190){
  line(x,y,x1,y1);
  y++,y1++;
  }
  setcolor(1);
	 rectangle(30,170,115,180);
  x=31,y=171,x1=115,y1=171;
  while(y1!=180){
  line(x,y,x1,y1);
  y++,y1++;
  }
  setcolor(14);
	 rectangle(40,160,105,170);
  x=41,y=161,x1=105,y1=161;
  while(y1!=170){
  line(x,y,x1,y1);
  y++,y1++;
  }
  setcolor(8);
	 rectangle(50,150,95,160);
  x=51,y=151,x1=95,y1=151;
  while(y1!=160){
  line(x,y,x1,y1);
  y++,y1++;
  }
  setcolor(9);
	 rectangle(55,140,90,150);
  x=56,y=141,x1=90,y1=141;
  while(y1!= 150){
  line(x,y,x1,y1);
  y++,y1++;
  }
  line(540,70,540,200);
  fillellipse(600,201,201,1);
  setcolor(14);
  outtextxy(550,212,"TEMPORARY");
  line(getmaxx()/2-20,250,getmaxx()/2-20,400);
  fillellipse(300,400,200,1);
  setcolor(15);
  outtextxy(getmaxx()/2,410,"DESTINATION");

/*

  /////1st move////////



       x=55,x1=90,y=140,y1=150;
while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     setcolor(WHITE);
    outtextxy(180,200,"SELECT BOTTOM DISC");
 if((Xpos>x && Xpos<x1)&& (Ypos>y && Ypos<y1))if(1==(button&1)){
 popup(180,195,450,210);
 setcolor(WHITE);
 outtextxy(180,200,"Now click on the moveable place");
   x=540-25,x1=540+25,y=190,y1=200;
  break;
 }
  }
  while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     if((Xpos>x && Xpos<x1)&&(Ypos>y && Ypos<y1))if(1==(button&1)){
	  rectangle(x,y,x1,y1);
	  hidemouse();
	 // sound(1);
	  color(x,y,x1,y1,9);

		x=55,x1=90,y=140,y1=150;
	  erase(x,y,x1,y1,2);
	   erase(240,140,370,160,2);
	   linedraw(70,70,70,200,13);
	  linedraw(540,70,540,200,13);
	  linedraw(getmaxx()/2-20,250,getmaxx()/2-20,400,13);

	  break;
	 }
  }

  rectangle(180,195,450,210);
  popup(180,195,450,210);
  showmouse();




/////2nd move//////



 x=50,x1=95,y=150,y1=160;
while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     setcolor(WHITE);
    outtextxy(180,200,"Try next MOVE");
 if((Xpos>x && Xpos<x1)&& (Ypos>y && Ypos<y1))if(1==(button&1)){
 popup(180,195,450,210);
 setcolor(WHITE);
 outtextxy(180,200,"Now click on the moveable place");
    x=getmaxx()/2-20-35,x1=getmaxx()/2-20+35,y=390,y1=400;
  break;
 }
  }
  while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     if((Xpos>x && Xpos<x1)&&(Ypos>y && Ypos<y1))if(1==(button&1)){
	  rectangle(x,y,x1,y1);
	  hidemouse();
	 // sound(1);
	  color(x,y,x1,y1,8);

	   x=50,x1=95,y=150,y1=160;
	  erase(x,y,x1,y1,2);
	   erase(240,140,370,160,2);
	   linedraw(70,70,70,200,13);
	  linedraw(540,70,540,200,13);
	  linedraw(getmaxx()/2-20,250,getmaxx()/2-20,400,13);

	  break;
	 }
  }

  rectangle(180,195,450,210);
  popup(180,195,450,210);
  showmouse();



/////3rd move//////



  x=540-25,x1=540+25,y=190,y1=200;
while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     setcolor(WHITE);
    outtextxy(180,200,"Try next MOVE");
 if((Xpos>x && Xpos<x1)&& (Ypos>y && Ypos<y1))if(1==(button&1)){
 popup(180,195,450,210);
 setcolor(WHITE);
 outtextxy(180,200,"Now click on the moveable place");
    x=getmaxx()/2-20-25,x1=getmaxx()/2-20+25,y=380,y1=390;
  break;
 }
  }
  while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     if((Xpos>x && Xpos<x1)&&(Ypos>y && Ypos<y1))if(1==(button&1)){
	  rectangle(x,y,x1,y1);
	  hidemouse();
	 // sound(1);
	  color(x,y,x1,y1,9);

	    x=540-25,x1=540+25,y=190,y1=200;
	  erase(x,y,x1,y1,2);
	   erase(240,140,370,160,2);
	   linedraw(70,70,70,200,13);
	  linedraw(540,70,540,200,13);
	  linedraw(getmaxx()/2-20,250,getmaxx()/2-20,400,13);

	  break;
	 }
  }

  rectangle(180,195,450,210);
  popup(180,195,450,210);
  showmouse();




/////4th move//////



  x=40,x1=105,y=160,y1=170;
while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     setcolor(WHITE);
    outtextxy(180,200,"Try next MOVE");
 if((Xpos>x && Xpos<x1)&& (Ypos>y && Ypos<y1))if(1==(button&1)){
 popup(180,195,450,210);
 setcolor(WHITE);
 outtextxy(180,200,"Now click on the moveable place");
     x=540-45,x1=540+45,y=190,y1=200;
  break;
 }
  }
  while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     if((Xpos>x && Xpos<x1)&&(Ypos>y && Ypos<y1))if(1==(button&1)){
	  rectangle(x,y,x1,y1);
	  hidemouse();
	 // sound(1);
	  color(x,y,x1,y1,14);

	     x=40,x1=105,y=160,y1=170;
	  erase(x,y,x1,y1,2);
	   erase(240,140,370,160,2);
	   linedraw(70,70,70,200,13);
	  linedraw(540,70,540,200,13);
	  linedraw(getmaxx()/2-20,250,getmaxx()/2-20,400,13);

	  break;
	 }
  }

  rectangle(180,195,450,210);
  popup(180,195,450,210);
  showmouse();






/////5th move//////



      x=getmaxx()/2-20-25,x1=getmaxx()/2-20+25,y=380,y1=390;
while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     setcolor(WHITE);
    outtextxy(180,200,"Try next MOVE");
 if((Xpos>x && Xpos<x1)&& (Ypos>y && Ypos<y1))if(1==(button&1)){
 popup(180,195,450,210);
 setcolor(WHITE);
 outtextxy(180,200,"Now click on the moveable place");
      x=55,x1=90,y=160,y1=170;
  break;
 }
  }
  while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     if((Xpos>x && Xpos<x1)&&(Ypos>y && Ypos<y1))if(1==(button&1)){
	  rectangle(x,y,x1,y1);
	  hidemouse();
	 // sound(1);
	  color(x,y,x1,y1,9);

	       x=getmaxx()/2-20-25,x1=getmaxx()/2-20+25,y=380,y1=390;
	  erase(x,y,x1,y1,2);
	   erase(240,140,370,160,2);
	   linedraw(70,70,70,200,13);
	  linedraw(540,70,540,200,13);
	  linedraw(getmaxx()/2-20,250,getmaxx()/2-20,400,13);

	  break;
	 }
  }

  rectangle(180,195,450,210);
  popup(180,195,450,210);
  showmouse();







/////6th move//////



      x=getmaxx()/2-20-35,x1=getmaxx()/2-20+35,y=390,y1=400;
while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     setcolor(WHITE);
    outtextxy(180,200,"Try next MOVE");
 if((Xpos>x && Xpos<x1)&& (Ypos>y && Ypos<y1))if(1==(button&1)){
 popup(180,195,450,210);
 setcolor(WHITE);
 outtextxy(180,200,"Now click on the moveable place");
	x=540-35,x1=540+35,y=180,y1=190;
  break;
 }
  }
  while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     if((Xpos>x && Xpos<x1)&&(Ypos>y && Ypos<y1))if(1==(button&1)){
	  rectangle(x,y,x1,y1);
	  hidemouse();
	 // sound(1);
	  color(x,y,x1,y1,8);

		 x=getmaxx()/2-20-35,x1=getmaxx()/2-20+35,y=390,y1=400;
	  erase(x,y,x1,y1,2);
	   erase(240,140,370,160,2);
	   linedraw(70,70,70,200,13);
	  linedraw(540,70,540,200,13);
	  linedraw(getmaxx()/2-20,250,getmaxx()/2-20,400,13);

	  break;
	 }
  }

  rectangle(180,195,450,210);
  popup(180,195,450,210);
  showmouse();






/////7th move//////



       x=55,x1=90,y=160,y1=170;
while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     setcolor(WHITE);
    outtextxy(180,200,"Try next MOVE");
 if((Xpos>x && Xpos<x1)&& (Ypos>y && Ypos<y1))if(1==(button&1)){
 popup(180,195,450,210);
 setcolor(WHITE);
 outtextxy(180,200,"Now click on the moveable place");
	x=540-25,x1=540+25,y=170,y1=180;
  break;
 }
  }
  while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     if((Xpos>x && Xpos<x1)&&(Ypos>y && Ypos<y1))if(1==(button&1)){
	  rectangle(x,y,x1,y1);
	  hidemouse();
	 // sound(1);
	  color(x,y,x1,y1,9);

		  x=55,x1=90,y=160,y1=170;
	  erase(x,y,x1,y1,2);
	   erase(240,140,370,160,2);
	   linedraw(70,70,70,200,13);
	  linedraw(540,70,540,200,13);
	  linedraw(getmaxx()/2-20,250,getmaxx()/2-20,400,13);

	  break;
	 }
  }

  rectangle(180,195,450,210);
  popup(180,195,450,210);
  showmouse();






/////8th move//////



       x=30,x1=115,y=170,y1=180;
while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     setcolor(WHITE);
    outtextxy(180,200,"Try next MOVE");
 if((Xpos>x && Xpos<x1)&& (Ypos>y && Ypos<y1))if(1==(button&1)){
 popup(180,195,450,210);
 setcolor(WHITE);
 outtextxy(180,200,"Now click on the moveable place");
      x=getmaxx()/2-20-45,x1=getmaxx()/2-20+45,y=390,y1=400;
  break;
 }
  }
  while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     if((Xpos>x && Xpos<x1)&&(Ypos>y && Ypos<y1))if(1==(button&1)){
	  rectangle(x,y,x1,y1);
	  hidemouse();
	 // sound(1);
	  color(x,y,x1,y1,1);

		     x=30,x1=115,y=170,y1=180;
	  erase(x,y,x1,y1,2);
	   erase(240,140,370,160,2);
	   linedraw(70,70,70,200,13);
	  linedraw(540,70,540,200,13);
	  linedraw(getmaxx()/2-20,250,getmaxx()/2-20,400,13);

	  break;
	 }
  }

  rectangle(180,195,450,210);
  popup(180,195,450,210);
  showmouse();






/////9th move//////



       x=540-25,x1=540+25,y=170,y1=180;
while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     setcolor(WHITE);
    outtextxy(180,200,"Try next MOVE");
 if((Xpos>x && Xpos<x1)&& (Ypos>y && Ypos<y1))if(1==(button&1)){
 popup(180,195,450,210);
 setcolor(WHITE);
 outtextxy(180,200,"Now click on the moveable place");
	  x=getmaxx()/2-20-25,x1=getmaxx()/2-20+25,y=380,y1=390;
  break;
 }
  }
  while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     if((Xpos>x && Xpos<x1)&&(Ypos>y && Ypos<y1))if(1==(button&1)){
	  rectangle(x,y,x1,y1);
	  hidemouse();
	 // sound(1);
	  color(x,y,x1,y1,9);

		     x=540-25,x1=540+25,y=170,y1=180;
	  erase(x,y,x1,y1,2);
	   erase(240,140,370,160,2);
	   linedraw(70,70,70,200,13);
	  linedraw(540,70,540,200,13);
	  linedraw(getmaxx()/2-20,250,getmaxx()/2-20,400,13);

	  break;
	 }
  }

  rectangle(180,195,450,210);
  popup(180,195,450,210);
  showmouse();







/////10th move//////



	x=50,x1=95,y=170,y1=180;
while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     setcolor(WHITE);
    outtextxy(180,200,"Try next MOVE");
 if((Xpos>x && Xpos<x1)&& (Ypos>y && Ypos<y1))if(1==(button&1)){
 popup(180,195,450,210);
 setcolor(WHITE);
 outtextxy(180,200,"Now click on the moveable place");
      x=getmaxx()/2-20-25,x1=getmaxx()/2-20+25,y=380,y1=390;
  break;
 }
  }
  while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     if((Xpos>x && Xpos<x1)&&(Ypos>y && Ypos<y1))if(1==(button&1)){
	  rectangle(x,y,x1,y1);
	  hidemouse();
	 // sound(1);
	  color(x,y,x1,y1,8);

			x=50,x1=95,y=170,y1=180;
	  erase(x,y,x1,y1,2);
	   erase(240,140,370,160,2);
	   linedraw(70,70,70,200,13);
	  linedraw(540,70,540,200,13);
	  linedraw(getmaxx()/2-20,250,getmaxx()/2-20,400,13);

	  break;
	 }
  }

  rectangle(180,195,450,210);
  popup(180,195,450,210);
  showmouse();




/////11th move//////




	 x=getmaxx()/2-20-25,x1=getmaxx()/2-20+25,y=380,y1=390;
while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     setcolor(WHITE);
    outtextxy(180,200,"Try next MOVE");
 if((Xpos>x && Xpos<x1)&& (Ypos>y && Ypos<y1))if(1==(button&1)){
 popup(180,195,450,210);
 setcolor(WHITE);
 outtextxy(180,200,"Now click on the moveable place");
	x=55,x1=90,y=160,y1=170;
  break;
 }
  }
  while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     if((Xpos>x && Xpos<x1)&&(Ypos>y && Ypos<y1))if(1==(button&1)){
	  rectangle(x,y,x1,y1);
	  hidemouse();
	 // sound(1);
	  color(x,y,x1,y1,9);

	    x=getmaxx()/2-20-25,x1=getmaxx()/2-20+25,y=380,y1=390;
	  erase(x,y,x1,y1,2);
	   erase(240,140,370,160,2);
	   linedraw(70,70,70,200,13);
	  linedraw(540,70,540,200,13);
	  linedraw(getmaxx()/2-20,250,getmaxx()/2-20,400,13);

	  break;
	 }
  }

  rectangle(180,195,450,210);
  popup(180,195,450,210);
  showmouse();




/////12th move//////

    // x=540-45,x1=540+45,y=190,y1=200;
     // x=getmaxx()/2-20-40,x1=getmaxx()/2-20+40,y=380,y1=390;
       //	x=55,x1=90,y=160,y1=170;


    x=540-45,x1=540+45,y=190,y1=200;

while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     setcolor(WHITE);
    outtextxy(180,200,"Try next MOVE");
 if((Xpos>x && Xpos<x1)&& (Ypos>y && Ypos<y1))if(1==(button&1)){
 popup(180,195,450,210);
 setcolor(WHITE);
 outtextxy(180,200,"Now click on the moveable place");

	 x=getmaxx()/2-20-40,x1=getmaxx()/2-20+40,y=380,y1=390;
  break;
 }
  }
  while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     if((Xpos>x && Xpos<x1)&&(Ypos>y && Ypos<y1))if(1==(button&1)){
	  rectangle(x,y,x1,y1);
	  hidemouse();
	 // sound(1);
	  color(x,y,x1,y1,14);

	     x=540-45,x1=540+45,y=190,y1=200;
	  erase(x,y,x1,y1,2);
	   erase(240,140,370,160,2);
	   linedraw(70,70,70,200,13);
	  linedraw(540,70,540,200,13);
	  linedraw(getmaxx()/2-20,250,getmaxx()/2-20,400,13);

	  break;
	 }
  }

  rectangle(180,195,450,210);
  popup(180,195,450,210);
  showmouse();






/////13th move//////

    // x=540-45,x1=540+45,y=190,y1=200;
     // x=getmaxx()/2-20-40,x1=getmaxx()/2-20+40,y=380,y1=390;
       //	x=55,x1=90,y=160,y1=170;


    x=55,x1=90,y=160,y1=170;

while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     setcolor(WHITE);
    outtextxy(180,200,"Try next MOVE");
 if((Xpos>x && Xpos<x1)&& (Ypos>y && Ypos<y1))if(1==(button&1)){
 popup(180,195,450,210);
 setcolor(WHITE);
 outtextxy(180,200,"Now click on the moveable place");

	  x=540-25,x1=540+25,y=190,y1=200;
  break;
 }
  }
  while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     if((Xpos>x && Xpos<x1)&&(Ypos>y && Ypos<y1))if(1==(button&1)){
	  rectangle(x,y,x1,y1);
	  hidemouse();
	 // sound(1);
	  color(x,y,x1,y1,9);

	  x=55,x1=90,y=160,y1=170;
	  erase(x,y,x1,y1,2);
	   erase(240,140,370,160,2);
	   linedraw(70,70,70,200,13);
	  linedraw(540,70,540,200,13);
	  linedraw(getmaxx()/2-20,250,getmaxx()/2-20,400,13);

	  break;
	 }
  }

  rectangle(180,195,450,210);
  popup(180,195,450,210);
  showmouse();







/////14th move//////

    // x=540-45,x1=540+45,y=190,y1=200;
     // x=getmaxx()/2-20-40,x1=getmaxx()/2-20+40,y=380,y1=390;
       //	x=55,x1=90,y=160,y1=170;


    x=50,x1=95,y=170,y1=180;

while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     setcolor(WHITE);
    outtextxy(180,200,"Try next MOVE");
 if((Xpos>x && Xpos<x1)&& (Ypos>y && Ypos<y1))if(1==(button&1)){
 popup(180,195,450,210);
 setcolor(WHITE);
 outtextxy(180,200,"Now click on the moveable place");

	   x=getmaxx()/2-20-30,x1=getmaxx()/2-20+30,y=370,y1=380;
  break;
 }
  }
  while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     if((Xpos>x && Xpos<x1)&&(Ypos>y && Ypos<y1))if(1==(button&1)){
	  rectangle(x,y,x1,y1);
	  hidemouse();
	 // sound(1);
	  color(x,y,x1,y1,8);

	   x=50,x1=95,y=170,y1=180;
	  erase(x,y,x1,y1,2);
	   erase(240,140,370,160,2);
	   linedraw(70,70,70,200,13);
	  linedraw(540,70,540,200,13);
	  linedraw(getmaxx()/2-20,250,getmaxx()/2-20,400,13);

	  break;
	 }
  }

  rectangle(180,195,450,210);
  popup(180,195,450,210);
  showmouse();






/////15th move//////

    // x=540-45,x1=540+45,y=190,y1=200;
     // x=getmaxx()/2-20-40,x1=getmaxx()/2-20+40,y=380,y1=390;
       //	x=55,x1=90,y=160,y1=170;


    x=540-25,x1=540+25,y=190,y1=200;

while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     setcolor(WHITE);
    outtextxy(180,200,"Try next MOVE");
 if((Xpos>x && Xpos<x1)&& (Ypos>y && Ypos<y1))if(1==(button&1)){
 popup(180,195,450,210);
 setcolor(WHITE);
 outtextxy(180,200,"Now click on the moveable place");

	   x=getmaxx()/2-20-20,x1=getmaxx()/2-20+20,y=360,y1=370;
  break;
 }
  }
  while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     if((Xpos>x && Xpos<x1)&&(Ypos>y && Ypos<y1))if(1==(button&1)){
	  rectangle(x,y,x1,y1);
	  hidemouse();
	 // sound(1);
	  color(x,y,x1,y1,9);

	   x=540-25,x1=540+25,y=190,y1=200;
	  erase(x,y,x1,y1,2);
	   erase(240,140,370,160,2);
	   linedraw(70,70,70,200,13);
	  linedraw(540,70,540,200,13);
	  linedraw(getmaxx()/2-20,250,getmaxx()/2-20,400,13);

	  break;
	 }
  }

  rectangle(180,195,450,210);
  popup(180,195,450,210);
  showmouse();




/////16th move//////

    // x=540-45,x1=540+45,y=190,y1=200;
     // x=getmaxx()/2-20-40,x1=getmaxx()/2-20+40,y=380,y1=390;
       //	x=55,x1=90,y=160,y1=170;


    x=20,x1=125,y=190,y1=200;

while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     setcolor(WHITE);
    outtextxy(180,200,"Try next MOVE");
 if((Xpos>x && Xpos<x1)&& (Ypos>y && Ypos<y1))if(1==(button&1)){
 popup(180,195,450,210);
 setcolor(WHITE);
 outtextxy(180,200,"Now click on the moveable place");

      x=540-55,x1=540+55,y=190,y1=200;
  break;
 }
  }
  while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     if((Xpos>x && Xpos<x1)&&(Ypos>y && Ypos<y1))if(1==(button&1)){
	  rectangle(x,y,x1,y1);
	  hidemouse();
	 // sound(1);
	  color(x,y,x1,y1,15);

	    x=20,x1=125,y=190,y1=200;
	  erase(x,y,x1,y1,2);
	   erase(240,140,370,160,2);
	   linedraw(70,70,70,200,13);
	  linedraw(540,70,540,200,13);
	  linedraw(getmaxx()/2-20,250,getmaxx()/2-20,400,13);

	  break;
	 }
  }

  rectangle(180,195,450,210);
  popup(180,195,450,210);
  showmouse();





/////17th move//////

    // x=540-45,x1=540+45,y=190,y1=200;
     // x=getmaxx()/2-20-40,x1=getmaxx()/2-20+40,y=380,y1=390;
       //	x=55,x1=90,y=160,y1=170;


     x=getmaxx()/2-20-20,x1=getmaxx()/2-20+20,y=360,y1=370;

while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     setcolor(WHITE);
    outtextxy(180,200,"Try next MOVE");
 if((Xpos>x && Xpos<x1)&& (Ypos>y && Ypos<y1))if(1==(button&1)){
 popup(180,195,450,210);
 setcolor(WHITE);
 outtextxy(180,200,"Now click on the moveable place");

      x=55,x1=90,y=180,y1=190;
  break;
 }
  }
  while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     if((Xpos>x && Xpos<x1)&&(Ypos>y && Ypos<y1))if(1==(button&1)){
	  rectangle(x,y,x1,y1);
	  hidemouse();
	 // sound(1);
	  color(x,y,x1,y1,9);

	     x=getmaxx()/2-20-20,x1=getmaxx()/2-20+20,y=360,y1=370;
	  erase(x,y,x1,y1,2);
	   erase(240,140,370,160,2);
	   linedraw(70,70,70,200,13);
	  linedraw(540,70,540,200,13);
	  linedraw(getmaxx()/2-20,250,getmaxx()/2-20,400,13);

	  break;
	 }
  }

  rectangle(180,195,450,210);
  popup(180,195,450,210);
  showmouse();




/////18th move//////

    // x=540-45,x1=540+45,y=190,y1=200;
     // x=getmaxx()/2-20-40,x1=getmaxx()/2-20+40,y=380,y1=390;
       //	x=55,x1=90,y=160,y1=170;


     x=getmaxx()/2-20-30,x1=getmaxx()/2-20+30,y=370,y1=380;

while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     setcolor(WHITE);
    outtextxy(180,200,"Try next MOVE");
 if((Xpos>x && Xpos<x1)&& (Ypos>y && Ypos<y1))if(1==(button&1)){
 popup(180,195,450,210);
 setcolor(WHITE);
 outtextxy(180,200,"Now click on the moveable place");

       x=540-35,x1=540+35,y=180,y1=190;
  break;
 }
  }
  while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     if((Xpos>x && Xpos<x1)&&(Ypos>y && Ypos<y1))if(1==(button&1)){
	  rectangle(x,y,x1,y1);
	  hidemouse();
	 // sound(1);
	  color(x,y,x1,y1,8);

	       x=getmaxx()/2-20-30,x1=getmaxx()/2-20+30,y=370,y1=380;
	  erase(x,y,x1,y1,2);
	   erase(240,140,370,160,2);
	   linedraw(70,70,70,200,13);
	  linedraw(540,70,540,200,13);
	  linedraw(getmaxx()/2-20,250,getmaxx()/2-20,400,13);

	  break;
	 }
  }

  rectangle(180,195,450,210);
  popup(180,195,450,210);
  showmouse();





/////19th move//////

    // x=540-45,x1=540+45,y=190,y1=200;
     // x=getmaxx()/2-20-40,x1=getmaxx()/2-20+40,y=380,y1=390;
       //	x=55,x1=90,y=160,y1=170;


     x=55,x1=90,y=180,y1=190;

while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     setcolor(WHITE);
    outtextxy(180,200,"Try next MOVE");
 if((Xpos>x && Xpos<x1)&& (Ypos>y && Ypos<y1))if(1==(button&1)){
 popup(180,195,450,210);
 setcolor(WHITE);
 outtextxy(180,200,"Now click on the moveable place");

       x=540-25,x1=540+25,y=170,y1=180;
  break;
 }
  }
  while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     if((Xpos>x && Xpos<x1)&&(Ypos>y && Ypos<y1))if(1==(button&1)){
	  rectangle(x,y,x1,y1);
	  hidemouse();
	 // sound(1);
	  color(x,y,x1,y1,9);

		 x=55,x1=90,y=180,y1=190;
	  erase(x,y,x1,y1,2);
	   erase(240,140,370,160,2);
	   linedraw(70,70,70,200,13);
	  linedraw(540,70,540,200,13);
	  linedraw(getmaxx()/2-20,250,getmaxx()/2-20,400,13);

	  break;
	 }
  }

  rectangle(180,195,450,210);
  popup(180,195,450,210);
  showmouse();




/////20th move//////

    // x=540-45,x1=540+45,y=190,y1=200;
     // x=getmaxx()/2-20-40,x1=getmaxx()/2-20+40,y=380,y1=390;
       //	x=55,x1=90,y=160,y1=170;


     x=getmaxx()/2-20-40,x1=getmaxx()/2-20+40,y=380,y1=390;

while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     setcolor(WHITE);
    outtextxy(180,200,"Try next MOVE");
 if((Xpos>x && Xpos<x1)&& (Ypos>y && Ypos<y1))if(1==(button&1)){
 popup(180,195,450,210);
 setcolor(WHITE);
 outtextxy(180,200,"Now click on the moveable place");

	x=40,x1=105,y=180,y1=190;
  break;
 }
  }
  while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     if((Xpos>x && Xpos<x1)&&(Ypos>y && Ypos<y1))if(1==(button&1)){
	  rectangle(x,y,x1,y1);
	  hidemouse();
	 // sound(1);
	  color(x,y,x1,y1,14);

		  x=getmaxx()/2-20-40,x1=getmaxx()/2-20+40,y=380,y1=390;
	  erase(x,y,x1,y1,2);
	   erase(240,140,370,160,2);
	   linedraw(70,70,70,200,13);
	  linedraw(540,70,540,200,13);
	  linedraw(getmaxx()/2-20,250,getmaxx()/2-20,400,13);

	  break;
	 }
  }

  rectangle(180,195,450,210);
  popup(180,195,450,210);
  showmouse();




/////21st move//////

    // x=540-45,x1=540+45,y=190,y1=200;
     // x=getmaxx()/2-20-40,x1=getmaxx()/2-20+40,y=380,y1=390;
       //	x=55,x1=90,y=160,y1=170;


      x=540-25,x1=540+25,y=170,y1=180;

while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     setcolor(WHITE);
    outtextxy(180,200,"Try next MOVE");
 if((Xpos>x && Xpos<x1)&& (Ypos>y && Ypos<y1))if(1==(button&1)){
 popup(180,195,450,210);
 setcolor(WHITE);
 outtextxy(180,200,"Now click on the moveable place");

	 x=getmaxx()/2-20-20,x1=getmaxx()/2-20+20,y=380,y1=390;
  break;
 }
  }
  while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     if((Xpos>x && Xpos<x1)&&(Ypos>y && Ypos<y1))if(1==(button&1)){
	  rectangle(x,y,x1,y1);
	  hidemouse();
	 // sound(1);
	  color(x,y,x1,y1,9);

		   x=540-25,x1=540+25,y=170,y1=180;
	  erase(x,y,x1,y1,2);
	   erase(240,140,370,160,2);
	   linedraw(70,70,70,200,13);
	  linedraw(540,70,540,200,13);
	  linedraw(getmaxx()/2-20,250,getmaxx()/2-20,400,13);

	  break;
	 }
  }

  rectangle(180,195,450,210);
  popup(180,195,450,210);
  showmouse();




/////22nd move//////

    // x=540-45,x1=540+45,y=190,y1=200;
     // x=getmaxx()/2-20-40,x1=getmaxx()/2-20+40,y=380,y1=390;
       //	x=55,x1=90,y=160,y1=170;


      x=540-35,x1=540+35,y=180,y1=190;

while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     setcolor(WHITE);
    outtextxy(180,200,"Try next MOVE");
 if((Xpos>x && Xpos<x1)&& (Ypos>y && Ypos<y1))if(1==(button&1)){
 popup(180,195,450,210);
 setcolor(WHITE);
 outtextxy(180,200,"Now click on the moveable place");

		x=50,x1=95,y=170,y1=180;
  break;
 }
  }
  while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     if((Xpos>x && Xpos<x1)&&(Ypos>y && Ypos<y1))if(1==(button&1)){
	  rectangle(x,y,x1,y1);
	  hidemouse();
	 // sound(1);
	  color(x,y,x1,y1,8);

		   x=540-35,x1=540+35,y=180,y1=190;
	  erase(x,y,x1,y1,2);
	   erase(240,140,370,160,2);
	   linedraw(70,70,70,200,13);
	  linedraw(540,70,540,200,13);
	  linedraw(getmaxx()/2-20,250,getmaxx()/2-20,400,13);

	  break;
	 }
  }

  rectangle(180,195,450,210);
  popup(180,195,450,210);
  showmouse();



/////23rd move//////

    // x=540-45,x1=540+45,y=190,y1=200;
     // x=getmaxx()/2-20-40,x1=getmaxx()/2-20+40,y=380,y1=390;
       //	x=55,x1=90,y=160,y1=170;


       x=getmaxx()/2-20-40,x1=getmaxx()/2-20+40,y=380,y1=390;

while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     setcolor(WHITE);
    outtextxy(180,200,"Try next MOVE");
 if((Xpos>x && Xpos<x1)&& (Ypos>y && Ypos<y1))if(1==(button&1)){
 popup(180,195,450,210);
 setcolor(WHITE);
 outtextxy(180,200,"Now click on the moveable place");

		x=40,x1=80,y=160,y1=170;
  break;
 }
  }
  while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     if((Xpos>x && Xpos<x1)&&(Ypos>y && Ypos<y1))if(1==(button&1)){
	  rectangle(x,y,x1,y1);
	  hidemouse();
	 // sound(1);
	  color(x,y,x1,y1,9);

		    x=getmaxx()/2-20-40,x1=getmaxx()/2-20+40,y=380,y1=390;
	  erase(x,y,x1,y1,2);
	   erase(240,140,370,160,2);
	   linedraw(70,70,70,200,13);
	  linedraw(540,70,540,200,13);
	  linedraw(getmaxx()/2-20,250,getmaxx()/2-20,400,13);

	  break;
	 }
  }

  rectangle(180,195,450,210);
  popup(180,195,450,210);
  showmouse();



/////24th move//////

    // x=540-45,x1=540+45,y=190,y1=200;
     // x=getmaxx()/2-20-40,x1=getmaxx()/2-20+40,y=380,y1=390;
       //	x=55,x1=90,y=160,y1=170;


       x=getmaxx()/2-20-60,x1=getmaxx()/2-20+60,y=390,y1=400;

while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     setcolor(WHITE);
    outtextxy(180,200,"Try next MOVE");
 if((Xpos>x && Xpos<x1)&& (Ypos>y && Ypos<y1))if(1==(button&1)){
 popup(180,195,450,210);
 setcolor(WHITE);
 outtextxy(180,200,"Now click on the moveable place");

	x=540-40,x1=540+40,y=180,y1=190;
  break;
 }
  }
  while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     if((Xpos>x && Xpos<x1)&&(Ypos>y && Ypos<y1))if(1==(button&1)){
	  rectangle(x,y,x1,y1);
	  hidemouse();
	 // sound(1);
	  color(x,y,x1,y1,1);

	   x=getmaxx()/2-20-60,x1=getmaxx()/2-20+60,y=390,y1=400;
	  erase(x,y,x1,y1,2);
	   erase(240,140,370,160,2);
	   linedraw(70,70,70,200,13);
	  linedraw(540,70,540,200,13);
	  linedraw(getmaxx()/2-20,250,getmaxx()/2-20,400,13);

	  break;
	 }
  }

  rectangle(180,195,450,210);
  popup(180,195,450,210);
  showmouse();





/////25th move//////

    // x=540-45,x1=540+45,y=190,y1=200;
     // x=getmaxx()/2-20-40,x1=getmaxx()/2-20+40,y=380,y1=390;
       //	x=55,x1=90,y=160,y1=170;



     x=55,x1=90,y=160,y1=170;
while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     setcolor(WHITE);
    outtextxy(180,200,"Try next MOVE");
 if((Xpos>x && Xpos<x1)&& (Ypos>y && Ypos<y1))if(1==(button&1)){
 popup(180,195,450,210);
 setcolor(WHITE);
 outtextxy(180,200,"Now click on the moveable place");

	x=540-30,x1=540+30,y=170,y1=180;
  break;
 }
  }
  while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     if((Xpos>x && Xpos<x1)&&(Ypos>y && Ypos<y1))if(1==(button&1)){
	  rectangle(x,y,x1,y1);
	  hidemouse();
	 // sound(1);
	  color(x,y,x1,y1,9);

	   x=55,x1=90,y=160,y1=170;
	  erase(x,y,x1,y1,2);
	   erase(240,140,370,160,2);
	   linedraw(70,70,70,200,13);
	  linedraw(540,70,540,200,13);
	  linedraw(getmaxx()/2-20,250,getmaxx()/2-20,400,13);

	  break;
	 }
  }

  rectangle(180,195,450,210);
  popup(180,195,450,210);
  showmouse();






/////26th move//////

    // x=540-45,x1=540+45,y=190,y1=200;
     // x=getmaxx()/2-20-40,x1=getmaxx()/2-20+40,y=380,y1=390;
       //	x=55,x1=90,y=160,y1=170;



     x=50,x1=95,y=170,y1=180;
while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     setcolor(WHITE);
    outtextxy(180,200,"Try next MOVE");
 if((Xpos>x && Xpos<x1)&& (Ypos>y && Ypos<y1))if(1==(button&1)){
 popup(180,195,450,210);
 setcolor(WHITE);
 outtextxy(180,200,"Now click on the moveable place");

	 x=getmaxx()/2-20-30,x1=getmaxx()/2-20+30,y=390,y1=400;
  break;
 }
  }
  while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     if((Xpos>x && Xpos<x1)&&(Ypos>y && Ypos<y1))if(1==(button&1)){
	  rectangle(x,y,x1,y1);
	  hidemouse();
	 // sound(1);
	  color(x,y,x1,y1,8);

	     x=50,x1=95,y=170,y1=180;
	  erase(x,y,x1,y1,2);
	   erase(240,140,370,160,2);
	   linedraw(70,70,70,200,13);
	  linedraw(540,70,540,200,13);
	  linedraw(getmaxx()/2-20,250,getmaxx()/2-20,400,13);

	  break;
	 }
  }

  rectangle(180,195,450,210);
  popup(180,195,450,210);
  showmouse();






/////27th move//////

    // x=540-45,x1=540+45,y=190,y1=200;
     // x=getmaxx()/2-20-40,x1=getmaxx()/2-20+40,y=380,y1=390;
       //	x=55,x1=90,y=160,y1=170;



      x=540-25,x1=540+25,y=170,y1=180;
while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     setcolor(WHITE);
    outtextxy(180,200,"Try next MOVE");
 if((Xpos>x && Xpos<x1)&& (Ypos>y && Ypos<y1))if(1==(button&1)){
 popup(180,195,450,210);
 setcolor(WHITE);
 outtextxy(180,200,"Now click on the moveable place");

	 x=getmaxx()/2-20-20,x1=getmaxx()/2-20+20,y=380,y1=390;
  break;
 }
  }
  while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     if((Xpos>x && Xpos<x1)&&(Ypos>y && Ypos<y1))if(1==(button&1)){
	  rectangle(x,y,x1,y1);
	  hidemouse();
	 // sound(1);
	  color(x,y,x1,y1,9);

	      x=540-25,x1=540+25,y=170,y1=180;
	  erase(x,y,x1,y1,2);
	   erase(240,140,370,160,2);
	   linedraw(70,70,70,200,13);
	  linedraw(540,70,540,200,13);
	  linedraw(getmaxx()/2-20,250,getmaxx()/2-20,400,13);

	  break;
	 }
  }

  rectangle(180,195,450,210);
  popup(180,195,450,210);
  showmouse();






/////28th move//////

    // x=540-45,x1=540+45,y=190,y1=200;
     // x=getmaxx()/2-20-40,x1=getmaxx()/2-20+40,y=380,y1=390;
       //	x=55,x1=90,y=160,y1=170;



      x=40,x1=105,y=180,y1=190;
while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     setcolor(WHITE);
    outtextxy(180,200,"Try next MOVE");
 if((Xpos>x && Xpos<x1)&& (Ypos>y && Ypos<y1))if(1==(button&1)){
 popup(180,195,450,210);
 setcolor(WHITE);
 outtextxy(180,200,"Now click on the moveable place");

	  x=540-40,x1=540+40,y=170,y1=180;
  break;
 }
  }
  while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     if((Xpos>x && Xpos<x1)&&(Ypos>y && Ypos<y1))if(1==(button&1)){
	  rectangle(x,y,x1,y1);
	  hidemouse();
	 // sound(1);
	  color(x,y,x1,y1,14);

	       x=40,x1=105,y=180,y1=190;
	  erase(x,y,x1,y1,2);
	   erase(240,140,370,160,2);
	   linedraw(70,70,70,200,13);
	  linedraw(540,70,540,200,13);
	  linedraw(getmaxx()/2-20,250,getmaxx()/2-20,400,13);

	  break;
	 }
  }

  rectangle(180,195,450,210);
  popup(180,195,450,210);
  showmouse();



/////29th move//////

    // x=540-45,x1=540+45,y=190,y1=200;
     // x=getmaxx()/2-20-40,x1=getmaxx()/2-20+40,y=380,y1=390;
       //	x=55,x1=90,y=160,y1=170;



      x=getmaxx()/2-20-20,x1=getmaxx()/2-20+20,y=380,y1=390;
while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     setcolor(WHITE);
    outtextxy(180,200,"Try next MOVE");
 if((Xpos>x && Xpos<x1)&& (Ypos>y && Ypos<y1))if(1==(button&1)){
 popup(180,195,450,210);
 setcolor(WHITE);
 outtextxy(180,200,"Now click on the moveable place");

	  x=55,x1=90,y=180,y1=190;
  break;
 }
  }
  while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     if((Xpos>x && Xpos<x1)&&(Ypos>y && Ypos<y1))if(1==(button&1)){
	  rectangle(x,y,x1,y1);
	  hidemouse();
	 // sound(1);
	  color(x,y,x1,y1,9);

	     x=getmaxx()/2-20-20,x1=getmaxx()/2-20+20,y=380,y1=390;
	  erase(x,y,x1,y1,2);
	   erase(240,140,370,160,2);
	   linedraw(70,70,70,200,13);
	  linedraw(540,70,540,200,13);
	  linedraw(getmaxx()/2-20,250,getmaxx()/2-20,400,13);

	  break;
	 }
  }

  rectangle(180,195,450,210);
  popup(180,195,450,210);
  showmouse();




/////30th move//////

    // x=540-45,x1=540+45,y=190,y1=200;
     // x=getmaxx()/2-20-40,x1=getmaxx()/2-20+40,y=380,y1=390;
       //	x=55,x1=90,y=160,y1=170;



      x=getmaxx()/2-20-30,x1=getmaxx()/2-20+30,y=390,y1=400;
while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     setcolor(WHITE);
    outtextxy(180,200,"Try next MOVE");
 if((Xpos>x && Xpos<x1)&& (Ypos>y && Ypos<y1))if(1==(button&1)){
 popup(180,195,450,210);
 setcolor(WHITE);
 outtextxy(180,200,"Now click on the moveable place");

	  x=540-30,x1=540+30,y=160,y1=170;
  break;
 }
  }
  while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     if((Xpos>x && Xpos<x1)&&(Ypos>y && Ypos<y1))if(1==(button&1)){
	  rectangle(x,y,x1,y1);
	  hidemouse();
	 // sound(1);
	  color(x,y,x1,y1,8);

	      x=getmaxx()/2-20-30,x1=getmaxx()/2-20+30,y=390,y1=400;
	  erase(x,y,x1,y1,2);
	   erase(240,140,370,160,2);
	   linedraw(70,70,70,200,13);
	  linedraw(540,70,540,200,13);
	  linedraw(getmaxx()/2-20,250,getmaxx()/2-20,400,13);

	  break;
	 }
  }

  rectangle(180,195,450,210);
  popup(180,195,450,210);
  showmouse();




/////31st move//////

    // x=540-45,x1=540+45,y=190,y1=200;
     // x=getmaxx()/2-20-40,x1=getmaxx()/2-20+40,y=380,y1=390;
       //	x=55,x1=90,y=160,y1=170;



    x=55,x1=90,y=180,y1=190;
while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     setcolor(WHITE);
    outtextxy(180,200,"Try next MOVE");
 if((Xpos>x && Xpos<x1)&& (Ypos>y && Ypos<y1))if(1==(button&1)){
 popup(180,195,450,210);
 setcolor(WHITE);
 outtextxy(180,200,"Now click on the moveable place");

	  x=540-20,x1=540+20,y=150,y1=160;
  break;
 }
  }
  while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     if((Xpos>x && Xpos<x1)&&(Ypos>y && Ypos<y1))if(1==(button&1)){
	  rectangle(x,y,x1,y1);
	  hidemouse();
	 // sound(1);
	  color(x,y,x1,y1,9);

      x=55,x1=90,y=180,y1=190;
	  erase(x,y,x1,y1,2);
	   erase(240,140,370,160,2);
	   linedraw(70,70,70,200,13);
	  linedraw(540,70,540,200,13);
	  linedraw(getmaxx()/2-20,250,getmaxx()/2-20,400,13);

	  break;
	 }
  }

  rectangle(180,195,450,210);
  popup(180,195,450,210);
  showmouse();



/////32nd move//////

    // x=540-45,x1=540+45,y=190,y1=200;
     // x=getmaxx()/2-20-40,x1=getmaxx()/2-20+40,y=380,y1=390;
       //	x=55,x1=90,y=160,y1=170;



    x=10,x1=130,y=190,y1=200;
while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     setcolor(WHITE);
    outtextxy(180,200,"Try next MOVE");
 if((Xpos>x && Xpos<x1)&& (Ypos>y && Ypos<y1))if(1==(button&1)){
 popup(180,195,450,210);
 setcolor(WHITE);
 outtextxy(180,200,"Now click on the moveable place");

	   x=getmaxx()/2-20-70,x1=getmaxx()/2-20+70,y=390,y1=400;
  break;
 }
  }
  while(true){
    mouseInfo(&button, &Xpos, &Ypos);
     if((Xpos>x && Xpos<x1)&&(Ypos>y && Ypos<y1))if(1==(button&1)){
	  rectangle(x,y,x1,y1);
	  hidemouse();
	 // sound(1);
	  color(x,y,x1,y1,4);

	   x=10,x1=130,y=190,y1=200;
	  erase(x,y,x1,y1,2);
	   erase(240,140,370,160,2);
	   linedraw(70,70,70,200,13);
	  linedraw(540,70,540,200,13);
	  linedraw(getmaxx()/2-20,250,getmaxx()/2-20,400,13);

	  break;
	 }
  }

  rectangle(180,195,450,210);
  popup(180,195,450,210);
  showmouse();

  */
  // disc6();



   if(kbhit());
  char ch=getch();
  if(ch==8){
   cleardevice();
   graphicsdriver();
   discselection();
  }
 getch();
 cleardevice();
// closegraph();
 return 0;
}







////page for 7 disc///

int calldisc7(){
clrscr();
cleardevice();
graphicsdriver();
showmouse();
 settextstyle(SANS_SERIF_FONT,HORIZ_DIR,3);
 setcolor(15);
 outtextxy(190,0,"Draw 7 disc PUZZLE");
 setcolor(13);
 outtextxy(191,1,"Draw 7 disc PUZZLE");
 settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
  line(60,70,60,200);
  setbkcolor(2);
  fillellipse(0,201,201,1);
  setcolor(1);
  outtextxy(30,210,"SOURCE");
  setcolor(4);
  rectangle(5,190,125,200);
  int x=5,y=191,x1=125,y1=191;///x1 will be constant
  while(y1!=200){
   line(x,y,x1,y1);
   y++,y1++;
   }
   setcolor(15);
  rectangle(10,180,120,190);
  x=10,y=181,x1=120,y1=181;
  while(y1!=190){
  line(x,y,x1,y1);
  y++,y1++;
  }
  setcolor(1);
  rectangle(15,170,115,180);
  x=15,y=171,x1=115,y1=171;
  while(y1!=180){
  line(x,y,x1,y1);
  y++,y1++;
  }
  setcolor(14);
  rectangle(20,160,110,170);
  x=20,y=161,x1=110,y1=161;
  while(y1!=170){
  line(x,y,x1,y1);
  y++,y1++;
  }
  setcolor(8);
  rectangle(25,150,105,160);
  x=25,y=151,x1=105,y1=151;
  while(y1!=160){
  line(x,y,x1,y1);
  y++,y1++;
  }
  setcolor(9);
  rectangle(30,140,95,150);
  x=30,y=141,x1=95,y1=141;
  while(y1!= 150){
  line(x,y,x1,y1);
  y++,y1++;
  }
  setcolor(5);
  rectangle(35,130,90,140);
  x=35,y=131,x1=90,y1=131;
  while(y1!= 140){
  line(x,y,x1,y1);
  y++,y1++;
  }
  setcolor(4);
  line(540,70,540,200);
  fillellipse(600,201,201,1);
  setcolor(14);
  outtextxy(550,212,"TEMPORARY");
  line(getmaxx()/2-20,250,getmaxx()/2-20,400);
  fillellipse(300,400,200,1);
  setcolor(15);
  outtextxy(getmaxx()/2,410,"DESTINATION");
   setcolor(1);
 outtextxy(190,50,"Not Available Now");
 outtextxy(190,100,"Press any Key");
   if(kbhit());
  char ch=getch();
  if(ch==27)exitpage();
  if(ch==8){
   cleardevice();
   graphicsdriver();
   discselection();
  }
 getch();
 cleardevice();
// closegraph();
 return 0;
}




///page for 8 disc////

int calldisc8(){
clrscr();
cleardevice();
graphicsdriver();
showmouse();
 settextstyle(SANS_SERIF_FONT,HORIZ_DIR,3);
 setcolor(15);
 outtextxy(190,0,"Draw 8 disc PUZZLE");
 setcolor(13);
 outtextxy(191,1,"Draw 8 disc PUZZLE");
 settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
  line(60,70,60,200);
  setbkcolor(2);
  fillellipse(0,201,201,1);
  setcolor(1);
  outtextxy(30,210,"SOURCE");
  setcolor(4);
  rectangle(5,190,125,200);
  int x=5,y=191,x1=125,y1=191;///x1 will be constant
  while(y1!=200){
   line(x,y,x1,y1);
   y++,y1++;
   }
   setcolor(15);
  rectangle(10,180,120,190);
  x=10,y=181,x1=120,y1=181;
  while(y1!=190){
  line(x,y,x1,y1);
  y++,y1++;
  }
  setcolor(1);
  rectangle(15,170,115,180);
  x=15,y=171,x1=115,y1=171;
  while(y1!=180){
  line(x,y,x1,y1);
  y++,y1++;
  }
  setcolor(14);
  rectangle(20,160,110,170);
  x=20,y=161,x1=110,y1=161;
  while(y1!=170){
  line(x,y,x1,y1);
  y++,y1++;
  }
  setcolor(8);
  rectangle(25,150,105,160);
  x=25,y=151,x1=105,y1=151;
  while(y1!=160){
  line(x,y,x1,y1);
  y++,y1++;
  }
  setcolor(9);
  rectangle(30,140,95,150);
  x=30,y=141,x1=95,y1=141;
  while(y1!= 150){
  line(x,y,x1,y1);
  y++,y1++;
  }
  setcolor(5);
  rectangle(35,130,90,140);
  x=35,y=131,x1=90,y1=131;
  while(y1!= 140){
  line(x,y,x1,y1);
  y++,y1++;
  }
  setcolor(4);
  rectangle(40,120,85,130);
  x=40,y=121,x1=85,y1=121;
  while(y1!=130){
  line(x,y,x1,y1);
  y++,y1++;
  }
  setcolor(4);
  line(540,70,540,200);
  fillellipse(600,201,201,1);
  setcolor(14);
  outtextxy(550,212,"TEMPORARY");
  line(getmaxx()/2-20,250,getmaxx()/2-20,400);
  fillellipse(300,400,200,1);
  setcolor(15);
  outtextxy(getmaxx()/2,410,"DESTINATION");
   setcolor(1);
 outtextxy(190,50,"Not Available Now");
 outtextxy(190,100,"Press any Key");
   if(kbhit());
  char ch=getch();
  if(ch==27)exitpage();
  if(ch==8){
   cleardevice();
   graphicsdriver();
   discselection();
  }
 getch();
 cleardevice();
// closegraph();
 return 0;
}


///page for 9 disc////



int calldisc9(){
clrscr();
cleardevice();
graphicsdriver();
showmouse();
 settextstyle(SANS_SERIF_FONT,HORIZ_DIR,3);
 setcolor(15);
 outtextxy(190,0,"Draw 9 disc PUZZLE");
 setcolor(13);
 outtextxy(191,1,"Draw 9 disc PUZZLE");
 settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
  line(60,70,60,200);
  setbkcolor(2);
  fillellipse(0,201,201,1);
  setcolor(1);
  outtextxy(30,210,"SOURCE");
  setcolor(4);
  rectangle(5,190,125,200);
  int x=5,y=191,x1=125,y1=191;///x1 will be constant
  while(y1!=200){
   line(x,y,x1,y1);
   y++,y1++;
   }
   setcolor(15);
  rectangle(10,180,120,190);
  x=10,y=181,x1=120,y1=181;
  while(y1!=190){
  line(x,y,x1,y1);
  y++,y1++;
  }
  setcolor(1);
  rectangle(15,170,115,180);
  x=15,y=171,x1=115,y1=171;
  while(y1!=180){
  line(x,y,x1,y1);
  y++,y1++;
  }
  setcolor(14);
  rectangle(20,160,110,170);
  x=20,y=161,x1=110,y1=161;
  while(y1!=170){
  line(x,y,x1,y1);
  y++,y1++;
  }
  setcolor(8);
  rectangle(25,150,105,160);
  x=25,y=151,x1=105,y1=151;
  while(y1!=160){
  line(x,y,x1,y1);
  y++,y1++;
  }
  setcolor(9);
  rectangle(30,140,95,150);
  x=30,y=141,x1=95,y1=141;
  while(y1!= 150){
  line(x,y,x1,y1);
  y++,y1++;
  }
  setcolor(5);
  rectangle(35,130,90,140);
  x=35,y=131,x1=90,y1=131;
  while(y1!= 140){
  line(x,y,x1,y1);
  y++,y1++;
  }
  setcolor(4);
  rectangle(40,120,85,130);
  x=40,y=121,x1=85,y1=121;
  while(y1!=130){
  line(x,y,x1,y1);
  y++,y1++;
  }
  setcolor(13);
  rectangle(45,120,80,120);
  x=45,y=111,x1=80,y1=111;
  while(y1!=120){
  line(x,y,x1,y1);
  y++,y1++;
  }
  setcolor(4);
  line(540,70,540,200);
  fillellipse(600,201,201,1);
  setcolor(14);
  outtextxy(550,212,"TEMPORARY");
  line(getmaxx()/2-20,250,getmaxx()/2-20,400);
  fillellipse(300,400,200,1);
  setcolor(15);
  outtextxy(getmaxx()/2,410,"DESTINATION");
   setcolor(1);
 outtextxy(190,50,"Not Available Now");
 outtextxy(190,100,"Press any Key");
   if(kbhit());
   //if(ch==27)exitpage();
  char ch=getch();
  if(ch==27)exitpage();
  if(ch==8){
   cleardevice();
   graphicsdriver();
   discselection();
  }
 getch();
 cleardevice();
// closegraph();
 return 0;
}

///page for 10 disc////



int calldisc10(){
clrscr();
cleardevice();
graphicsdriver();
showmouse();
 settextstyle(SANS_SERIF_FONT,HORIZ_DIR,3);
 setcolor(15);
 outtextxy(190,0,"Draw 10 disc PUZZLE");
 setcolor(13);
 outtextxy(191,1,"Draw 10 disc PUZZLE");
 settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
  line(60,70,60,200);
  setbkcolor(2);
  fillellipse(0,201,201,1);
  setcolor(1);
  outtextxy(30,210,"SOURCE");
  setcolor(4);
  rectangle(5,190,125,200);
  int x=5,y=191,x1=125,y1=191;///x1 will be constant
  while(y1!=200){
   line(x,y,x1,y1);
   y++,y1++;
   }
   setcolor(15);
  rectangle(10,180,120,190);
  x=10,y=181,x1=120,y1=181;
  while(y1!=190){
  line(x,y,x1,y1);
  y++,y1++;
  }
  setcolor(1);
  rectangle(15,170,115,180);
  x=15,y=171,x1=115,y1=171;
  while(y1!=180){
  line(x,y,x1,y1);
  y++,y1++;
  }
  setcolor(14);
  rectangle(20,160,110,170);
  x=20,y=161,x1=110,y1=161;
  while(y1!=170){
  line(x,y,x1,y1);
  y++,y1++;
  }
  setcolor(8);
  rectangle(25,150,105,160);
  x=25,y=151,x1=105,y1=151;
  while(y1!=160){
  line(x,y,x1,y1);
  y++,y1++;
  }
  setcolor(9);
  rectangle(30,140,95,150);
  x=30,y=141,x1=95,y1=141;
  while(y1!= 150){
  line(x,y,x1,y1);
  y++,y1++;
  }
  setcolor(5);
  rectangle(35,130,90,140);
  x=35,y=131,x1=90,y1=131;
  while(y1!= 140){
  line(x,y,x1,y1);
  y++,y1++;
  }
  setcolor(4);
  rectangle(40,120,85,130);
  x=40,y=121,x1=85,y1=121;
  while(y1!=130){
  line(x,y,x1,y1);
  y++,y1++;
  }
  setcolor(13);
  rectangle(45,120,80,120);
  x=45,y=111,x1=80,y1=111;
  while(y1!=120){
  line(x,y,x1,y1);
  y++,y1++;
  }
  setcolor(12);
  rectangle(50,110,75,110);
  x=50,y=101,x1=75,y1=101;
  while(y1!=110){
  line(x,y,x1,y1);
  y++,y1++;
  }
  setcolor(4);
  line(540,70,540,200);
  fillellipse(600,201,201,1);
  setcolor(14);
  outtextxy(550,212,"TEMPORARY");
  line(getmaxx()/2-20,250,getmaxx()/2-20,400);
  fillellipse(300,400,200,1);
  setcolor(15);
  outtextxy(getmaxx()/2,410,"DESTINATION");
   setcolor(1);
 outtextxy(190,50,"Not Available Now");
 outtextxy(190,100,"Press any Key");
  if(kbhit());
  char ch=getch();
  if(ch==27)exitpage();
  if(ch==8){
   cleardevice();
   graphicsdriver();
   discselection();
  }
 getch();
 cleardevice();
// closegraph();
return 0;
}




////How to play this game?////////



void howtoplay(){
hidemouse();
clrscr();
cleardevice();
closegraph();
graphicsdriver();
hidemouse();
setbkcolor(4);
int y=0;
settextstyle(3,0,4);
setcolor(1);
outtextxy(100,y,"WAYS to DRAW LUCAS' PUZZLE");
setcolor(14);
settextstyle(0,HORIZ_DIR,1);


   y+=50;
outtextxy(0,y,"Object of the game is to move all the disks over to Tower 3 (with your mouse).");

  y+=20;
outtextxy(0,y,"But you cannot place a larger disk onto a smaller disk.");

setcolor(13);


y+=30;
outtextxy(0,y,"Simpler statement of iterative solution:");
y+=10;
outtextxy(0,y,"#For an even Number of DISC:");

y+=10;
outtextxy(0,y,"    make the legal move between pegs A and B (in either direction)");

y+=10;
outtextxy(0,y,"    make the legal move between pegs A and C (in either direction)");



y+=10;
outtextxy(0,y,"    make the legal move between pegs B and C (in either direction)");



y+=10;
outtextxy(0,y,"repeat until complete");




y+=10;
outtextxy(0,y,"  ");



y+=10;
outtextxy(0,y,"#For an odd number of disks:");




y+=10;
outtextxy(0,y,"     make the legal move between pegs A and C (in either direction)");

y+=10;
outtextxy(0,y,"     make the legal move between pegs A and B (in either direction)");



y+=10;
outtextxy(0,y,"     make the legal move between pegs C and B (in either direction)");

y+=10;
outtextxy(0,y,"repeat until complete");

y+=10;
outtextxy(0,y,"  ");


 y+=10;
outtextxy(0,y,"In each case, a total of 2n-1 moves are made.Equivalent iterative solution:");


y+=10;
outtextxy(0,y,"Another way to generate the unique optimal iterative solution:");




y+=10;
outtextxy(0,y,"Number the disks 1 through n (largest to smallest).");


 y+=10;
outtextxy(0,y,"If n is odd, the first move is from peg A to peg C.");




 y+=10;
outtextxy(0,y,"If n is even, the first move is from peg A to peg B.");




y+=10;
outtextxy(0,y,"Now, add these constraints:");




    y+=10;
outtextxy(0,y,"   No odd disk may be placed directly on an odd disk.");


y+=10;
outtextxy(0,y,"   No even disk may be placed directly on an even disk.");



   y+=10;
outtextxy(0,y,"There will be sometimes two possible pegs:one will have disks and the other");


    y+=10;
outtextxy(0,y,"will be empty.Place the disk in the non-empty peg.Never undo your previous move");


   y+=10;
outtextxy(0,y,"(that is, do not move a disk back to its immediate last peg).");



   y+=10;
outtextxy(0,y,"Considering those constraints after the first move,there is only one legal move");


  y+=10;
outtextxy(0,y,"at every subsequent turn.The sequence of these unique moves is an optimal ");

     y+=10;
outtextxy(0,y,"solution to the problem equivalent to the iterative solution described above.");


setcolor(YELLOW);
y+=20;
outtextxy(0,y,"..................................................................................");

y+=20;
outtextxy(10,y,"To play this game with ERROR FREE you must go back and view READ ME(MUST)");
outtextxy(10,y+15,"Else you will feel trouble during playing,so go back or choose exit");
y+=10;
setcolor(GREEN);
outtextxy(100,y+30,"ESC=exit from game and Backspace=go back");



 if(kbhit());
  char ch=getch();
  if(ch==8){
   cleardevice();
   graphicsdriver();
   gameinfo();
   }if(ch==27)exitpage();


// return false;
}




/////for user (important)/////




void readmust(){
hidemouse();
 clrscr();
 cleardevice();
 closegraph();
 graphicsdriver();
 setbkcolor(2);
 setcolor(14);
 settextstyle(0,0,2);
 outtextxy(0,1,"PLEASE PAY ATTENTION AND READ CAREFULLY");
 outtextxy(1,3,"PLEASE PAY ATTENTION AND READ CAREFULLY");
 printf("\n\nYou must Follow few rules in order to avoid some problem,DOS is bit different and ");
 printf(" provides less opportunities comparing other platforms,In order to play this game ");
 printf(" with ERROR FREE you'll Need to follow my instructions from here,first of all you ");
 printf(" must not press on any button untill you are said to do so,sometimes it may cause ");
 printf(" to fade some necessary pages away without Being Shown to You,So do as each and ");
 printf(" Every Page offers You to do,suppose you are said to press either Esc or Backspace ");
 printf(" In this Case you should not press on any other buttons.Now Read carefully:");
 printf(" Suppose for 2 disc puzzle game according to this games rule you will have to select ");
 printf(" The top Smallest disc first by simply clicking onto that disc once then you'll have ");
 printf(" to click next click onto the perfect moveable place,for 2 disc puzzle 2nd click must be ");
 printf(" on temporary(B) place and you should not try clicking anywhere around Temp to ");
 printf(" Move That Disc.you'll have to click right onto the perfect place where the disc ");
 printf(" should be placed after your click.so if you are clicking on the middle point of ");
 printf(" Temporary or somewhere else then the disc won't be moved,also you should always ");
 printf(" click very close to the verticle line while trying to move the disc sometimes if after ");
 printf(" Pressing ESC or any other Button once Anything doesn't happen then press that particular ");
 printf(" button twice but not more then that,not necessarily you'll have to do so, NOW");
 printf(" if you click on destination ");
 printf(" when you should have clicked around temporary,you'll Get Wrong Attempt pop-up sms ");
 printf(" with little sound,if there are too many wrong attempts then you'll Lose the game ");
 printf(" If you can win with 0 wrong attempt Then You'll get a special greeting page For you");
 printf(" As i told you earlier DOS doesn't provide that much opportunities so while playing,you ");
 printf(" may get error called memory full and may get yourself out from the game Immediately. ");
 printf(" Don't Worry,just re-run the Program and you'll Again get chance to play ");
 printf(" the game,playing multiple matches at a time may Cause this problem,to Avoid ");
 printf(" this you must exit from the game after finishing game and to play again ");
 printf(" You can re-run the code and HAVE FUN,Hope you'll Enjoy.thank you :) ");
 setcolor(4);
 settextstyle(0,0,1);
outtextxy(100,getmaxy()-10,"Press Backspace to go back or ESC (twice) to exit");

 if(kbhit());
  char ch=getch();
  if(ch==8){
   cleardevice();
   graphicsdriver();
   gameinfo();
   }
 //return false;
}



/////contact me page @mobassir/////


void contactme(){
hidemouse();
clrscr();
cleardevice();
closegraph();
graphicsdriver();
settextstyle(1,HORIZ_DIR,2);
 setbkcolor(15);
 setcolor(1);
 outtextxy(100,10,"From FSIT");
 setcolor(2);
 outtextxy(0,50,"Developed and Programmed by:");
 outtextxy(0,80,"Name : SYED MOBASSIR HOSSEN");
 outtextxy(0,110,"Hometown : TANGAIL");
 outtextxy(0,140,"E-mail : mobassirhossen94@gmail.com");
 outtextxy(0,170,"Skype-id : mobassir149");

 outtextxy(0,200,"Facebook id : Mobassir Hossen (fb email : www.mobassirhossen");
 outtextxy(400,230,"@gmail.com");
 setcolor(4);
 outtextxy(200,400,"Press Backspace to go back");
 outtextxy(200,430,"Press ESC to exit from the game");




 if(kbhit());
  char ch=getch();
  if(ch==27)exitpage();
  if(ch==8){
   cleardevice();
   graphicsdriver();
   gameinfo();
   }
 //return false;
}




////about me(mobassir)/////


void aboutme(){
hidemouse();
clrscr();
cleardevice();
closegraph();
graphicsdriver();
settextstyle(0,HORIZ_DIR,1);
  setbkcolor(2);
  setcolor(15);
  outtextxy(0,20,"This PROJECT was done in SWE-123 Under the course teacher SAYED ASADUZZAMAN");
  outtextxy(0,40,"This PROJECT course included graphics/openGL programming using C programming,");
  outtextxy(0,60,"MOUSE PROGRAMMING,few ADVANCE GRAPHICS PROGRAMMING(such as OBJECT MOVING");
  outtextxy(0,80,"techniques),little bit about DYNAMIC PROGRAMMING and lot more things within");
  outtextxy(0,100,"Short period");
  setcolor(4);
  outtextxy(0,120,"Learning C and getting the ability to create Practical Field or WORLD-CLASS");
  outtextxy(0,140,"Program is totally a Different Things.We May Learn C very well,we are adva-");
  outtextxy(0,160,"nce in ALGORITHM but these are not Guarantees that we can DEVELOP real-Life");
  outtextxy(0,180,"software.This requires a lot of additional knowledge including handling ");
  outtextxy(0,200,"Graphics Objects,loading and controlling mouse pointer,Driving menus,causing");
  outtextxy(0,220,"Software interrupts etc.Now this game was not written in such advance LEVEL");
  outtextxy(0,250,"but i'll talk briefly about the logics below i implemented on my game :");
  setcolor(15);
  outtextxy(0,270,"i just designed few discs using rectangle function,i filled each and every");
  outtextxy(0,290,"rectangle using different color and line function(using loop).though i can");
  outtextxy(0,310,"move object but i didn't,cause i had a different plan which was to remove");
  outtextxy(0,330,"the disc after click and then same size disc using same color i drew in the");
  outtextxy(0,350,"Moveable place,if user clicks in invalid place i just counted the wrong ");
  outtextxy(0,370,"move attempt and display if user wins or not(based on chances i provided");
  setcolor(YELLOW);
  outtextxy(0,390,"i could make this game using different technique but i prefered this one so i");
  outtextxy(0,410,"applied my particular algorithm to solve this problem,THE FUTURE PLAN OF");
  outtextxy(0,430,"MINE is to go further with this game with dynamic programming/gaming ");
  outtextxy(0,450,"technique using java which would be huge efficient and much more productive");
    setcolor(4);
 settextstyle(0,0,1);
outtextxy(100,getmaxy()-10,"Press Backspace to go back or ESC (twice) to exit");


 if(kbhit());
  char ch=getch();
  if(ch==27)exitpage();
  if(ch==8){
   cleardevice();
   graphicsdriver();
   gameinfo();
   }
 //return false;
}





////How tower of hanoi came?//////


void tohhistory(){
hidemouse();
cleardevice();
closegraph();
graphicsdriver();
setbkcolor(4);
short int y=0;
settextstyle(3,0,4);
setcolor(1);
outtextxy(100,y,"Tower of BRAHMA PUZZLE");
setcolor(13);
settextstyle(0,HORIZ_DIR,1);
y+=50;
outtextxy(0,y,"Tower of HANOI is a puzzle invented by professor E.Lucas in 1883.It is also ");
y+=20;
outtextxy(0,y,"called the tower of BRAHMA or LUCAS' Tower.It is a mathematical GAME or PUZZLE.");
y+=20;
outtextxy(0,y,"This BRAHMA PUZZLE appeared as an intelligence test for apes in the film RISE OF");
y+=20;
outtextxy(0,y,"THE PLANET OF THE APES(2011) under the name LUCAS TOWER.");

y+=20;
outtextxy(0,y,"There is a story about an Indian temple in Kashi Vishwanath which contains");

y+=20;
outtextxy(0,y,"a large room with three time-worn posts in it surrounded by 64 golden disks.");

 y+=20;
outtextxy(0,y,"Brahmin priests,acting out the command of an ancient prophecy, have been moving");


y+=20;
outtextxy(0,y,"these disks,in accordance with the immutable rules of the Brahma,since that time");


y+=20;
outtextxy(0,y,"e The puzzle is therefore also known as the Tower of Brahma puzzle.");


  y+=20;
outtextxy(0,y,"According to the legend, when the last move of the puzzle will be completed,");

y+=20;
outtextxy(0,y,"the world will end.It is not clear whether Lucas invented this legend or was");
y+=20;
outtextxy(0,y,"inspired by it.If the legend were true, and if the priests were able to move");


  y+=20;
outtextxy(0,y,"Disc at a rate of one per second, using the smallest number of moves, it would");


 y+=20;
outtextxy(0,y,"Take Them 2^64-1 seconds or roughly 585 billion years or 18,446,744,073,709,");

y+=20;
outtextxy(0,y,"551,615 turns to finish, or about 42 times the current age of the Universe.");


y+=20;
outtextxy(0,y,"There are many variations on this legend. For instance, in some tellings,");


y+=20;
outtextxy(0,y,"the temple is a monastery and the priests are monks.The temple or monastery may be");


y+=20;
outtextxy(0,y,"said to be in different parts of the world — including Hanoi, Vietnam, and may be");


   y+=20;
outtextxy(0,y,"associated with any religion. In some versions, other elements are introduced,");

y+=20;
outtextxy(0,y,"such as the fact that the tower was created at the beginning of the world,");


  y+=20;
outtextxy(0,y,"or that the priests or monks may make only one move per day.");
    setcolor(14);
 settextstyle(0,0,1);
outtextxy(100,getmaxy()-10,"Press Backspace to go back or ESC (twice) to exit");

 if(kbhit());
  char ch=getch();
  if(ch==8){
   cleardevice();
   graphicsdriver();
   gameinfo();
   }


 //return false;
}






//// color moved disc/////




void color(int x,int y,int x1,int y1,int n){
  setcolor(n);
  while(x!=(x1+1)){
   line(x,y,x,y1);
    x++;
   }
  // return 0;
}





//// erase selected disc/////



int erase(int x1,int y1,int x2,int y2,int c){
 setcolor(c);
 while(x1!=(x2+1)){
 line(x1,y1,x1,y2);
 x1++;
  }
  return 0;
}





//// drawing erased line/////




void linedraw(int xc,int yc,int x1c,int y1c,int col){
setcolor(col);
 line(xc,yc,x1c,y1c);

}



////play mode//////


int mode(){
  char ch=0;
  clrscr();
cleardevice();
graphicsdriver();
setbkcolor(1);
setcolor(2);
 settextstyle(SANS_SERIF_FONT,HORIZ_DIR,3);
outtextxy(200,10,"CHOOSE DIFFICULTIES");
 settextstyle(SANS_SERIF_FONT,HORIZ_DIR,2);
setcolor(15);
outtextxy(10,50,"Press (h/H) for playing in HARD MODE");
outtextxy(10,100,"Press (e/E) for playing in EASY MODE");
outtextxy(10,150,"Press (m/M) for playing in MEDIUM MODE");
setcolor(4);
outtextxy(100,200,"Press (ESC) to exit from game");
//printf("enter");
while(true){
 ch=getch();
 if(ch==27 || ch == 'h' || ch == 'H' || ch == 'm' || ch == 'M'|| ch == 'e' || ch == 'E')
 {
  break;
 }

}
    if(ch==27)exitpage();

 return ch;
}
///// Remove POP-up message....////////



void popup(int r,int e,int m,int o){
 setcolor(2);
 while(r!=(m+1)){
  line(r,e,r,o);
  r++;
 }
}

////////////////// THE END////////////////////////

/////////////FROM 20th OCTOBER TILL///////////////////
///////TUESDAY,8 DECEMBER at 5:06 am/////////////////

////IT TOOK ME AROUND 48 DAYS massive hard EFFORT to COMPLETE THIS PROJECT////////////

////////////////////////// SINGLE HANDEDLY///////////////////

///////////////  :) :) :) :)  //////////////////
///................................................////////////////////////