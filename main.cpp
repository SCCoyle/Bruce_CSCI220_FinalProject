#include <iostream>
#include "CourseTree.h"
using namespace std;

int main()
{
    CourseTree tree;
    tree.buildTree();
    int choice;
    bool running = true;
    while (running){
        cout<<"Main Menu:"<<endl;
        cout<<"1. View course list alphabetically"<<endl;
        cout<<"2. Find a course"<<endl;
        cout<<"3. View prerequisites"<<endl;
        cout<<"4. Take a Class"<<endl;
        cout<<"5. View Transcript"<<endl;
        cout<<"6. Exit"<<endl;
        cin>>choice;
        if (choice==1){
            tree.postOrder();
        }
        if (choice==2){
            string name;
            cout<<"Enter a course name: ";
            cin.ignore(1,'/n');
            getline (cin,name);
            tree.findCourse(name);
        }
        if (choice==3){
            string name;
            cout<<"Enter a course name: ";
            cin.ignore(1,'/n');
            getline (cin,name);
            tree.viewPrerequistites(name);
        }
        if (choice==4){
            string name;
            cout<<"Enter a course to take: ";
            cin.ignore(1,'/n');
            getline (cin,name);
            tree.takeCourse(name);
        }
        if (choice==5){
            tree.viewTranscript();
        }
        if (choice==6){
            running = false;
            cout<<"Goodbye!"<<endl;
        }
    }
    return 0;
}
