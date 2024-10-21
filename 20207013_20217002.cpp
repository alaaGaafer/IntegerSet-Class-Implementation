#include <iostream>                                

using namespace std;
int Size=101;          //making size a global variable
class IntegerSet
{
private:
    int arr[101];     //array of size 101
public:
    IntegerSet()        //default constructor sets the array to zero
    {
        for(int i=0 ; i<Size; i++)
        {
            arr[i]=0;
        }
    }


    /*parametrized constructor that takes an array and it's size as arguments ,the constructor puts one in the object's array at the
    index which is an element in the argument array  */


    IntegerSet(int arr1[],int sizee)
    {
        for(int i=0 ; i<Size; i++)        //sets the array to zero
        {
            arr[i]=0;
        }
        for(int i=0 ; i<sizee; i++)
        {
            if(arr1[i]<=100 && arr1[i]>=0)   //if the number in the range of (0,100) it puts one at the index of the element in the array(means if
            {
                arr[arr1[i]]=1;              //the element in the argument array is 5 it will set index 5 to one in the object's array
            }
        }
    }


    /*this member function combines the two sets by adding the elements which are only in set 1 or only in set or in bot but it adds it once*/


    IntegerSet unionOfSets(IntegerSet &right)
    {
        IntegerSet temp;                                      //the third object that will hold the Union the sets
        for(int i =0; i<Size; i++)
        {
            if(arr[i]==1 || right.arr[i]==1)                  //if the element is in set 1 or in set 2 add it to the temp objects's array
            {
                temp.arr[i]=1;

            }
        }
        return temp;                                          //returning the object and assign set 3 to it
    }


    /*this member function finds the common elements in 2 sets and puts it in another set(object) */


    IntegerSet intersectionOfSets(IntegerSet &right)
    {
        IntegerSet temp;                              //the third object that will hold the intersection of the sets
        int found=0;                                  //integer to detect if there is intersection or not
        for(int i =0; i<Size; i++)
        {
            if(arr[i]==1 &&right.arr[i]==1)           //if the element in set 1 and set 2 put it in set 3(temp object)
            {
                temp.arr[i]=1;
                found=1;                              //if there is intersection found will equal 1
            }
        }
        if(found==0)                                  //found remained = 0 so there is no intersection
        {
            cout<<"there is no intersection between the sets"<<endl;
        }
        else                                          //just a message for the user
        {
            cout<<"The intersection of sets is: ";

        }
        return temp;                                   //returning the object and assign set 3 to it
    }


    /*This member function insert an element to the set by taking the element as an argument and set the index(element)to 1  */


    void insertElement(int element)
    {
        if(element >=0 && element <= 100 )                          //if the element is in the range of (0-100)
        {
            if( arr[element]==1)                                    //if the index is already set to 1 tell the user it already exist
            {
                cout<<"the element:"<<element<<" already exist in the set"<<endl;
            }
            else                                                    //if the index is set to 0 set it to 1
            {
                arr[element]=1;
                cout<<"the element inserted successfully"<<endl;

            }
        }
    }


        /*This member function deletes an element from the set by taking the element as an argument and set the index(element)to 0  */


    void deleteElement(int element)
    {
        if( arr[element]==0)                                           //if the index already set to 0 tell the user it dosen't exist
        {
            cout<<"the element:"<<element<<" dosen't exist in the set"<<endl;
        }
        else
        {
            arr[element]=0;                                            //if it set to 1 set it to 0
            cout<<"deleted successfully"<<endl;
        }
    }


    /*Prints only the elements set to 1 in the array*/


    void PrintSet()
    {
        int found=0;                                  // integer to detect if there are elements set to 1 in the array
        for(int i=0; i<Size; i++)
        {
            if(arr[i]==1)                             // if the element is set to 1 print it
            {
                cout<<i<<" ";
                found=1;                              //found =1 if there are elements set in the arrae
            }

        }
        if (found==0)                                 //if found =0 then the set is empty
        {
            cout<<"---"<<endl;
        }
        cout<<endl;
    }


    /*This function detects if the sets are the same (equal) or not */


    bool isEqualTo(const IntegerSet &right)
    {
        for(int i=0; i<Size; i++)
        {
            if(arr[i]!=right.arr[i])                            //if the element in index i doesn't equal the element in index i then they aren't equal
            {
                cout<<"the sets aren't equal"<<endl;            //and there is no need to continue
                return false;
            }
        }
        cout<<"the sets are equal"<<endl;
        return true;
    }


    /*This function seeks for the elements that are in a set and are not in the other set and puts these elements in an array of third set(object)*/


    IntegerSet operator -(IntegerSet &right)
    {
        IntegerSet temp;
        for(int i=0; i<Size; i++)
        {
            if(arr[i]==1)                         //if an element in set 1 (is set to 1) and the same element in the other array dosen't exist(is set to 0)
            {
                if(right.arr[i]!=1)
                {
                    temp.arr[i]=1;               //then store that element in temp's array
                }
            }
        }
        return temp;                             //returning the object and assign set 3 to it
    }


    /*this function turns the zeros to ones so the other elements that weren't in the array will be printed and the other elements
    existed will be remove(set to 0)*/


    IntegerSet operator !()
    {
        IntegerSet temp;
        for(int i=0; i<Size; i++)
        {
            if(arr[i]==0)
            {
                temp.arr[i]=1;
            }
            else if(arr[i]==1)
            {
                temp.arr[i]=0;
            }
        }
        return temp;

    }
};

/*The menu that is shown to the user*/

void menu()
{
    cout<<"1-Union of two sets"<<endl;
    cout<<"2-intersection of two sets"<<endl;
    cout<<"3-insert an element"<<endl;
    cout<<"4-delete an element"<<endl;
    cout<<"5-equality of two sets"<<endl;
    cout<<"6-sets difference"<<endl;
    cout<<"7-set complement"<<endl;
    cout<<"8-print the sets"<<endl;
    cout<<"9-Exit"<<endl;
}


int main()
{
    int sizee,choice;
    cout<<"please enter a size"<<endl;
    cin>>sizee;                                        //taking the size of the array from the user

    /*Filling the arrays that will be passed to objcets*/

    cout<<"this is the first set"<<endl;
    int arr1[sizee];
    for(int i=0; i<sizee; i++)
    {
        cout<<"enter the #"<<i+1<<" element"<<endl;
        cin>>arr1[i];
    }

    cout<<"this is the second set"<<endl;
    int arr2[sizee];
    for(int i=0; i<sizee; i++)
    {
        cout<<"enter the #"<<i+1<<" element"<<endl;
        cin>>arr2[i];
    }

    IntegerSet s1(arr1,sizee),s2(arr2,sizee);            //passing the array and size to the parametrized constructor

    menu();                                              //calling the menu function

    do                                                   //do while loop so the program continue to work
    {
        cout<<"enter your choice"<<endl;
        cin>>choice;
        if(choice==1)
        {
            IntegerSet s3;                               //empty set
            s3=s1.unionOfSets(s2);                       //calling the union function
            cout<<"The union of the sets is: ";
            s3.PrintSet();                               //printing the union set

        }
        else if(choice==2)
        {
            IntegerSet s3;                               //empty set
            s3=s1.intersectionOfSets(s2);                //calling the intersection function
            s3.PrintSet();                               //printing the intersection set

        }
        else if(choice==3)
        {
            int entry,element;
            IntegerSet s3;
            cout<<"to insert an element in set 1 enter:1 / to insert an element in set  enter:2"<<endl;
            cin>>entry;
            while(entry!=1 && entry!=2)
            {
                cout<<"please enter 1 or 2"<<endl;
                cin>>entry;
            }
            if(entry==1)
            {
                cout<<"enter the element"<<endl;
                cin>>element;
                s1.insertElement(element);                      //passing the element that is wanted to be inserted
            }
            else if(entry==2)
            {
                cout<<"enter the element"<<endl;
                cin>>element;
                s2.insertElement(element);
            }
        }
        else if(choice==4)
        {
            int entry,element;
            IntegerSet s3;
            cout<<"to delete an element from set 1 enter:1/ to delete an element from set enter:2"<<endl;
            cin>>entry;
            while(entry!=1 && entry!=2)
            {
                cout<<"please enter 1 or 2"<<endl;
                cin>>entry;
            }
            if(entry==1)
            {
                cout<<"enter the element"<<endl;
                cin>>element;
                s1.deleteElement(element);                      //passing the element that is wanted to be deleted
            }
            else if(entry==2)
            {
                cout<<"enter the element"<<endl;
                cin>>element;
                s2.deleteElement(element);
            }
        }
        else if(choice==5)
        {
            s1.isEqualTo(s2);
        }
        else if(choice==6)
        {
            IntegerSet s3;
            int entry;
            cout<<"enter 1 for s1-s2  and 2 for s2-s1"<<endl;
            cin>>entry;
            while(entry!=1 && entry!=2)
            {
                cout<<"please enter 1 or 2"<<endl;
                cin>>entry;
            }
            if(entry==1)
            {
                s3=s1-s2;
                cout<<"s1 - s2 : "<<endl;
                s3.PrintSet();
            }
            else if(entry==2)
            {
                s3=s2-s1;
                cout<<"s2 - s1 : "<<endl;

                s3.PrintSet();
            }

        }
        else if(choice==7)
        {
            IntegerSet s3;
            int entry;
            cout<<"enter 1 for set 1 and 2 for set 2"<<endl;
            cin>>entry;
            while(entry!=1 && entry!=2)
            {
                cout<<"please enter 1 or 2"<<endl;
                cin>>entry;
            }
            if(entry==1)
            {
                s3=!s1;
                cout<<"s1 complement:";
                s3.PrintSet();
            }
            else if(entry==2)
            {
                s3=!s2;
                cout<<"s2 complement:";

                s3.PrintSet();
            }

        }
        else if(choice==8)
        {
            cout<<"set 1: ";
            s1.PrintSet();
            cout<<endl;
            cout<<"set 2: ";

            s2.PrintSet();
            cout<<endl;


        }
    }
    while(choice!=9);      //if the user enters 9 the program will terminate
    return 0;
}
