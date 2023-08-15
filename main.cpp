#include <iostream>
#include <limits.h>
#include <string.h>
#include <unordered_map>
using namespace std;

#define ll long long


unordered_map<ll, ll> memo;

typedef enum TagType {
  ADD = 0,
  SUB = 1,
  MUL = 3,
  DIV = 4
} TagType;

typedef struct Node {
  ll firstNum;
  ll secondNum;
  TagType type;

  operator ll(){
    if(this->type == ADD) return this->firstNum + this->secondNum;
    if(this->type == MUL) return this->firstNum * this->secondNum;
    if(this->type == SUB) return this->secondNum - this->firstNum;
    return LONG_MIN;
  }
} Node;

Node* add(ll a, ll b);

Node* mul(ll a, ll b);

Node* sub(ll a, ll b);

ll calculateFibo(ll);

void calc(Node* n);

Node* (*makeFun(TagType type))(ll, ll);

int main() {
  Node* add = (*makeFun(ADD))(10, 6);
  Node* mul = (*makeFun(MUL))(5, 4);
  Node* sub = (*makeFun(SUB))(*mul, *add);
  Node* fibo = (*makeFun(SUB))(*sub, NULL); // NULL can be assumed to be 0, so the result will be 0 - (-4) = 4

  calc(add);
  calc(mul);
  calc(sub);
  calc(fibo);

  ll limit;
  cout << "Enter the limit of fibonacci sequence: ";
  cin >> limit;
  cout << "The fibonancci sequence till " << limit << " is:\n";
  calculateFibo(limit);
  return 0;
}

Node* add(ll a, ll b) {
  Node *n = new Node();
  n->type = ADD;
  n->firstNum = a;
  n->secondNum = b;
  return n;
}

Node* mul(ll a, ll b) {
  Node *n = new Node();
  n->type = MUL;
  n->firstNum = a;
  n->secondNum = b;
  return n;
}

Node* sub(ll a, ll b) {
  Node *n = new Node();
  n->type = SUB;
  n->firstNum = a;
  n->secondNum = b;
  return n;
}

ll calculateFibo(ll n) {
  if(n <= 1) return n;

  if(memo.find(n) != memo.end()) return memo[n];

  memo[n] = *makeFun(ADD)(
    calculateFibo(*makeFun(SUB)(1, n)), 
    calculateFibo(*makeFun(SUB)(2, n)));

  cout << memo[n] << " ";
  return memo[n];
}

Node* (*makeFun(TagType type))(ll, ll) {
  if(type == ADD) return &add;
  if(type == MUL) return &mul;
  if(type == SUB) return &sub;
  return nullptr;
}

void calc(Node* n) {
  switch(n->type) {
    case(ADD):
      cout << "add: " << (ll)(*n)<<endl;
      break;
    case(MUL):
      cout << "mul: " << (ll)(*n)<<endl;
      break;
    case(SUB):
      cout << "sub: " << (ll)(*n)<<endl;
      break;
  }
}