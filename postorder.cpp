#include <iostream>
#include <string>
using namespace std;
string str1;
string str2;
class Tree{
    private:
        struct node{
            char data;
            node* left;
            node* right;
            node(char c = 0): data(c), left(NULL),right(NULL){
            }
        };
        node* root;
    public:
        Tree(){
            root = NULL;
        }
        void postorder(node* temp){
            if(temp){
                postorder(temp->left);
                postorder(temp->right);
                cout<<temp->data;
            }   
        }
        void show(){
            postorder(root);
            cout<<endl;
        }
        node* build(int s1, int e1, int s2, int e2){
            node* temp = new node();
            temp->data = str1[s1];
            int record = 0;
            for(int i=s2; i<=e2; i++){
                if(str2[i] == str1[s1]){
                    record = i;
                    break;
                }
            }
            if(record!=s2){
                temp->left = build(s1+1, s1+(record-s2), s2, record-1);
            }
            if(record!=e2){
                temp->right = build(s1+(record-s2)+1, e1, record+1, e2);
            }
            return temp;
        }
        void my_build(){
            root = NULL;
            root = build(0, str1.length()-1, 0, str2.length()-1);
        }
        void clear(node* temp){
            node* te = temp;
            if(te){
                clear(te->left);
                clear(te->right);
                delete te;
            }
        }
        ~Tree(){
            clear(root);
        }
};
int main(){
    cin>>str1>>str2;
    Tree test;
    test.my_build();
    test.show();
}  
