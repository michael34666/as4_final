//Michael_dadush12@gmail.com

#include "node.hpp"
#include "iterator.hpp"
#include <queue>
#include <stack>
#include <iostream>
#include <SFML/Graphics.hpp>
#ifndef TREE_H
#define TREE_H
using std::cout;
using std::endl;
using namespace std;
using std::stack;
using std::vector;




template <typename T, size_t K = 2 > class Tree
{ 
  public:
    Tree():root(nullptr) {}

    ~Tree()
    {  
       // Handle empty tree case
       if (root == nullptr) 
       {
            return;  
       }

        stack<Node<T>*> stack;
        stack.push(root);

        while (!stack.empty()) 
        {
            Node<T>* current = stack.top();
            stack.pop();

            // Print Deleting node info
            cout << "Deleting node with value: " << current->get_value() <<std:: endl;

            // Iterate over children and push them onto the stack
            for (Node<T>* child : current->get_son()) 
            {
                if (child != nullptr) 
                {
                    stack.push(child);
                }
            }

            // Clear son vector to avoid deleting them again in the destructor
            current->get_son().clear();
        }

        root = nullptr;  // Set root to nullptr after deletion
      
    }





    
  void add_root(Node <T>*  r)
 {
   if(!root)
   {
     root=r;
   }

   else
   {
     throw std::string("There is root for the tree");
   }

 }

     void set_root(Node<T> * r)
     {
       root=r;
     }
     
     Node<T>* get_root()
     {
      return root;
     }
     
void add_sub_node(Node<T>* tr, Node<T>* ad) 
{
    if (tr != nullptr) 
    {
        if (tr->get_son().size() >= K) 
        {
            throw std::string("Can't put more than K children per node");
        }

        tr->get_son().push_back(ad);
    } 

    else 
    {
        add_root(ad);
    }
}
     

     


void heapify(Node<T>* node) 
{
        if (node == nullptr) return;

        vector<Node<T>*> children = node->get_son();
        for (Node<T>* child : children) 
        {
            heapify(child);
        }

        if (!children.empty()) 
        {
            std::sort(children.begin(), children.end(), [](Node<T>* a, Node<T>* b) 
            {
                return a->get_value() < b->get_value();
            });
            node->get_son() = children;
        }

        for (Node<T>* child : children) 
        {
            if (child->get_value() < node->get_value()) 
            {
                T temp = child->get_value();
                child->set_value(node->get_value());
                node->set_value(temp);
            }
        }
}



IteratorDfsOrder<T> begin_pre_order()
{ 
    
  return IteratorDfsOrder<T>(root);

}
 IteratorDfsOrder<T> end_pre_order()
 {
 
   return IteratorDfsOrder<T>(nullptr);
  
 }
 
 IteratorDfsOrder<T> begin_post_order()
{
  
  return IteratorDfsOrder<T>(root);
 
}

IteratorDfsOrder<T> end_post_order()
{
  
  return IteratorDfsOrder<T>(nullptr);
}

IteratorDfsOrder<T> begin_in_order()
{
  return IteratorDfsOrder<T>(root);
}

IteratorDfsOrder<T> end_in_order()
{
  return IteratorDfsOrder<T>(nullptr);
}

IteratorBfsOrder<T> begin_bfs_scan()
{
  return IteratorBfsOrder<T>(root);
}

IteratorBfsOrder<T> end_bfs_scan()
{
  return IteratorBfsOrder<T>(nullptr);
}

IteratorBfsOrder<T> begin()
{
  return begin_bfs_scan();
}

IteratorBfsOrder<T> end()
{
  return end_bfs_scan();
}

IteratorDfsOrder<T> begin_dfs_scan()
{
  return IteratorDfsOrder<T>(root);
}

IteratorDfsOrder<T> end_dfs_scan()
{
  return IteratorDfsOrder<T>(nullptr);
}

IteratorHeapOrder<T> begin_min_heap_order() 
{
    return IteratorHeapOrder<T>(root);
}

IteratorHeapOrder<T> end_min_heap_order() 
{
  return IteratorHeapOrder<T>(nullptr);
}

void myHeap() 
{
  heapify(root);
}
void Drew(sf::RenderWindow& window) 
{
  if (root) 
  {
    DrewNode(root, window, 400.f, 50.f, 200.f); 
  }
}

private:
   Node<T>* root;
  
      void DrewNode(Node<T>* node, sf::RenderWindow& window, float x, float y, float xOffset) 
      {
        if (!node)
            return;

        // Draw node- the circle
        sf::CircleShape circle(20.f);
        circle.setFillColor(sf::Color::Black);
        circle.setPosition(x, y);
        window.draw(circle);

        // Draw data
        sf::Font font;
        font.loadFromFile("/usr/share/fonts/truetype/dejavu/DejaVuSans-Bold.ttf");
        sf::Text text(node->str(node->get_value()), font);
        text.setCharacterSize(12);
        text.setFillColor(sf::Color::White);
        text.setPosition(x + 10.f, y + 10.f);
        window.draw(text);
       

       
        auto children = node->get_son();
        float childX = x - xOffset;
        for (auto child : children) {
            if (child) {
                
                sf::Vertex line[] = {
                    sf::Vertex(sf::Vector2f(x + 10.f, y + 10.f)),
                    sf::Vertex(sf::Vector2f(childX + 10.f, y + 50.f))
                };
                window.draw(line, 2, sf::Lines);

               
                DrewNode(child, window, childX, y + 50.f, xOffset / 2.f);
                childX += xOffset;

            }
        }
    }
  
};

//for binary tree
template <typename T > class Tree<T,2>{

public:
    Tree():root(nullptr) {}

    ~Tree()
    {
       // Handle empty tree case
       if (root == nullptr) 
       {
            return;  
       }

        stack<Node<T>*> stack;
        stack.push(root);

        while (!stack.empty()) 
        {
            Node<T>* current = stack.top();
            stack.pop();

            
            std::cout << "Deleting node with value: " << current->get_value() << std::endl;

            // Iterate over children and push them to the stack
            for (Node<T>* child : current->get_son()) 
            {
                if (child != nullptr) 
                {
                    stack.push(child);
                }
            }

            // Clear son vector to avoid deleting them again 
            current->get_son().clear();
        }

        root = nullptr;  // Set root to nullptr after deletion
    
        
}

   void heapify(Node<T>* node) 
   {
        if (node == nullptr) return;

        std::vector<Node<T>*> children = node->get_son();
        for (Node<T>* child : children) 
        {
            heapify(child);
        }

        if (!children.empty()) 
        {
            std::sort(children.begin(), children.end(), [](Node<T>* a, Node<T>* b) 
            {
              return a->get_value() < b->get_value();
            });
            node->get_son() = children;
        }

        for (Node<T>* child : children) 
        {
            if (child->get_value() < node->get_value()) 
            {
                T temp = child->get_value();
                child->set_value(node->get_value());
                node->set_value(temp);
            }
        }
    }



    
  void add_root(Node <T>*  r)
 {
   if(!root)
   {
     root=r;
   }

   else
   {
     throw std::string("There is root for the tree");
   }

 }

void set_root(Node<T> * r)
{
  root=r;
}
     
Node<T>* get_root()
{
  return root;
}
     
void add_sub_node(Node<T>* tr, Node<T>* ad) 
{
    if (tr != nullptr) 
    {
        if (tr->get_son().size() >= 2) 
        {
            throw std::runtime_error("Can't put more than K children per node");
        }

        tr->get_son().push_back(ad);
    } 

    else 
    {
        add_root(ad);
    }
}
     
IteratorPreOrder<T> begin_pre_order()
{ 
    
  return IteratorPreOrder<T>(root);

}

IteratorPreOrder<T> end_pre_order()
{
  return IteratorPreOrder<T>(nullptr);
  
}
 
IteratorPostOrder<T> begin_post_order()
{
  
    return IteratorPostOrder<T>(root);
}
 
IteratorPostOrder<T> end_post_order()
{
   return IteratorPostOrder<T>(nullptr);
  
}

IteratorInOrder<T> begin_in_order()
{
  return IteratorInOrder<T>(root);
}
 
IteratorInOrder<T> end_in_order()
{
 return IteratorInOrder<T>(nullptr);
}

IteratorBfsOrder<T> begin_bfs_scan()
{
   return IteratorBfsOrder<T>(root);
}

IteratorBfsOrder<T> end_bfs_scan()
{
  return IteratorBfsOrder<T>(nullptr);
}


IteratorDfsOrder<T> begin_dfs_scan()
{
  return IteratorDfsOrder<T>(root);
}

IteratorDfsOrder<T> end_dfs_scan()
{
  return IteratorDfsOrder<T>(nullptr);
}

IteratorHeapOrder<T> begin_min_heap_order() 
{
    return IteratorHeapOrder<T>(root);
}

IteratorHeapOrder<T> end_min_heap_order() 
{
  return IteratorHeapOrder<T>(nullptr);
}

void myHeap() 
{
  heapify(root);
}

IteratorBfsOrder<T> begin()
{
  return begin_bfs_scan();
}

IteratorBfsOrder<T> end()
{
  return end_bfs_scan();
}

void Drew(sf::RenderWindow& window) 
{
  if (root) 
  {
    DrewNode(root, window, 400.f, 50.f, 200.f); 
  }
}


  private:
   Node<T>* root;
   void DrewNode(Node<T>* node, sf::RenderWindow& window, float x, float y, float xOffset) 
      {
        if (!node)
            return;

        // Draw node 
        sf::CircleShape circle(20.f);
        circle.setFillColor(sf::Color::Black);
        circle.setPosition(x, y);
        window.draw(circle);

        // Draw data
        sf::Font font;
        font.loadFromFile("/usr/share/fonts/truetype/dejavu/DejaVuSans-Bold.ttf");
        sf::Text text(node->str(node->get_value()), font);
        text.setCharacterSize(12);
        text.setFillColor(sf::Color::White);
        text.setPosition(x + 10.f, y + 10.f);
        window.draw(text);
       

        
        auto children = node->get_son();
        float childX = x - xOffset;
        for (auto child : children) {
            if (child) {
                
                sf::Vertex line[] = {
                    sf::Vertex(sf::Vector2f(x + 10.f, y + 10.f)),
                    sf::Vertex(sf::Vector2f(childX + 10.f, y + 50.f))
                };
                window.draw(line, 2, sf::Lines);

                
                DrewNode(child, window, childX, y + 50.f, xOffset / 2.f);
                childX += xOffset;

            }
        }
    }
   

};

#endif

