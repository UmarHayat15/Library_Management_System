#include<iostream>
#include<fstream>
using namespace std;
class Node{
    private:
        friend class LMS;
        string author;
        string title;
        string publication;
        string book_id;
        Node* next;
        Node* pre;
    public:
    Node(){}
    Node(string auth,string tit,string pub,string book){
        this->author=auth;
        this->title=tit;
        this->publication=pub;
        this->book_id=book;
        this->next=NULL;
        this->pre=NULL;
    }
};

class LMS{
    private:
    Node* head=NULL;
    fstream File;
    public:
    void menu(){
        up:
        char op;
		cout<<"*************************************************************************"<<endl;
		cout<<"1. To Enter Book"<<endl;
    	cout<<"2. To Edit Book Data"<<endl;
    	cout<<"3. To Delete Book Data"<<endl;
    	cout<<"4. To Search Book"<<endl;
    	cout<<"5. To Display Data"<<endl;
        cout<<"6. To exit"<<endl;
    	cout<<"************************************************************************"<<endl;
		cin>>op;
        switch (op){
            case '1':{
                EnterData();
                break;
            }
            case '2':{
                EditRecord();
                break;
            }
            case '3':{
                char op1;
                cout<<"1.Delete All Record"<<endl;
                cout<<"2.Delete specific Record"<<endl;
                cin>>op1;
                switch(op1){
                    case '1':{
                        head=NULL;
                        remove("LMS.txt");
                        cout<<"All Record Deleted...."<<endl;
                        break;
                    }
                    case '2':{
                        Delete();
                        break;
                    }
                    default:{
                        cout<<"Invalid Input...."<<endl;
                    }
                }
                break;
            }
            case '4':{
                Search();
                break;
            }
            case '5':{
                Display();
                break;
            }
            case '6':{
                exit(0);
                break;
            }
            default:
            cout<<"Invalid input....."<<endl;
        }
        goto up;
    }

    void Search(){
        int i=0;
        if(i==0){
            FiletoLL();
            i++;
        }
        if(head==NULL){
            cout<<"No Record...."<<endl;
            return;
        }
        char op;
        Node* temp=head;
        cout<<"Wanna search by."<<endl;
        cout<<"1.Book Id"<<endl;
        cout<<"2.Book Title"<<endl;
        cin>>op;
        switch(op){
            case '1':{
                bool flag=false;
                string var;
                cin.ignore();
                cout<<"Enter Book Id:"<<endl;
                getline(cin,var);
                while(temp!=NULL){
                    if(temp->book_id==var){
                        cout<<"Book Id:"<<temp->book_id<<endl;
                        cout<<"Author:"<<temp->author<<endl;
                        cout<<"Book Title:"<<temp->title<<endl;
                        cout<<"Publication:"<<temp->publication<<endl;
                        flag=true;
                        break;
                    }
                    temp=temp->next;
                }
                if(!flag){
                    cout<<"Record Not Found...."<<endl;
                }
                break;
            }
            case '2':{
                bool flag=false;
                string var;
                cin.ignore();
                cout<<"Enter Book Title:"<<endl;
                getline(cin,var);
                while(temp!=NULL){
                    if(temp->title==var){
                        cout<<"Book Id:"<<temp->book_id<<endl;
                        cout<<"Author:"<<temp->author<<endl;
                        cout<<"Book Title:"<<temp->title<<endl;
                        cout<<"Publication:"<<temp->publication<<endl;
                        flag=true;
                        break;
                    }
                    temp=temp->next;
                }
                if(!flag){
                    cout<<"Record Not Found...."<<endl;
                }
                break;
            }
            default:{
                cout<<"Invalid input...."<<endl;
            }
        }
    }

    bool Del(){
        Node* temp=head;
        char op;
        string var;
        bool flag=false;
        cout<<"1.To del by Book Id"<<endl;
        cout<<"2.To del by Title"<<endl;
        cin>>op;
        if(op=='1'){
            cin.ignore();
            cout<<"Enter Book Id";
            getline(cin,var);
            if(temp->book_id==var){
                head=head->next;
                head->pre=NULL;
                temp->next=NULL;
                delete temp;
                cout<<"Record deleted...."<<endl;
                return true;
            }
            while(temp!=NULL){
                if(temp->book_id==var){
                    flag=true;
                    break;
                }
                temp=temp->next;
            }
            if(flag){
                if(temp->next==NULL){
                    temp->pre->next=NULL;
                    temp->pre=NULL;
                    delete temp;
                    cout<<"Record Deleted...."<<endl;
                    return true;
                }
                temp->next->pre=temp->pre;
				temp->pre->next=temp->next;
				temp->next=NULL;
				temp->pre=NULL;
				delete temp;
				cout<<"Record deleted...."<<endl;
				return true;
			}
			return false;
        } else if(op=='2'){
            cin.ignore();
            cout<<"Enter Book Title";
            getline(cin,var);
            if(temp->title==var){
                head=head->next;
                head->pre=NULL;
                temp->next=NULL;
                delete temp;
                cout<<"Record deleted...."<<endl;
                return true;
            }
            while(temp!=NULL){
                if(temp->title==var){
                    flag=true;
                    break;
                }
                temp=temp->next;
            }
            if(flag){
                if(temp->next==NULL){
                    temp->pre->next=NULL;
                    temp->pre=NULL;
                    delete temp;
                    cout<<"Record Deleted...."<<endl;
                    return true;
                }
                temp->next->pre=temp->pre;
				temp->pre->next=temp->next;
				temp->next=NULL;
				temp->pre=NULL;
				delete temp;
				cout<<"Record deleted...."<<endl;
				return true;
			}
			return false;
        }
        else{
            return false;
        }
    }

    void Delete(){
        File.open("LMS.txt",ios::in);
        if(File.peek()==EOF && head==NULL){
            cout<<"Record is Empty...."<<endl;
            File.close();
            return;
        }
        if(!(File.eof()) && head==NULL){
            File.close();
            FiletoLL();
            if(Del()){
                LLtoFile();
            }
            return;
        }
        if(!(File.eof()) && head!=NULL){
            string var;
            File>>var;
            if(var!=head->author){
                File.close();
                FiletoLL();
                if(Del()){
                    LLtoFile();
                }
            }
        }
    }

    void EditRecord(){
        int i=0;
        if(i==0){
            FiletoLL();
            i++;
        }
        if(head==NULL){
            cout<<"No Record Found...."<<endl;
            return;
        }
        char op;
        Node* temp=head;
        cout<<"Wanna edit by."<<endl;
        cout<<"1.Book Id"<<endl;
        cout<<"2.Book Title"<<endl;
        cin>>op;
        switch(op){
            case '1':{
                cin.ignore();
                string var;
                bool flag=false;
                cout<<"Book Id:"<<endl;
                getline(cin,var);
                while (temp!=NULL)
                {
                    if(temp->book_id==var){
                        cout<<"Previous Record:"<<endl;
                        cout<<"Book Id:"<<temp->book_id<<endl;
                        cout<<"Author:"<<temp->author<<endl;
                        cout<<"Book Title:"<<temp->title<<endl;
                        cout<<"Publication:"<<temp->publication<<endl;

                        cout<<"Enter new info:"<<endl;
                        cout<<"Book Id:";
                        getline(cin,temp->book_id);
                        cout<<"Author Name:";
                        getline(cin,temp->author);
                        cout<<"Book Title:";
                        getline(cin,temp->title);
                        cout<<"Publication:";
                        getline(cin,temp->publication);

                        flag=true;
                        break;
                    }
                    temp=temp->next;
                }
                if(!flag){
                    cout<<"Record Not Found...."<<endl;
                }
                break;
            }
            case '2':{
                string var;
                bool flag=false;
                cin.ignore();
                cout<<"Enter Book Title:";
                getline(cin,var);
                while(temp!=NULL){
                    if(temp->title==var){
                        cout<<"Previous Info."<<endl;
                        cout<<"Book Id:"<<temp->book_id<<endl;
                        cout<<"Author:"<<temp->author<<endl;
                        cout<<"Book Title:"<<temp->title<<endl;
                        cout<<"Publication:"<<temp->publication<<endl;

                        cout<<"Enter new info."<<endl;
                        cout<<"Book Id:";
                        getline(cin,temp->book_id);
                        cout<<"Author Name:";
                        getline(cin,temp->author);
                        cout<<"Book Title:";
                        getline(cin,temp->title);
                        cout<<"Publication:";
                        getline(cin,temp->publication);

                        flag=true;
                        break;
                    }
                    temp=temp->next;
                }
                if(!flag){
					cout<<"Invalid info"<<endl;
				}
				break;
            }
            default:{
                cout<<"Invalid Input......"<<endl;
            }
        }
        LLtoFile();
    }

    void LLtoFile(){
        remove("LMS.txt");
        File.open("LMS.txt",ios::app);
        Node* temp=head;
        while(temp!=NULL){
            File<<temp->author<<"\n"<<temp->title<<"\n"<<temp->publication<<"\n"<<temp->book_id<<endl;
            temp=temp->next;
        }
        File.close();
    }

    void EnterData(){
        File.open("LMS.txt",ios::app);
        cin.ignore();
        string author,title,publication,bookID;
        cout<<"Enter Author Name:";
        getline(cin,author);
        cout<<"Enter Book Title:";
        getline(cin,title);
        cout<<"Enter Book Publication:";
        getline(cin,publication);
        cout<<"Enter Book Id:";
        getline(cin,bookID);
        File<<author<<"\n"<<title<<"\n"<<publication<<"\n"<<bookID<<endl;
        File.close();
        Node* node=new Node(author,title,publication,bookID);
        if(head==NULL){
            node->next=head;
            node->pre=NULL;
            head=node;
            return;
        }
        Node* temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=node;
        node->pre=temp;
    }

    void FiletoLL(){
        bool flag=false;
        head=NULL;
        File.open("LMS.txt",ios::in);
        string word,word1,word2,word3;
        while (!File.eof()){
            getline(File,word);
            getline(File,word1);
            getline(File,word2);
            getline(File,word3);
            Node* node=new Node(word,word1,word2,word3);
            if(head==NULL){
                node->next=head;
                node->pre=NULL;
                head=node;
                flag=true;
            } else{
                Node* temp=head;
                while(temp->next!=NULL){
                    temp=temp->next;
                }
                temp->next=node;
                node->pre=temp;
                flag=true;
            }
        }

        if(flag){
            Node* temp=head;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->pre->next=NULL;
            temp->pre=NULL;
            delete temp;
        }
        File.close();
        
    }
    
    void Display(){
        int i=0;
        if(i==0){
            FiletoLL();
            i++;
        }
        if(head==NULL){
            cout<<"No record found...."<<endl;
            return;
        }
        Node* temp=head;
        while(temp!=NULL){
            cout<<"Book ID:"<<temp->book_id<<endl;
            cout<<"Author Name:"<<temp->author<<endl;
            cout<<"Book Title:"<<temp->title<<endl;
            cout<<"Publication:"<<temp->publication<<endl<<endl;
            temp=temp->next;
        }
    }
};
int main(){
    LMS obj;
    obj.menu();
}