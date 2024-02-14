#include<iostream>
using namespace std;

//  --------> RECURSION

int printCounting(int n){

    // Base case
    if(n==1) return 1;

    //recursive case
    return n+printCounting(n-1);
}

int powerOfTwo(int n){

    // Base case
    if(n==0) return 1;

    // recursive case
    else{
        return 2*powerOfTwo(n-1);
    }
}

int factorial(int n){
    // Base case
    if(n==1 || n==0)return 1;

    // recursive case
    int chhoti=factorial(n-1);
    int badi=n*chhoti;
    return badi;
}

void reachHome(int src, int des){
    cout<<"Source "<<src<<"  Destination "<<des<<endl;
    // Base case
    if(src==des){
        cout<<"Pahuch gya"<<endl;
        return;
    }

    // processing
    src++;

    // recursive case
    reachHome(src,des);
}

int fibonacciSeries(int n){
    // Base case
    if(n==0) return 0;
    if(n==1) return 1;

    // recursive case
    return fibonacciSeries(n-1)+fibonacciSeries(n-2); 
}

void sayDigits(int n, string arr[]){
    // base case
    if(n==0){
        return;
    }

    // processing
    int digits=n%10;
    n=n/10;
    

    //recursive call
    sayDigits(n,arr);

    cout<<arr[digits]<<" ";

}

bool isSorted(int *arr,int size){

    // base case
    if(size==0 || size==1){
        return true;
    }
    if(arr[0]>arr[1]){
        return false;
    }
    else{
        bool remaining = isSorted(arr+1,size-1);
        return remaining;
    }
}

int sum(int *arr, int size){

    //base case
    if(size==0)return 0;
    
    else{
        int temp=arr[0];
        temp=temp+sum(arr+1,size-1);
        return temp;
    }
}

bool linearSearch(int *arr,int size, int key){
    // base case
    if(size==0){
        return false;
    }
    if(arr[0]==key){
        return true;
    }
    else{
        bool remaining = linearSearch(arr+1,size-1,key);
        return remaining;
    }

}
// ------>  BINARY SEARCH USING RECURSION

bool binarySearch(int *arr, int s, int e, int k){

    // base case
    if(s>e){
        return false;
    }
    int mid=s+(e-s)/2;

    if(arr[mid]==k){
        return true;
    }
    
    // recursive case
    if(arr[mid]<k){
        return binarySearch(arr,mid+1,e,k);
    }
    else{
        return binarySearch(arr,s,mid-1,k);
    }
}

void reverse(string &str, int s, int e){
    // base case
    if(s>e){
        return;
    }

    //processing
    swap(str[s],str[e]);
    s++;
    e--;

    // recursive case
    reverse(str,s,e);
}

bool checkPallindrome(string str, int i, int j){
    // base case
    if(i>j){
        return true;
    }
    // processing
    if(str[i]!=str[j]){
        return false;
    }
    else{
    // recursive
    return checkPallindrome(str,i+1,j-1);
    }

}

int power(int a, int b){
    // base case
    if(b==0){
        return 1;
    }
    if(b==1){
        return a;
    }

    // recursive case
    int ans = power(a,b/2);

    if(b%2==0){
        // even
        return ans*ans;
    }
    else{
        return a*ans*ans;
    }
}

int main(){

    int x,n;cin>>x>>n;
    cout<< power(x,n);
/*  string str="babbah";
    
    bool ans=checkPallindrome(str,0,str.length()-1);
    if(ans){
        cout<<"pallindrome"<<endl;
    }else{
    cout<<"Not pallindrome"<<endl;
    }
    int len=str.length()-1;
    reverse(str,0,len);

    cout<<str<<endl;

    int arr[6]={2,4,6,10,14,18};
    int s=0;
    int e=6;
    int key = 18;

    bool ans=binarySearch(arr,s,e,key);
    if(ans){
        cout<<"Found"<<endl;
    }else{
    cout<<"Not Found"<<endl;
    }
  bool ans = linearSearch(arr,size,key);
    if(ans){
        cout<<"Found"<<endl;
    }else{
    cout<<"Not Found"<<endl;
    }


  int answer=sum(arr,size);
    cout<<answer<<endl;

  bool ans = isSorted(arr,size);
    if(ans){
        cout<<"Sorted"<<endl;
    }else{
    cout<<"Not Sorted"<<endl;
    }

  string arr[10]={"zero","one","two","three",
                    "four","five","six","seven",
                    "eight","nine"};
    int n;
    cin>>n;

    sayDigits(n,arr);

    int ans=factorial(n);
    cout<<ans<<endl;

    int answer=powerOfTwo(n);
    cout<<answer<<endl;

    int answ=printCounting(n);
    cout<<answ<<endl; 

    int src,des; cin>>src>>des;
    cout<<endl;
    reachHome(src,des);

    int answer=fibonacciSeries(n);
    cout<<answer<<endl;*/
    
    return 0;
}