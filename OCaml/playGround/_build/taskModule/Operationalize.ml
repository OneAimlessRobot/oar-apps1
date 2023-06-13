
open ChallengeLiterals


let rec computeDifficulty ch=
	match ch with
	| Choice []->0
	| Option (s,x) -> x
	| Choice (head::trail)  -> computeDifficulty head + computeDifficulty (Choice trail)
		
		
let sizeOfIssue= computeDifficulty example;;

let sizeOfOtherIssue= computeDifficulty complex_challenge;;
		