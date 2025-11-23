#include<iostream>
#include<string>

using namespace std;

struct VertexMember {
    unsigned int prn;
    string name;
    VertexMember* next;

    VertexMember() : prn(0), name(""), next(nullptr) {}
};

class Vertex {
    VertexMember* head;

    public:
        Vertex(){
            head = nullptr;
        }

        void addPresident(){
            VertexMember* temp = new VertexMember;
            cout<<"Enter prn of president: ";
            cin>> temp-> prn;
            cout<<"enter name of president: ";
            cin>> temp-> name;
            temp-> next= head;
            head = temp;
        }

        void addSecretery(){
            VertexMember* temp = new VertexMember;
            cout<<"enter prn of secretery: ";
            cin>>temp-> prn;
            cout<<"enter name of secretary: ";
            cin>>temp-> name;
            temp->next = nullptr;

            if(head == nullptr){
                head = temp;
            }
            else{
                VertexMember* p = head;
                while(p -> next != nullptr){
                    p = p->next;

                }
                p->next = temp;
            }
        }

        void addMember(){
            VertexMember* temp = new VertexMember;
            cout<<"enter prn of member: ";
            cin>>temp-> prn;

            cout<<"enter name of member: ";
            cin>>temp-> name;

            if(head == nullptr){
                cout<<"1. Add a president and secretary!"<<endl;
                delete temp;
                return;
            }

            VertexMember* p = head;
            while(p -> next -> next != nullptr){
                p = p-> next;
            }
            temp ->next = p->next;
            p->next = temp;
        }

        void deletePresident(){
            if(head == nullptr){
                cout<<"no members to delete!"<<endl;
                return;
            }
            VertexMember* temp = head;
            head = head -> next;
            delete temp;
        }

        void deleteSecretary(){
            if(head == nullptr){
                cout<<"no members to delete!"<<endl;
                return;
            }
            VertexMember* p = head;
            VertexMember* q = nullptr;
            while(p-> next != nullptr){
                q = p;
                p = p-> next;
            }

            if(q == nullptr){
                head = nullptr;
            }
            else{
                q-> next = nullptr;
            }
            delete p;
        }

        void deleteMemberByPRN(){
            unsigned int prn;
            cout<<"enter prn to delete : ";
            cin>>prn;
            VertexMember* p = head;
            VertexMember* q = nullptr;
            while(p != nullptr && p->prn != prn){
                q = p;
                p = p-> next;
            }
            if(p == nullptr){
                cout<<"members not found"<<endl;
                return;

            }
            if(q == nullptr){
                head = p-> next;

            }
            else{
                q -> next = p-> next;
            }
            delete p;
            cout<<"member deleted successfully!"<<endl;

        }

        void countMembers(){
            int count = 0;
            VertexMember* p = head;
            while(p != nullptr){
                count++;
                p = p-> next;
            }
            cout<<"total members: "<<count <<endl;
            return;

        }

        void displayMembers(){
            if(head == nullptr){
                cout<<"no members in the club"<<endl;
                return;

            }

            VertexMember* p = head;
            cout<<"\n---------------Vertex Club Membership Records----------------------------\n";
            while(p != nullptr){
                cout<<"[PRN: "<<p->prn <<"| Name: "<<p->name<<"]";
                if(p-> next != nullptr){
                    cout<< " -> ";
                }
                p = p->next;
            }
            cout<<" -> NULL \n";
        }

        void reverse(){
            VertexMember* prev = nullptr;
            VertexMember* current = head;
            VertexMember* next = nullptr;

            while(current != nullptr){
                next = current->next;
                current->next = prev;
                prev = current;
                current = next;
            }

            head = prev;
            cout<<"reverse successful!"<<endl;
            displayMembers();
        }

        void searchbyPRN(){
            int prn;
            cout<<"enter prn to search: ";
            cin>> prn;

            VertexMember* v = head;
            while(v != nullptr){
                if(v->prn = prn){
                    cout<<"member found: "<<v->name<<endl;
                    return;

                }
                v = v->next;
            }
            cout<<"member not found"<<endl;
        }

        void sortByPRN() {
            if(head == nullptr || head->next == nullptr)
                return;

            bool swapped;
            VertexMember* ptr;
            VertexMember* last = nullptr;

            do {
                swapped = false;
                ptr = head;

                while(ptr->next != last) {
                    if(ptr->prn > ptr->next->prn) {
                        int tempPRN = ptr->prn;
                        string tempName = ptr->name;

                        ptr->prn = ptr->next->prn;
                        ptr->name = ptr->next->name;

                        ptr->next->prn = tempPRN;
                        ptr->next->name = tempName;

                        swapped = true;
                    }
                    ptr = ptr->next;
                }
                last = ptr;
            } while(swapped);

            cout << "List sorted by PRN successfully.\n";
        }


        void concatenate(Vertex& v) {
            if(head == nullptr) {
                head = v.head;
            } else {
                VertexMember* vm = head;
                while(vm->next != nullptr)
                    vm = vm->next;

                vm->next = v.head;
            }

            v.head = nullptr;

        }

        
};

int main(){
    Vertex divA, divB;
    int choice;

    do{
        cout<<"\n-------Vertex Club Menu------------\n";
        cout<<"1. Add President\n 2. Add Secretary \n 3. Add Member \n 4.Delete Secretary \n 5. Delete President \n"
            << "6. Delete member by PRN \n 7. Count Members \n 8. Display Members 9. Reverse \n 10. Search \n 11. Sort \n 12. Concatenate Divisions\n 0. exit\n";
        cout<<"Enter choice: ";
        cin>>choice;

        switch(choice){
            case 1 : divA.addPresident();
            break;
            case 2 : divA.addSecretery();
            break;
            case 3 : divA.addMember();
            break;
            case 4 : divA.deleteSecretary();
            break;
            case 5 : divA.deletePresident();
            break;
            case 6 : divA.deleteMemberByPRN();
            break;
            case 7 : divA.countMembers();
            break;
            case 8 : divA.displayMembers();
            break;
            case 9 : divA.reverse();
            break;
            case 10 : divA.searchbyPRN();
            break;
            case 11 : divA.sortByPRN();
            break;
            case 12 : divA.concatenate(divB);
            cout<<"enter members for division b: \n";
            divB.addPresident();
            divB.addSecretery();
            divB.addMember();
            divA.concatenate(divB);
            cout<<"Concatenated divisons! \n";
            break;
            case 0 : cout<<"exiting...\n";
            break;

            default : cout<<"invalid choice\n";

        }
      
    }while(choice != 0);

    return 0;

}
