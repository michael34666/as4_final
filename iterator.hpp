//Michael_dadush12@gmail.com
#include "node.hpp"

#include <stack>
#include <queue>
using std::stack;
using std::queue;
using std::pair;
#pragma once

template  <typename T> class IteratorPreOrder {

    private:
        std::stack<Node<T>*> node_stack;

    public:
        IteratorPreOrder(Node<T>* root) 
        {
            if (root != nullptr) 
            {
                node_stack.push(root);
            }
        }

bool operator!=(const IteratorPreOrder& other) const 
{
    if( !(*this == other))
    {
        return true;
    }
    return false;
}

        bool operator==(const IteratorPreOrder& other) const 
        {
            if( node_stack == other.node_stack)
            {
                return true;
            }

            return false;
        }

        Node<T>* operator*() const 
        {
            return node_stack.top();
        }

        IteratorPreOrder& operator++() 
        {
            if (!node_stack.empty()) 
            {
                Node<T>* current = node_stack.top();
                node_stack.pop();
                // Push children to stack in reverse order for correct pre-order traversal
                for (auto it = current->get_son().rbegin(); it != current->get_son().rend(); ++it) 
                {
                    node_stack.push(*it);
                }
            }
            return *this;
        }
        
        Node<T>* operator->() const 
        {
            return node_stack.top();
        }
};

template<typename T>
class IteratorPostOrder {
private:
    stack<Node<T>*> nodeStack;
    Node<T>* currentNode;
    
    // Push all node to the stack in reverse
    void push_node(Node<T>* node) 
    {
        if (!node)
        {
            return;
        }

        nodeStack.push(node);

        
        for (auto it = node->get_son().rbegin(); it != node->get_son().rend(); ++it) 
        {
            push_node(*it);
        }
    }

public:
    IteratorPostOrder(Node<T>* root) : currentNode(nullptr) 
    {
        push_node(root);

        if (!nodeStack.empty()) 
        {
            currentNode = nodeStack.top();
            nodeStack.pop();
        }

    }

    Node<T>* operator->() const 
    {
        return currentNode;
    }

    bool operator!=(const IteratorPostOrder& other) const 
    {
        if( currentNode != other.currentNode)
        {
            return true;
        }
        return false;
    }

    Node<T>& operator*() const 
    {
        return *currentNode;
    }

    

    IteratorPostOrder& operator++() 
    {
        if (nodeStack.empty()) 
        {
            currentNode = nullptr;
        } 
        else 
        {
            currentNode = nodeStack.top();
            nodeStack.pop();
        }
        return *this;
    }

};


template <typename T>class IteratorInOrder {

private:
    Node<T>* current;
    stack<pair<Node<T>*, int>> nodeStack;

    void push_lefty(Node<T>* node) 
    {
        while (node) 
        {
            nodeStack.push({node, -1});  // -1 indicates the node itself hasn't been visited
            if (!node->get_son().empty()) 
            {
                node = node->get_son()[0];
            } 
            else 
            {
                break;
            }
        }
    }

public:
    IteratorInOrder(Node<T>* root) : current(nullptr) 
    {
        if (root != nullptr) 
        {
            push_lefty(root);
            advance();  // Move to the first valid element
        }
    }

    bool operator!=(const IteratorInOrder& other) const 
    {
        return current != other.current;
    }

    const T& operator*() const 
    {
        return current->value;
    }

    IteratorInOrder& operator++() 
    {
        advance();
        return *this;
    }

    Node<T>* operator->() const 
    {
        return current;
    }

private:
    
void advance() 
{
        current = nullptr;

        while (!nodeStack.empty()) 
        {
            auto& [node, index] = nodeStack.top();

            if (index == -1) 
            {  // Node itself has not been visited
                current = node;
                nodeStack.top().second++;  // Mark node itself as visited
                return;
            }

            index++;  // Move to the next child

            if ((size_t)index < node->get_son().size()) 
            {
                push_lefty(node->get_son()[index]);
            } 
            else 
            {
                nodeStack.pop();  // All children have been visited
            }
        }
    }
};





template <typename T> class IteratorBfsOrder {

private:
    std::queue<Node<T>*> queue;

public:
    IteratorBfsOrder(Node<T>* root) 
    {
        if (root) 
        {
            queue.push(root);
        }
    }

    bool operator!=(const IteratorBfsOrder& ) const 
    {
        return !queue.empty();
    }

    Node<T>* operator*() const 
    {
        return queue.front();
    }

    Node<T>* operator->() const 
    {
        return queue.front();
    }

    IteratorBfsOrder& operator++() 
    {
        Node<T>* current = queue.front();
        queue.pop();

        for (Node<T>* child : current->get_son()) 
        {
            if (child) 
            {
                queue.push(child);
            }
        }

        return *this;
    }
};

template <typename T> class IteratorDfsOrder 
{
    private:
        stack<Node<T>*> stack_node;

    public:
        IteratorDfsOrder(Node<T>* root) 
        {
            if (root)
            {
                stack_node.push(root);
            }
        }

        bool operator!=(const IteratorDfsOrder& ) const 
        {
            return !stack_node.empty();
        }

        Node<T>* operator*() const 
        {
            return stack_node.top();
        }

        Node<T>* operator->() const 
        {
         return stack_node.top();
        }

        IteratorDfsOrder& operator++() 
        {
            Node<T>* current = stack_node.top();
            stack_node.pop();

            // Push children in reverse order to achieve DFS (left to right)
            for (auto it = current->get_son().rbegin(); it != current->get_son().rend(); ++it) 
            {
                if (*it)
                {
                 stack_node.push(*it);
                }
            }

            return *this;
        }
    };

template <typename T> class IteratorHeapOrder 
{
 
 private:
    std::queue<Node<T>*> Queue_node;

public:
    IteratorHeapOrder(Node<T>* root = nullptr) 
    {
        if (root!=nullptr ) 
        {
            Queue_node.push(root);
        }
    }

    IteratorHeapOrder& operator++() 
    {
        if (!Queue_node.empty()) 
        {
            Node<T>* node = Queue_node.front();
            Queue_node.pop();

            for (Node<T>* child : node->get_son()) 
            {
                if (child != nullptr) 
                {
                    Queue_node.push(child);
                }
            }
        }

        return *this;
    }

    bool operator!=(const IteratorHeapOrder& other) const 
    {
        if( !Queue_node.empty() || !other.Queue_node.empty())
        {
            return true;
        }
        return false;
    }

    Node<T>* operator*() const {
        return Queue_node.front();
    }

    Node<T>* operator->() const 
    {
        return Queue_node.front();
    }

   
};