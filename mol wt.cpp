// Copyright © Dr. Suvojit Hazra, 2024 under MIT Licence.

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>


using namespace std;


int main(int argc, char *argv[])
{
    string s,s1, temp, elem[100],ch,ch1[200],temp1,temp2,ch2[200],ch3,element[100],x;
    int a=0,b=0,i=0,j=0,k=0,p=0,atno[200],y,count=0,minus;
	double molwt=0,awt[200],value,ano;
	float atwt=0,mwt=0;
    cout<<"Enter the molecular formula: ";
    cin>>s;
    y=s.length();
    for(int d=0;d<y;d++)
    {
    	if((s[d]>=48 && s[d]<=57)||(s[d]>=65 && s[d]<=90)||(s[d]>=97 && s[d]<=122))
    	{
    		count++;
    	}
    }
    minus=y-count;
    if(minus!=0)
    {
    	cout<<"Please put the right Molecular formula "<<endl;
    	
    }
    else
   { 
    s1=s;
    while(i<s.length())
    {
                       elem[k]="";
                       temp="";    
                       if(i>0 && (s[i]>=65 && s[i]<=90))
                       {
                              for(j=0; j<i;j++)
                              {
                                      elem[k]+=s[j];
                              }
                              for(j=i; j<s.length();j++)
                              {
                                      temp+=s[j];
                              }
                              s=temp;
                              i=0;
                              k++;
                       }
                       i++;
    }
    elem[k]=s;
    k=0;
    while(!elem[k].empty())
    {
    	int a=0;
    	int z=elem[k].length();
    	if(!(elem[k][z-1]>=48 && elem[k][z-1]<=57))
    	{
    		elem[k]+=49;
    	}
    	int z1=elem[k].length();
    	while(a<z1)
            {
            	element[p]="";
    			temp1="";
           		 if(a>0 && (elem[k][a]>=48 && elem[k][a]<=57))
           		{
           			for(b=0;b<a;b++)
           			{
           				element[p]+=elem[k][b];
           			}
           			cout<<"Symbol of the element= "<<element[p]<<endl;
           			ifstream fin("atom_specification.txt",ios::in);
           			{
           				for(int c=0;c<107;c++)
           				{
           					fin>>atno[c]>>ch1[c]>>ch2[c]>>awt[c];
           					getline (fin,ch3);
           					if(ch2[c]==element[p])
           					{
           						atwt=awt[c];
           						cout<<"Name of the element= "<<ch1[c]<<endl;
           					}
           					
           		}
           	 	}  		
           			for(b=a;b<z1;b++)
           			{
           				temp1+=elem[k][b];
           				
           		}
           	
           			temp2=temp1;
           			cout<<"atomic weight of "<<element[p]<<" is = "<<atwt<<endl;
           			cout<<"No. of atom/s= "<<temp2<<endl;
           			stringstream ss(temp2);
           			ss>>ano;
           			value=atwt*ano;
           			cout<<"the total atomic weight is= "<<"< "<<value<<" >"<<endl;
           			molwt=molwt+atwt*ano;
           			break;
           			a=0;
           			p++;
           		}
           		
           		a++;
            }
         k++;
    }
    cout<<"\n \n The Molecular Weight of "<<s1<<"  is= "<<molwt<<" gm/mol"<<endl;
    cout<<"\n Thank you for compiling...\n"<<endl;
}

    system("PAUSE");
    return EXIT_SUCCESS;
}
