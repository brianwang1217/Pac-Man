- Initially had wonky collision detection despite checking for x and y position equivalence between all 4 ghosts and player. Initially thought it was boolean logic in if statement, but finally realized that while sometimes the ghost and player would switch positions and pass each other, they would not always end up at the same block at any given moment. 
  - Fixed by checking if the ghost and player were just 1 block away from each other and if they were going in opposite   directions.
  
- PAUSE issue: after unpausing, the screen would turn black.
  - Was using setColor(0, 0, 0) for the text, but never set color back to original color, thus drawing everything else after unpausing in black.
  
- constexpr static board[][] issue: couldn't access board 2D array in ofApp.cpp (no such architecture, etc.)
  - made it an extern variable in .hpp file and initialized it in the .cpp file.
