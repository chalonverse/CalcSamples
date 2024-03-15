#pragma once
#include <string>

class Node
{
public:
	virtual void debugOut() = 0;
};

class NInteger : public Node
{
public:
	NInteger(std::string& value);
	void debugOut();
private:
	int m_int;
};

class NAdd : public Node
{
public:
	NAdd(Node* lhs, Node* rhs);
	void debugOut();
private:
	Node* m_lhs;
	Node* m_rhs;
};

class NSub : public Node
{
public:
	NSub(Node* lhs, Node* rhs);
	void debugOut();
private:
	Node* m_lhs;
	Node* m_rhs;
};

class NMult : public Node
{
public:
	NMult(Node* lhs, Node* rhs);
	void debugOut();
private:
	Node* m_lhs;
	Node* m_rhs;
};

class NDiv : public Node
{
public:
	NDiv(Node* lhs, Node* rhs);
	void debugOut();
private:
	Node* m_lhs;
	Node* m_rhs;
};
