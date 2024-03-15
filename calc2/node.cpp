#include "node.h"
#include <iostream>


NInteger::NInteger( std::string& value )
{
	m_int = std::atoi(value.c_str());
}

void NInteger::debugOut()
{
	std::cout << m_int;
}

NAdd::NAdd( Node* lhs, Node* rhs )
	: m_lhs(lhs)
	, m_rhs(rhs)
{

}

void NAdd::debugOut()
{
	std::cout << "(";
	m_lhs->debugOut();
	std::cout << "+";
	m_rhs->debugOut();
	std::cout << ")";
}

NSub::NSub( Node* lhs, Node* rhs )
	: m_lhs(lhs)
	, m_rhs(rhs)
{

}

void NSub::debugOut()
{
	std::cout << "(";
	m_lhs->debugOut();
	std::cout << "-";
	m_rhs->debugOut();
	std::cout << ")";
}

NMult::NMult( Node* lhs, Node* rhs )
	: m_lhs(lhs)
	, m_rhs(rhs)
{

}

void NMult::debugOut()
{
	std::cout << "(";
	m_lhs->debugOut();
	std::cout << "*";
	m_rhs->debugOut();
	std::cout << ")";
}

NDiv::NDiv( Node* lhs, Node* rhs )
	: m_lhs(lhs)
	, m_rhs(rhs)
{

}

void NDiv::debugOut()
{
	std::cout << "(";
	m_lhs->debugOut();
	std::cout << "/";
	m_rhs->debugOut();
	std::cout << ")";
}
