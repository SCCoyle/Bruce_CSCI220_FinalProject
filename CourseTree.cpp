#include "CourseTree.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

CourseTree::CourseTree()
{
    //ctor
    root = NULL;
}

void CourseTree::addNode(int year, string name, int credit)
{
    Node *temp=root;
    Node *parent=NULL;
    Node *node= new Node(year, name, credit);
    node->parent=NULL;
    node->left=NULL;
    node->right=NULL;
    while (temp!=NULL){
        parent=temp;
        if (node->name.compare(temp->name) < 0)
            temp=temp->left;
        else
            temp=temp->right;
    }
    if (parent==NULL){ //tree is empty
        root=node;
        }
    else if (node->name.compare(parent->name) < 0) {
        parent->left=node;
        node->parent=parent;
        }
    else {
        parent->right=node;
        node->parent=parent;
    }
}

void CourseTree::postOrder()
{
    printAlphabetical(root);
}

void CourseTree::printAlphabetical(Node *node)
{
    if (node->left!=NULL)
        printAlphabetical(node->left);
    cout<<"Course: "<<node->name<<" Year: "<<node->year<<endl;
    if (node->right!=NULL)
        printAlphabetical(node->right);
}

void CourseTree::buildTree()
{
    addNode(1,"Intro to Programming",4);
    addNode(2,"Calculus",4);
    addNode(2,"Physics",4);
    addNode(3,"Applied Probability",4);
    addNode(3,"Data Structures",4);
    addNode(3,"Mathematical Modeling",4);
    addNode(3,"Software Development",4);
    addNode(4,"Algorithms",4);
    addNode(4,"Artificial Intelligence",4);
    addNode(4,"Computer Systems",4);
    addNode(4,"Discrete Structures",4);
    addNode(4,"Linear Algebra",4);
    addNode(4,"Operating Systems",4);
    addNode(4,"Robotics",4);
    addNode(4,"Theory of Computation",4);
}

Node * CourseTree::searchTree(string name)
{
    Node *temp = root;
    while (temp!=NULL){
        if (temp->name.compare(name) > 0)
            temp=temp->left;
        else if (temp->name.compare(name) < 0)
            temp=temp->right;
        else if (temp->name == name)
            return temp;
    }
    return NULL;
}

void CourseTree::findCourse(string name)
{
    Node *temp = searchTree(name);
    if (temp!=NULL){
        cout<<"Course: "<<temp->name<<endl;
        cout<<"Year: "<<temp->year<<endl;
        cout<<"Credits: "<<temp->credits<<endl;
    }
    else
        cout<<"Course not found"<<endl;
}

void CourseTree::viewPrerequistites(string name)
{
    Node *temp = searchTree(name);
    if (temp!=NULL){
        cout<<"Prerequisites: "<<endl;
        while (temp->parent!=NULL){
            cout<<"Course: "<<temp->parent->name<<" Year: "<<temp->parent->year<<" Credits: "<<temp->parent->credits<<endl;
            temp = temp->parent;
        }
    }
    else
        cout<<"Course not found"<<endl;
}
void CourseTree::DeleteAll(Node *node)
{
    if (node->left!=NULL)
        DeleteAll(node->left);
    if (node->right!=NULL)
        DeleteAll(node->right);
    delete node;
}
void CourseTree::takeCourse(string name)
{
    Node *temp = searchTree(name);
    if (temp!=NULL){
    coursesTaken.push_back(*temp);
    cout<<temp->name<<" taken."<<endl;
    totalCredits=totalCredits+4;
    }
    else{
        cout<<"Course not found"<<endl;
    }
}
void CourseTree::viewTranscript()
{
    cout<<"Student Transcript"<<endl;
    cout<<"Credits: "<<totalCredits<<endl;
    for (int i=0; i<coursesTaken.size(); i++)
        cout<<coursesTaken[i].name<<" Year: "<<coursesTaken[i].year<<" Credits: "<<coursesTaken[i].credits<<endl;
}

CourseTree::~CourseTree()
{
    //dtor
    DeleteAll(root);
}
