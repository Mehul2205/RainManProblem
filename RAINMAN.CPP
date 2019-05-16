/* This Code is Created by Mehul Patni using turbo c++
Last Update date - 16/05/2019

This is a c++ code which is based upon the concept of Kinematics "Rain Man Problem".
It helps students to visualize the problem and get the accurate solution in seconds.
*/


#include<stdio.h>
#include<graphics.h>
#include<iostream.h>
#include<conio.h>
#include<dos.h>
#include<stdlib.h>
#define ScreenWidth getmaxx()
#define ScreenHeight getmaxy()
#define GroundY ScreenHeight*0.8
#include<time.h>
#include<dos.h>
#include<math.h>
#define PI 3.14159265

int ldisp=0;
void DrawManAndUmbrella(int x,int ldisp, int theta)
{
	//head
	circle(x,GroundY-90,10);
	line(x,GroundY-80,x,GroundY-30);

	//hand
	line(x,GroundY-70,x+10,GroundY-60);
	line(x,GroundY-65,x+10,GroundY-55);
	line(x+10,GroundY-60,x+20,GroundY-70);
	line(x+10,GroundY-55,x+20,GroundY-70);

	//legs
	line(x,GroundY-30,x+ldisp,GroundY);
	line(x,GroundY-30,x-ldisp,GroundY);

	//umbrella
	if(theta >= 0){
		pieslice(x+20-abs(50*sin(theta)) , GroundY-70-abs(50*cos(theta)),theta,180+theta,40);
		line( x+20-abs(50*sin(theta)) , GroundY-70-abs(50*cos(theta)) , x+20 , GroundY-70);
	}

	else{
		pieslice(x+20-50*sin(theta) , GroundY-70-50*cos(theta),360+theta,360,40);
		pieslice(x+20-50*sin(theta) , GroundY-70-50*cos(theta),0,180+theta,40);
		line( x+20-50*sin(theta) , GroundY-70-50*cos(theta) , x+20 , GroundY-70);
	}
}

void Rain(int x, int RX, int RY, int theta)
{
	int i,rx,ry;
	for(i=0;i<400;i++)
	{
		//Random Rain On Screen
		rx=rand() % ScreenWidth;
		ry=rand() % ScreenHeight;
		if(ry<GroundY-RY)
		{
			if(ry<GroundY-120 || (ry>GroundY-120 && (rx<x-20-abs(50*sin(abs(theta))) || rx>x+20+abs(50*sin(abs(theta))))))
				line(rx,ry,rx+RX,ry+RY);
		}
	}
}
void printLetter()            // Screen 1
{
	cout<<"\n\n\n\n\n\n\n\n";
	for (int i =0; i<7 ; i++)
	{
		cout<<"\t\t   ";
		// To Print R Letter
		for(int j =0; j<7; j++)
		{
			if(i == 0 || i ==2 || j ==0 || j == 6 && i <= 2 || j == i-1 && i >= 2)
				cout<<"*";
			else
				cout<<" ";
			delay(50);
		}
		cout<<"     \t";

		// To Print M Letter
		for(j =0; j<7; j++)
		{
			if(i == j && i<=3 || j==6-i && i<=3 || j==0 || j==6)
				cout<<"*";
			else
				cout<<" ";
			delay(100);
		}
		cout<<"   \t";

		// To print P Letter
		for(j =0; j<7; j++)
		{
			if(i == 0 || i==2 || j==0 || j==6 && i<=2)
				cout<<"*";
			else
				cout<<" ";
			delay(50);
		}
		cout<<endl;
	}
}

void main()
{
	int gd=DETECT,gm,x=0;
	//Change BGI directory according to yours
	initgraph(&gd,&gm,"C:\\TurboC3\\BGI");
	printLetter();
	sleep(2);
	clrscr();
	cleardevice();
	int rmx,rmy,mx,rm;
	float rv,theta,fi;
	cout<<"\n\n\n\t***************Rain Man Problem***************";         //Ask Question  & Get Solution
	cout<<endl;
	cout<<"\n\nEnter Velocity of rain in x Direction w.r.t man --> ";
	cin>>rmx;
	cout<<"Enter Velocity of rain in y Direction w.r.t man --> ";
	cin>>rmy;
	cout<<"Enter velocity of Man in x Direction --> ";
	cin>>mx;

	// Calculating Velocity of Actual Rain and Angle of inclinatiion
	rm = mx + rmx;
	rv = sqrt( abs(rm)*abs(rm) + rmy*rmy );
	theta =atan2(rm,rmy) * 180/PI;
	cout<<"\nTherefore, Velocity of rain is -->  "<<rv;
	cout<<"\nAngle forming with vertical(Y) axis is --> "<<theta;
	fi = 180*atan2(rmx,rmy)/PI;
	delay(1000);

	clrscr();
	cleardevice();
	cout<<"\nActual Seen :- ";
	delay(1000);
	cleardevice();
	while(!kbhit() && mx>0)           // Screen 3
	{
		line(0,GroundY,ScreenWidth,GroundY);
		Rain(x,rm,rmy,theta);
		ldisp=(ldisp+mx)%30;
		DrawManAndUmbrella(x,ldisp,theta);
		delay(75);
		cleardevice();
		x=(x+5)%ScreenWidth;
	}

	clrscr();
	cleardevice();
	cout<<"\nView w.r.t Man :- ";                 // Screen 4
	delay(1000);
	cleardevice();
	x = ScreenWidth/2;
	line(0,GroundY,ScreenWidth,GroundY);
	Rain(x,rmx,rmy,fi);
	DrawManAndUmbrella(x,ldisp,fi);
	sleep(4);
	getch();
}