#include <iostream>
#include<cstring>
#include<algorithm>
using namespace std;
struct megadig{
    char a[300];
    int len;
}m,n;
megadig add(megadig m,megadig n){
    int tmp=0;
    megadig ans={0};
    int js=0;
    for(int i=0;i<max(m.len,n.len);i++){
        tmp=m.a[i]+n.a[i]+js;
        js=tmp/10;
        ans.a[i]=tmp%10;
    }
    ans.len=max(m.len,n.len);
    if(js!=0){
        ans.a[ans.len]=js;
        ans.len++;

    }
    return ans;
}
void mycpy(char a[],char b[],int lenb){
    for(int i=0;i<lenb;i++){
        a[i]=b[i];
    }
    return;
}
megadig mul(megadig m,megadig n){
    char tmp[301]={0};
    megadig tmp2={0};
    megadig ans={0};
    int js=0;
    for(int i=0;i<n.len;i++){
        memset(tmp,0,sizeof(tmp));
        memset(tmp2.a,0,sizeof(tmp2.a));
        for(int j=0;j<m.len;j++){

            tmp[j+1]=(n.a[i]*m.a[j]+tmp[j])/10;
            tmp[j]=(n.a[i]*m.a[j]+tmp[j])%10;
        }
        mycpy(tmp2.a+i,tmp,m.len+1);
        if(tmp[m.len]!=0) tmp2.len=m.len+i+1;
        else tmp2.len=m.len+i;
        ans=add(tmp2,ans);
    }
    return ans;
}
void myprint(megadig p){
    for(int i=p.len-1;i>=0;i--){
        printf("%d",p.a[i]);
    }
}
megadig input(char tmp[],int l){
    megadig ans={0};
    for(int i=l-1;i>=0;i--){
        ans.a[i]=tmp[l-i-1]-48;
         //printf("%d\n",ans.a[i]);
    }
    ans.len=l;
    return ans;
}
int main()
{
    megadig jg;
    char tmp[300]={0};
    scanf("%s",tmp);
    m=input(tmp,strlen(tmp));
    scanf("%s",tmp);
    n=input(tmp,strlen(tmp));
    jg=mul(m,n);
    myprint(jg);

    return 0;
}
