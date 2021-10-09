//Leetcode 212

vector < string > findWords(vector < vector < char >> & board, vector < string > & words) {
  unordered_map < char, unordered_set < string >> wordMap; // {first letter, whole word}
  unordered_set < string > found;
  // Inserts each word into map with last letter
  for (string word: words) {
    if (wordMap.count(word.back())) {
      wordMap[word.back()].insert(word);
    } else {
      wordMap.insert({
        word.back(),
        {
          word
        }
      });
    }
  }
  vector < string > result;
  int M = board.size(); // Rows
  int N = board[0].size(); // Columns
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      char currentLetter = board[i][j];
      if (wordMap.count(currentLetter) == 1) {
        for (string currentPossibleWord: wordMap[currentLetter]) {
          int letterIndex = currentPossibleWord.size() - 1;
          if (!found.count(currentPossibleWord) && dfs(board, currentPossibleWord, letterIndex, i, j) && currentPossibleWord != "") {
            result.push_back(currentPossibleWord);
            found.insert(currentPossibleWord);
          }
        }
      }
    }
  }
  return result;
}

bool dfs(vector < vector < char >> & board, string & word, int letterIndex, int i, int j) {
  // If we've found the whole word in the board
  if (letterIndex == -1) {
    return true;
  }
  if (!inside(board, word, letterIndex, i, j)) {
    return false;
  }
  // Save original letter for next searches
  char previousLetter = board[i][j];
  // Mark letter as visited on board
  board[i][j] = '*';
  // Decrease the last letter index
  letterIndex--;
  // Keep searching
  // Backtracking (Revert back previous letter)
  bool result = dfs(board, word, letterIndex, i + 1, j) ||
    dfs(board, word, letterIndex, i - 1, j) ||
    dfs(board, word, letterIndex, i, j + 1) ||
    dfs(board, word, letterIndex, i, j - 1);
  board[i][j] = previousLetter;
  return result;
}

// Checks borders if we are inside of the grid and check letter if valid
bool inside(vector < vector < char >> & board, string & word, int letterIndex, int & i, int & j) {
  if (i < 0 || i >= board.size() || j < 0 || j >= board[i].size() || word[letterIndex] != board[i][j]) {
    return false;
  }
  return true;
}
