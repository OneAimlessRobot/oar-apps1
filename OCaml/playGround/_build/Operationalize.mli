type task = int
type challenge = Choice of challenge list | Option of string * task
val example : challenge
val complex_challenge : challenge
val computeDifficulty : challenge -> task
val sizeOfIssue : task
val sizeOfOtherIssue : task
