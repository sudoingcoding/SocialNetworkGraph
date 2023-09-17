# SocialNetworkGraph
Showing Online Social Networking Graph
# Introduction
A social networking system is a digital platform designed to connect people
worldwide. Social networking system facilitate social interactions, making it easy
for individuals to stay connected and build relationships. Our social networking
system allows its users to build their own profiles, add friends, and remove
friends, display friend and friend suggestions.
# Objective
The objective of our project is to provide a very simple and user friendly social
networking platform that will enable a user to create his/her own profile, add
friends, remove friends, display friend’s profile and receive friend suggestions. It
is a prototype of a complete social networking platform where users can send
message amongst each other.
# Features
Our code has very simple features like adding, removing friends, making profiles, displaying profiles of friends, logging in and out of the user’s profile. 
These are all implemented using various data structures mostly Graph data structure.<br>
A simple overview on the mechanisms and techniques applied to buildour program is stated below:<br>
# UserProfile Class:
• This class represents a user's profile with attributes such as ID, name, age,location, institute, and password.<br>
• It has two constructors: one that takes user input to initialize these attributes and another that takes them as parameters.<br>
• The print() method is used to display the user's profile information.<br>
# Node Class:
• This class represents a node in a singly-linked list and is used to store user profiles.<br>
• It contains a pointer to a userProfile object (user) and a pointer to the next node (next).<br>
# NodeD Class:
• This class represents a node in a double-linked list and is used to store user profiles.<br>
• It contains a pointer to a userProfile object (user), a pointer to the next node (down) in the vertical direction, and a pointer to the next node (side) in the horizontal direction.<br>
# Queue Class:
• This class represents a queue data structure using linked nodes.<br>
• It includes methods for enqueueing, dequeuing, checking if the queue is empty, getting the size, displaying elements, and destroying the queue.<br>
• Front() and Rear() methods return the front and rear elements of the queue, respectively.<br>
# Stack Class:
• This class represents a stack data structure using linked nodes.<br>
• It includes methods for pushing, popping, getting the size, checking if the stack is empty, displaying elements, and destroying the stack.<br>
• Top() method returns the top element of the stack.<br>
# Graph Class:
• This class represents the social network graph, where users are stored as nodes.<br>
• It contains a pointer to the first node in the graph (head), variables to keep track of the total number of users and connections, and various methods for managing the graph.<br>
# Graph Constructor:
• Initializes head to NULL and sets totalUsers and totalConnections to 0.<br>
# CreateProfile Method:
• Creates a new user profile by taking input from the user and adds it to the graph as a new node.<br>
# AddFriend Method:
• Adds a friendship connection between two users by updating their respective linked lists (side).<br>
• Checks if the users are already friends to avoid duplicates.<br>
# SearchNewFriend and SearchFriend Methods:
• These methods search for a user profile node by name in the graph (SearchNewFriend) and within a user's friends list (SearchFriend).<br>
# DisplayFriends Method:
• Displays a user's friends and the number of mutual friends they have.<br>
# MutualFriend Method:
• Calculates the number of mutual friends between two users.<br>
# RemoveFriend Method:
• Removes a friendship connection between two users by updating their linked lists.<br>
• Handles cases where the friend to remove is the first or not the first in the list.<br>
# BFT (Breadth-First Traversal) Method:
• Performs a breadth-first traversal of the social network graph, starting from a specified user.<br>
• Displays user profiles connected to the starting user in breadth-first order.<br>
# DFT (Depth-First Traversal) Method:
• Performs a depth-first traversal of the social network graph, starting from a specified user.<br>
• Displays user profiles connected to the starting user in depth-first order.<br>
# ShortestPath Method:
• Finds the shortest path between two users in the social network graph using breadth-first search.<br>
• Displays the path from the source user to the target user.<br>
# FriendSuggestion Method:
• Generates friend suggestions for a user by comparing their friends with other users in the graph.<br>
• Returns a string containing the suggested friend names.<br>
# UserLogin Function:
• Takes the graph as input and allows users to log in by providing their name and password.<br>
• Validates the user's credentials and returns a pointer to the user's node if successful.<br>
# Limitations
• If the users or profiles have the same names then it will create conflict in the programs.<br>
• If there are many users then efficiency will decrease, it will take a longer time to execute each features of the program.<br>
# Conclusion
Overall, this code represents a basic social networking application with features for creating profiles, adding and removing friends, exploring friend
connections, and finding mutual friends. This code utilizes graph data
structures and uses other data structures like linked lists, queues, and
stacks to support the graph data structures.
