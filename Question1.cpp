#include<iostream>
#include<string>
using namespace std;

//base class 1
class Publication{

    private:
    string title;
    float price;

    public:
    void getdata(){
        cin.ignore();
    cout<<"Enter Title:"<<endl;
    getline(cin, title);
    cout<<"Enter Price:"<<endl;
    cin>>price;

    }
    void putdata(){
     cout<<title<<endl;
     cout<<price<<endl;
    }
};
//base class 2
class Sales{

    private:
    float sales[3]{};


    public:
    void getdata(){
       for(int i = 0; i< 3; ++i){
        cout<< " month "<< (i+1) << ":"<<endl;;
        cin>>sales[i];

       }

    }
    void putdata(){
     for(int i = 0; i< 3; ++i){
        cout<<  sales[i]
                 << (i < 2 ? ", " : "\n");//best logic
        
       }
    }
};


class Book : public Publication, public Sales{
   private:
    int pageCount;
public :
void getdata(){
    Publication::getdata();
    cout<<"pageCount is:"<<endl;
    cin>>pageCount;
    Sales::getdata();
}
void putdata(){
    Publication::putdata();
    cout<<pageCount<<endl;
    Sales::putdata();
}

};
class Tape: public Publication, public Sales{
   private:
    float playingTime;
    public:
    void getdata(){
        Publication::getdata();
        cout<<"playing Time is :"<<endl;
        cin>>playingTime;
        Sales::getdata();
    }
    void putdata(){
        Publication::putdata();
        cout<<playingTime<<endl;
        Sales::putdata();
    }

};
//Enum for disk sizes
enum DiskType { three_half, five_quarter };
//new drived class that inherits only publication
class Disk : public Publication{
    private:
    DiskType size;

    public:
    void getdata(){
        Publication::getdata();
        int choice;
        cout<<"Enter disk size(3 for 3.5 inches, 5 for 5.25 inches) ;";
        cin >> choice;
        if(choice == 3){
            size = three_half;
        }else{
            size  = five_quarter;
        }

    }
    void putdata() {
        Publication::putdata();
        cout<<"disk size:";
        if(size == three_half){
            cout<<  "3.5 inches"<<endl;

        }else{
            cout<<"5.25 inches"<<endl;
        }
    }

    


};

int main(){
    Disk d1;

cout<< "Enter disk publication details:";
d1.getdata();
cout<<"\nDisak publication details entered:";
d1.putdata();



    Book b1;
    Tape t1;
    cout << "Enter details for Book:\n";
    b1.getdata();
    cout << "\nEnter details for Tape:\n";
    t1.getdata();
     cout << "\nBook Details:\n";
    b1.putdata();
    cout << "\nTape Details:\n";
    t1.putdata();
    return 0;
}