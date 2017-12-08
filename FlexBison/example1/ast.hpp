#pragma once

#include <vector>
#include <memory>
#include <string>
#include <iostream>

class Node {
public: enum {
    PROGRAM,
    START_COMMAND,
    STOP_COMMAND,
    LOWER_LITERAL,
	UPPER_LITERAL,
    INTEGER_LITERAL,
	DOUBLE_LITERAL
  };
public: std::vector < std::shared_ptr < Node > > children;
public: virtual int type() const = 0;
public: virtual void print(std::ostream &out) const = 0;
public: virtual ~Node();
};

typedef std::shared_ptr < Node > NodePtr;

class WordNode : public Node {
public: Wordnode();
public: int type() const;
public: void print(std::ostream &out) const;  
public: const std::string getLowerValue() const;
public: const std::string getUpperValue() const;
};

typedef std::shared_ptr < WordNode > WordNodePtr;

class LowerNode : public WordNode {
public: std::string lower;
public: LowerNode(std::string _lower);
public: int type() const;
public: void print(std::ostream &out) const;  
public: const std::string getLowerValue() const;
public: const std::string getUpperValue() const;
};

typedef std::shared_ptr < LowerNode > LowerNodePtr;

class UpperNode : public WordNode {
public: std::string upper;
public: UpperNode(std::string _upper);
public: int type() const;
public: void print(std::ostream &out) const;  
public: const std::string getLowerValue() const;
public: const std::string getUpperValue() const;
};

typedef std::shared_ptr < UpperNode > UpperNodePtr;

class NumberNode : public Node {
public: NumberNode();
public: int type() const;
public: void print(std::ostream &out) const;
public: int getIntegerValue() const;
public: double getDoubleValue() const;
};

typedef std::shared_ptr < NumberNode > NumberNodePtr;

class IntegerNode : public NumberNode {
public: int integer;
public: IntegerNode(int _integer);
public: int type() const;
public: void print(std::ostream &out) const;  
public: int getIntegerValue() const;
public: double getDoubleValue() const;
};

typedef std::shared_ptr < IntegerNode > IntegerNodePtr;

class DoubleNode : public NumberNode {
public: double doub;
public: DoubleNode(double _doub);
public: int type() const;
public: void print(std::ostream &out) const;  
public: int getIntegerValue() const;
public: double getDoubleValue() const;
};

typedef std::shared_ptr < DoubleNode > DoubleNodePtr;


class StartCommandNode : public Node {
public: StartCommandNode(const NodePtr &target, const NodePtr &power);
public: int type() const;
public: void print(std::ostream &out) const;  

public: const std::string target() const;

public: double power() const;
  
};

typedef std::shared_ptr < StartCommandNode > StartCommandNodePtr;

class StopCommandNode : public Node {
public: StopCommandNode(const NodePtr &target);
public: int type() const;
public: void print(std::ostream &out) const;

public: const std::string target() const;

};

typedef std::shared_ptr < StopCommandNode > StopCommandNodePtr;

class ProgramNode : public Node {
public: int type() const;
public: void print(std::ostream &out) const;  
};

typedef std::shared_ptr < ProgramNode > ProgramNodePtr;

int integer(const NodePtr &p);

double doub(const NodePtr &p);

const std::string lower(const NodePtr &p);

const std::string upper(const NodePtr &p);

NodePtr node(int integer);

NodePtr node(double doub);

NodePtr node(const std::string lower);

NodePtr node(const std::string upper);

std::ostream &operator<< (std::ostream& out, const NodePtr &p);
