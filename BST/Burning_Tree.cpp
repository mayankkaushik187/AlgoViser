int burnTree(unordered_map < Node * , Node * > & mp, Node * target) {
  queue < Node * > q;
  unordered_map < Node * , bool > visited;
  q.push(target);
  visited[target] = true;
  int timeReq = 0;
  while (!q.empty()) {
    int size = q.size();
    int flag = 0;
    for (int i = 0; i < size; i++) {
      auto curr = q.front();
      q.pop();
      if (curr -> left and!visited[curr -> left]) {
        flag = 1;
        q.push(curr -> left);
        visited[curr -> left] = true;
      }
      if (curr -> right and!visited[curr -> right]) {
        flag = 1;
        q.push(curr -> right);
        visited[curr -> right] = true;
      }
      if (mp[curr] and!visited[mp[curr]]) {
        flag = 1;
        q.push(mp[curr]);
        visited[mp[curr]] = true;
      }
    }
    if (flag) {
      timeReq++;
    }
  }

  return timeReq;
}
Node * mark_parent(unordered_map < Node * , Node * > & mp, Node * root, int target) {
  queue < Node * > q;
  q.push(root);
  Node * res;
  while (!q.empty()) {
    int size = q.size();
    for (int i = 0; i < size; i++) {
      auto fr = q.front();
      if (fr -> data == target) {
        res = fr;
      }
      q.pop();
      if (fr -> left) {
        mp[fr -> left] = fr;
        q.push(fr -> left);
      }
      if (fr -> right) {
        mp[fr -> right] = fr;
        q.push(fr -> right);
      }
    }
  }

  return res;
}
int minTime(Node * root, int target) {
  // Your code goes here
  unordered_map < Node * , Node * > parent_map;
  Node * targetNode = mark_parent(parent_map, root, target);
  return burnTree(parent_map, targetNode);
}
