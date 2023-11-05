#!/bin/bash


echo "cs" | ../filecompressor file2 g
echo "ds" | ../filecompressor g s
echo "diferem?"
diff file2 s
