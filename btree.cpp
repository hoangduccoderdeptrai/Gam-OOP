#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<algorithm>
using namespace std;
class guild{
    protected:
        string ten;
        float hp,atk,def;
        static int dem_nhanloai;
    public:
        void virtual nhap(){
            getline(cin,ten);
            cin>>hp>>atk>>def;
            cin.ignore();
        }
        void hienthi(){
            
            
            cout<<ten<<" "<<hp<<" "<<atk<<" "<<def<<endl;
            
        }
        void virtual adjust(){
            return;
        }
        void attack(guild &t){
            if(atk>t.def){
                t.hp -=(atk-t.def);
            }
        }
        float get_hp(){
            return hp;
        }
        bool is_dead(){
            return hp<=0;
        }
       
};
int guild::dem_nhanloai=0;
class nhanloai:public guild{
    private:
        string job;
    public:
        void nhap(){
           
            guild::nhap();
            getline(cin,job);
            dem_nhanloai++;
        }


};
class humam:public nhanloai{
    public:
        
};
class elf:public nhanloai{
    public:
        void adjust(){
            def =1.5*def;
        }
};
class bannhan:public guild{
    private:
        string racial;
    public:
        void nhap(){
            guild::nhap();
           
            getline(cin,racial);
        }

};
class orc:public bannhan{
    public:
        void adjust(){
            hp =1.5*hp;
        }

    
};
class golbin:public bannhan{
    public:
        void adjust(){
            atk+=atk*0.1;
        }
};
class dihinh:public guild{
    public:
        
};
class vampire:public dihinh{
    public:
        void adjust(){
            hp +=0.1*hp*dem_nhanloai;
        }

};
class devil:public dihinh{
    private:
        static int dem;
    public:
        void nhap(){
            guild::nhap();
            dem++;
        }
        void adjust(){
            atk +=0.1*atk*dem;
            def +=0.1*def*dem;
        }
};
int devil::dem=0;
class boss:public guild{
    
};
bool cmp(guild *a,guild *b){
    return a->get_hp()<b->get_hp();
}
bool is_all_dead(guild*t[],int n){
    for(int i=0;i<n;i++){
        if(!t[i]->is_dead())return false;
    }
    return true;
}
int find_index_min(guild *t[],int n){
    int index=0;
    int min;
    for(int i=0;i<n;i++){
        if(!t[i]->is_dead()){
            min=t[i]->get_hp();
            index =i;
            break;
        }
    }
    for(int i=0;i<n;i++){
        if(min>t[i]->get_hp()&&!t[i]->is_dead()){
            min=t[i]->get_hp();
            index=i;
        }
    }
    return index;

}
int main(){
    guild *t[50];
    boss b;
    int soluong,n;
    cin>>soluong;
    for(int i=0;i<soluong;i++){
        cin>>n;
        if(n==1)t[i] =new humam();
        if(n==2)t[i]=new elf();
        if(n==3)t[i]=new orc();
        if(n==4)t[i]=new golbin();
        if(n==5)t[i]=new vampire();
        if(n==6)t[i]=new devil();
        cin.ignore();
        t[i]->nhap();
    }
    for(int i=0;i<soluong;i++){
        t[i]->adjust();
    }
    
    b.nhap();
    do{
        for(int i=0;i<soluong;i++){
            if(!t[i]->is_dead()){
                t[i]->attack(b);
            }
        }
        if(b.is_dead()){
            break;
        }
        int index =find_index_min(t,soluong);
            
        
        b.attack(*t[index]);
        
    }while(!is_all_dead(t,soluong));
    if(b.is_dead()){
        sort(t,t+soluong,cmp);
        for(int i=0;i<soluong;i++){
            t[i]->hienthi();
        }
    }else{
        b.hienthi();
    }
   
}