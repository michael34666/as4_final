//Michael_dadush12@gmail.com
#ifndef node_H
#define node_H


#include <string>
#include <sstream>
#include <vector>


template <typename T> class Node
{
   public:
   Node(const T& value): data(value){}

   
const T& get_value() const 
{
  return data;
}

void set_value(const T& value) 
{
        data = value;
}

const std::vector<Node<T>*>& get_son()const
{
    return son;
}

std::vector<Node<T>*>& get_son() 
{
        return son;
}


void son_remove() 
{
    son.clear();
        
}


std::string str(const T& value) 
{
    std::stringstream ss;
    ss << value;
    return ss.str();
}
   
     
   private:
   T data;
   std::vector<Node<T>*> son;
   
};
#endif