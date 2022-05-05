int pop() {
int y = 0;
int n = q1.size();
while(n>1)
{
int x = q1.front();
q1.pop();
q1.push(x);
n--;
}
y = q1.front();
q1.pop();
return y;
}
int top() {
int y = 0;
int n = q1.size();
while(n>1)
{
int x = q1.front();
q1.pop();
q1.push(x);
n--;
}
y = q1.front();
q1.pop();
q1.push(y);
return y;
}
bool empty() {
return q1.size()==0;
}
};
```