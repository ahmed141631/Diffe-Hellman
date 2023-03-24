#include<iostream>
#include<cstdlib>
using namespace std;
int  isPrime(long i);


typedef struct Person{
    long prKey;
    long PubKey;
    long generalkey;
}Person;
long modmul(long a, long b,long n){
    return (a*b) %n;
}
long s_a_m(long m,long e,long n){ //square and multiplication
    long result =1;
    while(e!=0){
        if(e& 0x1==1){
            result=modmul(result,m,n);
        }
        m=modmul(m,m,n);
        e=e>>1;
            }
    return result;
}

int  isPrime(long i){
    int result=0;
    long a,b=1;
    for(a=i-1; a>1; a--){
        b=i%a;
        if(b==0) result= 0;

    }
    if(b==1) {result= 1;}

   return result; 
}

class Diffe_Hellman
{    
public:
    long prime;
    long alpha;
    Person Alice;
    Person Bob;
    long generate_p(long range);
    long generate_alpha();
    Diffe_Hellman(long range);
    ~Diffe_Hellman();
   void generate_key();
    
    
    
};
long Diffe_Hellman::generate_alpha(){
    return rand()%((prime-2)-2+1)+2;
}
long Diffe_Hellman::generate_p(long range){
    long p=0;
    for(long i=0; i<=range; i++){
        if(isPrime(i)){
            p=i;
        }
    }
    return p;
}

Diffe_Hellman::Diffe_Hellman(long range){
    prime=generate_p(range);
    alpha=generate_alpha();
    generate_key();
}
void Diffe_Hellman::generate_key(){
    Alice.prKey=rand()%((prime-2)-2+1)+2;
    Alice.PubKey=modmul(alpha,Alice.prKey,prime);
    Bob.prKey=rand()%((prime-2)-2+1)+2;
    Bob.PubKey=modmul(alpha,Bob.prKey,prime);
    Alice.generalkey=modmul(Bob.PubKey,Alice.prKey,prime);
    Bob.generalkey=modmul(Alice.PubKey,Bob.prKey,prime);
   

}
Diffe_Hellman::~Diffe_Hellman(){
    char i;

    cout<<"key exchange is done successfulluy ,press anykey to show details"<<endl;
    cin>>i;
    if(i){
    cout<<"prime p is " <<prime<<endl;  
    cout<<"alpha  is " <<alpha<<endl;   
    cout<<"the private key of Alice is : "<<Alice.prKey<<endl;
    cout<<"the public key of Alice is: "<<Alice.PubKey<<endl;
    cout<<"the private key of Bob is : "<<Bob.prKey<<endl;
    cout<<"the public key of Bob is :"<<Bob.PubKey<<endl;
    cout<<"The general key of Alice "<<Alice.generalkey<<endl;
    cout<<"The general key of Bob "<<Bob.generalkey<<endl;

    }
}
int main()
{
    cout<<"enter big numbre :";
    long numbre;
    cin>>numbre;
    Diffe_Hellman dh(numbre);
    
    return 0;
}


