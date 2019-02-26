#include <iostream>
#include <windows.h>
#include <string>
#include <cstring>
#include <vector>
#include <stack>
#include <new>
#include<stdlib.h>

using namespace std;

HANDLE h,r;
WIN32_FIND_DATA fd;
stack <HANDLE> hstack;
stack <WIN32_FIND_DATA> fdstack;

int i,j,size,d=0,t;char A[100],B[100],choice;

struct node
{
    string value;
    vector <node *> subnodes;
};

void createtree(node * a, string dir)
{
	printf("\n\t\t\tDISPLAYING FOLDERS\n");
    if (a != 0)
    {
    	t++;
        a->value = dir;
        cout << a->value << endl;
        h = FindFirstFile((a->value+"/*.").c_str(), &fd);
	//	printf("\nThis %d time",t);
		if(r==h)
			return;
		r=h;
		while ((((string)fd.cFileName == ".") || ((string)fd.cFileName == "..")) && FindNextFile(h, &fd) )
        {
        //	{ if( remove( string.c_str()) != 0 )
 		//		   perror( "Error deleting file" );
 		//	 else
    	//			printf( "File %s successfully deleted",A);}

        }
        /*if(!counter)
        {
        	printf("\n No files found !");
        	return;
		}*/
        if (((string)fd.cFileName != ".") && ((string)fd.cFileName != ".."))
        {
           hstack.push(h);
           fdstack.push(fd);
            do
            {
                dir = a->value + '/' + (string)((fdstack.top()).cFileName);
                a->subnodes.push_back(new(nothrow)node);    //push a new node into the subnodes vector
                createtree(a->subnodes.back(), dir);    //call this function with this new node as the first parameter
                cout << "\t\ta->subnodes == " << a->subnodes.size()<< endl;
            }
            while (FindNextFile(hstack.top(),&(fdstack.top())));
            hstack.pop();
            fdstack.pop();
        }
        }
    else
    {
        cout << "I took a null pointer value."<<endl;
    }
}

void createtree_exe(node * a, string dir)
{
	printf("\n\t\t\t DISPLAYING EXE FILES\n");
    if (a != 0)
    {
    	t++;
        a->value = dir;
        cout << a->value << endl;
        h = FindFirstFile((a->value+"/*.exe").c_str(), &fd);
	//	printf("\nThis %d time",t);
		if(r==h)
			return;
		r=h;
		while ((((string)fd.cFileName == ".") || ((string)fd.cFileName == "..")) && FindNextFile(h, &fd) )
        {
        //	{ if( remove( string.c_str()) != 0 )
 		//		   perror( "Error deleting file" );
 		//	 else
    	//			printf( "File %s successfully deleted",A);}

        }
        /*if(!counter)
        {
        	printf("\n No files found !");
        	return;
		}*/
        if (((string)fd.cFileName != ".exe") && ((string)fd.cFileName != ".."))
        {
           hstack.push(h);
           fdstack.push(fd);
            do
            {
                dir = a->value + '/' + (string)((fdstack.top()).cFileName);
                a->subnodes.push_back(new(nothrow)node);    //push a new node into the subnodes vector
                createtree(a->subnodes.back(), dir);    //call this function with this new node as the first parameter
                cout << "\t\ta->subnodes == " << a->subnodes.size()<< endl;
            }
            while (FindNextFile(hstack.top(),&(fdstack.top()))); printf(" Do you want to remove the files?");
            scanf("%c",&choice);
			if (choice=='y'|| choice=='Y')
            {
			{ if( remove( dir.c_str()) != 0 )
 				   perror( "Error deleting file" );
 			else
    				printf( "File %s successfully deleted",A);}

        }
            hstack.pop();
            fdstack.pop();
        }
        }
    else
    {
        cout << "I took a null pointer value."<<endl;
    }
}
void createtree_dll(node * a, string dir)
{
	printf("\n\t\tDISPLAYING DLL FILES and their deletion\n");
    if (a != 0)
    {
    	t++;
        a->value = dir;
        cout << a->value << endl;
        h = FindFirstFile((a->value+"/*.dll").c_str(), &fd);
	//	printf("\nThis %d time",t);
		if(r==h)
			return;
		r=h;
		while ((((string)fd.cFileName == ".") || ((string)fd.cFileName == "..")) && FindNextFile(h, &fd) )
        {
        //	{ if( remove( string.c_str()) != 0 )
 		//		   perror( "Error deleting file" );
 		//	 else
    	//			printf( "File %s successfully deleted",A);}

        }
        /*if(!counter)
        {
        	printf("\n No files found !");
        	return;
		}*/
        if (((string)fd.cFileName != ".dll") && ((string)fd.cFileName != ".."))
        {
           hstack.push(h);
           fdstack.push(fd);
            do
            {
                dir = a->value + '/' + (string)((fdstack.top()).cFileName);
                a->subnodes.push_back(new(nothrow)node);    //push a new node into the subnodes vector
                createtree(a->subnodes.back(), dir);    //call this function with this new node as the first parameter
                cout << "\t\ta->subnodes == " << a->subnodes.size()<< endl;
            }
            while (FindNextFile(hstack.top(),&(fdstack.top()))); printf(" Do you want to remove the files?");
            scanf("%c",&choice);
			if (choice=='y'|| choice=='Y')
            {
			{ if( remove( dir.c_str()) != 0 )
 				   perror( "Error deleting file" );
 			else
    				printf( "File %s successfully deleted",A);}

        }
            hstack.pop();
            fdstack.pop();
        }
        }
    else
    {
        cout << "I took a null pointer value."<<endl;
    }
}
/*void extension_deletion(char *A)
{

	for(i=0;i<size;i++)
	{
		if(s[i]=='.')
		{
			for(j=i+1;j<size;j++)
				{
					B[d]=A[j];
					d++;
				}
		}
	}
	printf("\nThe entension of the string is:%s",B);
	{if(B=="dll"||B=="EXE")
			 { if( remove( s.c_str()) != 0 )
 				   perror( "Error deleting file" );
 			 else
    				printf( "File %s successfully deleted",A);}
		}

}*/
int main()
{
	printf("\n\t\t\t\t\tAntivirus Software");
	printf("\n-------------------------------------------------------------------------------------------\n");
    node tree;
    cout<<"Enter file to be searched:";
    string s;
    getline(cin, s);
    size=strlen(s.c_str());
    createtree(&tree,s);
    createtree_exe(&tree,s);
    createtree_dll(&tree,s);
    return 0;
}
