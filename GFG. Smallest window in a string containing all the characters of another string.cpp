string smallestWindow(string s, string p) {
    string str = "";

    // Create an array to store the count of characters in the window
    int count[256] = {0};
    int matchcount = 0;
    int dmatchcount = p.size();

    // Store the count of characters in string p
    for (char ch : p) {
        count[ch]++;
    }

    int i = 0, j = 0;
    int minLen = INT_MAX;

    while (i < s.size()) {
        // Expand the window and update the count
        count[s[i]]--;

        // If the character count is greater than or equal to 0, it's a valid match
        if (count[s[i]] >= 0) {
            matchcount++;
        }
        i++;

        // When all characters in p are found in the window, try to minimize the window size
        while (matchcount == dmatchcount) {
            if (i - j < minLen) {
                minLen = i - j;
                str = s.substr(j, minLen);
            }

            // Contract the window from the left and update the count
            count[s[j]]++;

            // If the character count becomes greater than 0, it's no longer a valid match
            if (count[s[j]] > 0) {
                matchcount--;
            }
            j++;
        }
    }
     if(str.size()==0){
         return "-1";
     }
    return str;
}
