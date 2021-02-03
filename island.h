// Programming Project 5 - Archipelago Expedition Planning
// Author: Mohammed Hisham Moizuddin - CS211 FALL 2020
// UIN - 650344339

#include <iostream>
#include <string>
using namespace std;
#pragma once

class Node {
  private:
      Node * next;
      int value;

  public:
      int getValue();
      void setNext (Node * node);
      void setValue (int value);
      Node * getNext();
};


class NodeString {
  private:
      NodeString * next;
      string file;

  public:
      void setNext (NodeString * node);
      void setFname (string fname);
      string getFname();
      NodeString * getNext();
};

class ListInt {
  private:
      Node * head;

  public:
      ListInt();
      void insertValue (int value);
      bool doesValueExist (int value);
      void removeValue (int value);
      void clear();
      Node * getNode();
};

class ListString {
  private:
      NodeString * head;

  public:
      ListString();
      void insertFname (string fname);
      bool doesFnameExist (string fname);
      void removeFname (string fname);
      void clear();
};

class Island {
  private:
      ListInt intList;
      bool visited;

  public:
      Island();
      void visitIsland();
      bool isIslandVisited();
      void unvisitIsland();
      void insertValue (int value);
      void clear();
      void removeValue (int value);
      Node * getNode();
      bool doesValueExist (int value);
};