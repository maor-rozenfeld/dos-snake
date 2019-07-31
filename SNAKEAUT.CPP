#include <stdio.h>
#include <dos.h>
#include <graphics.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
void food(int x,int y);
void head(int x,int y);
void body(int x,int y);
void clear_body(int x,int y);
void net(void);
void do_points(int p);
void snake();

void main()
 {
  snake();
 }

void snake()
 {                                        /////// up: 72   down:80
  clrscr();                               /////// left:75  right:77
  nosound();
							int FFF=0;
							while(FFF==0)
							     {
  randomize();
  int gd=DETECT,gm;
  initgraph(&gd,&gm,"C:\\TC\\BGI");

  int maxx=getmaxx(),maxy=getmaxy();
  int midx=maxx/2,midy=maxy/2;

  int lest_key=77,now_key=0,x[501],y[501],length=4,i,j,xx=128;
  int foodx,foody,food_on_snake=1,points=0,sound_timer=10;
  foodx=((random(21)+1)*18)+38;
  foody=((random(20)+1)*18)+32;

  setfillstyle(0,0);
  setcolor(9);
  bar3d(47,41,425,401,30,1);

  food(foodx,foody);
  do_points(0);
/*
net();
while(!kbhit())
 {
  foodx=((random(21)+1)*18)+38;
  foody=((random(20)+1)*18)+32;
  food(foodx,foody);
  delay(4);
 }
*/

  for (i=0;i<=500;i++)
   {
    x[i]=-1;
    y[i]=-1;
   }

  for(i=0;i<length;i++)
   {
    xx-=18;
    body(x[i]=xx,y[i]=50);
   }
  head(x[0],y[0]);
//  net();
  setcolor(9);
  rectangle(47,41,425,401);
  getch();getch();
  sound(500);
  lest_key==77;
  while (lest_key!=27 && lest_key!=1)
   {
    while(!kbhit())
     {
      if ((lest_key==80 || lest_key==72) && now_key!=27)
       {
	if (x[0]>foodx) lest_key=75;
	if (x[0]<foodx) lest_key=77;
       }
      else
	if (lest_key==75 || lest_key==77)
	 {
	  if (y[0]>foody) lest_key=72;
	  if (y[0]<foody) lest_key=80;
	 }

      //net();
/*
      gotoxy(5,1);
      printf(" Head:  X:%d   ",x[0]);
      gotoxy(30,1);
      printf("Y:%d   ",y[0]);*/

      for(i=length;i>=1;i--)
       {
	x[i]=x[i-1];                       //434
	y[i]=y[i-1];
       }

      switch(lest_key)
       {
	case 72:y[0]-=18;break;
	case 80:y[0]+=18;break;
	case 75:x[0]-=18;break;
	case 77:x[0]+=18;break;
	default:break;
       }

      for (i=1;i<=length;i++)
	if (x[0]==x[i] && y[0]==y[i])
	  lest_key=1;

    if (x[0]==38)   x[0]=416;
    if (x[0]==434)  x[0]=56;
    if (y[0]==32)   y[0]=392;
    if (y[0]==410)  y[0]=50;

//      if (x[0]==38 || x[0]==434 || y[0]==32 || y[0]==410)
//	lest_key=1;

      if (lest_key==1)
	break;

      if (x[0]==foodx && y[0]==foody)
       {
	while(food_on_snake==1)
	 {
	  food_on_snake=0;
	  foodx=((random(21)+1)*18)+38;
	  foody=((random(20)+1)*18)+32;
	  for (i=0;i<=length;i++)
	   {
	    if (x[i]==foodx && y[i]==foody)
	      food_on_snake=1;
	   }
	 }
	sound_timer=0;
	food(foodx,foody);
	food_on_snake=1;
	length++;
	points+=10;
	do_points(points);
       }
      sound_timer++;
      if (sound_timer<=4)
       {
	nosound();
	if (sound_timer==1 || sound_timer==3)
	  sound(random(500)+100);
       }
      head(x[0],y[0]);
      body(x[1],y[1]);
      clear_body(x[length],y[length]);
      delay(10);
      nosound();
     }
//    sound(500)
    if (lest_key!=1)
     {
      now_key=lest_key;
      lest_key=getch();
      if (lest_key!=27)
	lest_key=now_key;

     }
   // gotoxy(40,25);
   // printf("%d",lest_key);
//  if (now_key==80 && lest_key==72);  else
//  if (now_key==72 && lest_key==80);  else
//  if (now_key==75 && lest_key==77);  else
//  if (now_key==77 && lest_key==75);  else
//  if ((now_key!=80 && now_key!=72 && now_key!=75 && now_key!=77
//  && now_key!=27)  ||  lest_key==1); else
//    lest_key=now_key;
      /////////////////////////////

   }
  nosound();
  if (lest_key==1)
   {
    cleardevice();
    setcolor(4);
    settextstyle(10,0,5);
    setfillstyle(1,14);
    outtextxy(midx-180,midy-80,"Game Over!");
    settextstyle(7,0,5);
    outtextxy(midx-160,midy+5,"Your Score:");

    gotoxy(55,18);
    printf("%d",points);
    for (i=0;i<=5;i++)
     {
      sound(100);
      delay(50);
      nosound();
     }
    delay(1500);
    points=0;
   }
  else
   {
    setfillstyle(1,4);
    bar(midx-200,midy-50,midx+160,midy+50);
    setcolor(15);
    settextstyle(3,0,7);
    outtextxy(midx-190,midy-50,"SEE YA :)");
    sound(600);
    delay(200);
    sound(300);
    delay(200);
    nosound();
    delay(500);
    FFF=1;
   }
  closegraph();
							     }
 }
void body(int x,int y)
 {
  setcolor(0);
  setfillstyle(1,14);
  fillellipse(x,y,8,8);
  setcolor(1);
  ellipse(x,y,0,360,6,6);
  setcolor(14);
  ellipse(x,y,0,360,4,4);
  setcolor(1);
  ellipse(x,y,0,360,3,3);
  setcolor(14);
  ellipse(x,y,0,360,7,7);
  setcolor(1);
  ellipse(x,y,0,360,1,1);

  /*int c1=4;
  int j,c2=c1+8;
  setfillstyle(1,c1);
  setcolor(0);
  bar(x-6,y-6,x+6,y+6);
  for (j=8;j>=7;j--)
   {
    setcolor(c2);
    line(x-j,y-j,x+j,y-j);
    line(x-j,y-j,x-j,y+j);
   }*/
 }
void clear_body(int x,int y)
 {
  setfillstyle(0,0);
  bar(x-8,y-8,x+8,y+8);
 }

void net(void)
 {
  int x,y;
  for (x=56;x<=416;x+=18)
    for(y=50;y<=392;y+=18)
     {
      setcolor(1);
      rectangle(x+9,y+9,x-9,y-9);
     }
 }

void food(int x,int y)
 {
  setcolor(4);;
  setfillstyle(1,4);
  fillellipse(x,y+3,5,3);
  fillellipse(x+3,y,3,4);
  fillellipse(x-3,y,3,4);
  setcolor(2);
  setfillstyle(1,2);
//  fillellipse(x,y-4,1,3);
  line(x,y-3,x+1,y-7);
  line(x,y-3,x,y-7);
  line(x,y-3,x+1,y-5);

 /* int cc=2;
  int j,c1=cc,c2=cc+8;
  setfillstyle(1,c1);
  bar(x-6,y-6,x+6,y+6);
  for (j=8;j>=7;j--)
   {
    setcolor(c2);
    line(x-j,y-j,x+j,y-j);
    line(x-j,y-j,x-j,y+j);
   }  */
 }

void do_points(int p)
 {
  settextstyle(7,0,3);
  setcolor(14);
  outtextxy(463,100,"Points:");
//  setfillstyle(1,4);
  rectangle(548,110,590,130);
  gotoxy(70,8);
  printf("%d",p);
 }

void head(int x,int y)
 {
  setcolor(0);
  setfillstyle(1,5);
  fillellipse(x,y,8,8);
  setcolor(1);
  ellipse(x,y,0,360,6,6);
  setcolor(5);
  ellipse(x,y,0,360,4,4);
  setcolor(1);
  ellipse(x,y,0,360,3,3);
  setcolor(5);
  ellipse(x,y,0,360,7,7);
  setcolor(1);
  ellipse(x,y,0,360,1,1);
 }