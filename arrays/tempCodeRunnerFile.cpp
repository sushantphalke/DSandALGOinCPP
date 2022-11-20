for (int i = 0; i < n; i++) {
    int sum = 0;
    // cout << "__________" << endl;
    for (int j = i; j < n; j++) {
      sum = sum + arr[j]; 
      cout << sum << endl;
      // cout << "__________" << endl;
      counter++;
    }
  }