class Solution {
public:
 
vector<string> fullJustify(vector<string>& words, int maxWidth) {
    int count = 0;
    int k = 0;
    vector<string> v;
    int maxwidthrem = maxWidth;
    
    for (int i = 0; i < words.size();) {
        string ans;
        
        // Check if the next word can fit in the current line
        if (maxwidthrem >= words[i].length() && maxwidthrem>=0) {
            maxwidthrem = maxwidthrem - words[i].length() - 1;
            
            count++;
            i++;
            
        } 
        // Only one word in the line
        else if (count == 1) {
            ans = ans + words[k];
            for (int m = 0; m < maxwidthrem + 1; m++) {
                ans = ans + ' ';
            }
            v.push_back(ans);
            maxwidthrem = maxWidth;
            k++;
            count = 0;
        } 
        // Handle other cases
        else {
            
            int espaces = (maxwidthrem + 1) / (count - 1);
            int ospaces = (maxwidthrem + 1) % (count - 1);

            maxwidthrem = maxWidth;
            count = k + count;
            while (k < count) {
                
                ans = ans + words[k];
                if (ospaces > 0 && k < count - 1) {
                    ans += ' ';
                    for (int m = 0; m < espaces + 1; m++) {
                        ans = ans + ' ';

                      
                    }
                    ospaces--;
                } else if (ospaces == 0 && k < count - 1) {
                    ans += ' ';
                    for (int m = 0; m < espaces; m++) {
                        ans = ans + ' ';
                    }
                }
                k++;
            }
            count = 0;
            v.push_back(ans);
        }
    }
    
    // Left-justified last line
    string lastLine;
    while (k < words.size()) {
        lastLine += words[k];
        if (k < words.size() - 1) {
            lastLine += ' ';
        }
        k++;
    }
    int lastLineSpaces = maxWidth - lastLine.length();
    for (int i = 0; i < lastLineSpaces; i++) {
        lastLine += ' ';
    }
    v.push_back(lastLine);

    return v;
}

};
