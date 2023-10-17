#include<iostream>
#define MAX 100
using namespace std;


class SortedArray
{
public:

    /// sorted an array ///
    void sorted_array(int a[],int length)
    {

        for(int i=0; i<length; i++)
        {
            for(int j=i+1; j<length; j++)
            {
                if(a[i]>a[j])
                {
                    int temp = a[i];
                    a[i] = a[j];
                    a[j] = temp;
                }
            }
        }
       display_array(a,length);


    }

    /// insert value into sorted array
    int insert_sorted_array(int arr[], int length)
    {
        int i,elem, pos;

        cout<<"\nEnter Element to Insert: ";
        cin>>elem;
        cout<<"At What Position ? ";
        cin>>pos;
        /*cout<<"before insert"<<endl;
        for(int i=0; i<length; i++)
        {
            cout<<arr[i]<<" ";

        }*/
        for(i=length; i>=pos; i--)
            arr[i] = arr[i-1];
        arr[i] = elem;
        length++;

       display_array(arr,length);

        int option, option2;
        cout<<"Want to sort this array? enter 1 or 0; "<<endl;
       // cout<<"Delete: 2 and Search:3 and display:4 for this new array;"<<endl;
        cin>>option;

        if(option ==1)
        {
            sorted_array(arr,length);
            display_array(arr,length);

            cout<<"Delete: 2, Search:3 and display:4 for this new array;"<<endl;
            cin>>option2;
            if(option2 ==2)
            {
                delete_array(arr,length);

            }
            if(option2 ==3)
            {
                search_item(arr,length);

            }
            if(option2 == 4)
            {
                display_array(arr,length);

            }


        }



    }

    /// delete value from sorted array
    void delete_array(int arr[],int length)
    {
int count=0;
        int elem;
        cout<<"\nEnter Element to Delete: "<<endl;
        cin>>elem;
        for(int i=0; i<length; i++)
        {
            if(arr[i]==elem)
            {
                count++;
                for(int j=i; j<(length-1); j++)
                    arr[j] = arr[j+1];

                length--;
                break;
            }
            else
            {
                count=0;
            }
        }
        if(count==1)
        {
            cout<<elem<<" is deleted"<<endl;
        }
        if(count==0)
        {
            cout<<"deleted item not found"<<endl;
        }
        display_array(arr,length);

    }

    /// search value from sorted array
    void search_item(int arr[], int length)
    {
        int item,index;
        int count=0;
        cout<<"Search item:"<<endl;
        cin>>item;

        for(int i=0; i<length; i++)
        {
            if(arr[i]==item)
            {
                index=i;
                count++;
                break;
            }
            else
            {
                count =0;
            }

        }
        if(count==1)
        {
            cout<<"Value found at index "<<index<< ": "<<item<<endl;
        }
        else
        {
            cout<<"Not found"<<endl;
        }
    }


    /// display the array
    void display_array(int arr[],int length)
    {
        cout<<"\nDisplay the Array is:\n"<<endl;;
        for(int i=0; i<length; i++)
            cout<<arr[i]<<"  ";
        cout<<endl;

    }

};



int main()
{
    int arr[MAX];
    int length;
    int operation;

    cout<<"enter total number of elements:"<<endl;
    cin>>length;
    cout<<"enter value in an array:"<<endl;
    for(int i=0; i<length; i++)
    {
        cin>>arr[i];
    }

    cout<<"before sorting an array:"<<endl;

    for(int i=0; i<length; i++)
    {
        cout<<arr[i]<<" ";
    }

    SortedArray sa;


    do
    {

        cout<<endl;
        cout<<"enter operation no OR to exit press 0:"<<endl;
        cout<<"1. sorted array"<<endl;
        cout<<"2. insert value"<<endl;
        cout<<"3. delete value"<<endl;
        cout<<"4. search value"<<endl;



        cout<<"enter operation no: "<<endl;
        cin>>operation;

        switch(operation)
        {
        case 1:

            sa.sorted_array(arr,length);
            break;
        case 2:
            sa.insert_sorted_array(arr,length);
            break;
        case 3:
            sa.delete_array(arr,length);
            break;
        case 4:
            sa.search_item(arr,length);
            break;


        default:
            cout<<"enter proper option number"<<endl;

        }

    }
    while(operation!=0);

}
