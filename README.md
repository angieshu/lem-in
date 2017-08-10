# lem-in

42 School project

This project is a game about ant farm. Its goal is to find the shortest path from start room to the end.

## About lem-in

At the beginning from standart output the program recieves information about number of ants had to be leaded through path, room names (can be numbers, words, characters etc.) with coordinates and links. Here is an example:

<img width="142" alt="screen shot 2017-07-16 at 7 23 13 pm" align="middle" src="https://user-images.githubusercontent.com/25576444/28254024-ea2c5eb6-6a5d-11e7-922c-5808975b2419.png" >

Comments "##start" and "##end" are provided to show the start and end room information. We don't care about any other comments.

## Installation and usage

Simply clone repository and run following commands:

```
make

./lem-in < maps/subject-1.map
```
Here 'maps/subject-1.map' is an example of game map.

## Solving a task

There are a lot of possible ways and algorithms to solve the task. One of them is Edge Table.
As soon as the program got required information and validated it, I put all of the room names in array of strings, where index 0 is always start point and index (quantity_of_rooms - 1) - always the finish.
To create a table two coordinate axes are required. Each coordinate (on both axes) corresponds to index in the earlier created array of strings. This way a table with Square (quantity_of_rooms) ^ 2 is created. Now I want to show the connection between rooms using their indexes in array as coordinates: 0 - if there is no link and 1 - if there is one.
Using an example from previous screen shot, there are 8 rooms given, where '1' is a name of the start room and '0' is the end. So they get indexes 0 and (8 - 1) respectively in array where we store all room names.

<img width="376" alt="screen shot 2017-07-16 at 10 14 01 pm" align="middle" src="https://user-images.githubusercontent.com/25576444/28256139-31e6c53c-6a74-11e7-8e3d-3b07d6463b9e.png">

Now the solving part begings. To save the path I created an array of numbers with length equal to quantity_of_rooms (maximum number of rooms I might need to visit before reach the goal) and fill it up with '-1'. Every time before changing current room, the index will be added to the path. If the index is already there (minning the room has been visited before) using backtracking algorithm, I go back to the previous room and change the connection in the Edge Table to 0, making impossible to go back to the same room again. This way, the way out is found.

<img width="122" alt="screen shot 2017-07-16 at 10 55 47 pm" src="https://user-images.githubusercontent.com/25576444/28256736-f710ff44-6a79-11e7-821a-0bbc58196e7d.png">

The final step is to take every singe ant and lead it through the created path all the way to the end, considering that all of the ants are in a start room at the beginning. The result has to be written in format Ln-r, where n - the number of ant, r - room name.

<img width="138" alt="screen shot 2017-07-16 at 11 03 59 pm" src="https://user-images.githubusercontent.com/25576444/28256885-36e1a3fc-6a7b-11e7-8a92-ef6f8a20740d.png">

## Code overview

First of all, I create a structure, that contains all the information about given map.

<img width="600" src="https://github.com/angieshu/lem-in/blob/master/img/struct_map.png">

In main() function I initialize a structure, read input, split and add a given input into a structure, solve, print the output and properly exit a program.

<img width="300" src="https://github.com/angieshu/lem-in/blob/master/img/main.png">

The way I create an Edge Table was described above. Basically, after initialization of the table, where each index corresponds to the room name, I have to fill it up with 1's and 0's if there is a connection between rooms and if there is not. 

<img width="300" src="https://github.com/angieshu/lem-in/blob/master/img/create_tab.png">

Once table is created, I can begin solving a task
Before go further, I always check if there is a connection between start and end rooms. If it is, I add start room to my path and just print a result. Otherwise, I do next.
Idially, each room has doors that lead to other rooms. I take a look into every door and check if any of them lead to the room, that has a connection with final room. If it does, I think you know what will be next. While ckeching for an exit, I'm also ckecking if I've been to one of the rooms before.
If none of the rooms has a connection with the end, I go to the very first room that is connected to the current room. If there are no rooms, using backtracking algorithm, I go back to the previous room.

<img width="300" src="https://github.com/angieshu/lem-in/blob/master/img/solution.png">

If the task solved I print the results. If it's not - display an error massage.

Also, I have an exit function, that frees all the allocated memory, which prevents my program from memory leaks.

<img width="300" src="https://github.com/angieshu/lem-in/blob/master/img/exit.png">

## Author

Anhelina Shulha



