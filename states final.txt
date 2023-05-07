#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int main()
{
    ofstream outdata;
    outdata.open("sample.csv");
    int arr[5][5][5],i,j,k,a,b,c,option=0,state,quarter,att,year;
    int enter_S_no,enter_semsester,chosen_attribute;
    const char* years[10]={"2017","2018","2019","2020","2021"};
    const char* states[10]={"Assam","Kerela","Goa"};
    const char* column_val[10]={"q1","q2","q3","q4"};

    cout<<"Tourists in States"<<endl;
    cout<<"enter the dimensions"<<endl;
    cout<<"*************************"<<endl;
    cout<<"enter the size of the year dimensions"<<endl;
    cin>>a;
    cout<<"enter the size of the state dimensions"<<endl;
    cin>>b;
    cout<<"enter the size of the quarter attributes"<<endl;
    cin>>c;
    for(i=0;i<a;i++)
    {
        for(j=0;j<b;j++)
        {
            for(k=0;k<c;k++)
            {
                cout<<"enter the quarter attributes "<<column_val[k]<<" of state: "<<states[j]<<" in year: "<<years[i]<<endl;
                cout<<"location\t"<<i<<"\t"<<j<<"\t"<<k<<endl;
                cin>>arr[i][j][k];
            }
        }
    }
    outdata<<"Data Representation"<<endl;
    for(i=0;i<a;i++)
    {
        for(j=0;j<b;j++)
        {
            for(k=0;k<c;k++)
            {

                cout<<arr[i][j][k]<<"\t";
                outdata<<arr[i][j][k]<<"\t";
            }
            cout<<"\t";
            outdata<<"\t";
        }
        cout<<"\n";
        outdata<<"\n";

    }outdata<<"\n";



      do
    {
        cout<<"Enter the dimension along which you want to slice"<<endl;
        cout<<"1. year wise"<<endl;
        cout<<"2. state Row wise"<<endl;
        cout<<"3. quarter Attribute wise"<<endl;
        cout<<"4. Exit"<<endl;

        cin>>option;

        switch(option)
        {
            case 1:
                {
                    cout<<"Enter the year you want to extract"<<endl;
                    for(i=0;i<a;i++)
                    {
                        cout<<"year - "<<i+1<<"-"<<years[i]<<endl;
                    }
                    cin>>year;
                    outdata<<"years"<<endl;
                    for(j=0;j<b;j++)
                    {
                        for(k=0;k<c;k++)
                        {
                            cout<<arr[year-1][j][k]<<"\t";
                            outdata<<arr[year-1][j][k]<<"\t";
                        }outdata<<"\t";
                    }outdata<<"\n";
                    break;
                }


            case 2:
                {
                    cout<<"Enter the state number you want to extract"<<endl;
                    for(j=0;j<b;j++)
                    {
                        cout<<"state - "<<j+1<<"-"<<states[j]<<endl;
                    }
                    cin>>state;
                    outdata<<"states"<<endl;
                    for(i=0;i<a;i++)
                    {
                        for(k=0;k<c;k++)
                        {
                            cout<<arr[i][state-1][k]<<"\t";
                            outdata<<arr[i][state-1][k]<<"\t";
                        }outdata<<"\t";
                    }outdata<<"\n";
                    break;




                }
            case 3:
                {
                    cout<<"Enter the quarter Attribute you want to slice"<<endl;
                    for(k=0;k<c;k++)
                    {
                        cout<<column_val[k]<<"-"<<k+1<<endl;
                    }
                    cin>>att;
                    outdata<<"quarter attributes"<<endl;
                    for(i=0;i<a;i++)
                    {
                        for(j=0;j<b;j++)
                        {
                            cout<<arr[i][j][att-1]<<"\t";
                            outdata<<arr[i][j][att-1]<<"\t";
                        }outdata<<"\t";
                    }outdata<<"\n";
                    outdata.close();
                    break;



                }
            case 4:
                {
                    exit(3);
                    break;
                }
        }
    }while(option!=4);



    return 0;
}
