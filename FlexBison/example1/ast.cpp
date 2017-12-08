#include "ast.hpp"

Node::~Node() {};


int WordNode::type() const
{
  return -1;
}

const std::string WordNode::getLowerValue() const
{
  return 0;
}

const std::string WordNode::getUpperValue() const
{
  return 0;
}

void WordNode::print(std::ostream &out) const {
  out << "word(?)";
}

LowerNode::LowerNode(const std::string _lower)
{
  lower = _lower;
}

int LowerNode::type() const
{
  return LOWER_LITERAL;
}

void LowerNode::print(std::ostream &out) const {
  out << "lower(" << lower << ")";
}


UpperNode::UpperNode(const std::string _upper)
{
  upper = _upper;
}

int UpperNode::type() const
{
  return UPPER_LITERAL;
}

void UpperNode::print(std::ostream &out) const {
  out << "upper(" << upper << ")";
}

NumberNode::NumberNode()
{
}

int NumberNode::type() const
{
  return -1;
}

int NumberNode::getIntegerValue() const
{
  return 0;
}

double NumberNode::getDoubleValue() const
{
  return 0;
}

void NumberNode::print(std::ostream &out) const {
  out << "number(?)";
}

IntegerNode::IntegerNode(int _integer)
{
  integer = _integer;
}

int IntegerNode::type() const
{
  return INTEGER_LITERAL;
}

void IntegerNode::print(std::ostream &out) const {
  out << "integer(" << integer << ")";
}

int IntegerNode::getIntegerValue() const
{
  return integer;
}

double IntegerNode::getDoubleValue() const
{
  return integer;
}


DoubleNode::DoubleNode(double _doub)
{
  doub = _doub;
}

int DoubleNode::type() const
{
  return DOUBLE_LITERAL;
}

void DoubleNode::print(std::ostream &out) const {
  out << "double(" << doub << ")";
}

int DoubleNode::getIntegerValue() const
{
  return doub;
}

double DoubleNode::getDoubleValue() const
{
  return doub;
}

StartCommandNode::StartCommandNode(const NodePtr &target,
                                   const NodePtr &power)
{
  children.push_back(target);
  children.push_back(power);
}

int StartCommandNode::type() const { return START_COMMAND; }
void StartCommandNode::print(std::ostream &out) const {
  out << "start(target=" << children.at(0)
      << ", power=" << children.at(1) << ")";
}

const std::string StartCommandNode::target() const
{
  return std::dynamic_pointer_cast<WordNode>(children.at(0))->getUpperValue();
}

double StartCommandNode::power() const
{
  return std::dynamic_pointer_cast<NumberNode>(children.at(1))->getDoubleValue();
}

StopCommandNode::StopCommandNode(const NodePtr &target) {
  children.push_back(target);
}

int StopCommandNode::type() const { return STOP_COMMAND; }
void StopCommandNode::print(std::ostream &out) const {
  out << "stop(target=" << children.at(0) << ")";
}

const std::string StopCommandNode::target() const {
  return std::dynamic_pointer_cast<WordNode>(children.at(0))->getUpperValue();
}

int ProgramNode::type() const { return PROGRAM; }

void ProgramNode::print(std::ostream &out) const {
  out << "program(children=[" << std::endl;
  for (size_t i=0; i<children.size(); ++i) {
    out << "  " << children[i] << " // child " << i << std::endl;
  }
  out << "]) // program" << std::endl;
}

int integer(const NodePtr &p) {
  return std::dynamic_pointer_cast < NumberNode >(p)->getIntegerValue();
}
 
double doub(const NodePtr &p) {
  return std::dynamic_pointer_cast < NumberNode >(p)->getDoubleValue();
}

const std::string lower(const NodePtr &p) {
return std::dynamic_pointer_cast < WordNode >(p)->getLowerValue();}
  
const std::string upper(const NodePtr &p) {
return std::dynamic_pointer_cast < WordNode >(p)->getUpperValue();}

NodePtr node(int integer) {
  return NodePtr(new IntegerNode(integer));
}

NodePtr node(double doub) {
  return NodePtr(new DoubleNode(doub));
}

NodePtr nodeL(const std::string lower) {
  return NodePtr(new LowerNode(lower));
}

NodePtr nodeU(const std::string upper) {
  return NodePtr(new UpperNode(upper));
}

std::ostream &operator<< (std::ostream& out, const NodePtr &p) {
  p->print(out);
  return out;
}
