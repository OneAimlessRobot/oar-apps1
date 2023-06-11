type 'a ntree = NNil | NNode of 'a * 'a ntree list

let g = NNode(8,[NNode(7,[NNode(3,[NNil])]); NNode(10,[NNil]); NNode(9,[NNil])])

type 'a forest = 'a ntree list

let h =
	NNode (20, [
		NNode (6, [
			NNode (7, [NNil]);
			NNode (15, [NNil]);
			NNode (25, [NNil]);
			NNode (40, [NNil]);
			NNode (10, [NNil]);
			NNode (14, [
				NNode (7, [NNil])
				])
			])
		])
		let random_ntree =
			NNode (1,
				[ NNode (2, [ NNode (3, []); NNode (4, []) ]);
					NNode (5, []);
					NNode (6, [ NNode (7, []); NNode (8, []); NNode (9, []) ])
				])
				
let example_tree =
	NNode (1,
		[ NNode (2, []);
		NNode (3,
			[ NNode (4, []);
			NNode (5, []);
			NNode (6, [])
			]
		);
		NNode (7,
			[ NNode (8, []);
			NNode (9, [])
			]
		)
		]
	)

let tree_of_height_ten =
	NNode (10, [
		NNode (9, [
			NNode (8, [
				NNode (7, [
					NNode (6, [
						NNode (5, [
							NNode (4, [
								NNode (3, [
									NNode (2, [
										NNode (1, [
											NNode (0, [])
											])
										])
									])
								])
							])
						])
					])
				])
			])
		])
let f = [h; example_tree; tree_of_height_ten];;
