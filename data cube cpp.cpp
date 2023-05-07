#include <iostream>
#include<fstream>
using namespace std;

int main()
{
    ofstream outdata;
    outdata.open("data_cube_sample.csv");
    int arr[3][3][3], i, j, k, a, b, c;
    int entered_S_No,entered_semester,choosen_attribute;

    const char* column_val[10] = {"S.No", "Age","Sleeping habbit"};

    cout<<"Enter the dimensions";
    cout<<"*****"<<endl;
    cout<<"Enter the size of the semester dimensions\n";
    cin>>a;
    cout<<"Enter the size of the student dimensions\n";
    cin>>b;
    cout<<"Enter the size of the attribute dimensions\n";
    cin>>c;

    for(i=0;i<a;i++)
    {
        for(j=0;j<b;j++)
        {
            for(k=0;k<c;k++)
            {
                cout<<"Enter the "<<column_val[k]<<" of student: "<<j+1<<"in sem: "<<i+1<<endl;
                cout<<"location\t"<<i<<"\t"<<j<<"\t"<<k<<endl;
                cin>>arr[i][j][k];
            }
        }
    }
    cout<<"value extractions from data cube ****************"<<endl;
    cout<<"Enter the student Serial Number: "<<endl;
    cin>>entered_S_No;
    cout<<"Enter the semester"<<endl;
    cin>>entered_semester;
    cout<<"Enter the attribute you want to fetch"<<endl;
    cout<<"1. S.No \n2.Age \n3.Sleeping habbit"<<endl;
    cin>>choosen_attribute;
    outdata<<"required attribute"<<endl;
    if(choosen_attribute<1)
    {
        cout<<"Enter a valid attribute"<<endl;
    }
    else
    {
        cout<<"\n"<<endl;
        cout<<arr[entered_semester-1][entered_S_No-1][choosen_attribute-1]<<endl;
        //outdata<<"\n"<<endl;
        outdata<<arr[entered_semester-1][entered_S_No-1][choosen_attribute-1]<<endl;
    }



    return 0;
}
