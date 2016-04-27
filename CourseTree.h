#ifndef COURSETREE_H
#define COURSETREE_H
#include <iostream>
#include <vector>

struct Node{
    int year;
    int credits;
    std::string name;
    Node *parent;
    Node *left;
    Node *right;

    Node(){};

    Node(int in_year, std::string in_name, int in_credits)
    {
        year = in_year;
        name = in_name;
        credits = in_credits;
    }

};


class CourseTree
{
    public:
        CourseTree();
        ~CourseTree();
        void postOrder();
        void findCourse(std::string name);
        void viewPrerequistites(std::string name);
        void takeCourse(std::string name);
        void viewTranscript();
        void buildTree();
    protected:
    private:
        Node *root;
        Node *searchTree(std::string name);
        void printAlphabetical(Node *node);
        void addNode(int year, std::string name, int credit);
        void DeleteAll(Node *node);
        std::vector<Node> coursesTaken;
        int totalCredits = 0;
};

#endif // COURSETREE_H
