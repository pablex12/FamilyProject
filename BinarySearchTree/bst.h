#ifndef BST_H
#define BST_H

#include "../Person/person.h"
#include <iostream>
#include <sstream>

enum Relationship
{
  GRANDFATHER = 1,
  GRANDMOTHER = 2,
  FATHER = 3,
  MOTHER = 4,
  BROTHER = 5,
  SISTER = 6,
  BROTHERINLAW = 7,
  SISTERINLAW = 8,
};

class Node
{
  friend class BST;

private:
  Person boyFriend;
  Person girlFriend;
  Node *left;
  Node *right;

public:
  Node(Person &Partner1, Person &Partner2);
  Node(Node *leftBranch, Person &Partner1, Person &Partner2, Node *rightBranch);
  // operaciones de acceso
  string nodeValue();
  Node *leftSubTree();
  Node *rightSubTree();
};

class BST
{
private:
  Node *root;

public:
  // constructores
  BST();
  BST(Node *r);
  Person people[sizeof(Person) * 14];
  Node *newTree(Node *leftBranch, Person &Partner1, Person &Partner2, Node *rightBranch);
  void insert(Person &Partner1, Person &Partner2);
  Node *insert(Node *root, Person &Partner1, Person &Partner2);
  bool isMatchingParents(Node *node, Person &Partner1, Person &Partner2);
  bool isMatchingParentLastName(Node *node, Person &Partner1, Person &Partner2);
  bool isMatchingParentSecondLastName(Node *node, Person &Partner1, Person &Partner2);

  Person *postOrderArray();
  int postOrderArray(Node *node, int index);

  Person *preOrderArray();
  int preOrderArray(Node *node, int index);

  Person *inOrderArray();
  int inOrderArray(Node *node, int index);

  Person *findRelativeMember(const string &fullName, Relationship relationship);
  Person *findRelativeMember(Node *node, const string &fullName, Relationship relationship);

  int getHeight(const string &fullName);
  int getHeight(Node *node, const string &fullName, int currentHeight);

  bool isValidRelationship(const string &fullName, Relationship relationship);
  string getGender(Relationship relationship);

  Person *findGrandParent(const string &fullName, const string &lastName, const string &secondLastName, Relationship relationship);
  Person *findGrandParent(Node *node, const string &fullName, const string &lastName, const string &secondLastName, Relationship relationship);

  Person *findParent(const string &fullName, const string &lastName, const string &secondLastName, Relationship relationship);
  Person *findParent(Node *node, const string &fullName, const string &lastName, const string &secondLastName, Relationship relationship);

  Person *findSibling(const string &fullName, const string &lastName, const string &secondLastName, Relationship Relationship);
  Person *findSibling(Node *node, const string &fullName, const string &lastName, const string &secondLastName, Relationship Relationship);

  Person *findInLaw(const string &fullName, const string &lastName, const string &secondLastName, Relationship relationship);
  Person *findInLaw(Node *node, const string &fullName, const string &lastName, const string &secondLastName, Relationship relationship);

  void printBT();
  void printBT(const std::string &prefix, Node *node, bool isLeft);
};

#endif
