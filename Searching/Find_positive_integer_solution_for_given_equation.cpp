//Leetcode 1237

vector < vector < int >> findSolution(CustomFunction & customfunction, int z) {
  vector < vector < int >> res;
  int j = 1000;
  for (int i = 1; i <= 1000; i++) {
    while (j > 1 and customfunction.f(i, j) > z) j--;
    if (customfunction.f(i, j) == z) res.push_back({
      i,
      j
    });
  }
  return res;
}
