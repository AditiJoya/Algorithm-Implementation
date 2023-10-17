#include<iostream>

using namespace std;

struct Node
{
public:
    int data;
    Node *next;

    Node()
    {

        data = 0;
        next = NULL;
    }
    Node(int d)
    {
        data = d;
    }
};

class SinglyLinkedList
{
public:
    Node *head;

    SinglyLinkedList()
    {
        head = NULL;
    }
    SinglyLinkedList(Node * n)
    {
        head = n;
    }

    // 1. CHeck if node exists
    Node * nodeExists(int d)
    {
        Node * temp = NULL;

        Node * ptr = head;
        while (ptr != NULL)
        {
            if (ptr -> data == d)
            {
                temp = ptr;
            }
            ptr = ptr -> next;

        }
        return temp;
    }


    // 2. Append a node to the list
    void appendNode(Node * n)
    {
        if (nodeExists(n -> data) != NULL)
        {
            cout << "Node Already exists with data: " << n -> data << ". Append another node with different data" << endl;
        }
        else
        {
            if (head == NULL)
            {
                head = n;
                cout << "Node Appended" << endl;
            }
            else
            {
                Node * ptr = head;
                while (ptr -> next != NULL)
                {
                    ptr = ptr -> next;
                }
                ptr -> next = n;
                cout << "Node Appended" << endl;
            }
        }

    }

    // 3. Prepend Node - Attach a node at the start
    void prependNode(Node * n)
    {
        if (nodeExists(n -> data) != NULL)
        {
            cout << "Node Already exists with data : " << n -> data << ". Append another node with different data" << endl;
        }
        else
        {
            n -> next = head;
            head = n;
            cout << "Node Prepended" << endl;
        }
    }


    // 4. Insert a Node after a particular node in the list
    void insertNodeAfter(int previous_data, Node * n)
    {
        Node * ptr = nodeExists(previous_data);
        if (ptr == NULL)
        {
            cout << "No node exists with data: " << previous_data << endl;
        }
        else
        {
            if (nodeExists(n -> data) != NULL)
            {
                cout << "Node Already exists with data : " << n -> data << ". Append another node with different data" << endl;
            }
            else
            {
                n -> next = ptr -> next;
                ptr -> next = n;
                cout << "Node Inserted" << endl;
            }
        }
    }



    // 5. Delete node
    void deleteNode(int d)
    {
        if (head == NULL)
        {
            cout << "Singly Linked List already Empty. Cant delete" << endl;
        }
        else if (head != NULL)
        {
            if (head -> data == d)
            {
                head = head -> next;
                cout << "Node UNLINKED with data: " << d << endl;
            }
            else
            {
                Node * temp = NULL;
                Node * prevptr = head;
                Node * currentptr = head -> next;
                while (currentptr != NULL)
                {
                    if (currentptr -> data == d)
                    {
                        temp = currentptr;
                        currentptr = NULL;
                    }
                    else
                    {
                        prevptr = prevptr -> next;
                        currentptr = currentptr -> next;
                    }
                }
                if (temp != NULL)
                {
                    prevptr -> next = temp -> next;
                    cout << "Node UNLINKED: " << d << endl;
                }
                else
                {
                    cout << "Node Doesn't exist with the data : " << d << endl;
                }
            }
        }

    }

    //search node

    void searchNode(int d)
    {
        int count=0;
        if (head == NULL)
        {
            cout << "Singly Linked List already Empty. Cant delete" << endl;
        }
        else if (head != NULL)
        {
            if (head -> data == d)
            {
                count=1;
            }
            else
            {
                Node * temp = NULL;
                Node * prevptr = head;
                Node * currentptr = head -> next;
                while (currentptr != NULL)
                {
                    if (currentptr -> data == d)
                    {
                        count=1;
                        break;

                    }

                    currentptr=currentptr->next;


                }


            }
            if(count==1)
            {
                cout<<"found"<<endl;
            }
            else
            {
                cout<<"not found"<<endl;
            }
        }

    }

    // 6th update node
    void updateNode(int prdata, int newData)
    {

        Node * ptr = nodeExists(prdata);
        if (ptr != NULL)
        {
            ptr -> data = newData;
            cout << "Node Data Updated Successfully" << endl;
        }
        else
        {
            cout << "Node Doesn't exist  : " << prdata << endl;
        }

    }
    Node *sortedOparetion(Node *q){

    //q=p;
    }

    void sortedList()
    {
        if (head == NULL)
        {
            cout << "No Nodes in Singly Linked List";
        }
        else
        {

            cout << endl << "Singly Linked SortedList Values : ";
            Node * temp = head;
             Node* p=new Node;
            head=head -> next;

            while (temp != NULL)
            {
                if(temp -> data < head -> data){

                p=temp;
                }

                else{

                    p= head;
                }
                temp=temp->next;
                head=head->next;
            }
           // head=sortedOparetion(p);
            cout << "(" << p << ") --> ";

        }

    }

    // 7th printing
    void printList()
    {
        if (head == NULL)
        {
            cout << "No Nodes in Singly Linked List";
        }
        else
        {
            cout << endl << "Singly Linked List Values : ";
            Node * temp = head;

            while (temp != NULL)
            {
                cout << "(" << temp -> data<< ") --> ";
                temp = temp -> next;
            }
        }

    }
};



int main()
{

    SinglyLinkedList s;
    int option;
    int pdata, d1, data1;
    do
    {
        cout << "\nWhat operation do you want to perform? Select Option number. Enter 0 to exit." << endl;
        cout << "1. endingNode()" << endl;
        cout << "2. beginningNode()" << endl;
        cout << "3. insertNodeAfter()" << endl;
        cout << "4. deleteNode()" << endl;

        cout<<"5. search node"<<endl;
        cout << "6. print()" << endl;
        cout << "7. Clear Screen" << endl;
        cout << "8. sortedNode()" << endl;

        cin >> option;
        Node * n1 = new Node();

        switch (option)
        {
        case 0:
            break;
        case 1:
            cout << "Append Node Operation \nEnter data of the Node to be Appended" << endl;

            cin >> data1;

            n1 -> data = data1;
            s.appendNode(n1);

            break;

        case 2:
            cout << "Prepend Node Operation \n enter data of the Node to be Prepended" << endl;

            cin >> data1;
            n1 -> data = data1;
            s.prependNode(n1);
            break;

        case 3:
            cout << "Insert Node After Operation \nEnter data of existing Node after which you want to Insert this New node: " << endl;
            cin >> d1;
            cout << "Enter data of the New Node first: " << endl;
            cin >> data1;
            n1 -> data = data1;

            s.insertNodeAfter(d1, n1);
            break;

        case 4:

            cout << "\nEnter data of the Node to be deleted: " << endl;
            cin >> d1;
            s.deleteNode(d1);

            break;

        case 5:
            /*cout << "Update Node By new data Operation - \nEnter previous data & NEW data to be updated" << endl;
            cin >> pdata;
            cin >> data1;
            s.updateNode(pdata, data1);*/
            cout<<"search item"<<endl;
            cin>>data1;
            s.searchNode(data1);

            break;

        case 6:
            s.printList();

            break;
        case 7:
            system("cls");
            break;
        case 8:
           s.sortedList();
            break;
        default:
            cout << "Enter Proper Option number " << endl;
        }

    }
    while (option != 0);

    return 0;
}

