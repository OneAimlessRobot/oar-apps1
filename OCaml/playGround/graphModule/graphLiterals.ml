
type graph= {vexes: int list; edges: (int*int) list}



let testGraph = {  vexes=[1; 2; 3; 4]; edges=[(1, 2); (2, 3); (3, 4)] }


let pointGraph = {
  vexes = [1; 2; 3; 4; 5; 6; 7];
  edges = []
}

let complexGraph = {
  vexes = [1; 2; 3; 4; 5; 6; 7];
  edges = [(1, 2); (1, 3); (2, 4); (3, 4); (3, 5); (4, 6); (5, 7); (6, 7)]
}
let evenMoreComplexGraph = {
  vexes = [1; 2; 3; 4; 5; 6; 7; 8; 9; 10];
  edges = [(1, 2); (1, 3); (1, 4); (2, 4); (2, 5); (3, 6); (4, 6); (4, 7); (5, 7); (5, 8); (6, 9); (7, 9); (7, 10); (8, 10)]
}

let bigComplexGraph = {
  vexes = [1; 2; 3; 4; 5; 6; 7; 8; 9; 10; 11; 12; 13; 14];
  edges = [
    (1, 2); (1, 3); (1, 4); (2, 4); (2, 5); (3, 6); (4, 6); (4, 7); (5, 7); (5, 8);
    (6, 9); (7, 9); (7, 10); (8, 10); (11, 12); (12, 13); (13, 14)
  ]
}

let veryBigGraph = {
  vexes = [1; 2; 3; 4; 5; 6; 7; 8; 9; 10; 11];
  edges = [
    (1, 2); (1, 3); (1, 4); (1, 5); (2, 3); (2, 5); (2, 6); (3, 4); (3, 6);
    (3, 7); (4, 5); (4, 7); (4, 8); (5, 6); (5, 8); (5, 9); (6, 7); (6, 9);
    (6, 10); (7, 8); (7, 10); (7, 11); (8, 9); (8, 11); (9, 10); (9, 11);
    (10, 11); (1, 6); (2, 7); (3, 8); (4, 9); (5, 10); (6, 11); (1, 7); (2, 8);
    (3, 9); (4, 10); (5, 11); (1, 8); (2, 9); (3, 10); (4, 11)
  ]
}
let hugeGraph = {
  vexes = [1; 2; 3; 4; 5; 6; 7; 8; 9; 10; 11; 12; 13; 14; 15; 16; 17; 18; 19; 20];
  edges = [
    (1, 2); (1, 3); (1, 4); (2, 3); (2, 4); (2, 5); (3, 4); (3, 5); (3, 6); (4, 5);
    (4, 6); (4, 7); (5, 6); (5, 7); (5, 8); (6, 7); (6, 8); (6, 9); (7, 8); (7, 9);
    (7, 10); (8, 9); (8, 10); (8, 11); (9, 10); (9, 11); (9, 12); (10, 11); (10, 12);
    (10, 13); (11, 12); (11, 13); (11, 14); (12, 13); (12, 14); (12, 15); (13, 14);
    (13, 15); (13, 16); (14, 15); (14, 16); (14, 17); (15, 16); (15, 17); (15, 18);
    (16, 17); (16, 18); (16, 19); (17, 18); (17, 19); (17, 20); (18, 19); (18, 20);
    (1, 6); (2, 7); (3, 8); (4, 9); (5, 10); (6, 11); (7, 12); (8, 13); (9, 14);
    (10, 15); (11, 16); (12, 17); (13, 18); (14, 19); (15, 20)
  ]
}

let graphWithApprox50Edges = {
  vexes = [1; 2; 3; 4; 5; 6; 7; 8; 9; 10; 11; 12; 13; 14; 15; 16; 17; 18; 19; 20];
  edges = [
    (1, 2); (1, 3); (1, 4); (2, 3); (2, 4); (2, 5); (3, 4); (3, 5); (3, 6); (4, 5);
    (4, 6); (4, 7); (5, 6); (5, 7); (5, 8); (6, 7); (6, 8); (6, 9); (7, 8); (7, 9);
    (7, 10); (8, 9); (8, 10); (8, 11); (9, 10); (9, 11); (9, 12); (10, 11); (10, 12);
    (10, 13); (11, 12); (11, 13); (11, 14); (12, 13); (12, 14); (12, 15); (13, 14);
    (13, 15); (13, 16); (14, 15); (14, 16); (14, 17); (15, 16); (15, 17); (15, 18);
    (16, 17); (16, 18); (16, 19); (17, 18); (17, 19); (17, 20); (18, 19); (18, 20)
  ]
}

let graphWith16Islands = {
  vexes = [1; 2; 3; 4; 5; 6; 7; 8; 9; 10; 11; 12; 13; 14; 15; 16; 17; 18; 19; 20;
           21; 22; 23; 24; 25; 26; 27; 28; 29; 30; 31; 32; 33; 34; 35; 36; 37; 38;
           39; 40; 41; 42; 43; 44; 45; 46; 47; 48; 49; 50];
  edges = [
    (1, 2); (2, 3); (3, 4); (4, 5); (5, 6); (6, 1);  (* Island 1 *)
    (7, 8); (8, 9); (9, 7);                          (* Island 2 *)
    (10, 11); (11, 12); (12, 10);                     (* Island 3 *)
    (13, 14); (14, 15); (15, 13);                     (* Island 4 *)
    (16, 17); (17, 18); (18, 19); (19, 20);            (* Island 5 *)
    (21, 22); (22, 23); (23, 24); (24, 21);            (* Island 6 *)
    (25, 26); (26, 27); (27, 28); (28, 29);            (* Island 7 *)
    (30, 31); (31, 32); (32, 33); (33, 30);            (* Island 8 *)
    (34, 35); (35, 36); (36, 37); (37, 38);            (* Island 9 *)
    (39, 40); (40, 41); (41, 42); (42, 43); (43, 39);  (* Island 10 *)
    (44, 45); (45, 46); (46, 47); (47, 48);            (* Island 11 *)
    (49, 50)                                          (* Island 12 *)
  ]
}