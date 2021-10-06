#include<iostream>


using namespace std;
 class Phanso
 {
 private:
     /* data */
     int Tu, Mau; 
 public:
    int Laytu(){
        return Tu; 
    }
    int LayMau(){
        return Mau; 
    }
    void Settu(int a){
        Tu = a; 
    }
    void SetMau(int b){
        Mau = b; 
    }
    void Ouput(){
        cout<<Tu<<"/"<<Mau ; 
    }
     Phanso(){}; 
     Phanso(int a, int b ) {
         Tu = a; 
         Mau = b; 
     }
     Phanso operator+(Phanso); // phân số cộng với một phân số 
     Phanso operator+(int); //phân số  cộng với một  số nguyên
     friend Phanso operator+(int, Phanso); 
 };
// member funtion 
Phanso Phanso::operator+(int a){
    Phanso tam; 
    tam.Tu=a*Mau +Tu; 
    tam.Mau = Mau; 
    return tam; 
}

/*
  khi lấy một phân số cộng một số nuyên ta có thể lợi dụng được hàm class vì vậy có thể dùng number_function còn để cộng được 
  số nguyên cộng phân số thì ta dùng non_number_funciton hoặc hàm bạn 
*/
// non_nember function 
// Phanso operator+(int a, Phanso ps){
//     Phanso tam; 
//     tam.Settu(a*ps.LayMau()+ps.Laytu()); 
//     tam.SetMau(ps.LayMau()); 
//     return tam; 
// }
// sử dụng hàm bạn để lấy số nguyên cộng phân số
Phanso operator+(int a, Phanso ps){
     Phanso tam; 
    tam.Tu=a*ps.Mau +ps.Tu; 
    tam.Mau = ps.Mau; 
    return tam; 
}
Phanso Phanso::operator+(Phanso ps){
   Phanso tam; 
    tam.Tu = Tu*ps.Mau +ps.Tu*Mau; 
    tam.Mau = Mau*ps.Mau; 
    return tam; 
}
int main(){
    Phanso A(1,2), B(1,2), C; 
    cout<<"Phan so cong phan so: "; 
    C = A + B; 
    C.Ouput(); 
    cout<<"\n Phan so cong so nguyen: ";  
    C = A + 2; 
    C.Ouput(); 
    cout<<"\n so nguyen cong  phan so: "; 
    C= 2 + A; 
    C.Ouput(); 

    return 0;
}
/*
   nếu khi dùng non_number_funtion thì phải dùng getter và setter để truy câp 
*/