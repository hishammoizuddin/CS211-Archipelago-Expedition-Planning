// Programming Project 5 - Archipelago Expedition Planning
// Author: Mohammed Hisham Moizuddin - CS211 FALL 2020
// UIN - 650344339

#include "island.h"

int Node::getValue()
{ return value; }

void Node::setNext(Node * node)
{ this->next = node; }

void Node::setValue(int value)
{ this->value = value; }

Node * Node::getNext()
{ return next; }

string NodeString::getFname()
{ return file; }

void NodeString::setNext(NodeString * node)
{ this->next = node; }

void NodeString::setFname(string fname)
{ this->file = fname; }

NodeString * NodeString::getNext()
{ return next; }


ListInt::ListInt()
{ head = nullptr; }

ListString::ListString()
{ head = nullptr; }

void ListInt::insertValue(int value)
{ 
  if (doesValueExist(value))
    { cout <<"Ferry ride already added!" <<endl;
        return; }

    Node * node = new Node();
    node->setValue(value);

    if (head==nullptr)
    { head = node;
        return; }

    Node * tmp = head;

    while (tmp->getNext())
    { tmp = tmp->getNext(); }
    tmp->setNext(node);
}

void ListString::insertFname(string fname)
{
    NodeString * node = new NodeString();
    node->setFname(fname);

    if (head==nullptr)
    { head = node;
        return; }

    NodeString * tmp = head;

    while (tmp->getNext())
    { tmp = tmp->getNext(); }
    tmp->setNext(node);
}

bool ListInt::doesValueExist(int value)
{   
  Node * tmp = head;
    while (tmp!=nullptr)
    {if (tmp->getValue() == value)
            return true;
        tmp = tmp->getNext(); }
    return false;
}

bool ListString::doesFnameExist(string fname)
{
    NodeString * tmp = head;
    while (tmp!=nullptr)
    { if (tmp->getFname() == fname)
            return true;
        tmp = tmp->getNext(); }
    return false;
}

void ListInt::removeValue(int value)
{
    Node * tmp = head;
    if (tmp->getValue() == value)
    { head = head->getNext();
        delete tmp;
        return; }

    while (tmp->getNext())
    { if (tmp->getNext()->getValue() == value)
        {
            Node * next = tmp->getNext();
            tmp->setNext(tmp->getNext()->getNext());
            delete next;
            return;
        }
        tmp = tmp->getNext(); }
}

void ListString::removeFname(string fname)
{
    NodeString * tmp = head;

    if (tmp->getFname() == fname)
    { head = head->getNext();
        delete tmp;
        return; }

    while (tmp->getNext())
    { if (tmp->getNext()->getFname() == fname)
        {
            NodeString * fnode = tmp->getNext();
            tmp->setNext(tmp->getNext()->getNext());
            delete fnode;
            return;
        }
        tmp = tmp->getNext(); }
}

void ListInt::clear()
{ Node * tmp = head;

    while (tmp!=nullptr)
    { Node * node = tmp->getNext();
        delete tmp;
        tmp = node; }

    head = nullptr;
}

void ListString::clear()
{ NodeString * tmp = head;
    while (tmp!=nullptr)
    { NodeString * node = tmp->getNext();
        delete tmp;
        tmp = node; }

    head = nullptr;
}

Node * ListInt::getNode()
{ return head; }



Island::Island()
{ visited = false; }

bool Island::isIslandVisited()
{ return visited; }

void Island::visitIsland()
{ visited = true; }

void Island::unvisitIsland()
{ visited = false; }

Node * Island::getNode()
{ return intList.getNode(); }

void Island::insertValue(int value)
{ intList.insertValue(value); }

void Island::removeValue(int value)
{ intList.removeValue(value); }

bool Island::doesValueExist(int value)
{ return intList.doesValueExist(value); }

void Island::clear()
{ intList.clear(); }