#include <iostream>
#include <cstring>
#include <string>

using namespace std;

class Stack{
private:
    char A[101];
    int top = -1;
public:
    void push(char x);
    void pop();
    char Top();
    bool isempty();
    void annoy();
};

void Stack::pop(){
    if (isempty()){
        cout << "empty stack \n";
        return;
    }
    top--;

}

char Stack::Top(){
    if (isempty()){
        return '\n';
    }
    return A[top];
}

bool Stack::isempty(){
    if (top == -1){
        return true;
    }
    return false;
}

void Stack::push(char x){
    if (top == 100){
        cout << "Stack full" << endl;
        return;
    }
    top++;
    A[top] = x;
}

void Stack::annoy(){
    cout << top << endl;
}


void Reverse(char *C, int len){
    Stack wind;
    for( int i = 0; i < len; i++){
        wind.push(C[i]);
    }
    while(!(wind.isempty())){
        wind.pop();
    }
}

void Revtwo(char *C, int len){
    int mini = 0;
    int maxi = len-1;
    while (mini < maxi){
        char temp = C[mini];
        C[mini] = C[maxi];
        C[maxi] = temp;
        mini++;
        maxi--;
    }


}


bool is_opening(char a){
    if (a == '('){
            return true;
        }
    else {return false;}
}



bool CharCheck(char a, char b){
    if (a == '{' && b == '}'){
        return true;
    }
    if (a == '[' && b == ']'){
        return true;
    }
    if (a == '(' && b == ')'){
        return true;
    }
    return false;

}


void Compile(char* c, int len){
    Stack stark;
    for( int i = 0; i < len; i++){
        if (c[i] == '{' || c[i] == '(' || c[i] == '[' ){
                stark.push(c[i]);
            }
        else if (c[i] == '}' || c[i] == ')' || c[i] == ']' ){
                if (stark.isempty()){
                    cout << "Invalid Case \n";
                    return;
                }
                if (CharCheck(stark.Top(),c[i])){
                    stark.pop();
                }else{
                    cout << "Invalid Case \n";
                    return;
                }
            }
    }
    if (stark.isempty()){
        cout << "Valid Case \n";
    }else{
        cout << "Invalid Case \n";
    }

}

bool is_operand(char a){
    if (a == '+' || a == '-' || a == '*' || a == '/'){
        return true;
    }
    return false;
}

bool bodmas(char a, char b){
    char o[4] = {'/','*','+','-'};
    int a1, b1;
    for (int i = 0;i < 4; i++ ){
        if (o[i] == a){
            a1 = i;
            break;
        }
    }
    for (int s = 0; s < 4; s++ ){
        if (o[s] == b){
            b1 = s;
            break;
        }
    }

    if (a1 > b1 || a1 == b1){
        return false;
    }
    return true;
}




void postfix(char* problem){
    Stack stark;
    Stack operations;
    for (int i= 0; i< strlen(problem); i++){
        if (is_operand(problem[i]) && (operations.isempty()|| operations.Top()=='(')){
                operations.push(problem[i]);

        }else if (is_operand(problem[i])&& !(operations.isempty())){
                  if (bodmas(problem[i],operations.Top())){
                    operations.push(problem[i]);
                  }else{
                      while (!bodmas(problem[i],stark.Top()) && !operations.isempty()){
                        stark.push(operations.Top());
                        operations.pop();
                      }
                      operations.push(problem[i]);
                  }
        }else{
            if (problem[i]=='('){
                    operations.push(problem[i]);
                }else if(problem[i] == ')'){
                    while (operations.Top()!= '('){
                            stark.push(operations.Top());
                            operations.pop();
                           }
                           operations.pop();
                }else{
            stark.push(problem[i]);
                }
        }
    }
    while (!operations.isempty()){
                        stark.push(operations.Top());
                        operations.pop();
                      }
    string b = "";
    while(!stark.isempty()){
        b.insert(0,1,stark.Top());
        stark.pop();
    }
    cout << b;

}




int main()
{
postfix("A-B+C/D*E");

}
