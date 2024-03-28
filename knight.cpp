
#include "knight.h"
string s;
   int a[100];
string r;
   int b[100];
   int m;
   int levelO;
void display(int HP, int level, int remedy, int maidenkiss, int phoenixdown, int rescue) {
    cout << "HP=" << HP
        << ", level=" << level
        << ", remedy=" << remedy
        << ", maidenkiss=" << maidenkiss
        << ", phoenixdown=" << phoenixdown
        << ", rescue=" << rescue << endl;
}

int Read_string(int & HP, int & level,int &levelO, int &remedy, int & maidenkiss, int & phoenixdown, int & rescue,int &m,int &Max_HP)
{
    ifstream t;
   t.open("tc1_input");

    int n=0;
   istringstream iss;


       getline(t,s);
   	if(t.good())
   	{
   		iss.clear();
   		iss.str(s);
   		while(iss.good())
        {
            iss>>a[n];
            n++;
        }
	}

	  m=0;
	getline(t,r);
   	if(t.good())
   	{
   		iss.clear();
   		iss.str(r);
   		while(iss.good())
        {
            iss>>b[m];
            m++;
        }
	}

  HP=a[0];
  Max_HP=HP;
 level=a[1];
 remedy=a[2];
 maidenkiss=a[3];
 phoenixdown=a[4];
 int b;
 int i=1;



     while(i<=m)
     {
         b=i%10;
        levelO=  i > 6?(b > 5?b : 5) : b;

        if(level<levelO)
        {
            break;
        }
      i++;
     }
}

double baseDamage(double &N,int &level,int &levelO)
{
    int giatri;
  giatri=b[levelO-1];
	if(level<levelO)
    {

	switch(giatri)
	{
		case 1 : N = 1;break;
		case 2 : N = 1.5;break;
		case 3 : N= 4.5;break;
		case 4 : N= 7.5;break;
		case 5 : N=9.5;break;
	}
    }
}

int New_HP(int&HP,int &level,int levelO)
{
if(level<levelO)
{
    double N;
    baseDamage(N,level,levelO);
	double damage = N*levelO*10;

	HP=HP -(int)damage;
}
}

int New_level(int &HP,int &level,int &levelO,int &remedy,int &maidenkiss,int &phoenixdown,int &rescue)
{
    int giatri;
    int N;
  giatri =b[levelO-1];
	if(level>levelO&&giatri==6||level>levelO&&giatri==7)
	{
		level=level+2;
		if(level>10)
		{
			level=10;
		}
	}
}

int Thuocgiai(int &HP,int &level,int &levelO,int &remedy,int &maidenkiss,int &phoenixdown,int &rescue,double &N,int &m,int &Max_HP)
{
    int y;
    int giatri;
    giatri=b[levelO-1];
    if(remedy>0&&giatri==6&&level<levelO)
     	{
     		remedy--;
     		levelO++;
     		New_HP(HP,level,levelO);
		}
    else if(remedy==0&&giatri==6&&level<levelO)
        {
           if(HP<5)
               {
                 HP=1;
               }
            else
               {
                 HP=(int)HP/5;
                 while(levelO<m)
                 {
                if(levelO+3>m)
                {
                 if(HP>0)
                 {
                     levelO++;
                 }

                 New_HP(HP,level,levelO);
                 if(HP<0)
                 {
                     rescue=0;
                     break;
                 }
                 }
                 else if (levelO+3<=m)
                 {
                     int t=levelO;
                while(levelO<t+3)
                {
                     if(HP>0)
                 {
                     levelO++;
                 }

                 New_HP(HP,level,levelO);
                 if(HP<0)
                 {
                     rescue=0;
                     break;
                 }
                     }
                     HP=HP*5;
                     if(HP<0)
                 {
                     rescue=0;
                     break;
                 }
                 }
                 }

               }
        }
    if(maidenkiss>0&&giatri==7&&level<levelO)
		{
			maidenkiss--;
			levelO++;
			New_HP(HP,level,levelO);
		}
    else if(maidenkiss==0&&giatri==7&&level<levelO)
        {
            level=1;
        }
	if(HP<=0&&levelO-1<m)
	{
		if(phoenixdown>0)
		{
			HP=Max_HP;
			phoenixdown--;
		}
		else if(phoenixdown==0)
		{
		rescue =0;
     	}
	}
}


int return_rescue(int &levelO,int &m,int &HP,int &rescue)
{

    if(levelO==m&&HP>0)
    {
        rescue=1;
    }
    else if(levelO==m&&HP<=0)
    {
        rescue=0;
    }
}

int checkPos(int levelO)
{
    int HP;int level;int remedy;int maidenkiss;int phoenixdown;int rescue;
      int giatri;
      int Max_HP;
      double N;
        giatri=b[levelO];
    int y;
	 while(levelO<=m)
	 {
	if(giatri==6||giatri==7)
	 {
		 y=levelO;
	 }
	levelO++;
	Thuocgiai(HP,level,levelO,remedy,maidenkiss,phoenixdown,rescue,N,m,Max_HP);
	 }
	while((levelO-y<=3&&b[levelO-y]==6)||(levelO-y<=3&&b[levelO-y]==7))
	{
		levelO++;
	}
}

int Return_HP(int &HP,int &level,int &levelO,int &phoenixdown,int &remedy,int &maidenkiss,int &rescue)
{
    double N;
    int Max_HP;
	 if(HP<=0)
	  {
	  	Thuocgiai(HP,level,levelO,phoenixdown,remedy,maidenkiss,rescue,N,m,Max_HP);
	  }
	  //HP=HP*5;
	  if(HP>Max_HP)
	  {
	  	HP=Max_HP;
	  }

	if(HP>0&&levelO<m)
	  {
	  	levelO++;
	  }
    if(HP<0&&levelO<m)
    {
        rescue=-1;
    }
    else if(HP>0&&levelO==m)
    {
        rescue=1;
    }
}

int compare(int &HP,int &level,int &levelO,int &phoenixdown,int &remedy,int &maidenkiss,int &rescue,int &Max_HP)
{
    int N;
    int giatri;
	while(levelO<m)
	{
	  for(int i=0;i<m;i++)
      {
          giatri=b[i];
      }
	if(level>=levelO)
	{
	  levelO++;
    }
	else
	{
      New_HP(HP,level,levelO);
      Return_HP(HP,level,levelO,phoenixdown,remedy,maidenkiss,rescue);
	}

    }
}

int Fibonacci(int n)
{
	if(n==0)
	{
		return 0;
	}
	if(n==1)
	{
		return 1;
	}
	else if(n>1)
	{
		n =Fibonacci(n-1)+Fibonacci(n-2);
	}
	return n;
}

int NT(int &HP)
{
    for(int i=2;i<HP;i++)
        {
            if(HP%i==0)
            {
                return false;
            }
            return true;
        }
}

int NTGN(int &HP)
{
    int i;
    i=HP+1;
    while(NT(i)==false)
    {
        i++;
    }
    HP=i;
}

int Select_Mush(int &HP,int &level,int &levelO,int &remedy,int &maidenkiss,int &phoenixdown,int &rescue,int Max_HP)
{
    int giatri;
    giatri=b[levelO-1];

	if(giatri==11)
	{

		int n1;
        int s1=0;
		n1=(int)(((level+phoenixdown)*5/100+1)*3);
		for(int i=1;i<=n1;i++)
		{
        s1=s1+100-(2*i-1);
		}
		HP=HP +(int)(s1%100);
		NTGN(HP);
		if(HP>999)
		{
			HP=999;
		}

	}
	if(giatri==12)
	{
		int N[1000];
		N[0]=0;
		N[1]=1;
		int i=1;
		while(N[i]<HP)
        {
            N[i+1]=N[i]+N[i-1];
            i++;
        }
        HP=N[i-1];

	}
}

void DisplayMush(int &n2,string& s)
{
	ifstream Mush_ghost;
	Mush_ghost.open("tc1_mush_ghost");

	//string s;
	Mush_ghost >> n2;
	int i=0;
	while(Mush_ghost.eof()==false)
    {
        Mush_ghost >> s[i];
        i++;

        char x;
        Mush_ghost >> x;
    }
}

int Mush_ghostP1(int &HP,int& n2)
{
    string s;
    DisplayMush(n2,s);
	int maxi  =s[0];
	int mini =s[0];
	for(int i=0;i<n2;i++)
	{
		if(s[i]>maxi)
		{
			maxi=s[i];
		}
		if(s[i]<mini)
		{
			mini=s[i];
		}
	}

	HP= HP-(maxi+mini);
	return HP;
}

int Mush_ghostP2(int &HP,int &n2)
{
    string s;
	DisplayMush(n2,s);
    int i=0;
    int j=n2-1;
    int mtx;
    int mti;
   while(s[i]<s[i+1])
   {
   	i++;
   }
   while(s[j]<s[j-1])
   {
   	j--;
   }
   if(i+j==n2-1)
   {
   	mtx=s[i];
   	mti=i;
   }
   else
   {
   	mtx=-2;
   	mti=-3;
   }
   HP=HP-(mtx+mti);
   return HP;
}

int Mush_ghostP3(int &HP,int &n2)
{
    string s;
	DisplayMush(n2,s);
	int maxi2;
	int mini2;
	for(int i=0;i<n2;i++)
	{
		if(s[i]<0)
		{
			s[i]=-s[i];
			s[i]=(int)((17*s[i]+9)%257);
		}
	}
	maxi2=mini2=s[n2-1];

	for(int i=n2-1;i>0;i--)
	{
		if(s[i]>=maxi2)
		{
			maxi2=s[i];
		}
		maxi2=n2-1-i;
		if(s[i]<=mini2)
		{
			mini2=s[i];
		}
		mini2=n2-1-i;
	}
	HP= HP -(maxi2 +mini2);
	return HP;
}

int Mush_ghostP4(int &HP,int &n2)
{
    string s;
	DisplayMush(n2,s);
	int max2_3x;
	int max2_3i;
	for(int i=0;i<n2;i++)
	{
		if(s[i]<0)
		{
			s[i]=-s[i];
			s[i]=(int)((17*s[i]+9)%257);
		}
	}
	int max_i=s[0];
	int min_i=s[0];
	for(int i=0;i<=2;i++)
	{
		if(s[i]>max_i)
		{
			max_i=s[i];
		}
		if(s[i]<min_i)
		{
			min_i=s[i];
		}
		if(s[i]>=min_i&&s[i]<=max_i)
		{
		max2_3x=s[i];
		max2_3i=i;
		}

		if(max_i=max2_3x||min_i==max2_3i||max_i==min_i)
		{
			max2_3x=-5;
			max2_3i=-7;
		}

		HP= HP-(max2_3x+max2_3i);
		return HP;
	}
}

int Use_Mush_ghost(int &HP,int &levelO)
{
    int n2;
    string s;
    DisplayMush(n2,s);
   int giatri;
   giatri = b[levelO-1];

   switch(giatri)
   {
   	case 131  :  Mush_ghostP1(HP,n2); break;
   	case 132  :  Mush_ghostP2(HP,n2); break;
   	case 133  :  Mush_ghostP3(HP,n2); break;
   	case 134  :  Mush_ghostP4(HP,n2); break;
   	case 1311 : Mush_ghostP1(HP,n2); Mush_ghostP1(HP,n2) ; break;
   	case 1312 : Mush_ghostP1(HP,n2); Mush_ghostP2(HP,n2) ; break;
    case 1313 : Mush_ghostP1(HP,n2); Mush_ghostP3(HP,n2) ; break;
    case 1314 : Mush_ghostP1(HP,n2); Mush_ghostP4(HP,n2) ; break;
    case 1321 : Mush_ghostP2(HP,n2); Mush_ghostP1(HP,n2) ; break;
    case 1322 : Mush_ghostP2(HP,n2); Mush_ghostP2(HP,n2) ; break;
    case 1323 : Mush_ghostP2(HP,n2); Mush_ghostP3(HP,n2) ; break;
    case 1324 : Mush_ghostP2(HP,n2); Mush_ghostP4(HP,n2) ; break;
    case 1331 : Mush_ghostP3(HP,n2); Mush_ghostP1(HP,n2) ; break;
    case 1332 : Mush_ghostP3(HP,n2); Mush_ghostP2(HP,n2) ; break;
    case 1333 : Mush_ghostP3(HP,n2); Mush_ghostP3(HP,n2) ; break;
    case 1334 : Mush_ghostP3(HP,n2); Mush_ghostP4(HP,n2) ; break;
    case 1341 : Mush_ghostP4(HP,n2); Mush_ghostP1(HP,n2) ; break;
    case 1342 : Mush_ghostP4(HP,n2); Mush_ghostP2(HP,n2) ; break;
    case 1343 : Mush_ghostP4(HP,n2); Mush_ghostP3(HP,n2) ; break;
    case 1344 : Mush_ghostP4(HP,n2); Mush_ghostP4(HP,n2) ; break;
    default          : break;
   }
}

void Select_thuoc(int &remedy, int &maidenkiss, int &phoenixdown,int &levelO )
{
    int giatri;
    giatri =b[levelO-1];
	if(giatri==15)
	{
		remedy++;
		if(remedy>99)
		{
			remedy=99;
		}
	}
	if(giatri==16)
	{
		maidenkiss++;
		if(maidenkiss>99)
		{
			maidenkiss=99;
		}
	}
	if(giatri==17)
	{
		phoenixdown++;
		if(phoenixdown>99)
		{
			phoenixdown=99;
		}
	}
}

int Dem_thuoc(int &levelO,int &remedy,int &maidenkiss,int &phoenixdown)
{
 int giatri;
    giatri=b[levelO-1];
    if(giatri==19)
    {
	ifstream file_asclepius_pack;
	 file_asclepius_pack.open("tc1_aclepius_pack");
	 int r;
	 int c;
	 int m[100][100];
	 file_asclepius_pack>>r;
	 file_asclepius_pack>>c;
	 for(int i=0;i<r;i++)
     {
         for(int j=0;j<c;j++)
         {
             file_asclepius_pack>> m[i][j];
         }
     }
     int dem=0;
     for(int i=0;i<r;i++)
     {
         dem=0;
         for(int j=0;j<c;j++)
         {
                 if(m[i][j]==16)
                 {
                     remedy++;
                     dem++;
                 }
                 if(m[i][j]==17)
                 {
                     maidenkiss++;
                     dem++;
                 }
                 if(m[i][j]==18)
                 {
                     phoenixdown++;
                     dem++;
                 }
           while(dem==3&&j<c-1)
           {
               j=c-1;
           }
         }
     }
    }
}

int Merlin_SK18(int &HP,int &level,int &levelO,int &remedy,int &maidenkiss,int &phoenixdown,int &rescue,int &Max_HP)
{
    ifstream file_merlin_pack;
    file_merlin_pack.open("tc1_merlin_pack");
    int n1;
    istringstream iss;
    string s ;
    file_merlin_pack>>n1;

    while(!file_merlin_pack.eof())
    {
        getline(file_merlin_pack,s);
        if(file_merlin_pack.good())
        {
            file_merlin_pack>>s;
                int g=s.length();
                int dem1=0;int dem2=0;int dem3=0;int dem4=0;int dem5=0;int dem6=0;
                for(int i=0;i<g;i++)
                {
                    if(s[i]=='m'||s[i]=='M')
                    {
                    dem1++;
                    }
                    if(s[i]=='e'||s[i]=='E')
                    {
                    dem2++;
                    }
                    if(s[i]=='r'||s[i]=='R')
                    {
                    dem3++;
                    }
                    if(s[i]=='l'||s[i]=='L')
                    {
                    dem4++;
                    }
                    if(s[i]=='i'||s[i]=='I')
                    {
                    dem5++;
                    }
                    if(s[i]=='n'||s[i]=='N')
                    {
                    dem6++;
                    }
                }
                if(dem1>0&&dem2>0&&dem3>0&&dem4>0&&dem5>0&&dem6>0)
                {
                    HP=HP+2;
                    if(HP>Max_HP)
                    {
                        HP=Max_HP;
                    }
                }
        }
    }
}

int Display_const(int &HP,int &level,int &levelO,int &remedy,int &maidenkiss,int &phoenixdown,int &rescue)
{
            HP=a[0];
            level=a[1];
            remedy=a[2];
             maidenkiss=a[3];
             phoenixdown=a[4];
             rescue=1;
}

int Displayno_const(int &HP,int &level,int &levelO,int &remedy,int &maidenkiss,int &phoenixdown,int &rescue)
{
            HP=a[0];
            level=a[1];
            remedy=a[2];
             maidenkiss=a[3];
             phoenixdown=a[4];
             rescue=0;
}

int Arthur(int &HP,int &level,int &levelO,int &remedy,int &maidenkiss,int &phoenixdown,int &rescue,int &Max_HP)
{
    if(b[0]==999)
        {
            Display_const(HP,level,levelO,remedy,maidenkiss,phoenixdown,rescue);
        }
}

int Lancelot(int &HP,int &level,int &levelO,int &remedy,int &maidenkiss,int &phoenixdown,int &rescue,int &Max_HP)
{
    for(int i=2;i<Max_HP;i++)
    {
        if(Max_HP%i!=0||Max_HP==1)
        {
            if(levelO>=1&&levelO<=7&&levelO<m)
            {
            levelO++;
            }
            if(levelO==m)
            {
            Display_const(HP,level,levelO,remedy,maidenkiss,phoenixdown,rescue);
            }
            return Max_HP;
        }
        else if(Max_HP%i==0)
        {
            return false;
        }
    }
}

int Browser(int &HP,int &level,int &levelO,int &remedy,int &maidenkiss,int &phoenixdown,int &rescue,int &Max_HP)
{
    int N;
    int giatri;
    giatri =b[levelO-1];
  if(giatri==99)
  {
    if(level==10&&Max_HP!=Lancelot(HP,level,levelO,remedy,maidenkiss,phoenixdown,rescue,Max_HP)||level>=8&&Max_HP==Lancelot(HP,level,levelO,remedy,maidenkiss,phoenixdown,rescue,Max_HP))
    {
        if(levelO<m)
        {
            levelO++;
        }
        level=10;
        if(levelO==m)
        {
            Display_const(HP,level,levelO,remedy,maidenkiss,phoenixdown,rescue);
        }
    }
    else if(level<10&&Max_HP!=Lancelot(HP,level,levelO,remedy,maidenkiss,phoenixdown,rescue,Max_HP)||level<8&&Max_HP==Lancelot(HP,level,levelO,remedy,maidenkiss,phoenixdown,rescue,Max_HP))
    {
         Displayno_const(HP,level,levelO,remedy,maidenkiss,phoenixdown,rescue);
    }
  }
}

int Kill_Brower(int &HP,int &level,int &levelO,int &remedy,int &maidenkiss,int &phoenixdown,int &rescue,int &Max_HP)
{

    for(int i=0;i<m;i++)
    {
        if(b[i]==0)
        {
            Displayno_const(HP,level,levelO,remedy,maidenkiss,phoenixdown,rescue);
        }
    }
    Arthur(HP,level,levelO,remedy,maidenkiss,phoenixdown,rescue,Max_HP);
    Lancelot(HP,level,levelO,remedy,maidenkiss,phoenixdown,rescue,Max_HP);
    Browser(HP,level,levelO,remedy,maidenkiss,phoenixdown,rescue,Max_HP);
    Dem_thuoc(levelO,remedy,maidenkiss,phoenixdown);
    Merlin_SK18(HP,level,levelO,remedy,maidenkiss,phoenixdown,rescue,Max_HP);
}


void adventureToKoopa(string file_input, int & HP, int & level, int & remedy, int & maidenkiss, int & phoenixdown, int & rescue) {
    int levelO;
int Max_HP;
 Read_string(HP,level,levelO,remedy,maidenkiss, phoenixdown, rescue,m,Max_HP);
double N;
int giatri;
int n2;
baseDamage(N,level,levelO);
New_HP(HP,level,levelO);
New_level(HP,level,levelO,remedy,maidenkiss, phoenixdown, rescue);
Thuocgiai(HP,level,levelO,remedy,maidenkiss, phoenixdown,rescue,N,m,Max_HP);
return_rescue(levelO,m,HP,rescue);
Select_Mush(HP,level,levelO,remedy,maidenkiss, phoenixdown,rescue,Max_HP);
Use_Mush_ghost(HP,levelO);
Select_thuoc(remedy,maidenkiss,phoenixdown,levelO);
Kill_Brower(HP,level,levelO,remedy,maidenkiss, phoenixdown,rescue,Max_HP);
display(HP,level,remedy,maidenkiss,phoenixdown,rescue);

}


