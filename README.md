# lem-in
42 School project

This project is a game about ant farm. Its goal is to find the shortest path from start room to the end. 
At the beginning from standart output the program recieves information about number of ants had to be leaded through path, room names (can be numbers, words, characters etc.) with coordinates and links. Here is an example:

<img width="142" alt="screen shot 2017-07-16 at 7 23 13 pm" align="middle" src="https://user-images.githubusercontent.com/25576444/28254024-ea2c5eb6-6a5d-11e7-922c-5808975b2419.png" >

Comments "##start" and "##end" are provided to show the start and end room information. We don't care about any other comments.

There are a lot of possible ways and algorithms to solve the task. One of them is Edge Table.
As soon as we got required information and validated it, we put all of the room names in array of strings, where index 0 is always start point and index (quantity_of_rooms - 1) - always the finish.
To create a table we need two coordinate axes. Each coordinate (on both axes) corresponds to index in our earlier created array of strings. This way a table with Square (quantity_of_rooms) ^ 2 is created. Now we can show connection between rooms using their indexes in array as coordinates: 0 - if there is no link and 1 - if there is one.

<img width="376" alt="screen shot 2017-07-16 at 10 14 01 pm" align="middle" src="https://user-images.githubusercontent.com/25576444/28256139-31e6c53c-6a74-11e7-8e3d-3b07d6463b9e.png">
