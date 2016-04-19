void revSentence(string str, stack<char> &stk, int i) {
  if(i == str.size())
    return;
  revSentence(str, stk, i+1);
  if((!stk.empty() && stk.top != ' ' && str[i] == ' ') || i == 0) {
    if(!i)
      cout << str[i];
    while(!stk.empty()) {
      cout << stk.top();
      stk.pop();
    }
    if(i)
      cout << str[i];
  }
  stk.push(str[i]);
  if(!i)
    cout << str[i] << endl;
}
