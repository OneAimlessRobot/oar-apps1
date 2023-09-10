
type room = int
type rooms = room list

type path = room list
type island = room list

type passage = room * room
type passages = passage list

type maze = {
    rooms: rooms;
	entrances: rooms;
    exits: rooms;
    passages: passages
}

val _NO_PATH : path

val isValid : maze -> bool
val makeLineMaze : room -> room -> maze
val combine : maze -> maze -> maze
val next : maze -> room -> rooms
val next2 : maze -> rooms -> rooms
val prev : maze -> room -> rooms
val adjacent : maze -> room -> rooms
val reachable : maze -> rooms
val solitary : maze -> rooms
val islands : maze -> island list
val shortest : maze -> path
val paths : maze -> path list
val hasLoop : maze -> bool
val shortest2 : maze -> path