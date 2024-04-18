#include <string>
#include <cstring>
#include <iostream>
#include <fstream>
using namespace std;
class Account{
    private:
    int acc_no;
    string first_name;
    string last_name;
    int balance;
    public:
    static int num_of_accounts;
    void setfunction(){
        num_of_accounts++;
        acc_no=num_of_accounts;
        cout<<"Enter the first name: ";
        cin>>first_name;
        cout<<"Enter the last name: ";
        cin>>last_name;
        cout<<"Initial balance: ";
        cin>>balance;
        }
     
    friend ostream& operator<<(ostream &o,Account &s);
    friend istream& operator>>(istream &i,Account&s);
     friend ofstream& operator<<(ofstream &o,Account&s);
    friend ifstream& operator>>(ifstream &i,Account&s);
    friend int last_acc_no();
    friend int total_acc_no();
    friend void withdraw(int x,int amount);
    friend void deposit(int x,int amount);
    friend void balance_enquiry(int x);
    friend void closing_account(int x);
};
void closing_account(int);
void deposit(int,int);
void withdraw(int,int);
void balance_enquiry(int);
void show_all_accounts();
int last_acc_no(){
    ofstream ots("bank.txt",ios::app);
    ots.close();
    ifstream ifs;
    ifs.open("bank.txt");
    Account t;
    if(!(ifs>>t)) return 0;
    if(ifs.is_open()){
    while(ifs>>t){
    }
    ifs.close();
    return t.acc_no;}
    return 0;
}
int total_acc_no(){
    int i=0;
    ofstream ots("bank.txt",ios::app);
    ots.close();
    ifstream ifs;
    ifs.open("bank.txt");
    if(ifs.is_open()){
         Account t;
    while(ifs>>t){
         i++;
    }
    ifs.close();
}
return i;
}
int Account::num_of_accounts=last_acc_no();
int main(){ 
    while(1){
        int n;
        cout<<"\tSelect any one option from below:"<<endl;
        cout<<"\t1 Create a new account"<<endl;
        cout<<"\t2 Balance Enquiry"<<endl;
        cout<<"\t3 Deposit"<<endl;
        cout<<"\t4 Withdrawal"<<endl;
        cout<<"\t5 Close an account"<<endl;
        cout<<"\t6 Show all accounts"<<endl;
        cout<<"\t7 quit"<<endl;
        cout<<"\tEnter your choice: ";
        cin>>n; 
        char t= Account::num_of_accounts;
        if(n==1){
            Account t;
            t.setfunction();
            cout<<endl<<"Congratulations! Account has been created"<<endl;
            cout<<t<<endl<<endl;
            ofstream ots("bank.txt",ios::app);
            ots<<t;
            ots.close();
        }
        else if(n==2){
            int x;
            cout<<"Enter your Account number: ";
            cin>>x;
            balance_enquiry(x);
        }
        else if(n==3){
            int x,amount;
            cout<<"Enter your account number: ";
            cin>>x;
            cout<<"Enter amount deposited: ";
            cin>>amount;
            deposit(x,amount);
            cout<<endl<<"Congratulations! Amount has been deposited"<<endl;
            balance_enquiry(x);
        }
        else if(n==4){
            int x,amount;
            cout<<"Enter your account number: ";
            cin>>x;
            cout<<"Enter amount to be withdrawn: ";
            cin>>amount;
            withdraw(x,amount);
            cout<<endl<<"Congratulations! Amount has been withdrawn"<<endl;
            balance_enquiry(x);
        }
        else if(n==5) {
            int x;
            cout<<"Enter your account number: ";
            cin>>x;
            closing_account(x);
            cout<<"Congratulations! your account has been closed"<<endl<<endl;
        }
        else if(n==6) show_all_accounts();
        else if(n==7) break; 

    }
return 0;
}
ostream& operator<<(ostream&o,Account& a){
    o<<"First name: "<<a.first_name<<endl;
    o<<"Last name: "<<a.last_name<<endl;
    o<<"Account number: "<<a.acc_no<<endl;
    o<<"Balance: "<<a.balance<<endl;
    return o;
}
istream& operator>>(istream&i,Account& a){
    cout<<"Enter first name: ";
    i>>a.first_name;
    cout<<"Enter last name: ";
    i>>a.last_name;
    cout<<"Initial balance: ";
    i>>a.balance;
    return i;
}
ofstream& operator<<(ofstream&o,Account&a){
    // o<<"Account "<<a.acc_no<<endl;
    o<<a.first_name<<endl;
    o<<a.last_name<<endl;
    o<<a.acc_no<<endl;
    o<<a.balance<<endl<<endl;
    return o;
}
ifstream& operator>>(ifstream&i,Account&a){
    i>>a.first_name>>a.last_name>>a.acc_no>>a.balance;
    return i;
}
void show_all_accounts(){
    ifstream ifs;
    ifs.open("bank.txt");
    for(int i=0;i<total_acc_no();i++){
        Account n;
        ifs>>n;
        cout<<n<<endl;
    }
    ifs.close();
}
void balance_enquiry(int x){
    ifstream ifs;
    ifs.open("bank.txt");
    Account t;
    while(1){
          ifs>>t;
          if(t.acc_no==x)break;
    }
    cout<<t<<endl<<endl;
    ifs.close();
}
// void withdraw(int x,int amount){
//     ifstream ifs;
//     ifs.open("bank.txt");
//     Account t;
//     while(t.acc_no!=x){
//           ifs>>t;
//     }
//     t.balance=t.balance-amount;
    // ofstream ofs("bank.txt",ios::app);
    // ofs<<t.balance;
void withdraw(int x,int amount){
    ifstream ifs;
    ifs.open("bank.txt");
    int y=total_acc_no();
    Account t[y];
    for(int i=0;i<y;i++){
          ifs>>t[i];
          if(t[i].acc_no==x){
            t[i].balance-=amount;
          }
    }
    
    ofstream ofs("bank.txt",ios::trunc);
    for(int i=0;i<y;i++){
        ofs<<t[i];
    }
    ifs.close();
    ofs.close();
    
}
// void deposit(int x,int amount){
//     ifstream ifs;
//     ifs.open("bank.txt");
//     Account t;
//     while(t.acc_no!=x){
//           ifs>>t;
//     }
//     t.balance=t.balance+amount;
    // ofstream ofs("bank.txt",ios::app);
    // ofs<<t.balance;
    void deposit(int x,int amount){
    ifstream ifs;
    ifs.open("bank.txt");
    int y=total_acc_no();
    Account t[y];
    for(int i=0;i<y;i++){
          ifs>>t[i];
          if(t[i].acc_no==x){
            t[i].balance+=amount;
          }
    }
    ofstream ofs("bank.txt",ios::trunc);
    for(int i=0;i<y;i++){
        ofs<<t[i];
    }
    ifs.close();
    ofs.close();
    
}
void closing_account(int x){
    ifstream ifs;
    ifs.open("bank.txt");
    int y=total_acc_no();
    Account t[y];
    for(int i=0;i<y;i++){
          ifs>>t[i];
    }
    
    ofstream ofs("bank.txt",ios::trunc);
    for(int i=0;i<y;i++){
        if(t[i].acc_no!=x) ofs<<t[i];
    }
    ifs.close();
    ofs.close();
}