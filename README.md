# lem-in
42 School project

This project is a game about ant farm. Its goal is to find the shortest path from start room to the end. 
At the beginning from standart output the program recieves information about number of ants had to be leaded through path, room names (can be numbers, words, characters etc.) with coordinates and links. Here is an example:

<img width="142" alt="screen shot 2017-07-16 at 7 23 13 pm" align="middle" src="https://user-images.githubusercontent.com/25576444/28254024-ea2c5eb6-6a5d-11e7-922c-5808975b2419.png" >

Comments "##start" and "##end" are provided to show the start and end room information. We don't care about any other comments.

You can compile the program this way:

<img width="230" alt="screen shot 2017-07-16 at 11 10 44 pm" src="https://user-images.githubusercontent.com/25576444/28256980-19ebd910-6a7c-11e7-9d7a-d1abb891b823.png">

There are a lot of possible ways and algorithms to solve the task. One of them is Edge Table.
As soon as we got required information and validated it, we put all of the room names in array of strings, where index 0 is always start point and index (quantity_of_rooms - 1) - always the finish.
To create a table we need two coordinate axes. Each coordinate (on both axes) corresponds to index in our earlier created array of strings. This way a table with Square (quantity_of_rooms) ^ 2 is created. Now we can show connection between rooms using their indexes in array as coordinates: 0 - if there is no link and 1 - if there is one.
Using an example from previous screen shot, there are 8 rooms given, where '1' is a name of the start room and '0' is the end. So they get indexes 0 and (8 - 1) respectively in array where we store all room names.

<img width="376" alt="screen shot 2017-07-16 at 10 14 01 pm" align="middle" src="https://user-images.githubusercontent.com/25576444/28256139-31e6c53c-6a74-11e7-8e3d-3b07d6463b9e.png">

Now the solving part begings. To save the path we create an array of numbers with length equal to quantity_of_rooms (maximum number of rooms we might need to visit before we reach the goal) and fill it up with '-1'. Every time before changing current room, the index will be added to the path. If the index is already there (minning we've been to the room before) using backtracking algorithm, we go back to the previous room and change the connection in the Edge Table to 0, making impossible to go back to the same room again. This way, the way out is found.

<img width="122" alt="screen shot 2017-07-16 at 10 55 47 pm" src="https://user-images.githubusercontent.com/25576444/28256736-f710ff44-6a79-11e7-821a-0bbc58196e7d.png">

The final step is to take every singe ant and lead it through the created path all the way to the end, corsidering that all of the ants are in a start room at the beginning. The result has to written in format Ln-r, where n - the number of ant, r - room name.

<img width="138" alt="screen shot 2017-07-16 at 11 03 59 pm" src="https://user-images.githubusercontent.com/25576444/28256885-36e1a3fc-6a7b-11e7-8a92-ef6f8a20740d.png">

