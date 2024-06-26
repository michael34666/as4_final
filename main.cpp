//Michael_dadush12@gmail.com
#include <iostream>
#include "complex.hpp"
#include "node.hpp"
#include "tree.hpp"



using namespace std;

int main() {

    sf::RenderWindow window(sf::VideoMode(1000, 800), "EX4");
    Node<Complex> root_node(Complex(1.0, 1.0));
    

    Node<Complex> n1(Complex(2.0, 3.1));
    Node<Complex> n2 (Complex(3.2, 4.0));
    Node<Complex> n3(Complex(0, -6.5));
    Node<Complex> n4(Complex(-7.8, 8.0));
    Node<Complex> n5(Complex(9.0, 10.0));
    Node<Complex> n6 (Complex(11.0, -12.0));
    Node<Complex> n7 (Complex(13.5, 14.0));
    
    Tree<Complex,3> tree;
    tree.add_root(&root_node);
    tree.add_sub_node(&root_node, &n1);
    tree.add_sub_node(&root_node, &n2);
    tree.add_sub_node(&root_node, &n3);
    tree.add_sub_node(&n1, &n4);
    tree.add_sub_node(&n1, &n5);
    tree.add_sub_node(&n2, &n6);
    tree.add_sub_node(&n2, &n7);
     
     while (window.isOpen()) 
    {
        sf::Event event;
        while (window.pollEvent(event)) 
        {
            if (event.type == sf::Event::Closed) 
            {
                window.close();
            }
        }
    

        window.clear(sf::Color::Green);

        // Render the tree using the Tree class method
        tree.Drew(window);

        window.display();
    

    }
    
    for (auto node = tree.begin_dfs_scan(); node != tree.end_dfs_scan(); ++node)
    {
        cout<<"Dfs_order:" << node->get_value() << endl;
    } // prints: 1+1i, 2 + 3.1i, -7.8 + 8i, 9 + 10i, 3.2 + 4i, 11 - 12i, - 6.5i
     cout <<"-------------------------------"<<endl;
     cout << endl;

    cout<<"Same printing as dfs because we have tree child"<<endl;
     for (auto node = tree.begin_pre_order(); node != tree.end_pre_order(); ++node)
    {   
        cout <<"Pre_order:"<< node->get_value() << endl;
    } // prints: 1+1i, 2 + 3.1i, -7.8 + 8i, 9 + 10i, 3.2 + 4i, 11 - 12i,- 6.5i

    cout <<"-------------------------------"<<endl;
     cout << endl;

    
   
     cout <<"-------------------------------"<<endl;
     cout << endl;
sf::RenderWindow window2(sf::VideoMode(1000, 800), "EX4");

    Node<Complex> root_node2(Complex(1.0, 1.0));
    

    Node<Complex> n12(Complex(2.0, 3.1));
    Node<Complex> n22 (Complex(3, 4));
    Node<Complex> n42(Complex(7, 8));
    Node<Complex> n52(Complex(9, 10));
    Node<Complex> n62 (Complex(11, 12));
    Node<Complex> n72 (Complex(13, 14));
    Tree<Complex,2> tree2;
    tree2.add_root(&root_node2);
    tree2.add_sub_node(&root_node2, &n12);
    tree2.add_sub_node(&root_node2 , &n22);
    tree2.add_sub_node(&n12, &n42);
    tree2.add_sub_node(&n12, &n52);
    tree2.add_sub_node(&n22, &n62);
    tree2.add_sub_node(&n22, &n72);
    
    while (window2.isOpen()) 
    {
        sf::Event event;
        while (window2.pollEvent(event)) 
        {
            if (event.type == sf::Event::Closed) 
            {
                window2.close();
            }
        }
    

        window2.clear(sf::Color::Green);

        // Render the tree using the Tree class method
        tree2.Drew(window2);

        window2.display();
    
    }
     for (auto node = tree2.begin_pre_order(); node != tree2.end_pre_order(); ++node)
    {
        cout << "Pre_order:"<<node->get_value() << endl;
    } // prints:  1+ 1i, 2+3.1i, 7+8i, 9 + 10i, 3 + 4i , 11 + 12i,  13 + 14i
    
     cout <<"-------------------------------"<<endl;

    for (auto node = tree2.begin_post_order(); node != tree2.end_post_order(); ++node)
    {
        cout <<"Post_order:"<< node->get_value() << endl;
    } // prints: 7+8i, 9 + 10i, 2+3.1i,11 + 12i, 13 + 14i, 3 + 4i ,1 + 1i
    cout <<"-------------------------------"<<endl;
     cout << endl;

    for (auto node = tree2.begin_in_order(); node != tree2.end_in_order(); ++node)
    {
        cout <<"In_order:"<< node->get_value() << endl;
    } // prints: 7+8i,2+3.1i, 9 + 10i,1 + 1i,11 + 12i,3 + 4i , 13 + 14i
     cout <<"-------------------------------"<<endl;
     cout << endl;

    for (auto node = tree2.begin_bfs_scan(); node != tree2.end_bfs_scan(); ++node)
    {
        cout<< "Bfs_order:"<< node->get_value() << endl;
    } // prints: 1 + 1i , 2+3.1i , 3 + 4i , 7+8i , 9 + 10i , 11 + 12i , 13 + 14i
     cout <<"-------------------------------"<<endl;
     cout << endl;

    tree.myHeap();
   
   for (auto it = tree.begin_min_heap_order(); it != tree.end_min_heap_order(); ++it) 
   {
       
        std::cout << "MinHeap_order:" << it->get_value() << std::endl;
    } 



     //regular number:
     sf::RenderWindow window3(sf::VideoMode(1000, 800), "EX4");
    Node<double> root_noded(1.1);
    
    Node<double> n1d(1.2);
    Node<double> n2d(1.3);
    Node<double> n3d(1.4);
    Node<double> n4d(1.5);
    Node<double> n5d(1.6);
    Tree<double> tree_double; // Binary tree that contains doubles.
    tree_double.add_root(&root_noded);     
    tree_double.add_sub_node(&root_noded, &n1d);
    tree_double.add_sub_node(&root_noded, &n2d);
    tree_double.add_sub_node(&n1d, &n3d);
    tree_double.add_sub_node(&n1d, &n4d);
    tree_double.add_sub_node(&n2d,& n5d);
    while (window3.isOpen()) 
    {
        sf::Event event;
        while (window3.pollEvent(event)) 
        {
            if (event.type == sf::Event::Closed) 
            {
                window3.close();
            }
        }
    
      window3.clear(sf::Color::Green);

        // Render the tree using the Tree class method
        tree_double.Drew(window3);

        window3.display();
    }
    // The tree should look like:
    /**
     *       root = 1.1
     *     /       \
     *    1.2      1.3
     *   /  \      /
     *  1.4  1.5  1.6
     */

    for (auto node = tree_double.begin_pre_order(); node != tree_double.end_pre_order(); ++node)
    {
        cout <<"Pre_order:"<< node->get_value() << endl;
    } // prints: 1.1, 1.2, 1.4, 1.5, 1.3, 1.6
    cout <<"-------------------------------"<<endl;
    

    for (auto node = tree_double.begin_post_order(); node != tree_double.end_post_order(); ++node)
    {
        cout <<"Post_order:"<< node->get_value() << endl;
    } // prints: 1.4, 1.5, 1.2, 1.6, 1.3, 1.1
    cout <<"-------------------------------"<<endl;

    for (auto node = tree_double.begin_in_order(); node != tree_double.end_in_order(); ++node)
    {
        cout<<"In_order:" << node->get_value() << endl;
    } // prints: 1.4, 1.2, 1.5, 1.1, 1.6, 1.3
    cout <<"-------------------------------"<<endl;

    for (auto node = tree_double.begin_bfs_scan(); node != tree_double.end_bfs_scan(); ++node)
    {
        cout <<"Bfs_order:"<< node->get_value() << endl;
    } // prints: 1.1, 1.2, 1.3, 1.4, 1.5, 1.6
    cout <<"-------------------------------"<<endl;

    for (auto node : tree_double)
    {
       cout << node->get_value() << endl;
    } // same as BFS: 1.1, 1.2, 1.3, 1.4, 1.5, 1.6

     cout <<"-------------------------------"<<endl;

   // cout << tree; // Should print the graph using GUI.

    

    return 0;


}