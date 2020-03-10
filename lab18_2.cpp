//Modify function overlap() form lab18_1.cpp by using pointers as input arguments.
#include<iostream>
using namespace std;

struct Rect{
	double x,y,w,h;
};

double overlap(Rect *,Rect *);

int main(){
	Rect R1,R2;
	cout << "Please input Rect 1 (x y w h): ";
	cin>>R1.x>>R1.y>>R1.w>>R1.h;
	cout << "Please input Rect 2 (x y w h): ";
	cin>>R2.x>>R2.y>>R2.w>>R2.h;
	
	cout << "Overlap area = "<<overlap(&R1,&R2);	
	return 0;
}
double overlap(Rect *r1,Rect *r2){
/*	double wid,hi,area;
	if(r1->x<r2->x){
		
			wid= r1->x+r1->w-r2->x;
			if(r1->x+r1->w>r2->x+r2->w){
				wid=r2->w;
			}
		if(r1->y<r2->y){
			hi=r2->h-r1->y;
			if(r2->y-r2->h<r1->y-r1->h){
				hi=r1->h;
			}
		}
		
		if(r1->y>r2->y){
			hi=r1->h-r2->y;
			if(r1->y-r1->h<r2->y-r2->h){
				hi=r2->h;
			}
		}
			
	}else{
			wid= r2->x+r2->w-r1->x;
			if(r2->x+r2->w>r1->x+r1->w){
				wid=r1->w;
			}
		if(r2->y<r1->y){
			hi=r1->h-r2->y;
			if(r1->y-r1->h<r2->y-r2->h){
				hi=r2->h;
			}
		}
		
		if(r2->y>r1->y){
			hi=r2->h-r1->y;
			if(r2->y-r2->h<r1->y-r1->h){
				hi=r1->h;
			}
		}
	}

	
	//cout<<wid<<" "<<hi<<endl;
	
	if(wid<0){
		wid=0;
	}
	if(hi<0){
		hi=0;
	}
	area=wid*hi;*/
	
	double wid,hi,area,widr,widl,hu,hd;
	widr=max(r1->x,r2->x);
	widl=min(r1->x+r1->w,r2->x+r2->w);
	hu=max(r1->y-r1->h,r2->y-r2->h);
	hd=min(r1->y,r2->y);
	wid=widl-widr;
	hi=hd-hu;
	
	if(wid<0){
		wid=0;
	}
	if(hi<0){
		hi=0;
	}
	area=wid*hi;
	return area;
}
