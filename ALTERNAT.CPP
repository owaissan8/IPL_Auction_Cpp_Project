#include<iostream.h>
#include<dos.h>
#include<conio.h>
#include<stdlib.h>
#include<stdio.h>
#include<fstream.h>
#include<string.h>

struct player
{
	char name[30];
	int age;
	char desg[30];
};


class ipl
{
	player pl;
	char line[80];
	int p1, p2, p3, p4, b, rr, csk, mi, kkr, rcb, max, n;
	int g1[20], g2[20], g3[20], g4[20];

	public:
		ipl()
		{
			p1=p2=p3=p4=0;
			b=900;
			rr=csk=mi=kkr=rcb=0;
			max=0;
			n=0;
		}
		void set_team();
		void addtog1(int);
		void addtog2(int);
		void addtog3(int);
		void addtog4(int);
		int  checkg1(int);
		int  checkg2(int);
		int  checkg3(int);
		int  checkg4(int);
		void view_batsman();
		void view_bowler();
		void view_allrounder();
		void view_wicketk();
		void view_team();
};

void ipl::addtog1(int y)
{
	g1[p1]=y;
	p1++;
}

int ipl::checkg1(int q)
{
	for(int f=0;f<p1-1;f++)
	{
		if(g1[f]==q)
		{
		       return 0;
		}
	}

      return 1;

}

void ipl::addtog2(int y)
{
	g2[p2]=y;
	p2++;
}

int ipl::checkg2(int q)
{
	for(int f=0;f<p2-1;f++)
	{
		if(g2[f]==q)
		{
		       return 0;
		}
	}
	return 1;
}

void ipl::addtog3(int y)
{
	g3[p3]=y;
	p3++;
}

int ipl::checkg3(int q)
{
	for(int f=0;f<p3-1;f++)
	{
		if(g3[f]==q)
		{
			return 0;
		}
	}
	return 1;

}

void ipl::addtog4(int y)
{
	g4[p4]=y;
	p4++;
}

int ipl::checkg4(int q)
{
	for(int f=0;f<p4-1;f++)
	{
		if(g4[f]==q)
		{
		       return 0;
		}
	}

	return 1;

}

void ipl::set_team()
{
	if(n==1)
	{
		ofstream fin1;
		fin1.open("teamrr.txt",ios::binary|ios::app);
		if(!fin1)
		{
			cout<<"Can't open fin 1...";
			getch();
			return;
		}
		fin1.write((char*)&pl,sizeof(pl));
	}

	else if(n==2)
	{
		ofstream fin2;
		fin2.open("teamcsk.txt",ios::binary|ios::app);
		if(!fin2)
		{
			cout<<"Can't open fin 2...";
			getch();
			return;
		}
		fin2.write((char*)&pl,sizeof(pl));
	}

	else if(n==3)
	{
		ofstream fin3;

		fin3.open("teammi.txt",ios::binary|ios::app);
		if(!fin3)
		{
			cout<<"Can't open fin 3...";
			getch();
			return;
		}
		fin3.write((char*)&pl,sizeof(pl));
	}

	else if(n==4)
	{
		ofstream fin4;
		fin4.open("teamkkr.txt",ios::binary|ios::app);
		if(!fin4)
		{
			cout<<"Can't open fin 4...";
			getch();
			return;
		}
		fin4.write((char*)&pl,sizeof(pl));
	}

	else if(n==5)
	{
		ofstream fin5;
		fin5.open("teamrcb.txt",ios::binary|ios::app);
		if(!fin5)
		{
			cout<<"Can't open fin 5...";
			getch();
			return;
		}
		fin5.write((char*)&pl,sizeof(pl));
	}
}

void ipl::view_batsman()
{
	fstream file1;
	file1.open("batsman.txt",ios::binary|ios::in|ios::app);
	if(!file1)
	{
		cout<<"Can't open file 1...";
		getch();
		return;
	}

	int s=16;
	int o=0;
	do
	{
		o=random(s);		    //16 batsmen
		if(checkg1(o)==1)
		{
			for(int i=0;i<=o;i++)
			{
				file1.read((char*)&pl,sizeof(pl));
			}
			addtog1(o);
			delay(500);
			cout<<endl;
			cout<<"\n\n\t"<<pl.name<<"\t\t"<<"Age :	"<<pl.age<<"\t"<<pl.desg;
			cout<<endl;
			rr=50+random(b);
			csk=50+random(b);
			mi=50+random(b);
			kkr=50+random(b);
			rcb=50+random(b);
			cout<<"\n\n\tBID OF RAJASTHAN ROYALS : "<<rr;
			cout<<"\n\n\tBID OF CHENNAI SUPER KINGS : "<<csk;
			cout<<"\n\n\tBID OF MUMBAI INDIANS : "<<mi;
			cout<<"\n\n\tBID OF KOLKATA KNIGHT RIDERS : "<<kkr;
			cout<<"\n\n\tBID OF ROYAL CHALLENGERS BANGALORE:"<<rcb;
			max=50; n=1;
			if(rr>max)
			{
				max=rr;
			}
			if(csk>max)
			{
				max=csk;
				n=2;
			}
			if(mi>max)
			{
				max=mi;
				n=3;
			}
			if(kkr>max)
			{
				max=kkr;
				n=4;
			}
			if(rcb>max)
			{
				max=rcb;
				n=5;
			}
			set_team();
			char set[30];
			if(n==1)
			      strcpy(set,"RAJASTHAN ROYALS");
			else if(n==2)
			      strcpy(set,"CHENNAI SUPER KINGS");
			else if(n==3)
				strcpy(set,"MUMBAI INDIANS");
			else if(n==4)
			      strcpy(set,"KOLKATA KNIGHT RIDERS");
			else if(n==5)
			      strcpy(set,"ROYAL CHALLENGERS BANGALORE");


			cout<<"\n\nHighest Bid : "<<max;
			cout<<"\n\nThe player is sold to Team : "<<set;

		}
	}while(checkg1(o)!=1);
	file1.close();
}


void ipl::view_bowler()
{
	fstream file2;
	file2.open("bowler.txt",ios::binary|ios::in|ios::out);
	if(!file2)
	{
		cout<<"Can't open file 2...";
		getch();
		return;
	}
	int q=16;
	int o=0;
	do
	{ 				  //16 bowlers
		int o=random(q);
		if(checkg2(o)==1)
		{
			for(int i=0;i<=o;i++)
			{
				file2.read((char*)&pl,sizeof(pl));
			}
			addtog2(o);
			delay(500);
			cout<<endl;
			cout<<"\n\n"<<pl.name<<"\t\t"<<"Age : "<<pl.age<<"\t\t"<<pl.desg;
			cout<<endl;
			int rr=30+random(b);
			int csk=30+random(b);
			int mi=30+random(b);
			int kkr=30+random(b);
			int rcb=30+random(b);
			cout<<"\n\n\tBID OF RAJASTHAN ROYALS : "<<rr;
			cout<<"\n\n\tBID OF CHENNAI SUPER KINGS : "<<csk;
			cout<<"\n\n\tBID OF MUMBAI INDIANS : "<<mi;
			cout<<"\n\n\tBID OF KOLKATA KNIGHT RIDERS : "<<kkr;
			cout<<"\n\n\tBID OF ROYAL CHALLENGERS BANGALORE "<<rcb;
			max=30; n=1;
			if(rr>max)
			{
				max=rr;
			}
			if(csk>max)
			{
				max=csk;
				n=2;
			}
			if(mi>max)
			{
				max=mi;
				n=3;
			}
			if(kkr>max)
			{
				max=kkr;
				n=4;
			}
			if(rcb>max)
			{
				max=rcb;
				n=5;
			}
			set_team();
			char set[30];
			if(n==1)
			      strcpy(set,"RAJASTHAN ROYALS");
			else if(n==2)
			      strcpy(set,"CHENNAI SUPER KINGS");
			else if(n==3)
				strcpy(set,"MUMBAI INDIANS");
			else if(n==4)
			      strcpy(set,"KOLKATA KNIGHT RIDERS");
			else if(n==5)
			      strcpy(set,"ROYAL CHALLENGERS BANGALORE");


			cout<<"\n\nHighest Bid : "<<max;
			cout<<"\n\nThe player is sold to Team : "<<set;

		}
	}while(checkg2(o)!=1);
	file2.close();

}





void ipl::view_allrounder()
{
	fstream file3;
	file3.open("allrounder.txt",ios::binary|ios::in|ios::out);
	if(!file3)
	{
		cout<<"Can't open file 3...";
		getch();
		return;
	}

	int l=16;
	int o=0;
	do
	{ 				  //10 allrounders
		int o=random(l);
		if(checkg3(o)==1)
		{
			for(int i=0;i<=o;i++)
			{
				file3.read((char*)&pl,sizeof(pl));
			}
			addtog3(o);
			delay(500);
			cout<<endl;
			cout<<"\n\n"<<pl.name<<"\t\t"<<"Age : "<<pl.age<<"\t\t"<<pl.desg;
			cout<<endl;
			int rr=40+random(b);
			int csk=40+random(b);
			int mi=40+random(b);
			int kkr=40+random(b);
			int rcb=40+random(b);
			cout<<"\n\n\tBID OF RAJASTHAN ROYALS : "<<rr;
			cout<<"\n\n\tBID OF CHENNAI SUPER KINGS : "<<csk;
			cout<<"\n\n\tBID OF MUMBAI INDIANS : "<<mi;
			cout<<"\n\n\tBID OF KOLKATA KNIGHT RIDERS : "<<kkr;
			cout<<"\n\n\tBID OF ROYAL CHALLENGERS BANGALORE "<<rcb;
			max=40; n=1;
			if(rr>max)
			{
				max=rr;
			}
			if(csk>max)
			{
				max=csk;
				n=2;
			}
			if(mi>max)
			{
				max=mi;
				n=3;
			}
			if(kkr>max)
			{
				max=kkr;
				n=4;
			}
			if(rcb>max)
			{
				max=rcb;
				n=5;
			}
			set_team();
			char set[30];
			if(n==1)
			      strcpy(set,"RAJASTHAN ROYALS");
			else if(n==2)
			      strcpy(set,"CHENNAI SUPER KINGS");
			else if(n==3)
				strcpy(set,"MUMBAI INDIANS");
			else if(n==4)
			      strcpy(set,"KOLKATA KNIGHT RIDERS");
			else if(n==5)
			      strcpy(set,"ROYAL CHALLENGERS BANGALORE");


			cout<<"\n\nHighest Bid : "<<max;
			cout<<"\n\nThe player is sold to Team : "<<set;

		}
	}while(checkg3(o)!=1);
	file3.close();

}


void ipl::view_wicketk()
{
	fstream file4;
	file4.open("wicketk.txt",ios::binary|ios::in|ios::out);
	if(!file4)
	{
		cout<<"Can't open file 4...";
		getch();
		return;
	}

	int w=5;
	int o=0;
	do
	{ 				  //5 wicketkeepers
		int o=random(w);
		if(checkg4(o)==1)
		{
			for(int i=0;i<=o;i++)
			{
				file4.read((char*)&pl,sizeof(pl));
			}
			addtog4(o);
			delay(500);
			cout<<endl;
			cout<<"\n\n"<<pl.name<<"\t\t"<<"Age :"<<pl.age<<"\t\t"<<pl.desg;
			cout<<endl;
			int rr=30+random(b);
			int csk=30+random(b);
			int mi=30+random(b);
			int kkr=30+random(b);
			int rcb=30+random(b);
			cout<<"\n\n\tBID OF RAJASTHAN ROYALS : "<<rr;
			cout<<"\n\n\tBID OF CHENNAI SUPER KINGS : "<<csk;
			cout<<"\n\n\tBID OF MUMBAI INDIANS : "<<mi;
			cout<<"\n\n\tBID OF KOLKATA KNIGHT RIDERS : "<<kkr;
			cout<<"\n\n\tBID OF ROYAL CHALLENGERS BANGALORE "<<rcb;
			max=30; n=1;
			if(rr>max)
			{
				max=rr;
			}
			if(csk>max)
			{
				max=csk;
				n=2;
			}
			if(mi>max)
			{
				max=mi;
				n=3;
			}
			if(kkr>max)
			{
				max=kkr;
				n=4;
			}
			if(rcb>max)
			{
				max=rcb;
				n=5;
			}
			set_team();
			char set[30];
			if(n==1)
			      strcpy(set,"RAJASTHAN ROYALS");
			else if(n==2)
			      strcpy(set,"CHENNAI SUPER KINGS");
			else if(n==3)
				strcpy(set,"MUMBAI INDIANS");
			else if(n==4)
			      strcpy(set,"KOLKATA KNIGHT RIDERS");
			else if(n==5)
			      strcpy(set,"ROYAL CHALLENGERS BANGALORE");


			cout<<"\n\nHighest Bid : "<<max;
			cout<<"\n\nThe player is sold to Team : "<<set;

		}
	}while(checkg4(o)!=1);
	file4.close();

}


void ipl::view_team()
{

	fstream fin1;
	fin1.open("teamrr.txt",ios::binary|ios::in|ios::out);
	if(!fin1)
	{
		cout<<"Can't open fin 1...";
		getch();
		return;
	}

	fstream fin2;
	fin2.open("teamcsk.txt",ios::binary|ios::in|ios::out);
	if(!fin2)
	{
		cout<<"Can't open fin 2...";
		getch();
		return;
	}

	fstream fin3;
	fin3.open("teammi.txt",ios::binary|ios::in|ios::out);
	if(!fin3)
	{
		cout<<"Can't open fin 3...";
		getch();
		return;
	}

	fstream fin4;
	fin4.open("teamkkr.txt",ios::binary|ios::in|ios::out);
	if(!fin4)
	{
		cout<<"Can't open fin 4...";
		getch();
		return;
	}

	fstream fin5;
	fin5.open("teamrcb.txt",ios::binary|ios::in|ios::out);
	if(!fin5)
	{
		cout<<"Can't open fin 5...";
		getch();
		return;
	}
	int ch;
	do
	{
		clrscr();
		cout<<"\n\n---------------------IPL TEAMS 2018------"
		<<"-----------\n\n"
		<<"\n\n\t\t1. Rajasthan Royals  (RR)"
		<<"\n\n\t\t2. Chennai Super Kings  (CSK)"
		<<"\n\n\t\t3. Mumbai Indians   (MI)"
		<<"\n\n\t\t4. Kolakata Knight Riders  (KKR)"
		<<"\n\n\t\t5. Royal Challengers Bangalore   (RCB)"
		<<"\n\n\t\t6. Back"
		<<"\n\n\t\tEnter your choice : ";cin>>ch;

		switch(ch)
		{
			case 1:clrscr();
			       cout<<"-----RAJASTHAN ROYALS-----"<<endl;
			       cout<<"      NAME              AGE           JOB        "<<endl;
			       fin1.seekg(0,ios::end);
			       int v1=fin1.tellg();
			       fin1.seekg(0);
			       while(fin1.tellg()!=v1)
			       {
					fin1.read((char*)&pl,sizeof(pl));
					cout<<pl.name<<"\t"<<pl.age<<"\t"<<pl.desg;
					cout<<endl;
			       }
			       break;

			case 2:clrscr();
			       cout<<"-----CHENNAI SUPER KINGS-----"<<endl;
			       cout<<"      NAME              AGE           JOB   "<<endl;
			       fin2.seekg(0,ios::end);
			       int v2=fin2.tellg();
			       fin2.seekg(0);
			       while(fin2.tellg()!=v2)
			       {
					fin2.read((char*)&pl,sizeof(pl));
					cout<<pl.name<<"\t\t"<<pl.age<<"\t"<<pl.desg;
					cout<<endl;
			       }
			       break;
			case 3:clrscr();
			       cout<<"-----MUMBAI INDIANS-----"<<endl;
			       cout<<"      NAME              AGE           JOB  "<<endl;
			       fin3.seekg(0,ios::end);
			       int v3=fin3.tellg();
			       fin3.seekg(0);
			       while(fin3.tellg()!=v3)
			       {
					fin3.read((char*)&pl,sizeof(pl));
					cout<<pl.name<<"\t\t"<<pl.age<<"\t"<<pl.desg;
					cout<<endl;
			       }
			       break;
			case 4:clrscr();
			       cout<<"-----KOLKATA KNIGHT RIDERS-----"<<endl;
			       cout<<"      NAME              AGE           JOB  "<<endl;
			       fin4.seekg(0,ios::end);
			       int v4=fin4.tellg();
			       fin4.seekg(0);
			       while(fin4.tellg()!=v4)
			       {
					fin4.read((char*)&pl,sizeof(pl));
					cout<<pl.name<<"\t\t"<<pl.age<<"\t"<<pl.desg;
					cout<<endl;
			       }
			       break;
			case 5:clrscr();
			       cout<<"-----ROYAL CHALLENGERS BANGALORE-----"<<endl;
			       cout<<"      NAME              AGE           JOB  "<<endl;
			       fin5.seekg(0,ios::end);
			       int v5=fin5.tellg();
			       fin5.seekg(0);
			       while(fin5.tellg()!=v5)
			       {
					fin5.read((char*)&pl,sizeof(pl));
					cout<<pl.name<<"\t\t"<<pl.age<<"\t"<<pl.desg;
					cout<<endl;
			       }
			       break;
			case 6:break;
		       default:cout<<"\n\nWrong choice....";
			       break;
		}
		cout<<"\n\nPress any key to continue...";
		getch();
	}while(ch!=6);
	fin1.close();
	fin2.close();
	fin3.close();
	fin4.close();
	fin5.close();
}

void main()
{
   clrscr();
   ipl h;
   int ch,k;
   remove("teamrr.txt");
   remove("teamcsk.txt");
   remove("teammi.txt");
   remove("teamkkr.txt");
   remove("teamrcb.txt");

   do
   {
	clrscr();
	cout<<"\n\n-------------------INDIAN PREMIER LEAGUE 2018-------------------\n\n"
	<<"\n\n\t\t1. Auction Menu"
	<<"\n\n\t\t2. Team Squads"
	<<"\n\n\t\t3. Exit"
	<<"\n\n\t\tEnter your choice : ";cin>>k;

	switch(k)
	{
		case 1: do
			{
				clrscr();
				cout<<"\n\n---------------------IPL AUCTION 2018---------------------\n\n"
				<<"\n\n\t\t1. Batsman        (Base price : 50 lac)"
				<<"\n\n\t\t2. Bowler         (Base price : 30 lac)"
				<<"\n\n\t\t3. All Rounder    (Base price : 40 lac)"
				<<"\n\n\t\t4. Wicketkeeper   (Base price : 30 lac)"
				<<"\n\n\t\t5. Back"
				<<"\n\n\t\tEnter your choice : ";cin>>ch;

				switch(ch)
				{
					case 1: h.view_batsman();
						break;
					case 2: h.view_bowler();
						break;
					case 3: h.view_allrounder();
						break;
					case 4: h.view_wicketk();
						break;
					case 5: break;
				       default: cout<<"\n\nWrong choice....";
						break;
				}
				cout<<"\n\nPress any key to continue...";
				getch();
			}while(ch!=5);
			break;
		case 2 :h.view_team();
			break;
		case 3 :break;
		default:cout<<"\n\nWrong choice....";
			break;

	}
   }while(k!=3);
   getch();

}
