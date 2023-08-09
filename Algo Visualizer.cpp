#include <iostream>

using namespace std;
void protitle();
struct node{
    int val;
    node* next;
};
node* head=NULL;
class linkedlist{
    int count=0;
public:
    linkedlist(){
        head=NULL;
        int n;
        cout<<endl<<"Enter number of nodes you wish to create: ";
        cin>>n;
        for(int i=0;i<n;i++){
            node* temp=new node;
            count++;
            cout<<endl<<"Enter value: ";
            cin>>temp->val;
            temp->next=NULL;
            if(head==NULL){
                head=temp;
            }
            else{
                node* temp1 =head;
                while(temp1->next!=NULL){
                    temp1=temp1->next;
                }
                temp1->next=temp;
            }
        }
      system("CLS");
    }
    void display(){
        node* temp=head;
        int i=1;
        cout<<"\n\tElement No\t\t Address\t\tValue\t\tNext\n";
        while(temp!=NULL){
            cout<<"\t\t"<<i<<"\t\t"<<temp<<"\t\t"<<temp->val<<"\t\t"<<temp->next<<"\n";
            i++;
            temp=temp->next;
        }
        cout<<"\n";
    }
    void linsearch(){
        int s,i=1;
        cout<<endl<<"Enter value to search: ";
        cin>>s;
        node* temp= head;
        system("CLS");
        protitle();
        cout<<endl<<"Searching for: "<<s<<"\n";
        display();
        fflush(stdin);
        getchar();
        while(temp!=NULL && temp->val!=s){
            cout<< "Element "<<i<<" is checked if it contains: "<<s<<"\n";
            temp=temp->next;
            fflush(stdin);
            getchar();
            i++;
        }
        if(temp->val == s){
            cout<<endl<<"Value found, it is at element "<<i<<" address: "<<temp;
            fflush(stdin);
            getchar();
        }
        else{
            cout<<endl<<"List has ended, Value not found.";
            fflush(stdin);
            getchar();
        }

    }
    void swap(node* a,node* b,node* pre){
        if(a==head){
            head=b;
            a->next=b->next;
            b->next=a;
        }
        else{
            pre->next=b;
            a->next=b->next;
            b->next=a;
        }
    }
    void bubblesort(){
        node* temp;
        node* pre=head;
        cout<<endl<<"\n\t\tLets start with our Bubble Sort: ";
        getchar();
        for(int i=0;i<count;i++){
            temp=head;
            for(int j=1;j<count-i;j++){
                system("CLS");
                protitle();
                cout<<"\n\t\t\tBUBBLE SORT\n\n";
                cout<<"\n"<<i<<" values from the end are now sorted\n\n";
                display();
                cout<<temp->val<<" is compared to "<<temp->next->val<<"\n";
                if(temp->val>temp->next->val){
                    node* temp2=temp->next;
                    cout<<temp->val<<" is larger so they will be swapped\n";
                    swap(temp,temp->next,pre);
                    pre=temp2;
                    fflush(stdin);
                    getchar();
                }
                else{
                    cout<<temp->val<<" is smaller so No swapping will take place \n";
                    fflush(stdin);
                    getchar();
                    pre=temp;
                    temp=temp->next;
                }
                display();
                fflush(stdin);
                getchar();
            }

        }
        cout<<"\n\nAll values have been sorted";
        getchar();
    }
    void insertbf(node* ins,node* bef){

        node* temp=head;
        while(temp->next!=ins){
            temp=temp->next;

        }
        temp->next=ins->next;
        if(bef==head){
            ins->next=bef;
            head=ins;
        }

        else{
            temp=head;
            while(temp->next!=bef){
                temp=temp->next;
            }
            temp->next=ins;
            ins->next=bef;
        }
    }
    void insort(){
        cout<<endl<<"\n\t\tLets start with our Insertion Sort: ";
        node* temp=head->next;
        node* pre;
        while(temp!=NULL){
            system("CLS");
            protitle();
            cout<<"\n\t\t\tINSERTION SORT\n\n";
            node* temp1=head;
            display();
            cout<<temp->val<<" will be compared to all previous values in Linked List to determine position\n";
            cout<<temp->val<<" is compared to "<<temp1->val<<"\n";
            getchar();
            while(temp->val>temp1->val && temp!=temp1){
                cout<<temp->val<<" is greater than "<<temp1->val<<" so it will be compared with next element to determine position\n";
                temp1=temp1->next;
                getchar();
            }

            pre=temp->next;
            if(temp->val<temp1->val){
                cout<<temp->val<<" is less than "<<temp1->val<<" so it will be inserted before it.\n";
                insertbf(temp,temp1);
                getchar();
                display();
            }
            else{
                cout<<"There is no value less than "<<temp->val<<" before it so it will stay here and next value will be compared.\n";
            }

            temp=pre;
            getchar();

        }
    }
    void selsort(){
        int i=1;
        cout<<endl<<"\n\t\tLets start with our Selection Sort: ";
        getchar();
       while(i<count){

            node* temp=head;
            node* tempre;

            for(int j=1;j<i;j++){
                tempre=temp;
                temp=temp->next;
            }
            node* min=temp;
            node* minpre;
            node* temp2pre;
            node* temp2= temp->next;
            system("CLS");
            protitle();
            cout<<"\n\t\t\tSELECTION SORT\n\n";
            cout<<"\n"<<i-1<<" values from the start are sorted\n\n";
            display();
            cout<<"Element "<<i<<" will be compared with rest of linked list to check for least value\n";
            while(temp2!=NULL){
                cout<<min->val<<" is compared to "<<temp2->val<<"\n";
                if(temp2->val<min->val){
                    cout<<temp2->val<<" is selected as the least value known. \n";
                    minpre =temp2pre;
                    min=temp2;
                }
                else{
                    cout<<min->val<<" is the least value known. \n";
                }
                temp2pre=temp2;
                temp2=temp2->next;
                getchar();
            }

            if(min->val<temp->val){
                cout<<"\nSo the least value is: "<<min->val<<" and it will be swapped with "<<temp->val;
              if(temp==head && temp->next==min){
                head=min;
                temp->next=min->next;
                min->next=temp;
              }
              else if(temp==head){
                node* t=min->next;
                head=min;
                minpre->next=temp;
                min->next=temp->next;
                temp->next=t;
              }
              else if(temp->next==min){
                node* t=min->next;
                tempre->next=min;
                min->next=temp;
                temp->next=t;
              }
              else{
                node* t=min->next;
                tempre->next=min;
                min->next=temp->next;
                minpre->next=temp;
                temp->next=t;
              }
            }
            else{
                cout<<"\nIt is determined "<<min->val<<" is at correct position so no changes.";
            }
            display();
            getchar();
            i++;
       }
       cout<<"\nALL values have been sorted.";

    }

};
void print(int Arr[],int s){
    cout<<endl;
    for(int i=0;i<s;i++){
        cout<<Arr[i]<<"\t";
    }
}

void linsearch(int arr[],int s, int val){
        getchar();
        system("CLS");
        protitle();
        print(arr,s);
        cout<<endl<<"\n\t\tLinear Search: \n\t\tSearching for: "<<val;
    for(int i=0;i<s;i++){

        cout<<"\n\tIndex "<<i+1<<" is checked\n";
       if(arr[i]==val){
        cout<<"\tValue found @ "<<i+1<<endl;
        getchar();
        break;
       }
       else if(i+1==s){
        cout<<"\tValue not found, it is not in Array. "<<endl;
        }
        getchar();
    }

}
void binsearch(int arr[],int val,int h,int l,int s){
    getchar();
    system("CLS");
    protitle();
    print(arr,s);
    cout<<endl<<"\n\t\tBinary Search: \n\t\tSearching for: "<<val;


    int mid=(h+l)/2;

    if(val==arr[mid]){
        cout<<"\n\tMid of "<<l+1<<" & "<<h+1<<" is checked = "<<mid+1;
        cout<<"\n\tValue found @ "<<mid+1<<endl;
        getchar();
    }
    else if(h==l){
        cout<<"\n\t\tData not found";
        getchar();
    }
    else if(val>arr[mid]){
        cout<<"\n\tMid of "<<l+1<<" & "<<h+1<<" is checked = "<<mid+1<<"\n";
        cout<<"Data is greater than mid element so further search will done in between "<<mid+2<<" & "<<h+1<<" elements";
        binsearch(arr,val,h,mid+1,s);

    }
    else{
        cout<<"\n\tMid of "<<l<<" & "<<h<<" is checked = "<<mid+1<<"\n";
        cout<<"Data is lesser than mid element so further search will done in between "<<l+1<<" & "<<mid<<" elements";
        binsearch(arr,val,mid-1,l,s);

    }
}
void bubblesort(int arr[],int s){
    print(arr,s);
    cout<<endl<<"\n\t\tLets start with our Bubble Sort: ";
    getchar();
    for(int i=0;i<s;i++){
        for(int j=1;j<s-i;j++){
            system("CLS");
            protitle();
            cout<<"\n\t\t\tBUBBLE SORT\n\n";
            print(arr,s);
            cout<<"\n\t\tElement "<<j<<" will be compared with element "<<j+1<<"\n";
            if(arr[j-1]>arr[j]){
                cout<<"\t\tSince Element "<<j+1<<" is larger, they will be swapped\n";
                int temp=arr[j];
                arr[j]=arr[j-1];
                arr[j-1]=temp;
            }
            else{
                cout<<"\t\tThese will not be swapped\n";
            }
            getchar();
            print(arr,s);
            getchar();

        }
        if(i<s-1){
            cout<<"\n\t\t"<<i+1<<" element from the right are now sorted.";
        }
        else{
            cout<<endl<<"\t\t\tAll element  are now sorted.";
        }

    }
}
void selsort(int arr[],int s){
    int min;
    cout<<endl<<"\n\t\tLets start with Selection Sort: ";
    for(int i=0;i<s;i++){
        min=i;
        system("CLS");
        protitle();
        cout<<"\n\t\t\tSELECTION SORT\n\n";
        print(arr,s);
        for(int j=i+1;j<s;j++){

            cout<<"\n\t"<<j+1<<" element is compared with "<<min+1<<" element to determine "<<i+1<<" value\n";
            getchar();
            if(arr[j]<arr[min]){
                min=j;
                cout<<"\t"<<min+1<<" is smaller";
            }
        }
        if(min!=i){
            cout<<"\n\t "<<min+1<<" is smallest value and will be placed at "<<i+1<<" index";
            int temp=arr[i];
            arr[i]=arr[min];
            arr[min]=temp;
            getchar();
        }
    }
    cout<<"\n\t All values have been sorted in ascending order";
}
void insort(int arr[],int s){

    int val,j;
    cout<<endl<<"\n\t\tLets start with Insertion Sort: ";
    for(int i=1;i<s;i++){
        system("CLS");
        protitle();
        cout<<"\n\t\t\tINSERTION SORT\n\n";
        print(arr,s);
        val=arr[i];
        j=i-1;
        int k=0,flag=0;
        cout<<"\n\t"<<i+1<<" element is compared to previous values to determine its position";
        getchar();
        while(j>=0 && arr[j]>val){
            arr[j+1]=arr[j];
            j--;
            flag=1;
            k++;
        }
        if(flag==1){
            cout<<"\n\t It moves "<<k<<" position backwards and other elements are shifted forward";
        }
        else{
            cout<<"\n\tThere is no larger element behind it, no shifting takes place";
        }

        arr[j+1]=val;
        print(arr,s);
        getchar();
    }
    cout<<"\n\t All values have been sorted in ascending order";
}

void projectInfo(){
    system("CLS");
    cout<<"\n\n\t\t\t\t\t      S&S ALGORITHM VISUALISER";
    cout<<"\n\t\t\t\t---------------------------------------------------";
    cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t---------------------------------------------------";
    cout<<"\n\n\t\t\t\t\t\tDATA STRUCTURES";
    cout<<"\n\t\t\t\t\t\tAND";
    cout<<"\n\t\t\t\t\t\tALGORITHMS";
    cout<<"\n\t\t\t\t---------------------------------------------------";
    cout<<"\n\t\t\t\tCourse Instructor: MISS ANUM JAVED";
    cout<<"\n\n\n\n\n\tMember 01\t\t\t\t\t\t\t\tMember 02";
    cout<<"\n\t-----------------------------\t\t\t\t\t\t-----------------------------";
    cout<<"\n\tMUHAMMED TUAHA RIZWAN\t\t\t\t\t\t\tARHAM ADNAN";
    cout<<"\n\tFA21-BSCS-0066\t\t\t\t\t\t\t\tFA21-BSCS-0063";
    getchar();
    system("CLS");
}
void protitle(){
    cout<<"\n\t\t\t\t\t      S&S ALGORITHM VISUALISER";
    cout<<"\n\t\t\t\t---------------------------------------------------\n\n";
}
int main()
{

    int c=1;

    while(c!=0){
        projectInfo();
        protitle();
        cout<<"\n\n\n\n\n\t\t\t\t\t1) Arrays";
        cout<<"\n\n\t\t\t\t\t2) Linked List";
        cout<<"\n\n\t\t\t\t\t0) Quit";
        cin>>c;
        if(c==1){
            int size;
            system("CLS");
            protitle();
            cout<<"Enter size for your array: ";
            cin>>size;
            int Arr[size];
            for(int i=0;i<size;i++){
                cout<<"Enter value for array: ";
                cin>>Arr[i];
            }

            system("CLS");
            protitle();
            cout<<"\tARRAY: \n";
            print(Arr,size);
            int ch=1,sort=0;
            while(ch!=0){
                cout<<"\n\n\n\n\n\t\t\t\tWhich sorting algorithm would you like to perform on your Array:";
                cout<<"\n\n\t\t\t\t\t1) Bubble Sort";
                cout<<"\n\n\t\t\t\t\t2) Selection Sort";
                cout<<"\n\n\t\t\t\t\t3) Insertion Sort";
                cout<<"\n\n\t\t\t\t\t0) Skip";
                if(sort==1){
                    break;
                }
                cin>>ch;
                switch(ch){
                case 1:
                    bubblesort(Arr,size);
                    sort=1;
                    break;

                case 2:
                    selsort(Arr,size);
                    sort=1;
                    break;
                case 3:
                    insort(Arr,size);
                    sort=1;
                    break;
                case 0:
                    break;
                default:
                    cout<<"Please enter correct option";
                    break;
                }
            }

            system("CLS");
            protitle();
            cout<<"\tARRAY: \n";
            print(Arr,size);
            cout<<"\n\n\n\n\n\t\t\t\tWhich searching algorithm would you like to perform on your Array:";
            cout<<"\n\n\t\t\t\t\t1) Linear Search";
            cout<<"\n\n\t\t\t\t\t2) Binary Search";
            cin>>ch;
            if(ch==1){
                int search;
                cout<<"Enter the value you wish to search: ";
                cin>>search;
                linsearch(Arr,size,search);
            }
            else if(ch==2){
                if(sort==0){
                    cout<<"Sorry Binary search cannot be performed on unsorted data: ";
                    getchar();
                }
                else{
                    int search;
                    cout<<"Enter the value you wish to search: ";
                    cin>>search;
                    binsearch(Arr,search,size-1,0,size);
                }


            }

        }
        else if(c==2){

            system("CLS");
            protitle();
            cout<<"\tLINKED LIST: \n";
            linkedlist list;
            list.display();
            int ch=1,sort=0;
            while(ch!=0){
                if(sort==1){
                    break;
                }
                cout<<"\n\n\n\n\n\t\t\t\tWhich sorting algorithm would you like to perform on your Linked LIst:";
                cout<<"\n\n\t\t\t\t\t1) Bubble Sort";
                cout<<"\n\n\t\t\t\t\t2) Selection Sort";
                cout<<"\n\n\t\t\t\t\t3) Insertion Sort";
                cout<<"\n\n\t\t\t\t\t0) Skip";

                cin>>ch;
                switch(ch){
                case 1:

                    list.bubblesort();
                    list.display();
                    sort=1;
                    break;

                case 2:
                    list.selsort();
                    list.display();
                    sort=1;
                    break;
                case 3:
                    list.insort();
                    list.display();
                    sort=1;
                    break;
                case 0:
                    break;
                default:
                    cout<<"Please enter correct option";
                    break;
                }
            }

            system("CLS");
            protitle();
            cout<<"\tLINKED LIST: \n";
            list.display();
            cout<<"\n\n\n\n\n\t\t\t\tWould you like to perform linear search on your Linked List (1 for yes):";
            cin>>ch;
            if(ch==1){
                list.linsearch();
            }

        }
    }




    return 0;
}
