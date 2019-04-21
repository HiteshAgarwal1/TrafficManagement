#include<iostream>
#include<iomanip>
#include<fstream>
#include<stdlib.h>
#include<conio.h>
#include<stdio.h>
#include <windows.h>
using namespace std;

int cur_pos;

class chlan_rcrd{
      protected:
        string typeC,CHregNo,CHreason,dataCopier;
        int fine;
      public:
        void CHgetdata();
        void showchlan();
        void searchdata();

};

class veh_rcrd : public chlan_rcrd{
  protected:
    string manufac,modelName,vechileNo,vechicleType,mobile,owner_name;
    string data;

  public:
    void getdata();
    void displayAll();
    void searchdata();
    void deletedata();
    void modifydata();

};

void veh_rcrd::deletedata(){

  string readdata,data_SRCH,datatransfer;
  cout <<endl<< "   Enter the Regd. No.: ";
  fflush(stdin);
  cin>>data;

  ifstream fopen;
  fopen.open("Vechicle_Entry.txt");
  ofstream ftemp;
  ftemp.open("temp.txt");
  fopen.seekg(0,ios::beg);
    int flag=0;
    while(fopen>>readdata)
      {
        if(readdata==data)
        fopen.seekg(+74,ios::cur);
        else {
                fopen.seekg(-16,ios::cur);
                getline(fopen,datatransfer);
                ftemp<<datatransfer<<endl;
              }

      }
      fopen.close();
      ftemp.close();
      remove("Vechicle_Entry.txt");
      int test = rename("temp.txt","Vechicle_Entry.txt");
      if (test == 0){
        cout << "------------------------------------------------------------------------------------------------------------------------";
         cout <<setw(70) <<"Successful Deletion" << endl;
         cout << "------------------------------------------------------------------------------------------------------------------------";
         }
      else cout << "Failure in Deletion";
}

void veh_rcrd::modifydata(){

  string readdata,data_SRCH,datatransfer;
  cout <<endl<< "   Enter the Regd. No.: ";
  fflush(stdin);
  cin>>data;

  ifstream fopen;
  fopen.open("Vechicle_Entry.txt");
  ofstream ftemp;
  int cur_pos;
  ftemp.open("temp.txt",ios::out|ios::app);
  fopen.seekg(0,ios::beg);
    int flag=0;
    while(fopen>>readdata)
      {
        if(readdata==data)
        {
          cur_pos=fopen.tellg();
          cur_pos-=17;
          fopen.seekg(+74,ios::cur);
        }
        else {
                fopen.seekg(-16,ios::cur);
                getline(fopen,datatransfer);
                ftemp<<datatransfer<<endl;
            }

      }

      cout<< "Enter the data for modification:"<<endl;

      cout<<endl<<"   Enter the Manufacturers: ";
      fflush(stdin);
      getline(cin,manufac);
      cout<<"   Enter the Model Name: ";
      fflush(stdin);
      getline(cin,modelName);

      cout<<"   Enter the Type of Vechicle: ";
      fflush(stdin);
      getline(cin,vechicleType);
      cout<<"   Enter the Name of Owner: ";
      fflush(stdin);
      getline(cin,owner_name);
      cout<<"   Enter the Mobile No.: ";
      fflush(stdin);
      getline(cin,mobile);


      ftemp.seekp(cur_pos);
      ftemp << setw(15) << data << setw(15) << manufac << setw(15) << modelName
                << setw(15) << vechicleType << setw(15) << owner_name << setw(15) << mobile << endl;



      fopen.close();
      ftemp.close();
      remove("Vechicle_Entry.txt");
      int test = rename("temp.txt","Vechicle_Entry.txt");
      if (test == 0){
        cout << "------------------------------------------------------------------------------------------------------------------------";
         cout <<setw(70) <<"Successful Modification" << endl;
         cout << "------------------------------------------------------------------------------------------------------------------------";
         }
      else cout << "Failure in Modification";
}

void chlan_rcrd::CHgetdata()
{

  cout<< endl <<"   Enter the Vechicle Type(Car/Bike/Other): ";
  fflush(stdin);
  getline(cin,typeC);
  cout<<"   Enter the Vechicle Registration Number: ";
  fflush(stdin);
  getline(cin,CHregNo);
  cout<<"   Enter the Reason of Challan: ";
  fflush(stdin);
  getline(cin,CHreason);
  cout << "   Enter the Amount of Penalty(Rs): ";
  fflush(stdin);
  cin >> fine;
  cout << "------------------------------------------------------------------------------------------------------------------------";
  cout<< setw(70) << "Challan Issued Successfully." << endl;

  ofstream CHinput;
  CHinput.open("ChallanData.txt",ios::app);
  CHinput << setw(15) << typeC << setw(12) << CHregNo << setw(20) << CHreason << setw(15) << fine <<endl;
  CHinput.close();

  cout << "------------------------------------------------------------------------------------------------------------------------";
}

void chlan_rcrd::showchlan()
{
  ifstream CHshow;
  CHshow.open("ChallanData.txt");

        cout << "------------------------------------------------------------------------------------------------------------------------";

  cout << endl<< setw(15) << "Vechicle Type" << setw(12) << "Regd. No." << setw(20)
       << "Challan Reason" << setw(15) << "Penalty(Rs.)" << endl << endl;

       while (CHshow) {
            getline(CHshow,dataCopier);
            cout << dataCopier << endl;
       }

       CHshow.close();

       cout << "------------------------------------------------------------------------------------------------------------------------";

}

void chlan_rcrd::searchdata(){
  cout <<endl<< "   Enter the Regd. No.: ";
  fflush(stdin);
  cin>>dataCopier;
  string readdata,data_SRCH;
  ifstream fopen;
  fopen.open("ChallanData.txt");
  fopen.seekg(0,ios::beg);
    int cur_pos,flag=0;
    while(fopen>>readdata)
      {     if(readdata==dataCopier)
          {
            flag=1;
            cout << "------------------------------------------------------------------------------------------------------------------------";
            cout<<setw(65)<<"DATA FOUND!!!"<<endl;
            cout << "------------------------------------------------------------------------------------------------------------------------";
            // cur_pos=fopen.tellg();
            fopen.seekg(-17 ,ios::cur);
            getline(fopen,data_SRCH);
            cout << endl<< setw(45) << "Vechicle Type" << setw(12) << "Regd. No." << setw(20)
                 << "Challan Reason" << setw(15) << "Penalty(Rs.)" << endl;
            cout<<setw(92)<<data_SRCH<<endl;
            cout << "------------------------------------------------------------------------------------------------------------------------";
            break;
          }
      }
      if(flag==0)
      {
        {
          cout << "------------------------------------------------------------------------------------------------------------------------";
          cout<<setw(65)<<"DATA NOT FOUND!!!"<<endl;
          cout << "------------------------------------------------------------------------------------------------------------------------";
        }
      }
      fopen.close();
}

void veh_rcrd::getdata()
{

  cout<<endl<<"   Enter the Manufacturers: ";
  fflush(stdin);
  getline(cin,manufac);
  cout<<"   Enter the Model Name: ";
  fflush(stdin);
  getline(cin,modelName);
  cout<<"   Enter the Vechicle Registration Number: ";
  fflush(stdin);
  getline(cin,vechileNo);
  cout<<"   Enter the Type of Vechicle: ";
  fflush(stdin);
  getline(cin,vechicleType);
  cout<<"   Enter the Name of Owner: ";
  fflush(stdin);
  getline(cin,owner_name);
  cout<<"   Enter the Mobile No.: ";
  fflush(stdin);
  getline(cin,mobile);


  ofstream fileinput;
  fileinput.open("Vechicle_Entry.txt",ios::app);
  fileinput << setw(15) << vechileNo << setw(15) << manufac << setw(15) << modelName
            << setw(15) << vechicleType << setw(15) << owner_name << setw(15) << mobile << endl;
  fileinput.close();
  cout << "------------------------------------------------------------------------------------------------------------------------";
  cout<< setw(73) << "Data Saved Successfully." << endl;
  cout << "------------------------------------------------------------------------------------------------------------------------";

}

void veh_rcrd::displayAll()
{

  ifstream fileout;
  fileout.open("Vechicle_Entry.txt");

  cout << "------------------------------------------------------------------------------------------------------------------------";
  cout << endl << setw(15) << "Rgd. Number" << setw(15) << "Manufactures" << setw(15) << "Model Name"
            << setw(15) << "Vechicle Type" << setw(15) << "Owner Name" << setw(15) << "Mobile" << endl << endl;

  while(fileout){


    getline(fileout,data);
    cout << data << endl;
  }

fileout.close();

    cout << "------------------------------------------------------------------------------------------------------------------------";

}

void veh_rcrd::searchdata(){
  cout <<endl<< "   Enter the Regd. No.: ";
  fflush(stdin);
  cin>>data;
  string readdata,data_SRCH;
  ifstream fopen;
  fopen.open("Vechicle_Entry.txt");
  fopen.seekg(0,ios::beg);
    int flag=0;
    while(fopen>>readdata)
      {     if(readdata==data)
          {
            flag=1;
            cout << "------------------------------------------------------------------------------------------------------------------------";
            cout<<setw(70)<<"DATA FOUND!!!"<<endl;
            cout << "------------------------------------------------------------------------------------------------------------------------";

            fopen.seekg(-15,ios::cur);
            cur_pos=fopen.tellg();
            getline(fopen,data_SRCH);
            cout << endl << setw(15) << "Rgd. Number" << setw(15) << "Manufactures" << setw(15) << "Model Name"
                      << setw(15) << "Vechicle Type" << setw(15) << "Owner Name" << setw(15) << "Mobile" << endl << endl;
            cout<<setw(22)<<data_SRCH<<endl;
            cout << "------------------------------------------------------------------------------------------------------------------------";
            break;
          }
      }
      if(flag==0)
      {
        {
          cout << "------------------------------------------------------------------------------------------------------------------------";
          cout<<setw(65)<<"DATA NOT FOUND!!!"<<endl;
          cout << "------------------------------------------------------------------------------------------------------------------------";
        }
      }

}



int main() {

  cout<<setw(88)<<"============================================================"
      <<setw(110)<<"Smart Traffic Management Solution"<<endl
      <<setw(88)<<"============================================================";

int choice;
B:
    do{
          system("Color F0");
        cout<< endl << setw(70)<< "You Can Do The Following:" << endl << endl
        << setw(65)<< "1. Vechicle Records" << endl
        << setw(64)<< "2. Challan System " <<endl
        << setw(87)<< "3. Helpline Numbers and Nearby Hospitals "<< endl
        << setw(53)<< "4. Exit" << endl << endl
        << setw(64)<< "Enter Your Choice: ";

    cin >> choice;
    if(choice==4)
    goto A;


veh_rcrd data;
chlan_rcrd CHentry;
        char input;

    switch(choice){

                    case 1:
                              system("Color B4");
                            cout << endl << "   A. Add New Vehicle" << endl
                                 << "   B. Delete the Vechicle Data"  <<endl
                                 << "   C. Modify the Vechicle Data"  <<endl
                                 << "   D. Display The All Vehicle's Records" <<endl
                                 << "   E. Search for a Vehicle Entry" <<endl
                                 << "   F. Return to Main Menu" << endl
                                 << "   Press the Respective Input: ";
                            cin >> input;
                            switch(input){
                                case 'A':
                                            system("Color B1");
                                            data.getdata();
                                            break;
                                case 'B':
                                            data.deletedata();
                                            break;

                                case 'C':

                                            data.modifydata();
                                            break;

                                case 'D':

                                              system("Color B0");
                                            data.displayAll();
                                            Sleep( 3000 );
                                            break;
                                case 'E':
                                              system("Color B5");
                                            data.searchdata();
                                            break;
                                case 'F':
                                            goto B;
                                        }
                                        break;
                    case 2:
                            system("Color B4");
                              cout << endl << "   A. Make a Challan" << endl
                                   << "   B. Challan Records" <<endl
                                   << "   C. Search a Challan Record" <<endl
                                   << "   D. Return to Main Menu" << endl
                                   << "   Press the Respective Input: ";
                              cin >> input;

                              switch(input){
                                    case 'A':
                                              system("Color B1");
                                              CHentry.CHgetdata();
                                              break;
                                    case 'B':
                                              system("Color B0");
                                              CHentry.showchlan();
                                              break;
                                    case 'C':
                                              system("Color B5");
                                              CHentry.searchdata();
                                              break;
                                    case 'D':
                                              goto B;

                                            }
                                break;

                    case 3:
                            string help_data;
                              ifstream help_inform;
                              help_inform.open("information.txt");
                              system("Color B0");
                              while(help_inform)
                              {
                                getline(help_inform,help_data);
                                cout << help_data << endl;
                              }
                              Sleep( 3000 );
                              break;


    }
        } while(choice!=4);
A:
  return 0;
}
