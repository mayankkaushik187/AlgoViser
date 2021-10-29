//Leetcode 863
void mark_parent(TreeNode * root, unordered_map < TreeNode * , TreeNode * > & parent_map) {
  queue < TreeNode * > q;
  q.push(root);
  parent_map[root] = NULL;
  while (!q.empty()) {
    int k = q.size();
    for (int i = 0; i < k; i++) {
      auto fr = q.front();
      if (fr -> left) {
        parent_map[fr -> left] = fr;
        q.push(fr -> left);
      }
      if (fr -> right) {
        parent_map[fr -> right] = fr;
        q.push(fr -> right);
      }
      q.pop();
    }
  }
}
vector < int > distanceK(TreeNode * root, TreeNode * target, int k) {
  unordered_map < TreeNode * , TreeNode * > parent_map;
  mark_parent(root, parent_map);

  unordered_map < TreeNode * , bool > visited;
  queue < TreeNode * > q;
  q.push(target);
  visited[target] = true;
  int level = 0;
  while (!q.empty()) {
    int size = q.size();
    if (level == k) break;
    level++;
    for (int i = 0; i < size; i++) {
      auto curr = q.front();
      q.pop();
      if (curr -> left and!visited[curr -> left]) {
        q.push(curr -> left);
        visited[curr -> left] = true;
      }
      if (curr -> right and!visited[curr -> right]) {
        q.push(curr -> right);
        visited[curr -> right] = true;
      }
      if (parent_map[curr] and!visited[parent_map[curr]]) {
        q.push(parent_map[curr]);
        visited[parent_map[curr]] = true;
      }
    }
  }
  vector < int > res;
  while (!q.empty()) {
    res.push_back(q.front() -> val);
    q.pop();
  }

  return res;

}
