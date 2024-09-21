#include <iostream>

using namespace std;
int ans=0;
int findingv1(int n, int stat){
    if(n==0){
        ans++;
        return 0;
    }
    if(n<0) return 0;
    if(stat<=0)findingv1(n-1,0);
    if(stat<=1)findingv1(n-2,1);
    if(stat<=2)findingv1(n-5,2);
    return 0;
}
int findingv2(int n){
    int s[1000]={0};
    s[0]=1;
    for(int i=0;i<=n;i++){
        if(i>=1)s[i]=s[i-1]+s[i];
        if(i>=2)s[i]=s[i-2]+s[i];
        if(i>=5)s[i]=s[i-5]+s[i];
    }
    return s[n];
}
int findingv3(int n){
    int s1[1000]={0};
    int s2[1000]={0};
    int s3[1000]={0};
    s1[0]=1;
    for(int i=0;i<=n;i++){
        if(i>=1)s1[i]=s1[i-1];
        if(i>=2)s2[i]=s1[i-2]+s2[i-2];
        if(i>=5)s3[i]=s1[i-5]+s2[i-5]+s3[i-5];
    }
    return s1[n]+s2[n]+s3[n];
}
int main()
{
    int n=0;
    cin>>n;
    findingv1(n,0);
    cout<<ans<<endl;
    cout<<findingv2(n)<<endl;
    cout<<findingv3(n);
    return 0;
}
