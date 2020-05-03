#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;
class Job
{
public:
ll pid,ts,st=-1,et,dur;
int imp;
string orig,inst;
};
istream& operator>>(istream& in,Job* j)
{
in >> j->ts >> j->pid >> j->orig >> j->inst >> j->imp >> j->dur;
j->st=-1;
return in;
}
ostream& operator<<(ostream& out,const Job* j)
{
out << "job " << j->ts << " " << j->pid << " " << j->orig << " " << j->inst << " " << j->imp << "
" << j->dur;
return out;
}
struct comparator
queue
{
bool operator()( const Job* j1, const Job* j2 ) const {
if(j1->imp != j2->imp)
return j1->imp < j2->imp;
else if(j1->ts != j2->ts)
return j1->ts > j2->ts;
else
return j1->dur > j2->dur;
}
};
struct comp
{
bool operator()( const ll i, const ll j ) const {
return i > j;
}
};
priority_queue<Job*,vector<Job*>,comparator> q;
priority_queue<ll,vector<ll>,comp> e_tim;
vector<Job*> jobs;
int main()
{

ios_base::sync_with_stdio(0);
ll limit;
string s;
cin>>s>>limit;
ll fre = limit;
moment
string ch,query;
ll tim,k,assigned,fin;
while(cin>>ch){
if(ch=="job"){
Job* j = new Job;
cin>>j;
q.push(j);
jobs.push_back(j);
}
else if(ch=="assign"){
cin>>tim>>k;
while(!e_tim.empty()){
if(e_tim.top()<=tim){
fre++;
e_tim.pop();
}
else
break;
}
assigned = min(min(k,fre),(ll)q.size());
fre-=assigned;
while(assigned--){
Job* temp = q.top();
cout<<temp<<"\n";
q.pop();
temp->st = tim;
temp->et = tim + temp->dur;
e_tim.push(temp->et);
}
}
else{
cin>>tim>>query;
ll qll=0;
int flag=0;
for(int i=0;i<query.length();i++){
if(!(query[i]>='0'&&query[i]<='9')){
flag=1;
break;
}
qll=qll*10+query[i]-'0';
}
if(flag){
priority_queue<Job*,vector<Job*>,comparator> temp;
for(ll i=0;i<jobs.size();i++){
Job* j=jobs[i];
if(j->ts>tim)
break;
if((j->st==-1||j->st>tim)&&j->orig==query)
temp.push(j);
}
while(!temp.empty()){
cout<<temp.top()<<"\n";
temp.pop();
}
}
else{
priority_queue<Job*,vector<Job*>,comparator> temp;
for(ll i=0;i<jobs.size();i++){
Job* j=jobs[i];
if(j->ts>tim)
break;
if(j->st==-1||j->st>tim)
temp.push(j);
}
ll i=min((ll)temp.size(),qll);
while(i--){
cout<<temp.top()<<"\n";
temp.pop();
}
}
}
}
return 0;
}
